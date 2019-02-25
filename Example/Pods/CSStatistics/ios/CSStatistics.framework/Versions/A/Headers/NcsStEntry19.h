//
// Created by matt on 2018-12-27.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"

/**
 * 19协议：http://wiki.3g.net.cn/pages/viewpage.action?pageId=6914524
 */
@interface NcsStEntry19 : NcsStEntryData

/**
 * 字段21：真版本标识
 */
@property (strong, nonatomic) NSString* originalLogo;

/**
 * 字段26：IDFA
 */
@property (strong, nonatomic) NSString* idfa;

@end