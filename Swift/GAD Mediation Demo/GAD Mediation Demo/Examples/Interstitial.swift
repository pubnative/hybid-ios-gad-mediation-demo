// For GAD Mediation Interstitial integration, simply just follow GAD's documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

import UIKit
import GoogleMobileAds

class Interstitial: UIViewController {
    
    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var showAdButton: UIButton!
    
    private var interstitialAd: InterstitialAd?
    let adUnitID = "ca-app-pub-8741261465579918/1815008264"
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "GAD Mediation Interstitial"
    }
    
    @IBAction func loadAdTouchUpInside(_ sender: UIButton) {
        activityIndicator.startAnimating()
        showAdButton.isHidden = true
        let request = Request()
        InterstitialAd.load(with:adUnitID,
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
            interstitialAd?.present(from: self)
        } else {
            print("Ad wasn't ready")
        }
    }
}

extension Interstitial : FullScreenContentDelegate {
    func adWillPresentFullScreenContent(_ ad: FullScreenPresentingAd) {
        
    }
    
    func ad(_ ad: FullScreenPresentingAd, didFailToPresentFullScreenContentWithError error: Error) {
        activityIndicator.stopAnimating()
    }
    
    func adDidDismissFullScreenContent(_ ad: FullScreenPresentingAd) {
        showAdButton.isHidden = true
    }
}
