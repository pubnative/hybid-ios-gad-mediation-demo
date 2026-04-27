// For GAD Mediation Native integration, simply just follow GAD's documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

import UIKit
import GoogleMobileAds

class Native: UIViewController {
    
    @IBOutlet weak var nativeAdContainer: UIView!
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    
    var adLoader: AdLoader!
    var nativeAdView: NativeAdView?
    let adUnitID = "ca-app-pub-8741261465579918/8160924764"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "GAD Mediation Native"
    }
    
    @IBAction func loadAdTouchUpInside(_ sender: UIButton) {
        nativeAdContainer.isHidden = true
        activityIndicator.startAnimating()
        let multipleAdsOptions = MultipleAdsAdLoaderOptions()
        adLoader = AdLoader(adUnitID: adUnitID, rootViewController: self,
                               adTypes: [.native],
                               options: [multipleAdsOptions])
        adLoader.delegate = self
        adLoader.load(Request())
    }
}

extension Native : NativeAdLoaderDelegate {
    func adLoaderDidFinishLoading(_ adLoader: AdLoader) {
        activityIndicator.stopAnimating()
    }
    
    func adLoader(_ adLoader: AdLoader, didReceive nativeAd: NativeAd) {
        let nibView = Bundle.main.loadNibNamed("NativeView", owner: nil, options: nil)?.first
        guard let nativeAdView = nibView as? NativeAdView else {
            return
        }
        self.nativeAdView?.removeFromSuperview()
        self.nativeAdView = nativeAdView
        self.nativeAdView!.frame = nativeAdContainer.bounds
        nativeAdContainer.addSubview(self.nativeAdView!)
        nativeAdContainer.isHidden = false
        
        (nativeAdView.headlineView as? UILabel)?.text = nativeAd.headline
        (nativeAdView.bodyView as? UILabel)?.text = nativeAd.body
        nativeAdView.bodyView?.isHidden = nativeAd.body == nil
        (nativeAdView.callToActionView as? UIButton)?.setTitle(nativeAd.callToAction, for: .normal)
        nativeAdView.callToActionView?.isHidden = nativeAd.callToAction == nil
        nativeAdView.callToActionView?.isUserInteractionEnabled = false
        (nativeAdView.iconView as? UIImageView)?.image = nativeAd.icon?.image
        nativeAdView.iconView?.isHidden = nativeAd.icon == nil
        (nativeAdView.imageView as? UIImageView)?.image = nativeAd.images?.first?.image
        nativeAdView.imageView?.isHidden = nativeAd.images == nil
        nativeAdView.nativeAd = nativeAd
    }
    
    func adLoader(_ adLoader: AdLoader, didFailToReceiveAdWithError error: Error) {
        activityIndicator.stopAnimating()
    }
}
