#ifndef FEED_H
#define FEED_H
#include "IwGameFile.h"
#include "IwGameString.h"
#include "../h/NotificationSystem.h"
namespace{

	
	int32 WebFileRetrievedCallback(void* caller, void* data)
	{
		CIwGameString str;
		CIwGameFile* file = (CIwGameFile*)caller;
		int len = file->getContentLength();
		if(len == -1)
		{//no network

			return 0;
		}
		str.allocString(len);
		str.setLength(len);

		CIwGameFile fileW;
		file->Read((void*)str.c_str(), len);
		if(str.GetLength() > 500 )
		{//blank feed
			s3eFileDelete("feed.bin");

			return 0;
		}
		
		if (fileW.Open("feed.bin", "wb"))
		{
			fileW.Write((void*)str.c_str(),str.GetLength());
			fileW.Close();
		}		


		return 0;
	}

}

class Feed{

	CIwGameFile* fileIO;
	char* text;
public:
	void pushFeed()
	{
		/*char TempString[S3E_CONFIG_STRING_MAX+8] = {'\0'};

		s3eConfigGetString("feed", "broadcast", TempString);
		notificationSystem.pushFeed(TempString);*/
		
		IwRandSeed(s3eTimerGetUTC());

		if(IwRandRange(5) != 1)
			return;
		// Here we declare a string, open a file then read some data into it
		CIwGameString data;
		CIwGameFile file;
		if (file.Open("feed.bin", "r"))
		{
			int len = file.getFileSize();

			data.allocString(len);
			data.setLength(len);
			file.Read((void*)data.c_str(), len);
			file.Close();
			if(text != NULL)
				delete text;text = NULL;
			text = new char[len+1];
			strlcpy(text,(char*)data.c_str(),len+1);
			notificationSystem.pushFeed(text);
		}		
	}
	
	void initFeed()
	{
		text = NULL;
		int urlID = 0;
		fileIO = new CIwGameFile();
		fileIO->setFileAvailableCallback(WebFileRetrievedCallback, NULL);
		char *url[10];
		url[0] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/iOSfeed.txt";
		url[1] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/androidfeed.txt";
		url[2] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/badafeed.txt";
		url[3] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/playbookfeed.txt";
		url[4] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/symbianfeed.txt";
		url[5] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/winmobilefeed.txt";
		url[6] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/webosfeed.txt";
		url[7] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/desktopfeed.txt";
		url[8] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/consolefeed.txt";
		url[9] = "http://dl.dropbox.com/u/19489672/CandyMare/feed/unknownfeed.txt";

		// Get the devices operating system
	int32 OperatingSystem = s3eDeviceGetInt(S3E_DEVICE_OS);

	// Calculate portal type from OS
	switch (OperatingSystem)
	{
	case S3E_OS_ID_IPHONE:
		{
			urlID = 0;
			break;
		}
	case S3E_OS_ID_ANDROID:
		{
			urlID = 1;
			break;
		}
	case S3E_OS_ID_BADA:
		{
			urlID = 2;
			break;
		}
	case S3E_OS_ID_QNX:
		{
			urlID = 3;
			break;
		}
	case S3E_OS_ID_SYMBIAN:
		{
			urlID = 4;
			break;
		}
				
	case S3E_OS_ID_WINCE:
	case S3E_OS_ID_WINMOBILE:
		{
			urlID = 5;
			break;
		}
				
	case S3E_OS_ID_WEBOS:
		{
			urlID = 6;
			break;
		}
		
	case S3E_OS_ID_WINDOWS:
	case S3E_OS_ID_OSX:
	case S3E_OS_ID_LINUX:
		{
			urlID = 7;
			break;
		}

	case S3E_OS_ID_WIPI:
	case S3E_OS_ID_NDS:
	case S3E_OS_ID_ARM_SEMIH:
	case S3E_OS_ID_NUCLEUS:
	case S3E_OS_ID_NGI:
	case S3E_OS_ID_SHARPEMP:
	case S3E_OS_ID_UIQ:
	case S3E_OS_ID_PS3:
	case S3E_OS_ID_X360:
	case S3E_OS_ID_PSP:
	case S3E_OS_ID_WII:
		{
			urlID = 8;
			break;
		}
	default:
		{
			urlID = 9;
			break;
		}
		break;
	}

		fileIO->Open(url[urlID], NULL, false);

	}

	void destruct()
	{//not needed
		if(text !=NULL)
			delete text;text = NULL;
		if(fileIO != NULL)
		{			
			fileIO->Close();
			delete fileIO;fileIO = NULL;
		}
	}
}feed;
#endif