#ifndef GAMEMENULAYOUT_H
#define GAMEMENULAYOUT_H

#include "click.h"

class GameMenuLayout
{
	int xGap;
	int x[3];
	int y;
	
	CIw2DImage* tReset;
	CIw2DImage* tQuit;
	CIw2DImage* tResume;


public:

	Click cReset;
	Click cQuit;
	Click cResume;

	void construct()
	{
		tReset = util.getTexture("menu/reset.png");
		tQuit = util.getTexture("menu/quit.png");
		tResume = util.getTexture("menu/resume.png");
		
		int adjustX = (util.widthDisplay-util.widthGame)/2;
		int adjustY = (util.heightDisplay-util.heightGame)/2;

		xGap = (util.widthGame-(tReset->GetWidth()*3))/4;
		

		
		x[0] = xGap;
		x[1] = x[0] + xGap + tReset->GetWidth();
		x[2] = x[1] + xGap + tReset->GetWidth();

		x[0]+=adjustX;
		x[1]+=adjustX;
		x[2]+=adjustX;
		
		y = (util.heightDisplay-tReset->GetHeight())/2;
		//y+=adjustY;

		cQuit.construct(x[0],y,util.LEFT,util.TOP,"",tQuit);
		cReset.construct(x[1],y,util.LEFT,util.TOP,"",tReset);
		cResume.construct(x[2],y,util.LEFT,util.TOP,"",tResume);
		//cQuit.setTexture(tQuit,tQuit);
		cQuit.x = -tReset->GetWidth();
		cQuit.y = y;
		
		//cResume.setTexture(tResume,tResume);
		cResume.x = util.widthDisplay;
		cResume.y = y;

		//cReset.setTexture(tReset,tReset);
		cReset.x = x[1];
		cReset.y = -tReset->GetHeight();

	}

	void update()
	{
		//y++;
		if(cQuit.x<x[0])
		{
			cQuit.x+=30;
		}
		else if(cQuit.x>x[0])
		{
			cQuit.x = x[0];
		}
		
		if(cResume.x > x[2])
		{
			cResume.x-=30;
		}
		else if(cResume.x>x[2])
		{
			cResume.x = x[2];
		}

		if(cReset.y < y)
		{
			cReset.y+=30;
		}
		else if(cReset.y > y)
		{
			cReset.y = y;
		}
		
	}
	
	void quit()
	{
		AchivementSystem as;
		as.getQuits(storage.userData.achivement.quitter);
		storage.userData.achivement.quitter++;
		storage.saveStorage();
	}

	void destruct()
	{
		if(tReset)
		delete tReset;tReset=NULL; 
		if(tQuit)
		delete tQuit;tQuit=NULL; 
		if(tResume)
		delete tResume;tResume=NULL; 

		cQuit.destruct();
		cReset.destruct();
		cResume.destruct();
	}
};

#endif