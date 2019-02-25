//
//  NcsStatisticsApi.h
//  CSStatistics
//
//  Created by matt on 2018/12/7.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"

@class NcsStInitParams;
@class NcsStInitParamsMaker;
@class NcsStEntryDataMaker;
@class NcsStEntry103Maker;
@class NcsStEntry19Maker;
@class NcsStEntry45Maker;
@class NcsStEntry59Maker;
@class NcsStEntry101Maker;
@class NcsStEntry102Maker;
@class NcsStEntry104Maker;
@class NcsStEntry105Maker;

NS_ASSUME_NONNULL_BEGIN

@interface NcsStatisticsApi : NSObject

/*********************************SDK初始化及配置*****************************************/

/**
 * 启动sdk, 在UIApplicationDelegate#didFinishLaunchingWithOptions里调用。
 * 可重复调用，新配置会覆盖旧配置。没配置的参数，会使用默认配置，而不是上一次的配置。
 * 推荐debug包，默认打开log配置，方便排查问题。
 * @param params 初始化参数，appId必填，其它选填。
 */
+ (void)setup:(NcsStInitParams *)params;

/**
 * 启动sdk, 在UIApplicationDelegate#didFinishLaunchingWithOptions里调用。
 * 可重复调用，新配置会覆盖旧配置。没配置的参数，会使用默认配置，而不是上一次的配置。
 * 推荐debug包，默认打开log配置，方便排查问题。
 * @param block 初始化参数，appId必填，其它选填。
 */
+ (void)setupByBlock:(void(^)(NcsStInitParamsMaker *maker)) block;

/**
 * 获取当前sdk的配置参数。
 * 如果sdk setup后，想只改变某个配置如log开关，可以先获取当前配置，修改后再setup。
 * @return
 */
+ (NcsStInitParams *)getCurrentParams;

/**
 * 程序热启动，回调这个接口。主要是上传19和失败重传。
 */
+ (void)applicationDidBecomeActive;

/*********************************SDK提供的信息*****************************************/

/**
 获取当前SDK版本名称
 */
+ (NSString *)sdkVersionName;

/*********************************统计上传*****************************************/

/**
 * 上传统计，内置支持19、45、59、101～105、自定义协议等。
 * 内置协议使用形如NcsStEntry45、NcsStEntry45Maker，自定义协议使用NcsStEntryData
 * @param entry
 */
+ (void)upload:(NcsStEntryData *)entry;

/**
 * 上传自定义统计的简单接口
 * @param data
 */
+ (void)uploadSimply:(NSString *)data ;

/**
 * 上传自定义统计
 * @param block
 */
+ (void)uploadCustom:(void(^)(NcsStEntryDataMaker *maker)) block;

/**
 * 上传19协议，默认情况下sdk已自动上传，无需客户端调用此接口
 * @param block
 */
+ (void)upload19:(void(^)(NcsStEntry19Maker *maker)) block;

/**
 * 上传45协议
 * @param block
 */
+ (void)upload45:(void(^)(NcsStEntry45Maker *maker)) block;

/**
 * 上传59协议
 * @param block
 */
+ (void)upload59:(void(^)(NcsStEntry59Maker *maker)) block;

/**
 * 上传101协议
 * @param block
 */
+ (void)upload101:(void(^)(NcsStEntry101Maker *maker)) block;

/**
 * 上传102协议
 * @param block
 */
+ (void)upload102:(void(^)(NcsStEntry102Maker *maker)) block;

/**
 * 上传103协议
 * @param block
 */
+ (void)upload103:(void(^)(NcsStEntry103Maker *maker)) block;

/**
 * 上传104协议
 * @param block
 */
+ (void)upload104:(void(^)(NcsStEntry104Maker *maker)) block;

/**
 * 上传105协议
 * @param block
 */
+ (void)upload105:(void(^)(NcsStEntry105Maker *maker)) block;


@end

NS_ASSUME_NONNULL_END
