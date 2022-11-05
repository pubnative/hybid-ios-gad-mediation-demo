//
//  Copyright © 2020 PubNative. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import "HyBidGADUtils.h"

NSString *const HyBidGADAdapterKeyZoneID = @"pn_zone_id";
NSString *const HyBidGADAdapterKeyAppToken = @"pn_app_token";

@implementation HyBidGADUtils

+ (BOOL)areExtrasValid:(NSString *)extras {
    if ([HyBidGADUtils zoneID:extras] && [HyBidGADUtils appToken:extras]) {
        return YES;
    } else {
        return NO;
    }
}

+ (NSString *)appToken:(NSString *)extras {
    return [HyBidGADUtils valueWithKey:HyBidGADAdapterKeyAppToken fromExtras:extras];
}

+ (NSString *)zoneID:(NSString *)extras {
    return [HyBidGADUtils valueWithKey:HyBidGADAdapterKeyZoneID fromExtras:extras];
}

+ (NSString *)valueWithKey:(NSString *)key
                fromExtras:(NSString *)extras {
    NSString *result = nil;
    NSData *jsonData = [extras dataUsingEncoding:NSUTF8StringEncoding];
    NSError *error;
    NSMutableDictionary *dictionary = [NSJSONSerialization JSONObjectWithData:jsonData
                                                                      options:0
                                                                        error:&error];
    if (!error) {
        result = (NSString *)dictionary[key];
    }
    
    return result;
}

// v: 2.16.1
+ (GADVersionNumber)adSDKVersion {
    GADVersionNumber version = {0};
    version.majorVersion = 2;
    version.minorVersion = 16;
    version.patchVersion = 1;
    return version;
}

+ (GADVersionNumber)adapterVersion {
    GADVersionNumber version = {0};
    version.majorVersion = 2;
    version.minorVersion = 16;
    version.patchVersion = 1;
    return version;
}

+ (Class<GADAdNetworkExtras>)networkExtrasClass {
    return nil;
}

@end
