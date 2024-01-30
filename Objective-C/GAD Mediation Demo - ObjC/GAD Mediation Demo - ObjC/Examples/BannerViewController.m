// For GAD Mediation Banner integration, simply just follow GAD's documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

#import "BannerViewController.h"

#define BANNER_AD_UNIT_ID @"ca-app-pub-8741261465579918/4075513559"

@import GoogleMobileAds;

@interface BannerViewController () <GADBannerViewDelegate>

@property (weak, nonatomic) IBOutlet UIView *bannerAdContainer;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) GAMBannerView *bannerView;

@end

@implementation BannerViewController

- (void)dealloc {
    self.bannerView = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"GAD Mediation Banner";
    self.bannerView = [[GAMBannerView alloc] initWithAdSize:GADAdSizeBanner];
    self.bannerView.delegate = self;
    self.bannerView.adUnitID = BANNER_AD_UNIT_ID;
    self.bannerView.rootViewController = self;
    [self.bannerAdContainer addSubview:self.bannerView];
}

- (IBAction)loadAdTouchUpInside:(id)sender {
    [self.activityIndicator startAnimating];
    self.bannerAdContainer.hidden = YES;
    [self.bannerView loadRequest:[GAMRequest request]];
}

#pragma mark - GADBannerViewDelegate

- (void)bannerViewDidReceiveAd:(GADBannerView *)bannerView {
    self.bannerAdContainer.hidden = NO;
    [self.activityIndicator stopAnimating];
}

- (void)bannerView:(GADBannerView *)bannerView didFailToReceiveAdWithError:(NSError *)error {
    [self.activityIndicator stopAnimating];
}

-(void)bannerViewDidRecordImpression:(GADBannerView *)bannerView {
}

- (void)bannerViewWillPresentScreen:(GADBannerView *)bannerView {
}

- (void)bannerViewWillDismissScreen:(GADBannerView *)bannerView {
}

- (void)bannerViewDidDismissScreen:(GADBannerView *)bannerView {
}

@end
