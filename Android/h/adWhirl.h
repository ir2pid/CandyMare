#ifndef ADWHIRL
#define ADWHIRL
#include "util.h"
//#include "s3eAdWhirl.h"

namespace
{
	const char* g_LastMessage;
	
	bool displayAd;
	bool availableAd;
	
	int adW;
	int adH;

	float GetAdScale()
	{
		// the banners are 320x50 but they may be scaled up depending on the screen size
		float adScale = s3eSurfaceGetInt(S3E_SURFACE_WIDTH) / 320.0f;
		return adScale;
	}

	int32 AdLoad(void* system, void* user)
	{
		availableAd = true;
		g_LastMessage = "`x666666Ad loaded";

		float adScale = s3eSurfaceGetInt(S3E_SURFACE_WIDTH) / 320.0f;
		adW = (int)(320 * adScale);
		adH = (int)(50 * adScale);
		return 0;
	}

	int32 AdFail(void* system, void* user)
	{
		availableAd = false;
		g_LastMessage = "`x666666Ad failed";
		return 0;
	}

	int32 AdFullscreenBegin(void* system, void* user)
	{
		g_LastMessage = "`x666666Fullscreen ad began";
		return 0;
	}

	int32 AdFullscreenEnd(void* system, void* user)
	{
		g_LastMessage = "`x666666Fullscreen ad ended";
		return 0;
	}

	// avoid bringing in conflicting SC++L implementations
	int iabs(int x)
	{
		return x < 0 ? -x : x;
	}
}

class AdWhirl{
	
public:
	void construct()
	{
		g_LastMessage = NULL;
		bool displayAd = true;
		bool availableAd = false;
	
		int adW = 1; 
		int adH = 1; 

		// initialise s3eAdWhirl
		s3eDeviceOSID osid = (s3eDeviceOSID)s3eDeviceGetInt(S3E_DEVICE_OS);
		if (osid == S3E_OS_ID_IPHONE)
		{
			// this ID is specifically made for testing s3eAdWhirl
			// make sure you change this ID to your iPhone app AdWhirl ID when building your own app
			s3eAdWhirlStart("319df3beaa5441eea9ebe5c41f5621cc");
		}
		else if (osid == S3E_OS_ID_ANDROID)
		{
			// this ID is specifically made for testing s3eAdWhirl
			// make sure you change this ID to your Android app AdWhirl ID when building your own app
			s3eAdWhirlStart("052b0e7247e7432db29f8e527a37b509");
		}
		else
		{
			s3eDebugErrorShow(S3E_MESSAGE_CONTINUE, "AdWhirl only works on iOS/Android");
		}

		s3eAdWhirlRegister(S3E_ADWHIRL_CALLBACK_AD_LOAD, &AdLoad, NULL);
		s3eAdWhirlRegister(S3E_ADWHIRL_CALLBACK_AD_FAIL, &AdFail, NULL);
		s3eAdWhirlRegister(S3E_ADWHIRL_CALLBACK_FULLSCREEN_BEGIN, &AdFullscreenBegin, NULL);
		s3eAdWhirlRegister(S3E_ADWHIRL_CALLBACK_FULLSCREEN_END, &AdFullscreenEnd, NULL);
	}

	void destruct()
	{

	}

/*	bool Update()
	{
		if (!s3eAdWhirlAvailable())
			return true;

		return true;
	}
*/
	void showAd()
	{
		if (!displayAd)
		{
			g_LastMessage = "`x666666Showing ad";
			s3eAdWhirlShow();
			displayAd = true;
		}
	}

	void hideAd()
	{
		if (displayAd)
		{
			g_LastMessage = "`x666666Hiding ad";
			s3eAdWhirlHide();
			displayAd = false;
		}
	}

	void refreshAd()
	{
		g_LastMessage = "`x666666Refreshing ad";
		s3eAdWhirlRequestFreshAd();
	}

	void Render()
	{

		/*if (g_LastMessage != NULL)
		{
			s3eDebugPrintf(10, 350, S3E_FALSE, g_LastMessage);
		}

		if (displayAd && availableAd)
		{
			// draw a fake ad for the simulator
			//Iw2DDrawImage( util.pNotificationFrame,CIwSVec2(0,0),  
  //CIwSVec2  size   
 //) 

			//Iw2DDrawRect(CIwSVec2(0, 0),CIwSVec2(adW,adH));
			//s3eDebugPrintf(10, 400, S3E_FALSE, "`x666666Loaded ad...yahoo!");
		}*/

	}
};

#endif