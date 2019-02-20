//
//  Co_pay_PayNotificationConfig.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/22.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, PayNotificationMethod) {
PayNotificationHttpMethodGET = 0,
PayNotificationMethodPOST,
};
NS_ASSUME_NONNULL_BEGIN

@interface Co_pay_PayNotificationConfig : NSObject

@property (nonatomic,copy) NSString *accessToken;
@property (nonatomic,copy) NSString *accountId;
@property(nonatomic, assign) BOOL isTest;
@property(nonatomic, copy) NSString *staticUUID;
@property(nonatomic, copy) NSString *clientID;
@property(nonatomic, copy) NSString *xSignatureKey;
@property(nonatomic, copy) NSString *payStateDomain;
@property(nonatomic, copy) NSString *desKey;

@property(nonatomic, assign)NSInteger desBytesCapacity;
@property(nonatomic, assign)NSInteger requestTimeout;
- (void)initPayNotificationConfigWith:(BOOL)isDebug withClientID:(NSString *)clientID withSignatureKey:(NSString *)signatureKey withDesKey:(NSString *)desKey appid:(NSString *)appId;

- (NSString *)getPayStateDomain;

- (NSString *)getSignatureKey;

- (NSString *)getClientID;
- (NSString *)getStaticUUID;

- (void)setStaticUUID:(NSString *)uuid;

+ (instancetype)sharedManger;

@end

NS_ASSUME_NONNULL_END
