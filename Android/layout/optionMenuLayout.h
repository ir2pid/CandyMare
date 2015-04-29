#ifndef OPTIONMENULAYOUT_H
#define OPTIONMENULAYOUT_H

#include "click.h"
#include "vibrate.h"

class OptionMenuLayout
{

	int xGap;
	int x[3];
	int y[2];
	int acc;
	CIw2DImage* tMute0;
	CIw2DImage* tMute1;
	CIw2DImage* tVib0;
	CIw2DImage* tVib1;
	CIw2DImage* tInfo;
	CIw2DImage* tQuit;
	
public:

	Click cMute;
	Click cVib;
	Click cInfo;
	Click cQuit;

	void construct()
	{
		acc = 30;
		tMute0 = util.getTexture("menu/speaker0.png");
		tMute1 = util.getTexture("menu/speaker1.png");
		tInfo = util.getTexture("menu/infoicon.png");
		tQuit = util.getTexture("menu/quit.png");
		
		if(s3eVibraGetInt(S3E_VIBRA_ENABLED)==1 && s3eVibraGetInt(S3E_VIBRA_AVAILABLE)==1)
		{
			tVib0 = util.getTexture("menu/vibrate0.png");
			tVib1 = util.getTexture("menu/vibrate1.png");
		}
		else
		{
			tVib0 = util.getTexture("menu/vibrate2.png");
			tVib1 = tVib0;			
		}


		int adjustX = (util.widthDisplay-util.widthGame)/2;
		int adjustY = (util.heightDisplay-util.heightGame)/2;

		xGap = (util.widthGame-(tMute0->GetWidth()*3))/4;
		

		
		x[0] = xGap;
		x[1] = x[0] + xGap + tMute0->GetWidth();
		x[2] = x[1] + xGap + tMute0->GetWidth();

		x[0]+=adjustX;
		x[1]+=adjustX;
		x[2]+=adjustX;
		
		y[0] = (util.heightDisplay-tMute0->GetHeight())/2;
		y[1] = (util.heightDisplay/2)-(tMute0->GetHeight()*3/2);
		//y+=adjustY;



		cMute.construct(x[0],y[0],util.LEFT,util.TOP,"",tMute1,tMute0);
		cInfo.construct(x[1],y[0],util.LEFT,util.TOP,"",tInfo);
		cVib.construct(x[2],y[0],util.LEFT,util.TOP,"",tVib1,tVib0);
		cQuit.construct(x[1],y[1],util.LEFT,util.TOP,"",tQuit);
		
		cMute.x = -tMute0->GetWidth();
		cMute.y = y[0];
		
		cInfo.x = x[1];
		cInfo.y = util.heightDisplay;

		cQuit.x = x[1];
		cQuit.y = -tMute0->GetHeight();
		
		cVib.x = util.widthDisplay;
		cVib.y = y[0];

	}
	
	void update()
	{

		if(cMute.x<x[0])
		{
			cMute.x+=acc;
		}
		else if(cMute.x!= x[0])
		{
			cMute.x = x[0];
		}
		

		
		if(cQuit.y < y[1])
		{
			cQuit.y+=acc;
		}
		else if(cQuit.y != y[1])
		{
			cQuit.y = y[1];
		}

		if(cVib.x > x[2])
		{
			cVib.x-=acc;
		}
		else if(cVib.x!= x[2])
		{
			cVib.x = x[2];
		}
		
		if(cInfo.y > y[0])
		{
			cInfo.y-=acc;
			acc=(float)acc*1.2;
		}
		else if(cInfo.y != y[0])
		{
			cInfo.y = y[0];
		}
	}
	
	void destruct()
	{
		if(tMute0)
		delete tMute0;tMute0=NULL; 
		if(tMute1)
		delete tMute1;tMute1=NULL; 

		if(tVib0 == tVib1)
		{
			if(tVib0)
			delete tVib0;tVib0=NULL; 
		}
		else
		{
			if(tVib0)
			delete tVib0;tVib0=NULL; 
			if(tVib1)
			delete tVib1;tVib1=NULL; 
		}

		if(tInfo)
		delete tInfo;tInfo=NULL; 
		if(tQuit)
		delete tQuit;tQuit=NULL; 

		cMute.destruct();
		cVib.destruct();
		cInfo.destruct();
		cQuit.destruct();
	}

};

#endif