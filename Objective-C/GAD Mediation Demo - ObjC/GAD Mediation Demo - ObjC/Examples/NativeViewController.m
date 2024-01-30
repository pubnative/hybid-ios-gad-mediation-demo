// For GAD Mediation Native integration, simply just follow GAD's documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

#import "NativeViewController.h"

#define NATIVE_AD_UNIT_ID @"ca-app-pub-8741261465579918/8160924764"

@import GoogleMobileAds;

@interface NativeViewController () <GADNativeAdLoaderDelegate>

@property (weak, nonatomic) IBOutlet UIView *nativeAdContainer;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property(nonatomic, strong) GADAdLoader *adLoader;
@property(nonatomic, strong) GADNativeAdView *nativeAdView;

@end

@implementation NativeViewController

- (void)dealloc {
    self.adLoader = nil;
    self.nativeAdView = nil;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"GAD Mediation Native";
}

- (IBAction)loadAdTouchUpInside:(id)sender {
    self.nativeAdContainer.hidden = YES;
    [self.activityIndicator startAnimating];
    self.adLoader = [[GADAdLoader alloc] initWithAdUnitID:NATIVE_AD_UNIT_ID
                                       rootViewController:self
                                                  adTypes:@[ GADAdLoaderAdTypeNative ]
                                                  options:@[ [[GADNativeAdViewAdOptions alloc] init] ]];
    self.adLoader.delegate = self;
    [self.adLoader loadRequest:[GADRequest request]];}

#pragma mark GADNativeAdLoaderDelegate

- (void)adLoaderDidFinishLoading:(GADAdLoader *)adLoader {
    [self.activityIndicator stopAnimating];
}

- (void)adLoader:(nonnull GADAdLoader *)adLoader didReceiveNativeAd:(nonnull GADNativeAd *)nativeAd {
    GADNativeAdView *nativeAdView = [[NSBundle mainBundle] loadNibNamed:@"NativeView" owner:nil options:nil].firstObject;
    [self.nativeAdView removeFromSuperview];
    self.nativeAdView = nativeAdView;
    self.nativeAdView.frame = self.nativeAdContainer.bounds;
    [self.nativeAdContainer addSubview:self.nativeAdView];
    self.nativeAdContainer.hidden = NO;
    
    ((UILabel *)nativeAdView.headlineView).text = nativeAd.headline;
    ((UILabel *)nativeAdView.bodyView).text = nativeAd.body;
    [((UIButton *)nativeAdView.callToActionView)setTitle:nativeAd.callToAction
                                                forState:UIControlStateNormal];
    nativeAdView.callToActionView.userInteractionEnabled = NO;
    ((UIImageView *)nativeAdView.iconView).image = nativeAd.icon.image;
    ((UIImageView *)nativeAdView.imageView).image = nativeAd.images.firstObject.image;
    nativeAdView.nativeAd = nativeAd;
}

- (void)adLoader:(GADAdLoader *)adLoader didFailToReceiveAdWithError:(NSError *)error {
    [self.activityIndicator stopAnimating];
}


@end
