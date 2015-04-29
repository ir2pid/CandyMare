#ifndef IAD_H
#define IAD_H

#include "s3eIOSIAd.h"
#include "util.h"
#define ALARM_DELAY_SHORT 3000
#define ALARM_DELAY_LONG 50000

//bool noIAd;

static int32 Alarm(void *systemData, void *userData)
{
	//cout<<"\nping!";
	if(s3eIOSIAdGetInt(S3E_IOSIAD_BANNER_LOADED))
		s3eIOSIAdSetInt(S3E_IOSIAD_BANNER_SHOW, 1);
	else
		s3eTimerSetTimer(ALARM_DELAY_SHORT, &Alarm, NULL);

	/*if(s3eIOSIAdGetInt(S3E_IOSIAD_RUNNING))//iAd is running
	{
		if(!s3eIOSIAdGetInt(S3E_IOSIAD_BANNER_LOADED))//Banner is not loaded
		{
			noIAd = true;
		}
	}*/

	//s3eTimerSetTimer(ALARM_DELAY_SHORT, &Alarm, NULL);

	//if(noIAd)
		//s3eTimerSetTimer(ALARM_DELAY_LONG, &Alarm, NULL);
	//else
		//s3eTimerSetTimer(ALARM_DELAY_SHORT, &Alarm, NULL);
		
    return 0;
}

class IAd
{
	
public:
	
	IAd()
	{
		s3eIOSIAdStart();
		//noIAd = false;
		s3eTimerSetTimer(ALARM_DELAY_SHORT, &Alarm, NULL);
	}

	void show()
	{
		if(s3eIOSIAdGetInt(S3E_IOSIAD_BANNER_LOADED))
			s3eIOSIAdSetInt(S3E_IOSIAD_BANNER_SHOW, 1);
	}

	void hide()
	{
		s3eIOSIAdSetInt(S3E_IOSIAD_BANNER_SHOW, 0);
	}
	int isShown()
	{
		if(s3eIOSIAdGetInt(S3E_IOSIAD_BANNER_SHOW) && s3eIOSIAdGetInt(S3E_IOSIAD_BANNER_LOADED))
			return s3eIOSIAdGetInt(S3E_IOSIAD_BANNER_HEIGHT);
		else 
			return 0;
	}
	~IAd()
	{
		s3eIOSIAdStop();
	}
};


#endif