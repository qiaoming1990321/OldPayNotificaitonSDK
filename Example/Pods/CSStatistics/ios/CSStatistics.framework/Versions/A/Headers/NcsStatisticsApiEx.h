//
// Created by matt on 2019-01-14.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"

@class NcsStEntryData;
@class NcsStEntry45;
@class NcsStEntry59;
@class NcsStEntry101;
@class NcsStEntry102;
@class NcsStEntry103;
@class NcsStEntry104;
@class NcsStEntry105;

/**
 * 扩展api，都是调用NcsStatisticsApi接口实现的
 */
@interface NcsStatisticsApiEx : NSObject

/**
 * 上传统计，可以设置上传结果回调。
 * @param entry
 * @param callback 上传结果回调，可能会存在多次失败的callback（恢复重传机制引起）。应用重启后，重传的统计没有callback。
 */
+ (void)upload:(NcsStEntryData *)entry callback:(NcsStUploadCallback) callback;

+ (void)upload45:(NcsStEntry45 *)entry;

+ (void)upload59:(NcsStEntry59 *)entry;

+ (void)upload101:(NcsStEntry101 *)entry;

+ (void)upload102:(NcsStEntry102 *)entry;

+ (void)upload103:(NcsStEntry103 *)entry;

+ (void)upload104:(NcsStEntry104 *)entry;

+ (void)upload105:(NcsStEntry105 *)entry;

/**
 * 上传45协议
 * @param funId 4：功能点ID -> 每个产品一个
 * @param statisticsObject 5：统计对象，即utmsource，形即从“utm_source=”开始到结束部分的链接
 * @param operationResult 7：操作结果，0：未成功，1：成功 （默认成功）
 * @param afDetails 13：AF明细，传appsflyer返回的map原始数据
 * @param referrer 14：Referrer，传原始的referrer
 * @param afAgency 18：AF Agency，传agency数据
 * @param userSourceType 21：用户类型标识，参考用户类型对照表，值为-1~9
 * @param buyChannelSdkVersion 23：推广（即买量）SDK版本号
 */
+ (void)    upload45:(NSString *)funId
    statisticsObject:(NSString *)statisticsObject
     operationResult:(NSString *)operationResult
           afDetails:(NSString *)afDetails
            referrer:(NSString *)referrer
            afAgency:(NSString *)afAgency
      userSourceType:(NSString *)userSourceType
buyChannelSdkVersion:(NSString *)buyChannelSdkVersion;

/**
 *
 * @param funId 4:功能点ID
 * @param statisticsObject 5:统计对象
 * @param operationCode 6:操作代码
 * @param operationResult 7:操作结果 --> 0：点击购买，1：购买成功
 * @param entrance 12:入口
 * @param tabCategory 13:Tab分类
 * @param position 14:位置 --> 购买成功时，上传订单编号
 * @param associationObject 17:关联对象
 * @param remark 18:备注
 * @param orderType 19:订单类型 --> 1：普通内购，2：订阅，3：订阅SDK-订阅，4：订阅sdk-一次性购买
 */
+ (void) upload59:(NSString *)funId
 statisticsObject:(NSString *)statisticsObject
    operationCode:(NSString *)operationCode
  operationResult:(NSString *)operationResult
         entrance:(NSString *)entrance
      tabCategory:(NSString *)tabCategory
         position:(NSString *)position
associationObject:(NSString *)associationObject
           remark:(NSString *)remark
        orderType:(NSString *)orderType;

/**
 * 上传101协议
 * @param functionId
 * @param statisticsObject
 * @param operationCode
 * @param operationResult
 * @param entrance
 * @param tabCategory
 * @param position
 * @param associationObject
 * @param advertId
 * @param remark
 */
+ (void)upload101:(NSString *)functionId
 statisticsObject:(NSString *)statisticsObject
    operationCode:(NSString *)operationCode
  operationResult:(NSString *)operationResult
         entrance:(NSString *)entrance
      tabCategory:(NSString *)tabCategory
         position:(NSString *)position
associationObject:(NSString *)associationObject
           remark:(NSString *)remark;

/**
 * 上传102协议
 * @param functionId 15:功能点ID
 * @param settingInfo 16:设置信息，格式："设置项;设置值#设置项;设置值"#...
 * @param type 17:类型, 详见设置信息表, 设置值可控时，用1：***；2：***；3：***（用冒号和中文分好分开）
 * @param position 18:位置
 * @param remark 19:备注
 */
+ (void)upload102:(NSString *)functionId
      settingInfo:(NSString *)settingInfo
             type:(NSString *)type
         position:(NSString *)position
           remark:(NSString *)remark;

/**
 * 上传103协议
 * @param functionId
 * @param statisticsObject
 * @param operationCode
 * @param operationResult
 * @param entrance
 * @param tabCategory
 * @param position
 * @param associationObject
 * @param advertId
 * @param remark
 */
+ (void)upload103:(NSString *)functionId
 statisticsObject:(NSString *)statisticsObject
    operationCode:(NSString *)operationCode
  operationResult:(NSString *)operationResult
         entrance:(NSString *)entrance
      tabCategory:(NSString *)tabCategory
         position:(NSString *)position
associationObject:(NSString *)associationObject
         advertId:(NSString *)advertId
           remark:(NSString *)remark;

/**
 * 上传104协议
 * @param functionId
 * @param statisticsObject
 * @param operationCode
 * @param operationResult
 * @param entrance
 * @param tabCategory
 * @param position
 * @param associationObject
 * @param advertId
 * @param remark
 */
+ (void)upload104:(NSString *)functionId
 statisticsObject:(NSString *)statisticsObject
    operationCode:(NSString *)operationCode
  operationResult:(NSString *)operationResult
         entrance:(NSString *)entrance
      tabCategory:(NSString *)tabCategory
         position:(NSString *)position
associationObject:(NSString *)associationObject
         advertId:(NSString *)advertId
           remark:(NSString *)remark;

/**
 * 上传105协议
 * @param functionId
 * @param statisticsObject
 * @param operationCode
 * @param operationResult
 * @param entrance
 * @param tabCategory
 * @param position
 * @param associationObject
 * @param advertId
 * @param remark
 */
+ (void)upload105:(NSString *)functionId
 statisticsObject:(NSString *)statisticsObject
    operationCode:(NSString *)operationCode
  operationResult:(NSString *)operationResult
         entrance:(NSString *)entrance
      tabCategory:(NSString *)tabCategory
         position:(NSString *)position
associationObject:(NSString *)associationObject
         advertId:(NSString *)advertId
           remark:(NSString *)remark;

@end