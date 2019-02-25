//
// Created by matt on 2018-12-28.
//

#import <Foundation/Foundation.h>


@class NcsStEntry104Maker;
@class NcsStEntry104;

typedef NcsStEntry104Maker *(^DotNSString104)(NSString *);
typedef NcsStEntry104 *(^DotMake104)();

@interface NcsStEntry104Maker : NSObject

/**
 * 15:功能点ID
 */
@property (strong, nonatomic, readonly) DotNSString104 functionId;

/**
 * 16:统计对象
 */
@property (strong, nonatomic, readonly) DotNSString104 statisticsObject;

/**
 * 17:操作代码
 */
@property (strong, nonatomic, readonly) DotNSString104 operationCode;

/**
 * 18:操作结果
 */
@property (strong, nonatomic, readonly) DotNSString104 operationResult;

/**
 * 19:入口
 */
@property (strong, nonatomic, readonly) DotNSString104 entrance;

/**
 * 20:Tab分类
 */
@property (strong, nonatomic, readonly) DotNSString104 tabCategory;

/**
 * 21:位置
 */
@property (strong, nonatomic, readonly) DotNSString104 position;

/**
 * 22:关联对象
 */
@property (strong, nonatomic, readonly) DotNSString104 associationObject;

/**
 * 23:广告ID
 */
@property (strong, nonatomic, readonly) DotNSString104 advertId;

/**
 * 24:备注
 */
@property (strong, nonatomic, readonly) DotNSString104 remark;

/**
 * 构建NcsStEntry104对象
 */
@property (strong, nonatomic, readonly) DotMake104 make;

@end