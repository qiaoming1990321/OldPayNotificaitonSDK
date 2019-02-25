//
// Created by matt on 2018-12-27.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"


/**
 * 45协议：http://wiki.3g.net.cn/pages/viewpage.action?pageId=18781210
 */
@interface NcsStEntry45 : NcsStEntryData

/**
 * 4:功能点ID -> 每个产品一个
 */
@property (strong, nonatomic) NSString* functionId;

/**
 * 5：统计对象，即utmsource，形即从“utm_source=”开始到结束部分的链接
 */
@property (strong, nonatomic) NSString* statisticsObject;

/**
 * 7：操作结果，0：未成功，1：成功 （默认成功）
 */
@property (strong, nonatomic) NSString* operationResult;

/**
 * 13：AF明细，传appsflyer返回的map原始数据
 */
@property (strong, nonatomic) NSString* afDetails;

/**
 * 14：Referrer，传原始的referrer
 */
@property (strong, nonatomic) NSString* referrer;

/**
 * 18：AF Agency，传agency数据
 */
@property (strong, nonatomic) NSString* afAgency;

/**
 * 21：用户类型标识，参考用户类型对照表，值为-1~9
 */
@property (strong, nonatomic) NSString* userSourceType;

/**
 * 23：推广（即买量）SDK版本号
 */
@property (strong, nonatomic) NSString* buyChannelSdkVersion;

@end