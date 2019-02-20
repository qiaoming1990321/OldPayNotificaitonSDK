//
//  PayNotificationHTTPResponse.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger , PayNotificationHttpStatus) {
    PayNotificationHttpStatusFail = -1,
    PayNotificationHttpStatusSuccess = 0,
};
NS_ASSUME_NONNULL_BEGIN

@interface CSPayNotificationHTTPResponse : NSObject

@property (nonatomic) PayNotificationHttpStatus status;

/**
 http 的返回码
 */
@property (nonatomic) NSInteger statusCode;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, copy) NSDictionary *bodyData;
@property (nonatomic, copy) NSString *bodyString;
@property (nonatomic, strong) NSURLResponse *response;

@end

NS_ASSUME_NONNULL_END
