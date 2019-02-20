//
//  Co_pay_PayNotificationSecureManager.m
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "Co_pay_PayNotificationSecureManager.h"
#import <CommonCrypto/CommonCrypto.h>
#import "Co_pay_PayNotificationConfig.h"

#define _kDesBytesCount 1024 * 80
@implementation Co_pay_PayNotificationSecureManager

//加密
+ (NSData *)encryptUseDES2:(NSString *)plainText key:(NSString *)key keyBase64:(BOOL)keyNeedBase64 {
//    plainText = @"{"receipt":"123","product_id":"hexa.puzzle.game.block899_1","device":{"app_version_number":1,"channel":"500","did":"E87A94E9-E3E1-4665-B776-4EFDC1DB8039","lang":"en","country":"CN","dtype":2,"phone_model":"iPhone10,1","system_version_name":"12.1","net_type":"unknown","app_version_name":"1.0"}}";
NSData *data = [plainText dataUsingEncoding:NSUTF8StringEncoding allowLossyConversion:YES];

unsigned char buffer[_kDesBytesCount];
memset(buffer, 0, sizeof(char));
size_t numBytesEncrypted = 0;

NSInteger keyL = key.length;
if (keyL % 4) {
NSInteger keyShouldBeL = (keyL / 4 + 1) * 4;
key = [key stringByPaddingToLength:keyShouldBeL withString:@"0" startingAtIndex:0];
}

NSData *keyData = nil;
if (keyNeedBase64) {
keyData = [[NSData alloc] initWithBase64EncodedString:key options:0];
} else {
keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
}
Byte *iv = (Byte *) [keyData bytes];
CCCryptorStatus cryptStatus = CCCrypt(kCCEncrypt,
kCCAlgorithmDES,
kCCOptionPKCo_pay_7Padding | kCCOptionECBMode,
iv,
kCCKeySizeDES,
nil,
[data bytes],
[data length],
buffer,
(size_t) _kDesBytesCount,
&numBytesEncrypted);

NSData *plainData = nil;
if (cryptStatus == kCCo_pay_uccess) {
plainData = [NSData dataWithBytes:buffer length:(NSUInteger) numBytesEncrypted];
} else {
NSLog(@"DES加密失败");
}
return plainData;

}

//解密
+ (NSString *)decryptUseDES:(NSData *)cipherData key:(NSString *)key keyNeedBase64:(BOOL)keyNeedBase64 {
unsigned char buffer[_kDesBytesCount];
memset(buffer, 0, sizeof(char));
size_t numBytesDecrypted = 0;

NSInteger keyL =  key.length;
if(keyL % 4) {
NSInteger keyShouldBeL = (keyL / 4 + 1 ) * 4;
key = [key stringByPaddingToLength:keyShouldBeL withString:@"0" startingAtIndex:0];
}

NSData *keyData = nil;
if (keyNeedBase64) {
keyData = [[NSData alloc] initWithBase64EncodedString:key options:0];
} else {
keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
}
Byte *iv = (Byte *)[keyData bytes];
CCCryptorStatus cryptStatus = CCCrypt(kCCDecrypt,
kCCAlgorithmDES,
kCCOptionECBMode,
iv,
kCCKeySizeDES,
NULL,
[cipherData bytes],
cipherData.length,
buffer,
(size_t) _kDesBytesCount,
&numBytesDecrypted);
NSString* plainText = nil;
if (cryptStatus == kCCo_pay_uccess) {
NSData* data = [NSData dataWithBytes:buffer length:(NSUInteger)numBytesDecrypted];
plainText = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
}
return plainText;
}

@end
