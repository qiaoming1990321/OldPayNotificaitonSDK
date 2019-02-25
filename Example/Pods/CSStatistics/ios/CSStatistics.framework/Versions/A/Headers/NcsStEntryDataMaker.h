//
// Created by matt on 2019-01-17.
//

#import <Foundation/Foundation.h>
#import "NcsStEntryData.h"

@class NcsStEntryDataMaker;
@class NcsStEntryData;

typedef NcsStEntryDataMaker *(^DotNSStringBase)(NSString *);
typedef NcsStEntryDataMaker *(^DotBoolBase)(BOOL);
typedef NcsStEntryDataMaker *(^DotPriorityBase)(NcsPriority);
typedef NcsStEntryDataMaker *(^DotCallbackBase)(NcsStUploadCallback);
typedef NcsStEntryData *(^DotMakeBase)();


@interface NcsStEntryDataMaker : NSObject

/**
 * 上传的完整数据
 */
@property (strong, nonatomic, readonly) DotNSStringBase data;

/**
 * 协议id
 */
@property (strong, nonatomic, readonly) DotNSStringBase protocalId;

/**
 * 优先级，优先级高的先传
 */
@property (strong, nonatomic, readonly) DotPriorityBase priority;

/**
 * 是否独立上传(不参与拼接)，默认NO
 */
@property (strong, nonatomic, readonly) DotBoolBase uploadSeperately;

/**
 * 上传callback，如果应用重启恢复重传，则这个参数会丢失。
 */
@property (strong, nonatomic, readonly) DotCallbackBase callback;

/**
 * 构建NcsStEntryData对象
 */
@property (strong, nonatomic, readonly) DotMakeBase make;

@end