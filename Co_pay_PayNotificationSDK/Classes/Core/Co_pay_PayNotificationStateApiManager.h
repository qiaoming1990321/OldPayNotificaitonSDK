//
//  Co_pay_PayNotificationStateApiManager.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/22.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Co_pay_PayNotificationModel.h"
#import <AFNetworking/AFNetworking.h>
#import "Co_pay_PayNotificationHTTPResponse.h"

NS_ASSUME_NONNULL_BEGIN

//typedef void (^GMPayStateApiCompleteBlock) (GMNetHTTPResponse *response);
typedef void (^PayNotificationStateApiCompleteBlock) (Co_pay_PayNotificationHTTPResponse *response);

@interface Co_pay_PayNotificationStateApiManager : AFHTTPSessionManager
+ (Co_pay_PayNotificationStateApiManager *)sharedManager;
//支付成功新增后台 通知接口
-(void)checkiOSIAPPayOrderWithPayNotificationModel:(Co_pay_PayNotificationModel *)payNotificationModel  complete:(PayNotificationStateApiCompleteBlock)complete;
@end

NS_ASSUME_NONNULL_END
