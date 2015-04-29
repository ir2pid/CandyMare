#ifndef APPLIFIER_SYSTEM
#define APPLIFIER_SYSTEM

#include "ApplifierCrossPromotion.h"

class ApplifierSystem
{
		
public:

	void construct()
	{
		if (ApplifierCrossPromotionAvailable()) 
		{
			 if(s3eDeviceGetInt (S3E_DEVICE_OS) == S3E_OS_ID_IPHONE)
				ApplifierCrossPromotionInitialize("kfpoehaphbdfdnabhcgggggi", false, true, false, false);
			else if(s3eDeviceGetInt (S3E_DEVICE_OS) == S3E_OS_ID_ANDROID)
				ApplifierCrossPromotionInitialize("kfanclaonhnmaliigjgggggh", false, true, false, false);
			//ApplifierCrossPromotionPrepareAnimated(1);
			//ApplifierCrossPromotionPrepareFeaturedGames();
			//ApplifierCrossPromotionPrepareInterstitial();
			//ApplifierCrossPromotionPrepareAnimated(1);
			//ApplifierCrossPromotionPrepareAnimated(2);
			//ApplifierCrossPromotionPrepareAnimated(3);
			//ApplifierCrossPromotionPrepareAnimated(4);
		}
	}
	/*void showAnimated()
	{
		ApplifierCrossPromotionShowAnimated(1);
	}
	void hideAnimated()
	{
	}*/
	void showBanner(int h)
	{
		//if(w <= 960)
		//	ApplifierCrossPromotionShowBanner(1,265);
		//else
			ApplifierCrossPromotionShowBanner(1,h-(h/6));
				

		// Get the devices operating system
		/*int OperatingSystem = s3eDeviceGetInt(S3E_DEVICE_OS);

		// Calculate portal type from OS
		switch (OperatingSystem)
		{
			
			case S3E_OS_ID_IPHONE:
			{	
				if (w <= 480)
				{
					ApplifierCrossPromotionShowBanner(165,265);
					break;
				}
				else if(w <= 960)
				{
					ApplifierCrossPromotionShowBanner(340,300);
					break;
				}
				else
				{
					ApplifierCrossPromotionShowBanner(559,693);
					break;
				}
			}
			default:
			{	
				if (w <= 480)
				{
					ApplifierCrossPromotionShowBanner(165,265);
					break;
				}
				else if(w <= 960)
				{
					ApplifierCrossPromotionShowBanner(340,535);
					break;
				}
				else
				{
					ApplifierCrossPromotionShowBanner(559,693);
					break;
				}
			}

		}		*/
		
	}
	void hideBanner()
	{
		ApplifierCrossPromotionHideBanner();
	}
	/*void showFeatureGames()
	{
		//ApplifierCrossPromotionShowFeaturedGames();
	}
	void showInterstatial()
	{
		//ApplifierCrossPromotionShowInterstitial();
	}
	
	void showAnimated()
	{
		//ApplifierCrossPromotionShowAnimated(1);
		//ApplifierCrossPromotionShowAnimated(2);
		//ApplifierCrossPromotionShowAnimated(3);
		//ApplifierCrossPromotionShowAnimated(4);
	}
	
	void showCustomInterstitial()
	{
		//ApplifierCrossPromotionShowCustomInterstitial();		
	}*/
};

#endif