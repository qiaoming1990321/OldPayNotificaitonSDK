//
// Created by matt on 2018-12-27.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"


/**
 * 101协议：非实时统计，格式比103、104统计少一个"23：广告id"
 * http://wiki.3g.net.cn/pages/viewpage.action?pageId=18776101
 */
@interface NcsStEntry101 : NcsStEntryData

/**
 * 15:功能点ID
 */
@property (strong, nonatomic) NSString* functionId;

/**
 * 16:统计对象
 */
@property (strong, nonatomic) NSString* statisticsObject;

/**
 * 17:操作代码
 */
@property (strong, nonatomic) NSString* operationCode;

/**
 * 18:操作结果
 */
@property (strong, nonatomic) NSString* operationResult;

/**
 * 19:入口
 */
@property (strong, nonatomic) NSString* entrance;

/**
 * 20:Tab分类
 */
@property (strong, nonatomic) NSString* tabCategory;

/**
 * 21:位置
 */
@property (strong, nonatomic) NSString* position;

/**
 * 22:关联对象
 */
@property (strong, nonatomic) NSString* associationObject;

/**
 * 23:备注
 */
@property (strong, nonatomic) NSString* remark;


@end