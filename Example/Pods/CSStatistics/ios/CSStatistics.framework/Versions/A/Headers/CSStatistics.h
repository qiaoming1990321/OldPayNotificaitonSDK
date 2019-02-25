//
// Created by matt on 2018-12-29.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, StaitsticsEnvironment) {
    StaitsticsEnvironmentDebug = 0,
    StaitsticsEnvironmentRelease
};

__attribute__((deprecated("use Class NcsStatisticsApi instead")))
@interface CSStatistics : NSObject

/*********************************统计SDK环境配置*****************************************/


/**
 设置统计SDK的编译环境

 StaitsticsEnvironmentDebug: 数据上传测试服

 StaitsticsEnvironmentRelease: 数据上传正式服 (默认)

 @param environment 编译环境类型
 */
+ (void)setEnvironment:(StaitsticsEnvironment)environment
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));

/**
 设置日志输出

 @param enable 是否输出日志
 */
+ (void)setEnableLog:(BOOL)enable
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));


/**
 获取当前环境的服务器地址

 @return 服务器地址
 */
+ (NSString *)currnetUploadURL
__attribute__((deprecated("nouse!")));


/**
 获取当前SDK版本号 (当前版本 0.6.2)
 */
+ (NSString *)sdkVersion
__attribute__((deprecated("use NcsStatisticsApi#sdkVersionName instead")));


/*********************************统计SDK功能配置*****************************************/

/**
 初始化(须传入appId) (必须在配置功能点后调用, 具体请看README.md)

 @param AppId AppId(请在Apple store connect 后台查看)
 */
+ (void)setup:(NSString *)AppId
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));

/**
 配置SDK功能点 (统一配置)

 @param paymentFuncId               支付统计协议功能点
 @param disseminationFuncId         推广统计协议功能点
 @param userRealTimeBehaviorFuncId  用户实时行为统计协议功能点   (统计数据实时上传)
 @param userNormalBehaviorFuncId    用户行为统计协议功能点      (统计数据8小时上传一次)
 @param adFuncId                    广告接入统计协议功能点
 */
+ (void)configurePaymentFuncId:(NSString *)paymentFuncId
           disseminationFuncId:(NSString *)disseminationFuncId
    userRealTimeBehaviorFuncId:(NSString *)userRealTimeBehaviorFuncId
      userNormalBehaviorFuncId:(NSString *)userNormalBehaviorFuncId
                      adFuncId:(NSString *)adFuncId
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));


/**
 配置支付统计协议功能点 (59协议) (可单独配置)
 */
+ (void)configurePaymentFuncId:(NSString *)paymentFuncId
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));


/**
 配置推广统计协议功能点 (45协议) (可单独配置)

 */
+ (void)configureDisseminationFuncId:(NSString *)disseminationFuncId
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));


/**
 配置用户实时行为统计协议功能点 (104协议, 统计数据实时上传) (可单独配置)

 */
+ (void)configureUserRealTimeBehaviorFuncId:(NSString *)userRealTimeBehaviorFuncId
__attribute__((deprecated("nouse!")));


/**
 配置用户行为统计协议功能点 (101协议, 统计数据8小时上传一次) (可单独配置)
 */
+ (void)configureUserNormalBehaviorFuncId:(NSString *)userNormalBehaviorFuncId
__attribute__((deprecated("nouse!")));


/**
 配置广告接入统计协议功能点 (105协议) (可单独配置)

 */
+ (void)configureAdFuncId:(NSString *)adFuncId
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));

/**
 配置SDK渠道 (可单独配置)
 */
+ (void)configureChannel:(NSString *)channel
__attribute__((deprecated("use NcsStatisticsApi#setup instead")));

/*********************************埋点统计方法******************************************/

/**
 上传用于信息 (19协议)
 */
+ (void)uploadUserInfoStatisticsIfNeeded
__attribute__((deprecated("use NcsStatisticsApi#applicationDidBecomeActive instead")));

/**
 ios操作行为统计（默认8小时一次）
 */
+ (void)uploadUserOpretionBehavioursStaisticsIfNeeded
__attribute__((deprecated("nouse")));

/**
 上传所有信息(包括用户信息 和 ios操作行为统计  默认与上一次间隔8小时 才会上传)
 */
+ (void)uploadAllStatisticIfNeeded
__attribute__((deprecated("use NcsStatisticsApi#applicationDidBecomeActive instead")));

/**
 上传失败记录
 */
+(void)retryUploadStaitisticsRecordFormLocal;
__attribute__((deprecated("use NcsStatisticsApi#applicationDidBecomeActive instead")));

/**
 上传合作方推广统计 (45协议)

 @param utmSource 统计对象
 @param success 操作结果
 @param afDetail AF明细
 @param reffer Referrer
 @param afAgency AF Agency
 @param userSource 用户类型标识
 @param appsflyVersion 推广SDK版本
 */
+ (void)postUserDissemniationStatisticWithUtmSource:(NSString *)utmSource
                                            success:(NSString *)success
                                           afDetail:(NSString *)afDetail
                                             reffer:(NSString *)reffer
                                           afAgency:(NSString *)afAgency
                                         userSource:(NSString *)userSource
                                     appsflyVersion:(NSString *)appsflyVersion
__attribute__((deprecated("use NcsStatisticsApi#upload instead")));


/**
 插入一条行为统计记录(缓存到本地数据库)(101协议)

 @param operationCode 操作码
 @param statisticsObject 统计对象
 @param associationObject 关联对象
 @param tab Tab分类
 @param entrance 入口标注
 @param remark 备注
 @param position 位置
 */
+ (void)insertUserStatisticOperationCode:(NSString *)operationCode
                        statisticsObject:(NSString *)statisticsObject
                       associationObject:(NSString *)associationObject
                                     tab:(NSString *)tab
                                entrance:(NSString *)entrance
                                  remark:(NSString *)remark
                                position:(NSString *)position
__attribute__((deprecated("use NcsStatisticsApi#upload instead")));

/**
 上传一条实时统计 (即时上传服务器)(104协议)

 @param operationCode 操作码
 @param statisticsObject 统计对象
 @param associationObject 关联对象
 @param tab Tab分类
 @param entrance 入口
 @param remark 备注
 @param position 位置
 */
+ (void)postUserRealtimeStatisticOperationCode:(NSString *)operationCode
                              statisticsObject:(NSString *)statisticsObject
                             associationObject:(NSString *)associationObject
                                           tab:(NSString *)tab
                                      entrance:(NSString *)entrance
                                        remark:(NSString *)remark
                                      position:(NSString *)position
__attribute__((deprecated("use NcsStatisticsApi#upload instead")));

/**
 上传一条广告实时统计 (即时上传服务器)(105协议)

 @param operationCode 操作码
 @param statisticsObject 统计对象
 @param associationObject 关联对象
 @param tab Tab分类
 @param remark 备注
 @param position 位置
 @param adId 广告Id
 */
+ (void)postAdRealtimeStatisticOperationCode:(NSString *)operationCode
                            statisticsObject:(NSString *)statisticsObject
                           associationObject:(NSString *)associationObject
                                         tab:(NSString *)tab
                                      remark:(NSString *)remark
                                    position:(NSString *)position
                                        adId:(NSString *)adId
                                    entrance:(NSString *)entrance
__attribute__((deprecated("use NcsStatisticsApi#upload instead")));


/**
 支付记录实时上传 (即时上传服务器) (59协议)功能点

 @param operationCode 操作码
 @param statisticsObject 统计对象
 @param associationObject 关联对象
 @param tab Tab分类
 @param position 购买成功时，上传谷歌或第三方订单编号
 @param entrance 入口
 @param remark 部分支付方式，例如fortumo，取不到用户相关的帐号信息，则此字段为空）
 @param orderType 订单来源; 1：普通内购，2：订阅
 @param result 操作结果; 0：点击购买，1：购买成功
 */
+ (void)postUserRealtimePayMentStatisticOperationCode:(NSString *)operationCode
                                     statisticsObject:(NSString *)statisticsObject
                                    associationObject:(NSString *)associationObject
                                                  tab:(NSString *)tab
                                             position:(NSString *)position
                                             entrance:(NSString *)entrance
                                               remark:(NSString *)remark
                                            orderType:(NSInteger)orderType
                                            resultObj:(NSString *)result
__attribute__((deprecated("use NcsStatisticsApi#upload instead")));

/**
 自定义上传(需要自己拼接上传的数据)

 @param customDataString 操作码
 @param postPolicy 上传策略 YES表示实时上传  NO表示不实时上传
 */
+(void)postCustomDataString:(NSString *)customDataString
    isPostPolicyImmediately:(BOOL )postPolicy
__attribute__((deprecated("use NcsStatisticsApi#upload instead")));

@end
