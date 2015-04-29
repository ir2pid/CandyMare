#ifndef APPIRATER_SYSTEM_H
#define APPIRATER_SYSTEM_H

#include "s3eAndroidAppirater.h"

class AppiraterSystem
{
public:
	void appiraterInit()
	{
		AppiraterInit("CandyMare","com.noisyninja.candymare",2,10,23);
	}
		
	void appiraterEventOccured()
	{
		AppiraterEventOccured();
	}
};
#endif