// For GAD (AdMob) Mediation Rewarded integration, simply just follow GAD's (AdMob's) documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

#import "RewardedViewController.h"

#define REWARDED_AD_UNIT_ID @"ca-app-pub-8741261465579918/7366717846"

@import GoogleMobileAds;

@interface RewardedViewController () <GADFullScreenContentDelegate>

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (weak, nonatomic) IBOutlet UIButton *showAdButton;
@property (nonatomic, strong) GADRewardedAd *rewardedAd;

@end

@implementation RewardedViewController

- (void)dealloc {
    self.rewardedAd = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"GAD Mediation Rewarded";
}

- (IBAction)loadAdTouchUpInside:(id)sender {
    [self.activityIndicator startAnimating];
    self.showAdButton.hidden = YES;
    GAMRequest *request = [GAMRequest request];
    [GADRewardedAd loadWithAdUnitID:REWARDED_AD_UNIT_ID
                            request:request
                  completionHandler:^(GADRewardedAd *ad, NSError *error) {
        if (error) {
            NSLog(@"Failed to load interstitial ad with error: %@", [error localizedDescription]);
            [self.activityIndicator stopAnimating];
            return;
        }
        self.rewardedAd = ad;
        [self.activityIndicator stopAnimating];
        self.showAdButton.hidden = NO;
        self.rewardedAd.fullScreenContentDelegate = self;
    }];
}

- (IBAction)showAdTouchUpInside:(UIButton *)sender {
    if (self.rewardedAd) {
        [self.rewardedAd presentFromRootViewController:self
                              userDidEarnRewardHandler:^ {
            if (self.rewardedAd.adReward) {
                NSLog(@"Reward received: %@", self.rewardedAd.adReward);
            }
        }];
    } else {
        NSLog(@"Ad wasn't ready");
    }
}

#pragma mark GADFullScreenContentDelegate

- (void)adWillPresentFullScreenContent:(id<GADFullScreenPresentingAd>)ad {
    
}

- (void)ad:(id)ad didFailToPresentFullScreenContentWithError:(NSError *)error {
    [self.activityIndicator stopAnimating];
}

- (void)adDidDismissFullScreenContent:(id)ad {
    self.showAdButton.hidden = YES;
}

@end
