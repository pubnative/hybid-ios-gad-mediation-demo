// For GAD (AdMob) Mediation Rewarded integration, simply just follow GAD's (AdMob's) documentation.
// Google Mobile Ads HyBid Adapters that you've added to the project, will do all the work.
// You don't have to write any HyBid related code for this integration.

import UIKit
import GoogleMobileAds

class Rewarded: UIViewController {

    @IBOutlet weak var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var showAdButton: UIButton!

    private var rewardedAd: GADRewardedAd?
    let adUnitID = "ca-app-pub-8741261465579918/7366717846"

    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "GAD Mediation Rewarded"
    }

    @IBAction func loadAdTouchUpInside(_ sender: UIButton) {
        activityIndicator.startAnimating()
        showAdButton.isHidden = true
        let request = GADRequest()
        GADRewardedAd.load(withAdUnitID:adUnitID,
                               request: request,
                               completionHandler: { [self] ad, error in
                                if let error = error {
                                    print("Failed to load rewarded ad with error: \(error.localizedDescription)")
                                    return
                                }
                                rewardedAd = ad
                                activityIndicator.stopAnimating()
                                showAdButton.isHidden = false
                                rewardedAd?.fullScreenContentDelegate = self
                               }
        )
    }

    @IBAction func showAdTouchUpInside(_ sender: UIButton) {
        if rewardedAd != nil {
            rewardedAd?.present(fromRootViewController: self, userDidEarnRewardHandler: {
                let reward = self.rewardedAd?.adReward
                print("Reward received:\(String(describing: reward))")
            })
        } else {
            print("Ad wasn't ready")
        }
    }
}

extension Rewarded : GADFullScreenContentDelegate {
    func adDidPresentFullScreenContent(_ ad: GADFullScreenPresentingAd) {
    }
    
    func ad(_ ad: GADFullScreenPresentingAd, didFailToPresentFullScreenContentWithError error: Error) {
        activityIndicator.stopAnimating()
    }
    
    func adDidDismissFullScreenContent(_ ad: GADFullScreenPresentingAd) {
        showAdButton.isHidden = true
    }
}
