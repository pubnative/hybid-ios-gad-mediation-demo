// For GAD (AdMob) Mediation Interstitial integration, simply just follow GAD's (AdMob's) documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

import UIKit
import GoogleMobileAds

class Interstitial: UIViewController {
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var showAdButton: UIButton!
    
    private var interstitialAd: GADInterstitialAd?
    let adUnitID = "ca-app-pub-8741261465579918/1815008264"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "GAD Mediation Interstitial"
    }
    
    @IBAction func loadAdTouchUpInside(_ sender: UIButton) {
        activityIndicator.startAnimating()
        showAdButton.isHidden = true
        let request = GADRequest()
        GADInterstitialAd.load(withAdUnitID:adUnitID,
                               request: request,
                               completionHandler: { [self] ad, error in
                                if let error = error {
                                    print("Failed to load interstitial ad with error: \(error.localizedDescription)")
                                    return
                                }
                                interstitialAd = ad
                                activityIndicator.stopAnimating()
                                showAdButton.isHidden = false
                                interstitialAd?.fullScreenContentDelegate = self
                               }
        )
    }
    
    @IBAction func showAdTouchUpInside(_ sender: UIButton) {
        if interstitialAd != nil {
            interstitialAd?.present(fromRootViewController: self)
        } else {
            print("Ad wasn't ready")
        }
    }
}

extension Interstitial : GADFullScreenContentDelegate {
    func adWillPresentFullScreenContent(_ ad: GADFullScreenPresentingAd) {
        
    }
    
    func ad(_ ad: GADFullScreenPresentingAd, didFailToPresentFullScreenContentWithError error: Error) {
        activityIndicator.stopAnimating()
    }
    
    func adDidDismissFullScreenContent(_ ad: GADFullScreenPresentingAd) {
        showAdButton.isHidden = true
    }
}
