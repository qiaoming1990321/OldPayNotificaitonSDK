//
// Created by matt on 2018-12-27.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"

/**
 * 102协议：非实时统计
 * http://wiki.3g.net.cn/pages/viewpage.action?pageId=18776101
 */
@interface NcsStEntry102 : NcsStEntryData

/**
 * 15:功能点ID
 */
@property (strong, nonatomic) NSString* functionId;

/**
 * 16:设置信息
 * 格式："设置项;设置值#设置项;设置值"#...
 */
@property (strong, nonatomic) NSString* settingInfo;

/**
 * 17:类型
 * 详见设置信息表, 设置值可控时，用1：***；2：***；3：***（用冒号和中文分好分开）
 */
@property (strong, nonatomic) NSString* type;

/**
 * 18:位置
 */
@property (strong, nonatomic) NSString* position;

/**
 * 19:备注
 */
@property (strong, nonatomic) NSString* remark;

@end
