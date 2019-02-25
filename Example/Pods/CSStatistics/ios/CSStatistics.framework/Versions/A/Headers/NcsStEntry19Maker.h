//
// Created by matt on 2019-01-02.
//

#import <Foundation/Foundation.h>


@class NcsStEntry19Maker;
@class NcsStEntry19;

typedef NcsStEntry19Maker *(^DotNSString19)(NSString *);
typedef NcsStEntry19 *(^DotMake19)();

@interface NcsStEntry19Maker : NSObject


/**
 * 字段21：真版本标识
 */
@property (strong, nonatomic, readonly) DotNSString19 originalLogo;

/**
 * 字段26：IDFA
 */
@property (strong, nonatomic, readonly) DotNSString19 idfa;

/**
 * 构建NcsStEntry19对象
 */
@property (strong, nonatomic, readonly) DotMake19 make;


@end