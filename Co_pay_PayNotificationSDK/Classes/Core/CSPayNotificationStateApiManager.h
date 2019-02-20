//
//  CSPayNotificationStateApiManager.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/22.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSPayNotificationModel.h"
#import <AFNetworking/AFNetworking.h>
#import "CSPayNotificationHTTPResponse.h"

NS_ASSUME_NONNULL_BEGIN

//typedef void (^GMPayStateApiCompleteBlock) (GMNetHTTPResponse *response);
typedef void (^PayNotificationStateApiCompleteBlock) (CSPayNotificationHTTPResponse *response);

@interface CSPayNotificationStateApiManager : AFHTTPSessionManager
+ (CSPayNotificationStateApiManager *)sharedManager;
//支付成功新增后台 通知接口
-(void)checkiOSIAPPayOrderWithPayNotificationModel:(CSPayNotificationModel *)payNotificationModel  complete:(PayNotificationStateApiCompleteBlock)complete;
@end

NS_ASSUME_NONNULL_END
