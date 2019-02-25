//
//  CSDeviceInfo.h
//  GLive
//
//  Created by Gordon Su on 17/4/10.
//  Copyright © 2017年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NcsStDeviceInfo : NSObject

+ (NSDictionary *)device;

+ (NSDictionary *)deviceForNetworkMonitor;

/**
 本机UDID (实际上为UUID, 存储在keychain来替代UDID)
 */
+ (NSString *)UDIDString;

/**
 Apple广告 id
 */
+ (NSString *)advertiseIDString;

/**
 当前国家码 (根据运营商获取)
 */
+ (NSString *)getCurrentMoblileCountryCode;

/**
 当前地区名称
 */
+ (NSString *)getDeviceCountryName;

/**
 当前本地语言
 */
+ (NSString *)getDeviceLangName;

/**
 应用版本号
 */
+ (NSString *)getAppVersion;

/**
 应用build 版本号
 */
+ (NSString *)getAppBuildVersion;

/**
 本机系统版本
 */
+ (NSString *)getiOSVersion;

/**
 本地CPU类型
 */
+ (NSString *)getCPUType;


/**
 App ID
 */
+ (NSString *)getAppID;


/**
 Bundle ID
 */
+ (NSString *)getBundleId;


/**
 获取当前IP
 */
+ (NSString *)getIPAddress;

/**
 获取当前DNS
 */
+ (NSArray *)getDNSAddresses;

/**
 根据域名获取IP地址
 */
+ (NSString*)getIPAddressByHostName:(NSString*)strHostName;

/**
 CSID
 */
+ (NSString *)getCSID;

/**
 新用户ID (协议需求)
 */
+ (NSString *)getCustomerNewId;


/**
 设备类型 (iPhone / iPad)
 */
+ (BOOL)isIpad;

//*日志打印时间
//客户端日志的打印时间；格式如：2013-02-26 12:00:02；默认转成中国时区
//+ (NSString *)getTimeStamp;

//获取具体的机型 型号
+ (NSString *)getDeviceModel;

//获取具体的机型 型号
+ (NSString *)getDeviceModel;

@end
