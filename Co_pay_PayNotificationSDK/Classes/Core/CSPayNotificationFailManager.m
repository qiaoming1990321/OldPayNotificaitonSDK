//
//  CSPayNotificationFailManager.m
//  FMDB
//
//  Created by qiaoming on 2018/12/27.
//

#import "CSPayNotificationFailManager.h"
#import "CSPayNotificationStateApiManager.h"
#import "CSPayNotificationHTTPResponse.h"

@implementation CSPayNotificationFailManager

//通知服务器的内容先缓存到本地 再上传
+(void)saveToCacheWithProductId:(NSString *)product_id {
    CSPayNotificationModel *cache =
    [[CSPayNotificationModel alloc] init];
    cache.product_id = product_id;
    
    NSURL *url = [[NSBundle mainBundle] appStoreReceiptURL];
    NSData *data = [NSData dataWithContentsOfURL:url];
    NSString *receipt = [data base64EncodedStringWithOptions:0];
    //凭证为空 直接返回
    if (receipt == nil || receipt.length == 0) {
        return;
    }
    cache.receipt = receipt;
    cache.uuid = [[NSProcessInfo processInfo] globallyUniqueString];
    [self serializepPayNotificationFailWriteToSanbaxFile:cache];

    [[CSPayNotificationStateApiManager sharedManager] checkiOSIAPPayOrderWithPayNotificationModel:cache complete:^(CSPayNotificationHTTPResponse *response) {
        if (response.status == PayNotificationHttpStatusSuccess) {
            //成功  服务端收到信息了
            NSLog(@"PayNotificationSDK:%@, 通知后台成功", response.bodyString);
            [CSPayNotificationFailManager delSerializedBean:cache];
        }
        else {
            //上传一条统计(协议暂定)
            NSLog(@"PayNotificationSDK:%@, 通知后台失败,下次app启动会重新上传", response.bodyString);
        }
    }];
}

+(void)serializepPayNotificationFailWriteToSanbaxFile:(CSPayNotificationModel*)bean{
    NSString *basePath = [[self class] getBasePath];
    NSString *fullPath = [basePath stringByAppendingString:bean.uuid];
    NSData  *data = [NSKeyedArchiver archivedDataWithRootObject:bean];
    [data writeToFile:fullPath atomically:YES];
}

+(CSPayNotificationModel*)unSerializedStatisticBeanFromFile:(NSString*)serializedBeanPath {
    NSData *data = [NSData dataWithContentsOfFile:serializedBeanPath];
    CSPayNotificationModel *bean = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    return bean;
}

+(NSArray <CSPayNotificationModel *>*)getSerializedStatisticBeanLst {
    NSString *statisticBeanPath = [[self class] getBasePath];
    
    //Get all sub dir files.
    NSArray* allSerializedBeans = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:statisticBeanPath error:nil];
    
    NSString *itemFullPath = nil;
    CSPayNotificationModel *beanItem = nil;
    NSMutableArray *beansAry = [[NSMutableArray alloc] init];
    
    for (int i = 0; i < allSerializedBeans.count; i++) {
        //Filter invalid file names out.
        if ([allSerializedBeans[i] hasPrefix:@"."]) {
            continue;
        }
        
        //Unserialize statistic beans.
        itemFullPath = [statisticBeanPath stringByAppendingString:allSerializedBeans[i]];
        beanItem = [[self class] unSerializedStatisticBeanFromFile:itemFullPath];
        [beansAry addObject:beanItem];
    }
    
    return beansAry;
}

+(void)delSerializedBean:(CSPayNotificationModel*)bean {
    NSString *statisticBeanPath = [[self class] getBasePath];
    NSString * fullBeanPath = [statisticBeanPath stringByAppendingString:bean.uuid];
    BOOL isDirExist = [[NSFileManager defaultManager] fileExistsAtPath:fullBeanPath];
    if (isDirExist) {
        [[NSFileManager defaultManager] removeItemAtPath:fullBeanPath error:nil];
    }
}

+(NSString*)getBasePath {
    //创建文件路径
    NSString *basePath = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject;
    NSString *fullPath = [basePath stringByAppendingString:@"/payNotificationFailCahche/"];
    
    BOOL isDirExist = [[NSFileManager defaultManager] fileExistsAtPath:fullPath];
    if (!isDirExist) {
        [[NSFileManager defaultManager] createDirectoryAtPath:fullPath withIntermediateDirectories:YES attributes:nil error:nil];
    }
    return fullPath;
}

#pragma mark - 上传失败记录
+(void)retryUploadPaynotificationRecordFormLocal
{
    NSArray *loaclRecords = [self getSerializedStatisticBeanLst];
    [loaclRecords enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        CSPayNotificationModel *cacheModel = (CSPayNotificationModel *)obj;
        
        [[CSPayNotificationStateApiManager sharedManager] checkiOSIAPPayOrderWithPayNotificationModel:cacheModel complete:^(CSPayNotificationHTTPResponse *response) {
            if (response.status == PayNotificationHttpStatusSuccess) {
                //成功  服务端收到信息了
                NSLog(@"PayNotificationSDK:%@, 通知后台成功", response.bodyString);
                [CSPayNotificationFailManager delSerializedBean:cacheModel];
            }
            else {
                //上传一条统计(协议暂定)
                NSLog(@"PayNotificationSDK:%@, 通知后台失败,下次app启动会重新上传", response.bodyString);
            }
        }];
    }];
}

@end
