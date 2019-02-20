//
//  Co_pay_PayNotificationSecureManager.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Co_pay_PayNotificationSecureManager : NSObject

//加密
+ (NSData *)encryptUseDES2:(NSString *)plainText key:(NSString *)key keyBase64:(BOOL)keyNeedBase64;

//解密
+ (NSString *)decryptUseDES:(NSData *)cipherData key:(NSString *)key keyNeedBase64:(BOOL)keyNeedBase64;

@end

NS_ASSUME_NONNULL_END
