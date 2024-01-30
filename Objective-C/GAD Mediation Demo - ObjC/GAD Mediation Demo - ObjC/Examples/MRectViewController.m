// For GAD Mediation MRect integration, simply just follow GAD's documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

#import "MRectViewController.h"

#define MRECT_AD_UNIT_ID @"ca-app-pub-8741261465579918/6510105208"

@import GoogleMobileAds;

@interface MRectViewController () <GADBannerViewDelegate>

@property (weak, nonatomic) IBOutlet UIView *mRectAdContainer;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) GAMBannerView *mRectView;

@end

@implementation MRectViewController

- (void)dealloc {
    self.mRectView = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"GAD Mediation MRect";
    self.mRectView = [[GAMBannerView alloc] initWithAdSize:GADAdSizeMediumRectangle];
    self.mRectView.delegate = self;
    self.mRectView.adUnitID = MRECT_AD_UNIT_ID;
    self.mRectView.rootViewController = self;
    [self.mRectAdContainer addSubview:self.mRectView];
}

- (IBAction)loadAdTouchUpInside:(id)sender {
    [self.activityIndicator startAnimating];
    self.mRectAdContainer.hidden = YES;
    [self.mRectView loadRequest:[GAMRequest request]];
}

#pragma mark - GADBannerViewDelegate

- (void)bannerViewDidReceiveAd:(GADBannerView *)bannerView {
    self.mRectAdContainer.hidden = NO;
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
