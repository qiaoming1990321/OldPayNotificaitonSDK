//
// Created by matt on 2018-12-29.
//

#import <Foundation/Foundation.h>

@class NcsStEntry59Maker;
@class NcsStEntry59;

typedef NcsStEntry59Maker *(^DotNSString59)(NSString *);
typedef NcsStEntry59 *(^DotMake59)();

@interface NcsStEntry59Maker : NSObject

/**
 * 4:功能点ID
 */
@property (strong, nonatomic, readonly) DotNSString59 functionId;

/**
 * 5:统计对象
 */
@property (strong, nonatomic, readonly) DotNSString59 statisticsObject;

/**
 * 6:操作代码
 */
@property (strong, nonatomic, readonly) DotNSString59 operationCode;

/**
 * 7:操作结果 --> 0：点击购买，1：购买成功
 */
@property (strong, nonatomic, readonly) DotNSString59 operationResult;

/**
 * 12:入口
 */
@property (strong, nonatomic, readonly) DotNSString59 entrance;

/**
 * 13:Tab分类
 */
@property (strong, nonatomic, readonly) DotNSString59 tabCategory;

/**
 * 14:位置 --> 购买成功时，上传订单编号
 */
@property (strong, nonatomic, readonly) DotNSString59 position;

/**
 * 17:关联对象
 */
@property (strong, nonatomic, readonly) DotNSString59 associationObject;

/**
 * 18:备注
 */
@property (strong, nonatomic, readonly) DotNSString59 remark;

/**
 * 19:订单类型 --> 1：普通内购，2：订阅，3：订阅SDK-订阅，4：订阅sdk-一次性购买
 */
@property (strong, nonatomic, readonly) DotNSString59 orderType;

/**
 * 构建NcsStEntry59对象
 */
@property (strong, nonatomic, readonly) DotMake59 make;


@end