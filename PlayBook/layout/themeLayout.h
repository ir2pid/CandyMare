#ifndef THEMELAYOUT_H
#define THEMELAYOUT_H

#include "sprite.h"

class ThemeLayout
{
	int bgX;
	int bgY;

	int theme1y;
	int theme2y;
	int theme3y;
	int theme4y;
	int theme5y;

public:

	//Sprite bg;
	CIw2DImage* tTh1a;
	CIw2DImage* tTh2a;
	CIw2DImage* tTh3a;
	CIw2DImage* tTh4a;
	CIw2DImage* tTh5a;
	Click cTh1;
	Click cTh2;
	Click cTh3;
	Click cTh4;
	Click cTh5;


	ThemeLayout()
	{
		int len = util.heightGame/5;
		theme1y = 0;
		theme2y = len;
		theme3y = len*2;
		theme4y = len*3;
		theme5y = len*4;
		//if(util.gameRes == util.R480x320)
		{
			/*bg.construct(0,0,util.TOP,util.LEFT);
			bg.setTexture("menu/th1.png");*/
			tTh1a = util.getTexture("theme/th1a.png");
			tTh2a = util.getTexture("theme/th2a.png");
			tTh3a = util.getTexture("theme/th3a.png");
			tTh4a = util.getTexture("theme/th4a.png");
			tTh5a = util.getTexture("theme/th5a.png");

			cTh1.construct(0,theme1y,util.TOP,util.LEFT,"",tTh1a);
			cTh2.construct(0,theme2y,util.TOP,util.LEFT,"",tTh2a);
			cTh3.construct(0,theme3y,util.TOP,util.LEFT,"",tTh3a);
			cTh4.construct(0,theme4y,util.TOP,util.LEFT,"",tTh4a);
			cTh5.construct(0,theme5y,util.TOP,util.LEFT,"",tTh5a);
			
		}
	}

	void destruct()
	{
		cTh1.destruct();
		cTh2.destruct();
		cTh3.destruct();
		cTh4.destruct();
		cTh5.destruct();

		if(tTh1a)
			delete tTh1a;tTh1a = NULL;
		if(tTh2a)
			delete tTh2a;tTh2a = NULL;
		if(tTh3a)
			delete tTh3a;tTh3a = NULL;
		if(tTh4a)
			delete tTh4a;tTh4a = NULL;
		if(tTh5a)
			delete tTh5a;tTh5a = NULL;

	}
	~ThemeLayout()
	{
		
	}
};

#endif