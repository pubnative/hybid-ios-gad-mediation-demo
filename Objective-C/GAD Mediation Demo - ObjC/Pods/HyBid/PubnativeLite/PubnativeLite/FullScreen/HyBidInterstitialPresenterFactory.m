//
//  Copyright © 2018 PubNative. All rights reserved.
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

#import "HyBidInterstitialPresenterFactory.h"
#import "PNLiteAssetGroupType.h"
#import "PNLiteInterstitialPresenterDecorator.h"
#import "PNLiteMRAIDInterstitialPresenter.h"
#import "PNLiteVASTInterstitialPresenter.h"
#import "HyBidAdTracker.h"
#import "HyBidLogger.h"
#import "HyBidRemoteConfigFeature.h"
#import "HyBidRemoteConfigManager.h"

@implementation HyBidInterstitialPresenterFactory

- (HyBidInterstitialPresenter *)createInterstitalPresenterWithAd:(HyBidAd *)ad
                                             withVideoSkipOffset:(NSUInteger)videoSkipOffset
                                              withHTMLSkipOffset:(NSUInteger)htmlSkipOffset
                                               withCloseOnFinish:(BOOL)closeOnFinish
                                                    withDelegate:(NSObject<HyBidInterstitialPresenterDelegate> *)delegate {
    HyBidInterstitialPresenter *interstitialPresenter = [self createInterstitalPresenterFromAd:ad withVideoSkipOffset:videoSkipOffset withHTMLSkipOffset:htmlSkipOffset withCloseOnFinish:closeOnFinish];
    if (!interstitialPresenter) {
        return nil;
    }
    PNLiteInterstitialPresenterDecorator *interstitialPresenterDecorator = [[PNLiteInterstitialPresenterDecorator alloc] initWithInterstitialPresenter:interstitialPresenter
                                                                                                                                         withAdTracker:[[HyBidAdTracker alloc] initWithImpressionURLs:[ad beaconsDataWithType:PNLiteAdTrackerImpression] withClickURLs:[ad beaconsDataWithType:PNLiteAdTrackerClick]]
                                                                                                                                          withDelegate:delegate];
    interstitialPresenter.delegate = interstitialPresenterDecorator;
    return interstitialPresenterDecorator;
}
    
- (HyBidInterstitialPresenter *)createInterstitalPresenterFromAd:(HyBidAd *)ad withVideoSkipOffset:(NSUInteger)videoSkipOffset withHTMLSkipOffset:(NSUInteger)htmlSkipOffset withCloseOnFinish: (BOOL)closeOnFinish {
    switch (ad.assetGroupID.integerValue) {
        case MRAID_300x600:
        case MRAID_320x480:
        case MRAID_480x320:
        case MRAID_1024x768:
        case MRAID_768x1024:{
            PNLiteMRAIDInterstitialPresenter *mraidInterstitalPresenter = [[PNLiteMRAIDInterstitialPresenter alloc] initWithAd:ad withSkipOffset:htmlSkipOffset];
            
            NSString *mraidString = [HyBidRemoteConfigFeature hyBidRemoteRenderingToString:HyBidRemoteRendering_MRAID];
            return ![[[HyBidRemoteConfigManager sharedInstance] featureResolver] isRenderingSupported: mraidString] ? nil : mraidInterstitalPresenter;
        }
        case VAST_INTERSTITIAL: {
            PNLiteVASTInterstitialPresenter *vastInterstitalPresenter = [[PNLiteVASTInterstitialPresenter alloc] initWithAd:ad withSkipOffset:videoSkipOffset withCloseOnFinish:closeOnFinish];
            
            NSString *vastString = [HyBidRemoteConfigFeature hyBidRemoteRenderingToString:HyBidRemoteRendering_VAST];
            return ![[[HyBidRemoteConfigManager sharedInstance] featureResolver] isRenderingSupported: vastString] ? nil : vastInterstitalPresenter;
        }
        default:
            [HyBidLogger warningLogFromClass:NSStringFromClass([self class]) fromMethod:NSStringFromSelector(_cmd) withMessage:[NSString stringWithFormat:@"Asset Group %@ is an incompatible Asset Group ID for Interstitial ad format.", ad.assetGroupID]];
            return nil;
            break;
    }
}

@end