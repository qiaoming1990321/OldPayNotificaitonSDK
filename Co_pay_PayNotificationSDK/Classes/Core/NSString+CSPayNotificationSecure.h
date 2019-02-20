//
//  NSString+CSPayNotificationSecure.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCrypto.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (CSPayNotificationSecure)
+(NSString *)payNotificationSecureHmacSHA256AndSafeUrlBase64EncodeWithKey:(NSString *)key value:(NSString *)value;
+(NSString *)payNotificationSecureBase64EncodedString:(NSString *)string;

@end

NS_ASSUME_NONNULL_END
