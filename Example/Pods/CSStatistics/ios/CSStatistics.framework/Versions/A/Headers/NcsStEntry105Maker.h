//
// Created by matt on 2018-12-28.
//

#import <Foundation/Foundation.h>
#import "NcsStEntry105Maker.h"

@class NcsStEntry105Maker;
@class NcsStEntry105;

typedef NcsStEntry105Maker *(^DotNSString105)(NSString *);
typedef NcsStEntry105 *(^DotMake105)();

@interface NcsStEntry105Maker : NSObject

/**
 * 15:功能点ID
 */
@property (strong, nonatomic, readonly) DotNSString105 functionId;

/**
 * 16:统计对象
 */
@property (strong, nonatomic, readonly) DotNSString105 statisticsObject;

/**
 * 17:操作代码
 */
@property (strong, nonatomic, readonly) DotNSString105 operationCode;

/**
 * 18:操作结果
 */
@property (strong, nonatomic, readonly) DotNSString105 operationResult;

/**
 * 19:入口
 */
@property (strong, nonatomic, readonly) DotNSString105 entrance;

/**
 * 20:Tab分类
 */
@property (strong, nonatomic, readonly) DotNSString105 tabCategory;

/**
 * 21:位置
 */
@property (strong, nonatomic, readonly) DotNSString105 position;

/**
 * 22:关联对象
 */
@property (strong, nonatomic, readonly) DotNSString105 associationObject;

/**
 * 23:广告ID
 */
@property (strong, nonatomic, readonly) DotNSString105 advertId;

/**
 * 24:备注
 */
@property (strong, nonatomic, readonly) DotNSString105 remark;

/**
 * 构建NcsStEntry105对象
 */
@property (strong, nonatomic, readonly) DotMake105 make;

@end