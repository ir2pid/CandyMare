
#ifndef TIMER_H
#define TIMER_H
#include <math.h>

#define MS_PER_FRAME (1000 / 25)

static class Timer
{
	int16 nn;
	int16 ss;
	int16 mm;
	//int16 hh;
	
	int64 initTime;
	int64 curTime;
	int64 start;

public:
	int32 yield;
	char timeStamp[10];

	Timer()
	{
		initTime = s3eTimerGetMs();
		nn = 0;
		ss = 0;
		mm = 0;
		//hh = 0;
	}

	int getTime()
	{
		return ss+(mm*60);
	}
	void reset()
	{
		initTime = s3eTimerGetMs();
		nn = 0;
		ss = 0;
		mm = 0;
		//hh = 0;
	}
	bool FPScontrol(int id)
	{
		if(id == 0)
		{
			start = s3eTimerGetMs();
		}
		else
		{
			//if((s3eTimerGetMs() - start) < MS_PER_FRAME)
			//{
				yield = (int32) (MS_PER_FRAME - (s3eTimerGetMs() - start));
				if (yield<0)
				{
					return false;
					nn+=40;
				}
				else
					return true;
		//	}
		}
	}

	int genTalk(int id)
	{
		if(id == 1)
		{
			return 15+(rand()%45);
		}
		else
		{
			return 15+(rand()%105);
		}
	}

	void addtime()
	{
		if(nn<=960)
		{
			nn+=40;
		}
		else if(ss<59)
		{
			nn = 0;
			ss++;
			sprintf(timeStamp,"%02i:%02i",mm,ss);
		}
		else if(mm<59)
		{
			nn = 0;
			ss = 0;
			mm++;
			sprintf(timeStamp,"%02i:%02i",mm,ss);
		}
		else// if(hh < 59)
		{
			nn = 1000;
			ss = 59;
			mm = 59;
			//hh++;
			sprintf(timeStamp,"59:59");
		}
	}
	/*String getTime()
	{
		char temp[10];
		//char 
		//if(ss<10)

		//sprintf(temp,"%i:%i:"
	}*/
};

#endif