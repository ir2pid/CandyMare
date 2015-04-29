#ifndef ADSERVICE_H
#define ADSERVICE_H

// Game headers
#include "IwGameInput.h"
#include "IwGameAds.h"
#include "IwGameAdsView.h"
#include "IwGameAdsViewAnimator.h"
#include "IwGameAdsMediator.h"

// Uncomment ANIMATE_ADS if you want ahimnating ads
#define ANIMATE_ADS

class AdService{
	int yFrame;

	enum AdType{
	SMALL_IOS,
	MEDIUM_IOS,
	LARGE_IOS,
	SMALL_ANDROID,
	MEDIUM_ANDROID,
	LARGE_ANDROID,
	SMALL_DEFAULT,
	MEDIUM_DEFAULT,
	LARGE_DEFAULT
	}adType;

public:
	void construct()
	{
		setPortalType();
		yFrame = (util.pNotificationFrame->GetHeight())/2;
		
		// Initialise the input system
		CIwGameInput::Create();
		IW_GAME_INPUT->Init();

		// Create ad view
		CIwGameAdsView::Create();

		initWithMM_JT();
		
		IW_GAME_ADS_VIEW->setAllowHouseAds(false);
		
		// Set ad request interval in seconds
		IW_GAME_ADS_VIEW->setNewAdInterval(15);

		// Set total number of ads visible in te ads view
		IW_GAME_ADS_VIEW->setNumAdsVisible(1);

		// Tell animators to loop
		IW_GAME_ADS_VIEW->setLooped(true);

		#if !defined(ANIMATE_ADS)
			// Set the ads view position
			IW_GAME_ADS_VIEW->setPosition(0, IwGxGetScreenWidth() / 2, 20);
			//IW_GAME_ADS_VIEW->setPosition(0, 0, 0);
		#elif defined(ANIMATE_ADS)
			// Create and attach an animator that fades the ad in over 1 second, pauses for 7 seconds and then fades the ad back out
			int width = IwGxGetScreenWidth();
			int height = IwGxGetScreenHeight();
			CIwGameAdsViewAnimator* anim = new CIwGameAdsViewAnimator();
			anim->Init();
			anim->setAdViewDataIndex(0);
			anim->setCanvasSize(width, height);
			//anim->setRestingPosition(IwGxGetScreenWidth()/2);
			anim->setInAnim(CIwGameAdsViewAnimator::AnimTopSweepIn, 1200);
			anim->setOutAnim(CIwGameAdsViewAnimator::AnimTopSweepOut, 1200);
			anim->setDissapearDuration(7000);
			//anim->setInAnim(CIwGameAdsViewAnimator::AnimFadeIn, 1000);
			//anim->setOutAnim(CIwGameAdsViewAnimator::AnimFadeOut, 1000);
			anim->setStayDuration(7000);
			IW_GAME_ADS_VIEW->addAnimator(0, anim);

			
		#endif	// ANIMATE_ADS
	}

	void constructHttp()
	{		
		// Init http manager		
		CIwGameHttpManager::Create();
		IW_GAME_HTTP_MANAGER->Init();
	}

	void destructHttp()
	{		
		// Shut down http manager
		IW_GAME_HTTP_MANAGER->Release();
		CIwGameHttpManager::Destroy();
	}

	void initWithMM_JT()
	{
		
		switch(adType)
		{
			case SMALL_IOS:
			case MEDIUM_IOS:
			case LARGE_IOS:
				{
					IW_GAME_ADS_VIEW->Init("73247");
					break;
				}
			case SMALL_DEFAULT:
			case MEDIUM_DEFAULT:
			case LARGE_DEFAULT:
			case SMALL_ANDROID:
			case MEDIUM_ANDROID:
			case LARGE_ANDROID:
				{
					IW_GAME_ADS_VIEW->Init("73409");
					break;
				}
			default:
				{
					IW_GAME_ADS_VIEW->Init("73409");
					
					break;
				}
		}

		// Initialise with Application ID (yuo get this from your ad provider)
		

		// Set ad provider
		IW_GAME_ADS_VIEW->setAdProvider(CIwGameAds::MillennialMedia);
		
		// Force a request for an initial ad
		IW_GAME_ADS_VIEW->RequestNewAd(CIwGameAds::MillennialMedia);
	}
	void initMediators()
	{
		// Create ad mediator and attach it to the ads system
		CIwGameAdsMediator* ad_mediator = new CIwGameAdsMediator();		
		setMillenialMedia(ad_mediator);
		setVserv(ad_mediator);
		setMojiva(ad_mediator);
		setAdFonic(ad_mediator);
		setInnerActive(ad_mediator);
		setJumpTap(ad_mediator);
		

		IW_GAME_ADS->setMediator(ad_mediator);
	}

	
	void update()
	{

		// Update input system
		IW_GAME_INPUT->Update();

		// Update http manager
		if (IW_GAME_HTTP_MANAGER != NULL)
		{
			IW_GAME_HTTP_MANAGER->Update();
		}

		// Update the ads view	
		if (IW_GAME_ADS_VIEW != NULL)
		{
			IW_GAME_ADS_VIEW->Update(1.0f);
			IW_GAME_ADS_VIEW->Draw(util.pNotificationFrame,yFrame);
		}
	}

	void show(bool show)
	{
		IW_GAME_ADS_VIEW->setVisible(show);
	}

	void destruct()
	{
		// Shut down the input system
		IW_GAME_INPUT->Release();
		CIwGameInput::Destroy();

		// Clean up ads system
		IW_GAME_ADS_VIEW->Release();
		CIwGameAdsView::Destroy();
	};
	
	void setPortalType()
	{
		// Get the devices operating system
		int OperatingSystem = s3eDeviceGetInt(S3E_DEVICE_OS);

		// Calculate portal type from OS
		switch (OperatingSystem)
		{
			case S3E_OS_ID_SYMBIAN:
			
			case S3E_OS_ID_WINMOBILE:
			case S3E_OS_ID_WINCE:
			case S3E_OS_ID_QNX:
			case S3E_OS_ID_BADA:
			{	
				if (util.widthGame <= 480)
				{
					adType = SMALL_ANDROID;
					break;
				}
				else if(util.widthGame <= 960)
				{
					adType = MEDIUM_ANDROID;
					break;
				}
				else
				{
					adType = LARGE_ANDROID;
					break;
				}
			}
			case S3E_OS_ID_ANDROID:
			{	
				if (util.widthGame <= 480)
				{
					adType = SMALL_ANDROID;
					break;
				}
				else if(util.widthGame <= 960)
				{
					adType = MEDIUM_ANDROID;
					break;
				}
				else
				{
					adType = LARGE_ANDROID;
					break;
				}
			}
			case S3E_OS_ID_IPHONE:
			{	
				if (util.widthGame <= 480)
				{
					adType = SMALL_IOS;
					break;
				}
				else if(util.widthGame <= 960)
				{
					adType = MEDIUM_IOS;
					break;
				}
				else
				{
					adType = LARGE_IOS;
					break;
				}
			}
			case S3E_OS_ID_WEBOS:
			case S3E_OS_ID_WINDOWS:
			case S3E_OS_ID_LINUX:
			case S3E_OS_ID_WIPI:
			case S3E_OS_ID_NDS:
			case S3E_OS_ID_ARM_SEMIH:
			case S3E_OS_ID_NUCLEUS:
			case S3E_OS_ID_NGI:
			case S3E_OS_ID_SHARPEMP:
			case S3E_OS_ID_OSX:
			case S3E_OS_ID_UIQ:
			case S3E_OS_ID_PS3:
			case S3E_OS_ID_X360:
			case S3E_OS_ID_PSP:
			case S3E_OS_ID_WII:
			default:
			{	
				if (util.widthGame <= 480)
				{
					adType = SMALL_ANDROID;
					break;
				}
				else if(util.widthGame <= 960)
				{
					adType = MEDIUM_ANDROID;
					break;
				}
				else
				{
					adType = LARGE_ANDROID;
					break;
				}
			}

		}

		//cout<<"\n>>>>>>>>>>AD NETWORK TYPE SET AS :"<<adType;
	}
	
	void setInnerActive(CIwGameAdsMediator* ad_mediator)
	{
		// Create inner-active ad party and ad it to the mediator
		CIwGameAdsParty* party = new CIwGameAdsParty();

		switch(adType)
		{
		case SMALL_IOS:
		case MEDIUM_IOS:
		case SMALL_DEFAULT:
		case MEDIUM_DEFAULT:
			{
				party->ApplicationID = "spritegames_CandyMare_iPhone";
				break;
			}
		case LARGE_IOS:
		case LARGE_ANDROID:
		case LARGE_DEFAULT:
			{
				party->ApplicationID = "spritegames_CandyMare_iPad";
				break;
			}
		case SMALL_ANDROID:
		case MEDIUM_ANDROID:
			{	party->ApplicationID = "spritegames_CandyMare_Android";
				break;
			}
		default:
			{
				party->ApplicationID = "spritegames_CandyMare_iPhone";
				break;
			}
		}
		
		party->Provider = CIwGameAds::InnerActive;
		ad_mediator->addAdParty(party);

	}
	
	void setMojiva(CIwGameAdsMediator* ad_mediator)
	{//all uses iphone zoneid, replace when other apps site is up n approved
		// Create inner-active ad party and ad it to the mediator
		CIwGameAdsParty* party = new CIwGameAdsParty();

		switch(adType)
		{
		case SMALL_IOS:
		case MEDIUM_IOS:
		case SMALL_DEFAULT:
		case MEDIUM_DEFAULT:
			{
				party->ApplicationID = "44241";
				break;
			}
		case LARGE_IOS:
		case LARGE_ANDROID:
		case LARGE_DEFAULT:
			{
				party->ApplicationID = "44241";
				break;
			}
		case SMALL_ANDROID:
		case MEDIUM_ANDROID:
			{	party->ApplicationID = "44241";
				break;
			}
		default:
			{
				party->ApplicationID = "44241";
				break;
			}
		}
		
		party->Provider = CIwGameAds::Mojiva;
		ad_mediator->addAdParty(party);

	}


	void setMillenialMedia(CIwGameAdsMediator* ad_mediator)
	{
		// Create inner-active ad party and ad it to the mediator
		CIwGameAdsParty* party = new CIwGameAdsParty();

		switch(adType)
		{
			case SMALL_IOS:
			case MEDIUM_IOS:
			case LARGE_IOS:
				{
					party->ApplicationID = "73209";
					break;
				}
			case SMALL_DEFAULT:
			case MEDIUM_DEFAULT:
			case LARGE_DEFAULT:
				{
					party->ApplicationID = "73209";
					break;
				}
			case SMALL_ANDROID:
			case MEDIUM_ANDROID:
			case LARGE_ANDROID:
				{
					party->ApplicationID = "72979";
					break;
				}
			default:
				{
					party->ApplicationID = "73209";
					break;
				}
		}
		party->Provider = CIwGameAds::MillennialMedia;
		ad_mediator->addAdParty(party);

	}

	
	void setVserv(CIwGameAdsMediator* ad_mediator)
	{		
		// Create inner-active ad party and ad it to the mediator
		CIwGameAdsParty* party = new CIwGameAdsParty();

		switch(adType)
		{
			case SMALL_IOS:
			case MEDIUM_IOS:
			case LARGE_IOS:	
				{
					party->ApplicationID = "3477";
					break;
				}
			case SMALL_DEFAULT:
			case MEDIUM_DEFAULT:
			case LARGE_DEFAULT:
			case SMALL_ANDROID:
			case MEDIUM_ANDROID:
			case LARGE_ANDROID:
			default:
				{
					party->ApplicationID = "3478";
					break;
				}
		}
		party->Provider = CIwGameAds::VServ;
		ad_mediator->addAdParty(party);

	}
	void setAdFonic(CIwGameAdsMediator* ad_mediator)
	{		
		// Create inner-active ad party and ad it to the mediator
		CIwGameAdsParty* party = new CIwGameAdsParty();

		switch(adType)
		{
			case SMALL_IOS:
			case MEDIUM_IOS://300x50
				{
					party->ApplicationID = "265019bb-7f64-4cc1-8dbf-2741056f0ccd";
					break;
				}
			case LARGE_DEFAULT:
			case LARGE_ANDROID:
			case LARGE_IOS://468 x 60
				{
					party->ApplicationID = "5cb5fff1-f3f2-4986-8286-90515cc5de8e";
					break;
				}
			case SMALL_DEFAULT:
			case MEDIUM_DEFAULT:
			case SMALL_ANDROID:
			case MEDIUM_ANDROID://300x50
				{
					party->ApplicationID = "908bbd38-4ce9-4d7a-bfbd-fe00e0af4139";
					break;
				}
			default://300x50
				{
					party->ApplicationID = "265019bb-7f64-4cc1-8dbf-2741056f0ccd";
					break;
				}
		}
		party->Provider = CIwGameAds::AdFonic;
		ad_mediator->addAdParty(party);
	}
	
	void setJumpTap(CIwGameAdsMediator* ad_mediator)
	{
		// Create inner-active ad party and ad it to the mediator
		CIwGameAdsParty* party = new CIwGameAdsParty();

		switch(adType)
		{
			case SMALL_IOS:
			case MEDIUM_IOS:
			case LARGE_IOS:
				{
					party->ApplicationID = "73247";
					break;
				}
			case LARGE_DEFAULT:
			case LARGE_ANDROID:
			case SMALL_DEFAULT:
			case MEDIUM_DEFAULT:
			case SMALL_ANDROID:
			case MEDIUM_ANDROID:
			default://300x50
				{
					party->ApplicationID = "73409";
					break;
				}
		}
		party->Provider = CIwGameAds::MillennialMedia;
		ad_mediator->addAdParty(party);
	}
		
};

#endif