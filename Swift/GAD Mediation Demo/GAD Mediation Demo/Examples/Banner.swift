// For GAD Mediation Banner integration, simply just follow GAD's documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

import UIKit
import GoogleMobileAds

class Banner: UIViewController {
    
    @IBOutlet weak var bannerAdContainer: UIView!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    
    var bannerView: BannerView!
    let adUnitID = "ca-app-pub-8741261465579918/4075513559"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "GAD Mediation Banner"
        bannerView = BannerView(adSize: AdSizeBanner)
        bannerView.delegate = self
        bannerView.adUnitID = adUnitID
        bannerView.rootViewController = self
        bannerAdContainer.addSubview(bannerView)
    }
    
    @IBAction func loadAdTouchUpInside(_ sender: UIButton) {
        activityIndicator.startAnimating()
        bannerAdContainer.isHidden = true
        bannerView.load(Request())
    }
}

extension Banner : BannerViewDelegate {
    func bannerViewDidReceiveAd(_ bannerView: BannerView) {
        bannerAdContainer.isHidden = false
        activityIndicator.stopAnimating()
    }
    
    func bannerView(_ bannerView: BannerView, didFailToReceiveAdWithError error: Error) {
        activityIndicator.stopAnimating()
    }
    
    func bannerViewDidRecordImpression(_ bannerView: BannerView) {
    }
    
    func bannerViewWillPresentScreen(_ bannerView: BannerView) {
    }
    
    func bannerViewWillDismissScreen(_ bannerView: BannerView) {
    }
    
    func bannerViewDidDismissScreen(_ bannerView: BannerView) {
    }
}
