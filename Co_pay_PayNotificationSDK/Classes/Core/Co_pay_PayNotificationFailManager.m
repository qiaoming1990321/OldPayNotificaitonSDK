//
//  Co_pay_PayNotificationFailManager.m
//  FMDB
//
//  Created by qiaoming on 2018/12/27.
//

#import "Co_pay_PayNotificationFailManager.h"
#import "Co_pay_PayNotificationStateApiManager.h"
#import "Co_pay_PayNotificationHTTPResponse.h"

@implementation Co_pay_PayNotificationFailManager

//通知服务器的内容先缓存到本地 再上传
+(void)saveToCacheWithProductId:(NSString *)product_id {
Co_pay_PayNotificationModel *cache =
[[Co_pay_PayNotificationModel alloc] init];
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

[[Co_pay_PayNotificationStateApiManager sharedManager] checkiOSIAPPayOrderWithPayNotificationModel:cache complete:^(Co_pay_PayNotificationHTTPResponse *response) {
if (response.status == PayNotificationHttpStatusSuccess) {
//成功  服务端收到信息了
NSLog(@"PayNotificationSDK:%@, 通知后台成功", response.bodyString);
[Co_pay_PayNotificationFailManager delSerializedBean:cache];
}
else {
//上传一条统计(协议暂定)
NSLog(@"PayNotificationSDK:%@, 通知后台失败,下次app启动会重新上传", response.bodyString);
}
}];
}

+(void)serializepPayNotificationFailWriteToSanbaxFile:(Co_pay_PayNotificationModel*)bean{
NSString *basePath = [[self class] getBasePath];
NSString *fullPath = [basePath stringByAppendingString:bean.uuid];
NSData  *data = [NSKeyedArchiver archivedDataWithRootObject:bean];
[data writeToFile:fullPath atomically:YES];
}

+(Co_pay_PayNotificationModel*)unSerializedStatisticBeanFromFile:(NSString*)serializedBeanPath {
NSData *data = [NSData dataWithContentsOfFile:serializedBeanPath];
Co_pay_PayNotificationModel *bean = [NSKeyedUnarchiver unarchiveObjectWithData:data];
return bean;
}

+(NSArray <Co_pay_PayNotificationModel *>*)getSerializedStatisticBeanLst {
NSString *statisticBeanPath = [[self class] getBasePath];

//Get all sub dir files.
NSArray* allSerializedBeans = [[NSFileManager defaultManager] contentsOfDirectoryAtPath:statisticBeanPath error:nil];

NSString *itemFullPath = nil;
Co_pay_PayNotificationModel *beanItem = nil;
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

+(void)delSerializedBean:(Co_pay_PayNotificationModel*)bean {
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
Co_pay_PayNotificationModel *cacheModel = (Co_pay_PayNotificationModel *)obj;

[[Co_pay_PayNotificationStateApiManager sharedManager] checkiOSIAPPayOrderWithPayNotificationModel:cacheModel complete:^(Co_pay_PayNotificationHTTPResponse *response) {
if (response.status == PayNotificationHttpStatusSuccess) {
//成功  服务端收到信息了
NSLog(@"PayNotificationSDK:%@, 通知后台成功", response.bodyString);
[Co_pay_PayNotificationFailManager delSerializedBean:cacheModel];
}
else {
//上传一条统计(协议暂定)
NSLog(@"PayNotificationSDK:%@, 通知后台失败,下次app启动会重新上传", response.bodyString);
}
}];
}];
}

@end
