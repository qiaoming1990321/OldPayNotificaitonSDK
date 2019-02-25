//
// Created by matt on 2018-12-28.
//

#import <Foundation/Foundation.h>

@class NcsStEntry102;
@class NcsStEntry102Maker;

typedef NcsStEntry102Maker *(^DotNSString102)(NSString *);
typedef NcsStEntry102 *(^DotMake102)();

@interface NcsStEntry102Maker : NSObject

/**
 * 15:功能点ID
 */
@property (strong, nonatomic, readonly) DotNSString102 functionId;

/**
 * 16:设置信息
 */
@property (strong, nonatomic, readonly) DotNSString102 settingInfo;

/**
 * 17:类型
 */
@property (strong, nonatomic, readonly) DotNSString102 type;

/**
 * 18:位置
 */
@property (strong, nonatomic, readonly) DotNSString102 position;

/**
 * 19:备注
 */
@property (strong, nonatomic, readonly) DotNSString102 remark;

/**
 * 构建NcsStEntry102对象
 */
@property (strong, nonatomic, readonly) DotMake102 make;

@end