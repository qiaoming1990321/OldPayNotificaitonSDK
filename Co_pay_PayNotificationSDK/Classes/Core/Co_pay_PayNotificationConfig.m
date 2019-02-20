//
//  Co_pay_PayNotificationConfig.m
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/22.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "Co_pay_PayNotificationConfig.h"
#import "Co_pay_PayNotificationFailManager.h"
#import <SAMKeychain/SAMKeychain.h>
#import <Co_pay_Statistics/CSStatisticsDeviceInfo.h>

@interface Co_pay_PayNotificationConfig()

@property(nonatomic, copy) NSString *appId;

@end

@implementation Co_pay_PayNotificationConfig


+ (instancetype)sharedManger {
static Co_pay_PayNotificationConfig *payNotificationConfig;
static dispatch_once_t onceToken;
dispatch_once(&onceToken, ^{
payNotificationConfig = [[Co_pay_PayNotificationConfig alloc] init];
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
[self setStaticUUID:[Co_pay_StatisticsDeviceInfo UDIDString]];
if (isDebug) {
self.payStateDomain = @"https://ipaylite-stage.ourstrade.com";
} else {
self.payStateDomain = @"https://ipaylite.ourstrade.com";
}
[Co_pay_PayNotificationFailManager retryUploadPaynotificationRecordFormLocal];
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



