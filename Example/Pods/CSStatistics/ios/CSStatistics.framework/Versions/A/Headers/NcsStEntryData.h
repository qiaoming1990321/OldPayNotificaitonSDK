//
//  NcsStEntryData.h
//  CSStatistics
//
//  Created by matt on 2018/12/11.
//

#import <Foundation/Foundation.h>

@class NcsStEntryData;

/**
 * 优先级定义，中间预留了字段以备扩展
 */
typedef NS_ENUM(NSInteger, NcsPriority) {
    NcsPriorityLow = -5,
    NcsPriorityDefault = 0,
    NcsPriorityHigh = 5,
};

/**
 * 上传callback
 */
typedef void(^NcsStUploadCallback)(NcsStEntryData *entry, BOOL success);

/**
 * 统计协议数据
 * "103实时"、"104非实时"、"105实时"格式一样，functionId字段分别是103、104、105
 * "101非实时"比103少一个字段"23：广告ID"
 * "102非实时"的"设置信息"字段是字典格式
 *
 */
@interface NcsStEntryData : NSObject

/**
 * 上传的完整数据
 */
@property (strong, nonatomic) NSString *data;

/**
 * 协议id
 */
@property (strong, nonatomic) NSString *protocalId;

/**
 * 优先级，优先级高的先传
 */
@property (assign, nonatomic) NcsPriority priority;

/**
 * 是否独立上传(不参与拼接)，默认NO
 */
@property (assign, nonatomic) BOOL uploadSeperately;

/**
 * 客户端日志时间，sdk内部赋值
 */
@property (assign, nonatomic) NSTimeInterval createTime;

/**
 * 数据库主键，sdk内部赋值
 */
@property (strong, nonatomic) NSString *uuid;

/**
 * 上传callback，如果应用重启恢复重传，则这个参数会丢失。
 */
@property (strong, nonatomic) NcsStUploadCallback callback;


-(instancetype) initWithData:(NSString *)data;

-(instancetype) initWithData:(NSString *)data priority : (NcsPriority) priority;

-(NcsStEntryData *)copyAsMe;

/**
 * 新entry被创建，做一些初始化工作
 */
-(void)onCreate;

/**
 * 填充data属性
 */
-(void)completeData;

/**
 * 替换掉无效字符
 */
-(void)replaceInvalidCharacters;

/**
 * 是否有效日志，无效日志会直接扔掉不上传.
 * @return
 */
-(BOOL)isValid;

/**
 * 部分data数据，通常用于101～105
 * @return
 */
-(NSString *)subData;

/**
 * 详细log
 * @return
 */
-(NSString *)detailsLog;

/**
 * 获取优先级比较器
 * @return
 */
+(NSComparator)getPriorityComparator;

+(NSArray *)searchOrdered;

@end
