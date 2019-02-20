//
//  PayNotificationDeviceModel.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CSPayNotificationDeviceModel : NSObject

+ (NSDictionary *)deviceWithDid:(NSString *)did;

@end

NS_ASSUME_NONNULL_END
