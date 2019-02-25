//
//  Co_pay_PayNotificationDeviceModel.m
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "Co_pay_PayNotificationDeviceModel.h"
#import <AFNetworking/AFNetworking.h>
#import<CoreTelephony/CTCarrier.h>
#import <CoreTelephony/CTTelephonyNetworkInfo.h>
#import <sys/utsname.h>

@implementation Co_pay_PayNotificationDeviceModel

+ (NSDictionary *)deviceWithDid:(NSString *)did
{
return @{
@"did": did,
@"dtype": [[self class] getDeviceType],
@"lang": [[self class] getDeviceLangName],
@"country": [[self class] getDeviceCountryName],
@"net_type": [[self class] getNetType],
@"channel": @"500",
@"phone_model": [[self class] getDeviceModel],
@"app_version_number": @([[[self class] getAppBuildVersion] integerValue]),
@"app_version_name": [[self class] getAppVersion],
@"system_version_name": [[self class] getiOSVersion],
};
}

+ (NSNumber *)getDeviceType
{
//dtype    int    设备类型，1=Android，2=IOS
return @2;
}

+ (NSString *)getDeviceLangName
{
NSLocale *currentLocale = [NSLocale currentLocale];  // get the current locale.
NSString *langCode = [currentLocale objectForKey:NSLocaleLanguageCode];
if (!langCode.length) {
langCode = @"N/A";
}
return langCode;
}

+ (NSString *)getDeviceCountryName
{
NSLocale *currentLocale = [NSLocale currentLocale];  // get the current locale.
NSString *countryCode = [currentLocale objectForKey:NSLocaleCountryCode];
if (!countryCode.length) {
countryCode = @"N/A";
}
return countryCode;
}

+ (NSString *)getNetType
{
NSString *netWorkType = @"unknown";
AFNetworkReachabilityStatus networkStatus =  [[AFNetworkReachabilityManager sharedManager] networkReachabilityStatus];
switch (networkStatus) {
case AFNetworkReachabilityStatusUnknown:{
netWorkType = @"unknown";}
break;
case AFNetworkReachabilityStatusReachableViaWiFi:
netWorkType = @"wifi";
break;
case AFNetworkReachabilityStatusReachableViaWWAN:
{
CTTelephonyNetworkInfo *telephonyInfo = [CTTelephonyNetworkInfo new];
NSString * carrierType = telephonyInfo.currentRadioAccessTechnology;
if ([carrierType isEqualToString:CTRadioAccessTechnologyGPRS]) {
//             @"2G";
netWorkType = @"2G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyEdge]) {
//             @"2G";
netWorkType = @"2G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyWCDMA]) {
//             @"3G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyHSDPA]) {
//             @"3G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyHSUPA]) {
//             @"3G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyCDMA1x]) {
//             @"2G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyCDMAEVDORev0]) {
//             @"3G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyCDMAEVDORevA]) {
//             @"3G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyCDMAEVDORevB]) {
//             @"3G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyeHRPD]) {
//             @"3G";
netWorkType = @"3G";
} else if ([carrierType isEqualToString:CTRadioAccessTechnologyLTE]) {
//             @"4G";
netWorkType = @"4G";
}
}
break;
default:
break;
}

return netWorkType;

//
}

+ (NSString *)getDeviceModel
{
return [self getDeviceName];
}

+(NSString *)getDeviceName{
struct utsname systemInfo;
uname(&systemInfo);
NSString*phoneType = [NSString stringWithCString: systemInfo.machine encoding:NSASCIIStringEncoding];

if([phoneType  isEqualToString:@"iPhone1,1"])  return@"iPhone 2G";

if([phoneType  isEqualToString:@"iPhone1,2"])  return@"iPhone 3G";

if([phoneType  isEqualToString:@"iPhone2,1"])  return@"iPhone 3GS";

if([phoneType  isEqualToString:@"iPhone3,1"])  return@"iPhone 4";

if([phoneType  isEqualToString:@"iPhone3,2"])  return@"iPhone 4";

if([phoneType  isEqualToString:@"iPhone3,3"])  return@"iPhone 4";

if([phoneType  isEqualToString:@"iPhone4,1"])  return@"iPhone 4S";

if([phoneType  isEqualToString:@"iPhone5,1"])  return@"iPhone 5";

if([phoneType  isEqualToString:@"iPhone5,2"])  return@"iPhone 5";

if([phoneType  isEqualToString:@"iPhone5,3"])  return@"iPhone 5c";

if([phoneType  isEqualToString:@"iPhone5,4"])  return@"iPhone 5c";

if([phoneType  isEqualToString:@"iPhone6,1"])  return@"iPhone 5s";

if([phoneType  isEqualToString:@"iPhone6,2"])  return@"iPhone 5s";

if([phoneType  isEqualToString:@"iPhone7,1"])  return@"iPhone 6 Plus";

if([phoneType  isEqualToString:@"iPhone7,2"])  return@"iPhone 6";

if([phoneType  isEqualToString:@"iPhone8,1"])  return@"iPhone 6s";

if([phoneType  isEqualToString:@"iPhone8,2"])  return@"iPhone 6s Plus";

if([phoneType  isEqualToString:@"iPhone8,4"])  return@"iPhone SE";

if([phoneType  isEqualToString:@"iPhone9,1"] || [phoneType  isEqualToString:@"iPhone9,3"])  return@"iPhone 7";

if([phoneType  isEqualToString:@"iPhone9,2"] || [phoneType  isEqualToString:@"iPhone9,4"])  return@"iPhone 7 Plus";

if([phoneType  isEqualToString:@"iPhone10,1"]) return@"iPhone 8";

if([phoneType  isEqualToString:@"iPhone10,4"]) return@"iPhone 8";

if([phoneType  isEqualToString:@"iPhone10,2"]) return@"iPhone 8 Plus";

if([phoneType  isEqualToString:@"iPhone10,5"]) return@"iPhone 8 Plus";

if([phoneType  isEqualToString:@"iPhone10,3"]) return@"iPhone X";

if([phoneType  isEqualToString:@"iPhone10,6"]) return@"iPhone X";

if([phoneType  isEqualToString:@"iPhone11,8"]) return@"iPhone XR";

if([phoneType  isEqualToString:@"iPhone11,2"]) return@"iPhone XS";

if([phoneType  isEqualToString:@"iPhone11,4"]) return@"iPhone XS Max";

if([phoneType  isEqualToString:@"iPhone11,6"]) return@"iPhone XS Max";

//
if([phoneType  isEqualToString:@"iPad3,1"] || [phoneType  isEqualToString:@"iPad3,2"] || [phoneType  isEqualToString:@"iPad3,3"]) return@"iPad (3th generation)";
if([phoneType  isEqualToString:@"iPad4,1"] || [phoneType  isEqualToString:@"iPad4,2"] || [phoneType  isEqualToString:@"iPad4,3"]) return@"iPad Air";
if([phoneType  isEqualToString:@"iPhone5,3"] || [phoneType  isEqualToString:@"iPhone5,4"]) return@"iPad Air 2";
if([phoneType  isEqualToString:@"iPad2,5"] || [phoneType  isEqualToString:@"iPad2,6"] || [phoneType  isEqualToString:@"iPad2,7"]) return@"iPad Mini";
if([phoneType  isEqualToString:@"iPad4,4"] || [phoneType  isEqualToString:@"iPad4,5"] || [phoneType  isEqualToString:@"iPad4,6"]) return@"iPad Mini 2";
if([phoneType  isEqualToString:@"iPad4,4"] || [phoneType  isEqualToString:@"iPad4,2"] || [phoneType  isEqualToString:@"iPad4,3"]) return@"iPad Air";
if([phoneType  isEqualToString:@"iPad4,7"] || [phoneType  isEqualToString:@"iPad4,8"] || [phoneType  isEqualToString:@"iPad4,9"]) return@"iPad Mini 3";
if([phoneType  isEqualToString:@"iPad5,1"] || [phoneType  isEqualToString:@"iPad5,2"]) return@"iPad Mini 4";

if([phoneType  isEqualToString:@"iPad6,3"] || [phoneType  isEqualToString:@"iPad6,4"]) return@"iPad Pro 9.7 Inch";
if([phoneType  isEqualToString:@"iPad6,7"] || [phoneType  isEqualToString:@"iPad6,8"]) return@"iPad Pro 12.9 Inch";
if([phoneType  isEqualToString:@"iPad6,11"] || [phoneType  isEqualToString:@"iPad6,12"]) return@"iPad (5th generation)";
if([phoneType  isEqualToString:@"iPad7,1"] || [phoneType  isEqualToString:@"iPad7,2"]) return@"iPad Pro 12.9 Inch (2th generation)";
if([phoneType  isEqualToString:@"iPad7,3"] || [phoneType  isEqualToString:@"iPad7,4"]) return@"iPad Pro 10.5 Inch";
if([phoneType  isEqualToString:@"iPad7,5"] || [phoneType  isEqualToString:@"iPad7,6"]) return@"iPad Pro 10.5 Inch";
if([phoneType  isEqualToString:@"iPad8,1"] || [phoneType  isEqualToString:@"iPad8,2"] || [phoneType  isEqualToString:@"iPad8,3"] || [phoneType  isEqualToString:@"iPad8,4"]) return@"iPad Pro 11 Inch";
if([phoneType  isEqualToString:@"iPad8,5"] || [phoneType  isEqualToString:@"iPad8,6"] || [phoneType  isEqualToString:@"iPad8,7"] || [phoneType  isEqualToString:@"iPad8,8"]) return@"iPad Pro 12.9 Inch (3r generation)";
return phoneType;

}

+ (NSString *)getAppBuildVersion
{
NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
NSString *buildVersion = [infoDictionary objectForKey:@"CFBundleVersion"];
return buildVersion;
}

+ (NSString *)getAppVersion
{
NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
NSString *majorVersion = [infoDictionary objectForKey:@"CFBundleShortVersionString"];

if (!majorVersion.length) {
majorVersion = @"N/A";
}
return majorVersion;
}

+ (NSString *)getiOSVersion
{
NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
if (!currSysVer.length) {
currSysVer = @"N/A";
}
return currSysVer;
}

@end
