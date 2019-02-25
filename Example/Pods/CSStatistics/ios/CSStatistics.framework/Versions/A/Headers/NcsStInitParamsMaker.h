//
// Created by matt on 2019-01-02.
//

#import <Foundation/Foundation.h>


@class NcsStInitParamsMaker;
@class NcsStInitParams;

typedef NcsStInitParamsMaker *(^NcsStDotNSStringInit)(NSString *);
typedef NcsStInitParamsMaker *(^NcsStDotBoolInit)(BOOL);
typedef NcsStInitParamsMaker *(^NcsStDotNSIntegerInit)(NSInteger);
typedef NcsStInitParamsMaker *(^NcsStDotNSTimeInit)(NSTimeInterval);
typedef NcsStInitParams *(^NcsStDotMakeInit)();

@interface NcsStInitParamsMaker : NSObject


/**
 * AppId(请在Apple store connect 后台查看)
 */
@property (strong, nonatomic, readonly) NcsStDotNSStringInit appId;

/**
 * app发布渠道，默认500。一般不用设置。
 */
@property (strong, nonatomic, readonly) NcsStDotNSStringInit channel;

/**
 * 设置是否输出日志。默认NO，不输出。
 */
@property (assign, nonatomic, readonly) NcsStDotBoolInit enableLog;

/**
 * 设置测试服。YES则测服，NO则正式服（默认）。
 */
@property (assign, nonatomic, readonly) NcsStDotBoolInit testServer;

/**
 * 45协议的功能ID。可选，传45用。也可以不设置，只要传45时配置了funtionId。
 */
@property (strong, nonatomic, readonly) NcsStDotNSStringInit protocal45FunId;

/**
 * 59协议的功能ID。可选，传59用。也可以不设置，只要传59时配置了funtionId。
 */
@property (strong, nonatomic, readonly) NcsStDotNSStringInit protocal59FunId;

/**
 * 105协议的功能ID。可选，传105用。也可以不设置，只要传105时配置了funtionId。
 */
@property (strong, nonatomic, readonly) NcsStDotNSStringInit protocal105FunId;

/**
 * 是否自动上传19协议，默认YES。
 * 一般情况无需客户端配置.
 */
@property (assign, nonatomic, readonly) NcsStDotBoolInit upload19Automatically;

/**
 * 多长时间传一次19协议，仅upload19Automatically为YES时有效。单位：s.
 * 一般情况无需客户端配置.
 */
@property (assign, nonatomic, readonly) NcsStDotNSTimeInit upload19TimeLimit;

/**
 * 最大上传线程数(http连接数)，默认2。一般情况无需客户端配置。
 */
@property (assign, nonatomic, readonly) NcsStDotNSIntegerInit maxUploadQueueCapacity;

/**
 * 最大统计拼接数(一次http连接最多上传几条统计)，默认10。一般情况无需客户端配置。
 */
@property (assign, nonatomic, readonly) NcsStDotNSIntegerInit maxEntryNumInAHttpConnnection;

/**
 * 构建NcsStInitParams对象
 */
@property (strong, nonatomic, readonly) NcsStDotMakeInit make;

@end


