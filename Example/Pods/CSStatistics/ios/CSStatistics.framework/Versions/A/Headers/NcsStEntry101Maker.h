//
// Created by matt on 2018-12-28.
//

#import <Foundation/Foundation.h>

@class NcsStEntry101;
@class NcsStEntry101Maker;

typedef NcsStEntry101Maker *(^DotNSString101)(NSString *);
typedef NcsStEntry101 *(^DotMake101)();

@interface NcsStEntry101Maker : NSObject

/**
 * 15:功能点ID
 */
@property (strong, nonatomic, readonly) DotNSString101 functionId;

/**
 * 16:统计对象
 */
@property (strong, nonatomic, readonly) DotNSString101 statisticsObject;

/**
 * 17:操作代码
 */
@property (strong, nonatomic, readonly) DotNSString101 operationCode;

/**
 * 18:操作结果
 */
@property (strong, nonatomic, readonly) DotNSString101 operationResult;

/**
 * 19:入口
 */
@property (strong, nonatomic, readonly) DotNSString101 entrance;

/**
 * 20:Tab分类
 */
@property (strong, nonatomic, readonly) DotNSString101 tabCategory;

/**
 * 21:位置
 */
@property (strong, nonatomic, readonly) DotNSString101 position;

/**
 * 22:关联对象
 */
@property (strong, nonatomic, readonly) DotNSString101 associationObject;

/**
 * 24:备注
 */
@property (strong, nonatomic, readonly) DotNSString101 remark;

/**
 * 构建NcsStEntry101对象
 */
@property (strong, nonatomic, readonly) DotMake101 make;

@end