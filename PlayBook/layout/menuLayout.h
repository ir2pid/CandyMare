#ifndef MENULAYOUT_H
#define MENULAYOUT_H

#include "sprite.h"
#include "click.h"
#include "crow.h"
#include "s3eOSExec.h"

#include "optionMenuLayout.h"
#include "InfoLayout.h"
#include "notificationSystem.h"

class MenuLayout
{
	int bgX;
	int bgY;

public:
	Crow crow;

	CIw2DImage* tBg;

	CIw2DImage* tLogo;
	CIw2DImage* tPlay;
	CIw2DImage* tOption;
	CIw2DImage* tTrophy;
	CIw2DImage* tCrow;
	//CIw2DImage* tCart;
	CIw2DImage* tFb0;
	CIw2DImage* tTw0;
	CIw2DImage* tzap;

	Sprite sBg;
	Sprite sLogo;
	 
	Click cPlay;
	Click cOption;
	Click cTrophy;
	//Click cCart;
	Click cFb;
	Click cTw;
	
	OptionMenuLayout *optionMenuLayout;
	InfoLayout *infoLayout;
	bool showSocial;
	char *completeTag;

	void construct()
	{
		infoLayout = NULL;
		optionMenuLayout = NULL;
		completeTag = NULL;
		//sprintf(completeTag,"0.0%% Completed");
		//
		switch(storage.userData.currTheme)
		{
		case 1:
			tBg = util.getBGTexture("menu/home1.jpg");
			break;
		case 2:
			tBg = util.getBGTexture("menu/home2.jpg");
			break;
		case 3:
			tBg = util.getBGTexture("menu/home3.jpg");
			break;
		default:
			tBg = util.getBGTexture("menu/home1.jpg");
		}
		//tBg = util.getTexture("menu/bg1.png");
		tLogo = util.getTexture("menu/logo.png");
		tPlay = util.getTexture("menu/play.png");
		tOption = util.getTexture("menu/option.png");
		tTrophy = util.getTexture("menu/trophy.png");
		//tCart = util.getTexture("menu/cart.png");
		tCrow = util.getTexture("fx/bat/bat.png");
		tFb0 = util.getTexture("menu/fb0.png");
		tTw0 = util.getTexture("menu/tw0.png");

		crow.init(tCrow);
		sBg.construct(0,0,util.LEFT,util.TOP,tBg);

		sLogo.construct(tFb0->GetWidth(),10,util.LEFT,util.TOP,tLogo);
		//bg.setTexture("menu/th1.png");
		int x[3];
		x[0] = tPlay->GetWidth();
		x[1] = x[0]+tPlay->GetHeight();
		x[2] = x[1]+tPlay->GetHeight();
		cPlay.constructRaw(-tPlay->GetWidth(),x[0],util.RIGHT,util.TOP,"",tPlay);
		cOption.constructRaw(-tPlay->GetWidth(),x[1],util.RIGHT,util.TOP,"",tOption);
		cTrophy.constructRaw(-tPlay->GetWidth(),x[2],util.RIGHT,util.TOP,"",tTrophy);
		//cCart.constructRaw(-tCart->GetWidth(),0,util.RIGHT,util.TOP,"",tCart);
		
		int fbx = 0;
		int fby = 0;//-tFb0->GetHeight();
		int twy = tFb0->GetWidth()+(2*util.em);
		int twx = 0;//-tTw0->GetHeight();
		int zapy = twy *2;
		int zapx = 0;
		
		if(s3eOSExecAvailable())
			showSocial = true;
		else
			showSocial = false;

		if(showSocial)
		{
			cTw.constructRaw(twx,twy,util.LEFT,util.TOP,"",tTw0);
			cFb.constructRaw(fbx,fby,util.LEFT,util.TOP,"",tFb0);
		}
		

		setCompleteTag();
	}

	void renderBG()
	{
		sBg.renderBG(CIwSVec2(util.widthDisplay,util.heightDisplay));
	}

	void setCompleteTag()
	{
		if(completeTag != NULL)
				delete completeTag;completeTag = NULL;

		//memset(completeTag,0,20);
		int tstars=0;
		for(int i=0;i<60;i++)
		{
			tstars+=storage.userData.sStar[i];
		}
		int tlevels = ((storage.userData.sTheme-1)*20)+storage.userData.sLevel-1;

		int tot = tstars + tlevels;

		completeTag = new char[18];

		sprintf(completeTag,"%3.1f%% completed",((float)tot*100.0f)/240.0f);

		notificationSystem.pushFeed(completeTag);
	} 

	void renderLogo()
	{
		IwRandSeed((int32)s3eTimerGetMs());
		
		switch(IwRandMinMax(1,5))
		{
			case 1:{
				sLogo.render((int8)-util.em,(int8)util.em);
				break;
				   }
			case 2:{
				sLogo.render((int8)util.em,(int8)util.em);
				break;
				   }
			case 3:{
				sLogo.render((int8)-util.em,(int8)-util.em);
				break;
				   }
			case 4:{
				sLogo.render((int8)util.em,(int8)-util.em);
				break;
				   }
		}
		Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
		switch(IwRandMinMax(1,5))
		{
			case 1:{
				sLogo.render((int8)-1,(int8)1);
				break;
				   }
			case 2:{
				sLogo.render((int8)1,(int8)1);
				break;
				   }
			case 3:{
				sLogo.render((int8)-1,(int8)-1);
				break;
				   }
			case 4:{
				sLogo.render((int8)1,(int8)-1);
				break;
				   }
		}
		
		Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		
	}
	//==
	void constructOptionMenuLayout()
	{
		optionMenuLayout = new OptionMenuLayout();
	}
	//==
	void destructOptionMenuLayout()
	{
		optionMenuLayout->destruct();
		delete optionMenuLayout;optionMenuLayout = NULL;
	}	
	//==
	//==
	void constructInfoLayout()
	{
		infoLayout = new InfoLayout();
	}
	//==
	void destructInfoLayout()
	{
		infoLayout->destruct();
		delete infoLayout;infoLayout = NULL;
	}	
	//==
	
		
	void destruct()
	{
		
		if(completeTag != NULL)
				delete completeTag;completeTag = NULL;

		if(infoLayout!=NULL)
			infoLayout->destruct();
		delete infoLayout;infoLayout = NULL;

		if(optionMenuLayout!=NULL)
			optionMenuLayout->destruct();
		delete optionMenuLayout;optionMenuLayout = NULL;

		cPlay.destruct();
		cOption.destruct();
		cTrophy.destruct();
		//cCart.destruct();


		cTw.destruct();
		cFb.destruct();
		
		if(tFb0)
			delete tFb0;tFb0 = NULL;


		if(tTw0)
			delete tTw0;tTw0 = NULL;

		
		if(tCrow)
			delete tCrow;tCrow = NULL;

		
		if(tBg)
			delete tBg;tBg = NULL;


		if(tLogo)
			delete tLogo;tLogo = NULL;


		if(tPlay)
			delete tPlay;tPlay = NULL;
		
		if(tOption)
			delete tOption;tOption = NULL;

		if(tTrophy)
			delete tTrophy;tTrophy = NULL;

		
		//bg.destruct();
	}

	~MenuLayout()
	{
		
	}
	
	inline void toFb()
	{
		s3eOSExecExecute("http://www.facebook.com/CandyMareApp", S3E_FALSE);
	}
	
	inline void toTw()
	{
		s3eOSExecExecute("https://twitter.com/#!/iCandyMare", S3E_FALSE);		
	}
};

#endif