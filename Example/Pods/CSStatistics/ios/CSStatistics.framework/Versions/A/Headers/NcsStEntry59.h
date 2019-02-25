//
// Created by matt on 2018-12-27.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"

/**
 * 59协议：http://wiki.3g.net.cn/pages/viewpage.action?pageId=6914386
 */
@interface NcsStEntry59 : NcsStEntryData

/**
 * 4:功能点ID
 */
@property (strong, nonatomic) NSString* functionId;

/**
 * 5:统计对象
 */
@property (strong, nonatomic) NSString* statisticsObject;

/**
 * 6:操作代码
 */
@property (strong, nonatomic) NSString* operationCode;

/**
 * 7:操作结果 --> 0：点击购买，1：购买成功
 */
@property (strong, nonatomic) NSString* operationResult;

/**
 * 12:入口
 */
@property (strong, nonatomic) NSString* entrance;

/**
 * 13:Tab分类
 */
@property (strong, nonatomic) NSString* tabCategory;

/**
 * 14:位置 --> 购买成功时，上传订单编号
 */
@property (strong, nonatomic) NSString* position;

/**
 * 17:关联对象
 */
@property (strong, nonatomic) NSString* associationObject;

/**
 * 18:备注
 */
@property (strong, nonatomic) NSString* remark;

/**
 * 19:订单类型 --> 1：普通内购，2：订阅，3：订阅SDK-订阅，4：订阅sdk-一次性购买
 */
@property (strong, nonatomic) NSString* orderType;



@end