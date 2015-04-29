#ifndef ADNINJA
#define ADNINJA

#include "s3eAdNinja.h"
#define AD_DURATION 50000

namespace{

	static bool adShow;

}
class AdNinjaSystem
{
public:

	void init()
	{
		if(s3eAdNinjaAvailable())
		{	s3eAdNinjaStart("b610ab6488704723");
			adShow = true;
			s3eTimerSetTimer(AD_DURATION, &Alarm, NULL);
		}
	}

	static int32 Alarm(void *systemData, void *userData)
	{
		if(adShow)
		{
			adShow = false;
			s3eAdNinjaHide();
			cout<<"\nadHide";
		}
		else
		{
			adShow = true;
			s3eAdNinjaShow();
			cout<<"\nadShow";
		}
		s3eTimerSetTimer(AD_DURATION, &Alarm, NULL);

		return 0;
	}

};

#endif