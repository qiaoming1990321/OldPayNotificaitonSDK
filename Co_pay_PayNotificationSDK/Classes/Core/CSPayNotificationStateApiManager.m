//
//  CSPayNotificationStateApiManager.m
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/22.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "CSPayNotificationStateApiManager.h"
#import "CSPayNotificationModel.h"
#import "CSPayNotificationConfig.h"
#import "CSPayNotificationDeviceModel.h"
#import "NSString+CSPayNotificationSecure.h"
#import <AFNetworking/AFNetworking.h>
#import "CSPayNotificationRequestSerializer.h"
#import "CSPayNotificationSecureManager.h"

@interface CSPayNotificationStateApiManager ()

//@property (nonatomic, strong) GMNetHttpHelper *helper;
@property (nonatomic, strong) AFHTTPSessionManager *httpManager;

@end

@implementation CSPayNotificationStateApiManager

+ (CSPayNotificationStateApiManager *)sharedManager
{
    static CSPayNotificationStateApiManager *payNotificationStateApiManager;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        payNotificationStateApiManager = [[CSPayNotificationStateApiManager alloc] init];
    });
    return payNotificationStateApiManager;
}

-(void)checkiOSIAPPayOrderWithPayNotificationModel:(CSPayNotificationModel *)payNotificationModel  complete:(PayNotificationStateApiCompleteBlock)complete
{

    [self startAsyncWithPayNotificationModel:payNotificationModel complete:^(CSPayNotificationHTTPResponse * _Nonnull response) {
        complete(response);
    }];
}

-(void)startAsyncWithPayNotificationModel:(CSPayNotificationModel *)payNotificationModel complete:(PayNotificationStateApiCompleteBlock)complete{
    //防止同时设置的时候 出现值被覆盖   加锁
    @synchronized(self) {
        NSString *url;
        NSString *baseUrl = [CSPayNotificationConfig sharedManger].getPayStateDomain;
        NSString *clientId = [CSPayNotificationConfig sharedManger].getClientID;
        BOOL isDebug = [CSPayNotificationConfig sharedManger].isTest;
        NSString *queriesString = [NSString stringWithFormat:@"client_id=%@&timestamp=%lld", clientId,(long long)[[NSDate date] timeIntervalSince1970]*1000];
//        NSString *queriesString = [NSString stringWithFormat:@"client_id=%@&timestamp=1548677852000", clientId];
        
        
        url = [NSString stringWithFormat:@"%@/api/v1/ios/verification/subscription?%@", baseUrl, queriesString];
        
        [self.httpManager.requestSerializer clearAuthorizationHeader];
        
        self.httpManager.requestSerializer = [CSPayNotificationRequestSerializer serializer];
        
        self.httpManager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json",@"text/html", @"text/plain",nil];
        
        self.httpManager.securityPolicy.allowInvalidCertificates = YES;
        self.httpManager.securityPolicy.validatesDomainName = NO;
        
        //集成账号类型认证：此种情况下客户端请求时所对应的用户账号来自账号中心，因此使用Token认证方式
        NSString *accessToken = [CSPayNotificationConfig sharedManger].accessToken;
        if (accessToken.length) {
            [self.httpManager.requestSerializer setValue:accessToken forHTTPHeaderField:@"X-Auth-Token"];
        }
        //独立账号类型认证:需要设置HTTP请求头X-Account-Id
        NSString *client_id = [CSPayNotificationConfig sharedManger].clientID;
        if (clientId.length) {
            [self.httpManager.requestSerializer setValue:client_id forHTTPHeaderField:@"X-Account-Id"];
        }
        
        [self.httpManager.requestSerializer setValue:@"des" forHTTPHeaderField:@"X-Crypto"];
        
        NSMutableDictionary *queries = [NSMutableDictionary dictionary];
        if (payNotificationModel.receipt.length) {
            [queries setObject:payNotificationModel.receipt forKey:@"receipt"];
        }
        if (payNotificationModel.product_id) {
            [queries setObject:payNotificationModel.product_id forKey:@"product_id"];
        }
        
        [queries setValue:[CSPayNotificationDeviceModel deviceWithDid:[[CSPayNotificationConfig sharedManger] getStaticUUID]] forKey:@"device"];

        

        NSString *sign = [self signatureWithMethodName:@"POST" requestUrl:@"/api/v1/ios/verification/subscription" queries:queriesString payload:queries];
        
        [self.httpManager.requestSerializer setValue:sign forHTTPHeaderField:@"X-Signature"];
        
        [self.httpManager POST:url parameters:queries progress:^(NSProgress * _Nonnull uploadProgress) {
            
        } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            NSString *responseString = nil;
            responseString = [CSPayNotificationSecureManager decryptUseDES:responseObject key:[CSPayNotificationConfig sharedManger].desKey keyNeedBase64:YES];
            NSRange range = [responseString rangeOfString:@"}" options:NSBackwardsSearch];
            responseString= [responseString substringWithRange:(NSRange){0,range.location+1}];
            
            
            CSPayNotificationHTTPResponse *httpResponse = [[CSPayNotificationHTTPResponse alloc] init];
            httpResponse.statusCode = PayNotificationHttpStatusSuccess;
            httpResponse.bodyString = responseString;
            complete(httpResponse);
            
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            CSPayNotificationHTTPResponse *httpResponse = [[CSPayNotificationHTTPResponse alloc] init];
            httpResponse.bodyString = [CSPayNotificationSecureManager decryptUseDES:error.userInfo[@"com.alamofire.serialization.response.error.data"] key:[CSPayNotificationConfig sharedManger].desKey keyNeedBase64:YES];
            httpResponse.bodyData = error.userInfo;
            if (error.code / 100 == 5 || error.code == 0) {
                //服务器配置问题 需要重新上传
                httpResponse.statusCode = PayNotificationHttpStatusFail;
                complete(httpResponse);
                return;
            }
            if (error.code == 404) {
                //网路问题
                httpResponse.statusCode = PayNotificationHttpStatusFail;
                complete(httpResponse);
                return;
            }
            httpResponse.statusCode = PayNotificationHttpStatusSuccess;
            complete(httpResponse);
        }];

    }
}

- (NSString *)signatureWithMethodName:(NSString *)methodName requestUrl:(NSString *)requestUrl queries:(NSString *)queryString payload:(NSMutableDictionary *)payload{
    NSMutableString *valueToDigest = [NSMutableString string];
    [valueToDigest appendFormat:@"%@\n", methodName];
    [valueToDigest appendFormat:@"%@\n", requestUrl ? requestUrl : @""];
    
    
    [valueToDigest appendFormat:@"%@\n", queryString ? queryString : @""];
    
    NSString *payloadString = @"";
    NSError *error;
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:payload
                                                       options:kNilOptions
                                                         error:&error];
    
    if (!error) {
        payloadString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    }
    
    [valueToDigest appendFormat:@"%@", payloadString ? payloadString : @""];
    NSAssert([CSPayNotificationConfig sharedManger].xSignatureKey != nil, @"XSignatureKey 的地址为空!");
    NSString *sign = [NSString payNotificationSecureHmacSHA256AndSafeUrlBase64EncodeWithKey:[CSPayNotificationConfig sharedManger].xSignatureKey value:valueToDigest];
    return sign;
}



+ (NSURLCache *)defaultURLCache {
    return [[NSURLCache alloc] initWithMemoryCapacity:5 * 1024 * 1024
                                         diskCapacity:20 * 1024 * 1024
                                             diskPath:@"com.payNotification.apiHelper"];
}

+ (NSURLSessionConfiguration *)defaultURLSessionConfiguration {
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    
    //TODO set the default HTTP headers
    
    configuration.HTTPShouldSetCookies = YES;
    configuration.HTTPShouldUsePipelining = NO;
    
    configuration.requestCachePolicy = NSURLRequestUseProtocolCachePolicy;
    configuration.allowsCellularAccess = YES;
//    configuration.timeoutIntervalForRequest = [CSPayNotificationConfig sharedInstance].req;
//    configuration.URLCache = [GMNetHttpHelper defaultURLCache];
    
    return configuration;
}

- (AFHTTPSessionManager *)httpManager
{
    if (!_httpManager) {
        _httpManager = [[AFHTTPSessionManager alloc] initWithSessionConfiguration:[[self class] defaultURLSessionConfiguration]];
    }
    return _httpManager;
}

@end
