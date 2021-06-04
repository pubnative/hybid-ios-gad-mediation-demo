// For GAD (AdMob) Mediation MRect integration, simply just follow GAD's (AdMob's) documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

import UIKit
import GoogleMobileAds

class MRect: UIViewController {
    
    @IBOutlet weak var mRectAdContainer: UIView!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    
    var mRectView: GADBannerView!
    let adUnitID = "ca-app-pub-8741261465579918/6510105208"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "GAD Mediation MRect"
        mRectView = GADBannerView(adSize: kGADAdSizeMediumRectangle)
        mRectView.delegate = self
        mRectView.adUnitID = adUnitID
        mRectView.rootViewController = self
        mRectAdContainer.addSubview(mRectView)
    }
    
    @IBAction func loadAdTouchUpInside(_ sender: UIButton) {
        activityIndicator.startAnimating()
        mRectAdContainer.isHidden = true
        mRectView.load(GADRequest())
    }
}

extension MRect : GADBannerViewDelegate {
    func bannerViewDidReceiveAd(_ bannerView: GADBannerView) {
        mRectAdContainer.isHidden = false
        activityIndicator.stopAnimating()
    }
    
    func bannerView(_ bannerView: GADBannerView, didFailToReceiveAdWithError error: Error) {
        activityIndicator.stopAnimating()
    }
    
    func bannerViewDidRecordImpression(_ bannerView: GADBannerView) {
    }
    
    func bannerViewWillPresentScreen(_ bannerView: GADBannerView) {
    }
    
    func bannerViewWillDismissScreen(_ bannerView: GADBannerView) {
    }
    
    func bannerViewDidDismissScreen(_ bannerView: GADBannerView) {
    }
}
