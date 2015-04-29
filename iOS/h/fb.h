#ifndef FB_H
#define FB_H

#include "IwGameFacebook.h"

class FB{
//CandyMare
//App ID: 	249307571821667
//App Secret: 	2218afbad77b348b3ca0313474e42de4(reset) 
public:
	void construct()
	{
		CIwGameFacebook::Create();
		IW_GAME_FACEBOOK->Init();
		IW_GAME_FACEBOOK->setAppID("249307571821667"); // Put your Facebook apps API_KEY here
	}
	void post(int level,int stars,int moves)
	{//completed level x with y stars in z moves at CandyMare
			if (IW_GAME_FACEBOOK == NULL)
			{
				construct();
			}

			if (IW_GAME_FACEBOOK->isAvailable())
			{
				char tmp[50];
				sprintf(tmp,"%d with %d stars in %d",level,stars,moves);

				CIwGameString message = "CandyMare Achivement! \nI just completed level ";
				message += tmp;
				message += "  moves at CandyMare.";

				if (s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_ANDROID)
					IW_GAME_FACEBOOK->PostWall(message.c_str(),"http://noisyninja.co.cc", "http://dl.dropbox.com/u/19489672/fb135.png", "CandyMare Android", "Get the game for free on your Android phone today!");
				else
				if (s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_IPHONE)
					IW_GAME_FACEBOOK->PostWall(message.c_str(), "http://noisyninja.co.cc", "http://dl.dropbox.com/u/19489672/fb135.png", "CandyMare iOS", "Get the game for free on your iPhone, iPad and iPod Touch today!");
			}
			else
			{
				s3eDebugErrorShow(S3E_MESSAGE_CONTINUE, "Cannot find any Facebook extension to post your achivemment.\nYou can write to us with Phone/Tab model and OS so we can add facebook support.");
				//cout<<"facebook unavailable";
			}
	}

	void destruct()
	{
		if (IW_GAME_FACEBOOK != NULL)
		{
			IW_GAME_FACEBOOK->Release();
			CIwGameFacebook::Destroy();
		}
	}
};

#endif