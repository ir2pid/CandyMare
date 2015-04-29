#ifndef FLURRY_ANALYTICS
#define FLURRY_ANALYTICS

#include "s3eFlurry.h"
#include "iostream.h"
#include <stdlib.h> // for atoi()
#include "s3eOSReadString.h"
#define MAX_CHAR_SIZE 64

class FlurryAnalytics
{

public:

	void construct()
	{
		if(s3eDeviceGetInt (S3E_DEVICE_OS) == S3E_OS_ID_IPHONE)
				s3eFlurryStart("XSICE5ZHF6FPSXC1QGDN");
			else if(s3eDeviceGetInt (S3E_DEVICE_OS) == S3E_OS_ID_ANDROID)
				s3eFlurryStart("7VZZ8G95DZERTQXUXUL4");
		
		s3eFlurrySetSessionReportOnPause(true);
		s3eFlurrySetSessionReportOnClose(true);
		//s3eFlurryLogEvent("Game Duration", true);
	}
	
	void logLevelMove(int level,int move)
	{		
		char EventName[MAX_CHAR_SIZE];
		sprintf(EventName, "level:%d, move:%d",level,move);
		s3eFlurryLogEvent(EventName, false);
	}
	void logLevelStar(int level,int star)
	{		
		char EventName[MAX_CHAR_SIZE];
		sprintf(EventName, "level:%d, star:%d",level,star);
		s3eFlurryLogEvent(EventName, false);
	}
	void logRestartQuit(int level)
	{		
		char EventName[MAX_CHAR_SIZE];
		sprintf(EventName, "restart/quit:%d",level);
		s3eFlurryLogEvent(EventName, false);
	}
	void logLevelStart(int i)
	{//timer start
		char EventName[MAX_CHAR_SIZE];
		sprintf(EventName, "LevelDuration:%d",i);
		s3eFlurryLogEvent(EventName, true);
	}

	void logLevelStop(int i)
	{//timer start
		char EventName[MAX_CHAR_SIZE];
		sprintf(EventName, "LevelDuration:%d",i);
		s3eFlurryEndTimedEvent(EventName);
	}

	void log(char *c)
	{
		s3eFlurryLogEvent(c, false);
	}

	void destruct()
	{
		//s3eFlurryEndTimedEvent("Game Life");;
	}
};
#endif