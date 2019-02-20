//
//  CSPayNotificationRequestSerializer.m
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "CSPayNotificationRequestSerializer.h"
#import "CSPayNotificationSecureManager.h"
#import "CSPayNotificationConfig.h"

@implementation CSPayNotificationRequestSerializer

- (NSURLRequest *)requestBySerializingRequest:(NSURLRequest *)request
                               withParameters:(id)parameters
                                        error:(NSError *__autoreleasing *)error
{
    NSParameterAssert(request);
    
    if ([self.HTTPMethodsEncodingParametersInURI containsObject:[[request HTTPMethod] uppercaseString]]) {
        return [super requestBySerializingRequest:request withParameters:parameters error:error];
    }
    
    NSMutableURLRequest *mutableRequest = [request mutableCopy];
    
    [self.HTTPRequestHeaders enumerateKeysAndObjectsUsingBlock:^(id field, id value, BOOL * __unused stop) {
        if (![request valueForHTTPHeaderField:field]) {
            [mutableRequest setValue:value forHTTPHeaderField:field];
        }
    }];
    if (![mutableRequest valueForHTTPHeaderField:@"Content-Type"]) {
        [mutableRequest setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    }
    [mutableRequest setValue: @"application/json" forHTTPHeaderField:@"Accept"];
    
    NSData *jsonData = [NSJSONSerialization dataWithJSONObject:parameters options:kNilOptions error:nil];
    NSString * text = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
    NSData *desData = [CSPayNotificationSecureManager encryptUseDES2:text key:[CSPayNotificationConfig sharedManger].desKey keyBase64:YES];
    ((NSMutableURLRequest *) mutableRequest).HTTPBody = desData;
    return mutableRequest;
}

@end
