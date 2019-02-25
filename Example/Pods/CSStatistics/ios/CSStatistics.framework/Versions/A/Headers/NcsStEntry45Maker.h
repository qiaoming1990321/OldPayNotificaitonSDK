//
// Created by matt on 2018-12-29.
//

#import <Foundation/Foundation.h>


@class NcsStEntry45Maker;
@class NcsStEntry45;

typedef NcsStEntry45Maker *(^DotNSString45)(NSString *);
typedef NcsStEntry45 *(^DotMake45)();

@interface NcsStEntry45Maker : NSObject

/**
 * 4:功能点ID -> 每个产品一个
 */
@property (strong, nonatomic, readonly) DotNSString45 functionId;

/**
 * 5：统计对象，即utmsource，形即从“utm_source=”开始到结束部分的链接
 */
@property (strong, nonatomic, readonly) DotNSString45 statisticsObject;

/**
 * 7：操作结果，0：未成功，1：成功 （默认成功）
 */
@property (strong, nonatomic, readonly) DotNSString45 operationResult;

/**
 * 13：AF明细，传appsflyer返回的map原始数据
 */
@property (strong, nonatomic, readonly) DotNSString45 afDetails;

/**
 * 14：Referrer，传原始的referrer
 */
@property (strong, nonatomic, readonly) DotNSString45 referrer;

/**
 * 18：AF Agency，传agency数据
 */
@property (strong, nonatomic, readonly) DotNSString45 afAgency;

/**
 * 21：用户类型标识，参考用户类型对照表，值为-1~9
 */
@property (strong, nonatomic, readonly) DotNSString45 userSourceType;

/**
 * 23：推广（即买量）SDK版本号
 */
@property (strong, nonatomic, readonly) DotNSString45 buyChannelSdkVersion;

/**
 * 构建NcsStEntry19对象
 */
@property (strong, nonatomic, readonly) DotMake45 make;


@end