//
// Created by matt on 2019-01-02.
//

#import <Foundation/Foundation.h>


@interface NcsStInitParams : NSObject

/**
 * 应用AppId(请在Apple store connect 后台查看)
 */
@property (strong, nonatomic) NSString *appId;

/**
 * app发布渠道，默认500。一般不用设置。
 */
@property (strong, nonatomic) NSString *channel;

/**
 * 设置是否输出日志。默认NO，不输出。
 */
@property (assign, nonatomic) BOOL enableLog;

/**
 * 设置测试服。YES则测服，NO则正式服（默认）。
 */
@property (assign, nonatomic) BOOL testServer;

/**
 * 45协议的功能ID。可选，传45用。也可以不设置，只要传45时配置了funtionId。
 * 接了买量sdk的产品，需要配置此项。
 */
@property (strong, nonatomic) NSString *protocal45FunId;

/**
 * 59协议的功能ID。可选，传59用。也可以不设置，只要传59时配置了funtionId。
 * 接了支付sdk的app，需要配置此项。
 */
@property (strong, nonatomic) NSString *protocal59FunId;

/**
 * 105协议的功能ID。可选，传105用。也可以不设置，只要传105时配置了funtionId。
 * 接了广告sdk的app，需要配置此项。
 */
@property (strong, nonatomic) NSString *protocal105FunId;

/**
 * 是否自动上传19协议，默认YES。
 * 一般情况无需客户端配置.
 */
@property (assign, nonatomic) BOOL upload19Automatically;

/**
 * 多长时间传一次19协议，仅upload19Automatically为YES时有效。单位：s.
 * 一般情况无需客户端配置.
 */
@property (assign, nonatomic) NSTimeInterval upload19TimeLimit;

/**
 * 最大上传线程数(http连接数)，默认2。一般情况无需客户端配置。
 */
@property (assign, nonatomic) NSInteger maxUploadQueueCapacity;

/**
 * 最大统计拼接数(一次http连接最多上传几条统计)，默认10。一般情况无需客户端配置。
 */
@property (assign, nonatomic) NSInteger maxEntryNumInAHttpConnnection;

-(BOOL) checkValid;

@end