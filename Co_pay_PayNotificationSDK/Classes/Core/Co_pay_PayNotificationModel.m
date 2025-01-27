//
//  Co_pay_PayNotificationModel.m
//  FMDB
//
//  Created by qiaoming on 2018/12/27.
//

#import "Co_pay_PayNotificationModel.h"

@implementation Co_pay_PayNotificationModel

- (void) encodeWithCoder:(NSCoder*)encoder {
[encoder encodeObject:self.uuid forKey:@"uuid"];
[encoder encodeObject:self.product_id forKey:@"product_id"];
[encoder encodeObject:self.receipt forKey:@"receipt"];
}

- (id) initWithCoder:(NSCoder*)decoder {
if (self = [super init]) {
self.uuid = [decoder decodeObjectForKey:@"uuid"];
self.product_id = [decoder decodeObjectForKey:@"product_id"];
self.receipt = [decoder decodeObjectForKey:@"receipt"];
}
return self;
}

@end
