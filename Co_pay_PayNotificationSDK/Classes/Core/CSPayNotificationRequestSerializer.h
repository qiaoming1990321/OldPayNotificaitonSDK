//
//  CSPayNotificationRequestSerializer.h
//  PayNotificationSDK
//
//  Created by qiaoming on 2019/1/28.
//  Copyright © 2019年 qiaoming. All rights reserved.
//

#import "AFURLRequestSerialization.h"

NS_ASSUME_NONNULL_BEGIN

@interface CSPayNotificationRequestSerializer : AFHTTPRequestSerializer

/**
 Returns a request with the specified parameters encoded into a copy of the original request.
 
 @param request The original request.
 @param parameters The parameters to be encoded.
 @param error The error that occurred while attempting to encode the request parameters.
 
 @return A serialized request.
 */
- (nullable NSURLRequest *)requestBySerializingRequest:(NSURLRequest *)request
                                        withParameters:(nullable id)parameters
                                                 error:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NOTHROW;

@end

NS_ASSUME_NONNULL_END
