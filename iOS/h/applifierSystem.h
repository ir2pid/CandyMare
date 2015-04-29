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
		}
	}
	
	void showBanner(int w)
	{
		if(w <= 960)
			ApplifierCrossPromotionShowBanner(1,265);
		else
			ApplifierCrossPromotionShowBanner(1,650);
			
	}
	void hideBanner()
	{
		ApplifierCrossPromotionHideBanner();
	}
	
};

#endif