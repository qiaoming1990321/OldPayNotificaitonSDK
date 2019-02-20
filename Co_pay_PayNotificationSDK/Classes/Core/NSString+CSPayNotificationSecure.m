//
//  NSString+CSPayNotificationSecure.m
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "NSString+CSPayNotificationSecure.h"

@implementation NSString (CSPayNotificationSecure)

+(NSString *)payNotificationSecureHmacSHA256AndSafeUrlBase64EncodeWithKey:(NSString *)key value:(NSString *)value
{
    NSString *hmacBase64Str = [[self class] hmacSHA256WithKey:key value:value];
    
    //因为Base64转码后可能包含有+,/,=这些不安全的URL字符串，所以要进行换字符
    // '+' -> '-'
    // '/' -> '_'
    // '=' -> ''
    NSString * base64Str = hmacBase64Str;
    
    NSMutableString * safeBase64Str = [[NSMutableString alloc] initWithString:base64Str];
    safeBase64Str = (NSMutableString * )[safeBase64Str stringByReplacingOccurrencesOfString:@"+" withString:@"-"];
    safeBase64Str = (NSMutableString * )[safeBase64Str stringByReplacingOccurrencesOfString:@"/" withString:@"_"];
    safeBase64Str = (NSMutableString * )[safeBase64Str stringByReplacingOccurrencesOfString:@"=" withString:@""];
    return safeBase64Str;
}

+(NSString *)hmacSHA256WithKey:(NSString *)k value:(NSString *)value
{
    NSString *key = k;
    NSString *data = value;
    
    const char *cKey = [key cStringUsingEncoding:NSUTF8StringEncoding];
    const char *cData = [data cStringUsingEncoding:NSUTF8StringEncoding];
    unsigned char cHMAC[CC_SHA256_DIGEST_LENGTH];
    
    CCHmac(kCCHmacAlgSHA256, cKey, strlen(cKey), cData, strlen(cData), cHMAC);
    NSData *hash = [[NSData alloc] initWithBytes:cHMAC length:sizeof(cHMAC)];
    
    NSString *sign = [self base64forData:hash];
    
    return sign;
}

+(NSString *)base64forData:(NSData *)theData
{
    const uint8_t *input = (const uint8_t *)[theData bytes];
    NSInteger length = [theData length];
    
    static char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    
    NSMutableData *data = [NSMutableData dataWithLength:((length + 2) / 3) * 4];
    uint8_t *output = (uint8_t *)data.mutableBytes;
    
    NSInteger i;
    for (i = 0; i < length; i += 3) {
        NSInteger value = 0;
        NSInteger j;
        for (j = i; j < (i + 3); j++) {
            value <<= 8;
            
            if (j < length) {
                value |= (0xFF & input[j]);
            }
        }
        NSInteger theIndex = (i / 3) * 4;  output[theIndex + 0] = table[(value >> 18) & 0x3F];
        output[theIndex + 1] = table[(value >> 12) & 0x3F];
        output[theIndex + 2] = (i + 1) < length ? table[(value >> 6) & 0x3F] : '=';
        output[theIndex + 3] = (i + 2) < length ? table[(value >> 0) & 0x3F] : '=';
    }
    
    return [[NSString alloc] initWithData:data encoding:NSASCIIStringEncoding];
}

- (NSString *)payNotificationSecureBase64EncodedString:(NSString *)string
{
    NSData *data = [string dataUsingEncoding:NSUTF8StringEncoding];
    return [data base64EncodedStringWithOptions:0];
}

@end
