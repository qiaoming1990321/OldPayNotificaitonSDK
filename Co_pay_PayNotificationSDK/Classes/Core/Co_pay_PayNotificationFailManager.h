//
//  Co_pay_PayNotificationFailManager.h
//  FMDB
//
//  Created by qiaoming on 2018/12/27.
//

#import <Foundation/Foundation.h>
#import "Co_pay_PayNotificationModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface Co_pay_PayNotificationFailManager : NSObject

//通知服务器的内容先缓存到本地 再上传
+(void)saveToCacheWithProductId:(NSString *)product_id;
+(Co_pay_PayNotificationModel*)unSerializedStatisticBeanFromFile:(NSString*)serializedBeanPath;
+(void)delSerializedBean:(Co_pay_PayNotificationModel*)bean;
+(NSArray <Co_pay_PayNotificationModel *>*)getSerializedStatisticBeanLst;
//再次上传失败的通知记录
+(void)retryUploadPaynotificationRecordFormLocal;
@end

NS_ASSUME_NONNULL_END
