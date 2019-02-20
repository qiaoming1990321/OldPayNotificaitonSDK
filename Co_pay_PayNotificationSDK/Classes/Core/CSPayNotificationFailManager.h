//
//  CSPayNotificationFailManager.h
//  FMDB
//
//  Created by qiaoming on 2018/12/27.
//

#import <Foundation/Foundation.h>
#import "CSPayNotificationModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSPayNotificationFailManager : NSObject

//通知服务器的内容先缓存到本地 再上传
+(void)saveToCacheWithProductId:(NSString *)product_id;
+(CSPayNotificationModel*)unSerializedStatisticBeanFromFile:(NSString*)serializedBeanPath;
+(void)delSerializedBean:(CSPayNotificationModel*)bean;
+(NSArray <CSPayNotificationModel *>*)getSerializedStatisticBeanLst;
//再次上传失败的通知记录
+(void)retryUploadPaynotificationRecordFormLocal;
@end

NS_ASSUME_NONNULL_END
