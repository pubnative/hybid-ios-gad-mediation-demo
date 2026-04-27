// For GAD Mediation MRect integration, simply just follow GAD's documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

import UIKit
import GoogleMobileAds

class MRect: UIViewController {
    
    @IBOutlet weak var mRectAdContainer: UIView!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    
    var mRectView: BannerView!
    let adUnitID = "ca-app-pub-8741261465579918/6510105208"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "GAD Mediation MRect"
        mRectView = BannerView(adSize: AdSizeMediumRectangle)
        mRectView.delegate = self
        mRectView.adUnitID = adUnitID
        mRectView.rootViewController = self
        mRectAdContainer.addSubview(mRectView)
    }
    
    @IBAction func loadAdTouchUpInside(_ sender: UIButton) {
        activityIndicator.startAnimating()
        mRectAdContainer.isHidden = true
        mRectView.load(Request())
    }
}

extension MRect : BannerViewDelegate {
    func bannerViewDidReceiveAd(_ bannerView: BannerView) {
        mRectAdContainer.isHidden = false
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
