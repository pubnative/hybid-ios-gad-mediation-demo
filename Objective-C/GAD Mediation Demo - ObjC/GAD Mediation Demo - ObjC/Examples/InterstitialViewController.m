// For GAD (AdMob) Mediation Interstitial integration, simply just follow GAD's (AdMob's) documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

#import "InterstitialViewController.h"

#define INTERSTITIAL_AD_UNIT_ID @"ca-app-pub-8741261465579918/1815008264"

@import GoogleMobileAds;

@interface InterstitialViewController () <GADFullScreenContentDelegate>

@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (weak, nonatomic) IBOutlet UIButton *showAdButton;
@property (nonatomic, strong) GAMInterstitialAd *interstitialAd;

@end

@implementation InterstitialViewController

- (void)dealloc {
    self.interstitialAd = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"GAD Mediation Interstitial";
}

- (IBAction)loadAdTouchUpInside:(id)sender {
    [self.activityIndicator startAnimating];
    self.showAdButton.hidden = YES;
    GAMRequest *request = [GAMRequest request];
    [GAMInterstitialAd loadWithAdManagerAdUnitID:INTERSTITIAL_AD_UNIT_ID
                                         request:request
                               completionHandler:^(GAMInterstitialAd *ad, NSError *error) {
        if (error) {
            NSLog(@"Failed to load interstitial ad with error: %@", [error localizedDescription]);
            [self.activityIndicator stopAnimating];
            return;
        }
        self.interstitialAd = ad;
        [self.activityIndicator stopAnimating];
        self.showAdButton.hidden = NO;
        self.interstitialAd.fullScreenContentDelegate = self;
    }];
}

- (IBAction)showAdTouchUpInside:(UIButton *)sender {
    if (self.interstitialAd) {
        [self.interstitialAd presentFromRootViewController:self];
    } else {
        NSLog(@"Ad wasn't ready");
    }
}

#pragma mark GADFullScreenContentDelegate

-(void)adWillPresentFullScreenContent:(id<GADFullScreenPresentingAd>)ad {
    
}

- (void)ad:(id)ad didFailToPresentFullScreenContentWithError:(NSError *)error {
    [self.activityIndicator stopAnimating];
}

- (void)adDidDismissFullScreenContent:(id)ad {
    self.showAdButton.hidden = YES;
}

@end
