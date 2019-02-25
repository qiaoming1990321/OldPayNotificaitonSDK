//
// Created by matt on 2018-12-28.
//

#import <Foundation/Foundation.h>

@class NcsStEntry103Maker;
@class NcsStEntry103;

typedef NcsStEntry103Maker *(^DotNSString103)(NSString *);
typedef NcsStEntry103 *(^DotMake103)();

@interface NcsStEntry103Maker : NSObject

/**
 * 15:功能点ID
 */
@property (strong, nonatomic, readonly) DotNSString103 functionId;

/**
 * 16:统计对象
 */
@property (strong, nonatomic, readonly) DotNSString103 statisticsObject;

/**
 * 17:操作代码
 */
@property (strong, nonatomic, readonly) DotNSString103 operationCode;

/**
 * 18:操作结果
 */
@property (strong, nonatomic, readonly) DotNSString103 operationResult;

/**
 * 19:入口
 */
@property (strong, nonatomic, readonly) DotNSString103 entrance;

/**
 * 20:Tab分类
 */
@property (strong, nonatomic, readonly) DotNSString103 tabCategory;

/**
 * 21:位置
 */
@property (strong, nonatomic, readonly) DotNSString103 position;

/**
 * 22:关联对象
 */
@property (strong, nonatomic, readonly) DotNSString103 associationObject;

/**
 * 23:广告ID
 */
@property (strong, nonatomic, readonly) DotNSString103 advertId;

/**
 * 24:备注
 */
@property (strong, nonatomic, readonly) DotNSString103 remark;

/**
 * 构建NcsStEntry103对象
 */
@property (strong, nonatomic, readonly) DotMake103 make;

@end