//
// Created by matt on 2018-12-28.
//

#import <Foundation/Foundation.h>

/**
 * 统计里通用字段值获取
 */
@interface NcsStEntryFieldUtil : NSObject

/**
 * 获取用户唯一标识
 * @return
 */
+ (NSString *)getUserUUID;

/**
 * 获取用户在CS系列产品中的唯一id
 * @return
 */
+ (NSString *)getCSID;

/**
 * 用户新id：优先IDFA，拿不到则用CSID
 * @return
 */
+ (NSString *)getUserNewID;

/**
 * IMEI，在iOS里同用户新id
 * @return
 */
+ (NSString *)getIMIE;

/**
 * 获取广告id，优先使用IDFA, 获取不到则使用UUID生成
 * @return
 */
+ (NSString *)getAdvertisingId;

/**
 * 获取当前的时间，转换为北京时区。格式如：2013-02-26 12:00:02
 * @return
 */
+ (NSString *)getTimeStampBeijing;

/**
 * 获取国家代码。 优先获取SIM卡，其次是系统语言里面的国家代码
 * @return
 */
+ (NSString *)getCountryCode;

/**
 * 获取产品发布渠道。默认：500
 * @return
 */
+ (NSString *)getChannelId;

/**
 * 获取App版本号
 * @return
 */
+ (NSString *)getVersionCode;

/***
 * 获取App版本名称
 * @return
 */
+ (NSString *)getVersionName;

/**
 * 获取用户手机操作系统的版本信息，如ios7.0
 * @return
 */
+ (NSString *)getOSVersion;

/**
 * 获取用户手机型号，如GT-I9000
 * @return
 */
+ (NSString *) getDeviceModel;

/**
 * 获取设备类型：1：手机；2：平板
 * @return
 */
+ (NSString *) getDeviceType;

//14
//手机运营商
//用户手机运营商
+ (NSString *) getPhoneOperatorVender;

/**
 * 是否app新用户。 用户首次安装或者卸载后重新安装上传1,否则上传0.（获取不到则留空）
 * @return 0-否, 1-是
 */
+ (NSString *)getIsAppNewUser;

/**
 * 获取CPU架构类型，如：armv7
 * @return
 */
+ (NSString *) getCPUModel;

/**
 * 获取手机屏幕分辨率，如：1280*720
 * @return
 */
+ (NSString *) getScreenResolution;

/**
 * 获取app包名（即BundleId)
 * @return
 */
+ (NSString *)getBundleId;

/**
 * 获取当前手机语言
 * @return
 */
+ (NSString *)getLaunguage;

/**
 * 获取ROM容量(MB)，格式(英文逗号分隔)：总量,当前可用
 * @return
 */
+ (NSString *)getROMofMB;

/**
 * 获取SIM所属国家代码（如：us），获取不到的传0
 * @return
 */
+ (NSString *)getSIMCountry;

/**
 * 获取app启动次数
 * @return
 */
+ (NSString *)getAppStartNum;


@end