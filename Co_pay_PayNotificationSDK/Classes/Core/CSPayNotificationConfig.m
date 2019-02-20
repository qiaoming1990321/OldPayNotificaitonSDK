//
//  CSPayNotificationConfig.m
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/22.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "CSPayNotificationConfig.h"
#import "CSPayNotificationFailManager.h"
#import <SAMKeychain/SAMKeychain.h>
#import <CSStatistics/CSStatisticsDeviceInfo.h>

@interface CSPayNotificationConfig()

@property(nonatomic, copy) NSString *appId;

@end

@implementation CSPayNotificationConfig


+ (instancetype)sharedManger {
    static CSPayNotificationConfig *payNotificationConfig;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        payNotificationConfig = [[CSPayNotificationConfig alloc] init];
    });
    return payNotificationConfig;
}

- (void)initPayNotificationConfigWith:(BOOL)isDebug withClientID:(NSString *)clientID withSignatureKey:(NSString *)signatureKey withDesKey:(NSString *)desKey appid:(NSString *)appId{
    self.isTest = isDebug;
    self.xSignatureKey = signatureKey;
    self.clientID = clientID;
    self.desKey = desKey;
    self.desBytesCapacity  = 1024 * 128;
    self.requestTimeout = 60.0;
    self.appId = appId;
    [self setStaticUUID:[CSStatisticsDeviceInfo UDIDString]];
    if (isDebug) {
        self.payStateDomain = @"https://ipaylite-stage.ourstrade.com";
    } else {
        self.payStateDomain = @"https://ipaylite.ourstrade.com";
    }
    [CSPayNotificationFailManager retryUploadPaynotificationRecordFormLocal];
}

- (NSString *)getPayStateDomain {
    return self.payStateDomain;
}

- (NSString *)getSignatureKey {
    return self.xSignatureKey;
}

- (NSString *)getClientID {
    return self.clientID;
}

-(void)setStaticUUID:(NSString *)uuid {
    _staticUUID = uuid;
}

-(NSString *)getStaticUUID {
    if (self.staticUUID == nil) {
        NSString *service = self.appId;
        NSString *account = [NSString stringWithFormat:@"%@_XD_DEVICE_TOKEN", service];
        __block NSString *udid = [SAMKeychain passwordForService:service
                                                         account:account];
        static dispatch_once_t onceToken;
        if (udid.length == 0) {
            dispatch_once(&onceToken, ^{
                udid = [NSUUID UUID].UUIDString;
                [SAMKeychain setPassword:udid forService:service account:account];
            });
            udid = [SAMKeychain passwordForService:service
                                           account:account];
        }
        [self setStaticUUID:udid];
        return udid;
    }
    return self.staticUUID;
}

@end



