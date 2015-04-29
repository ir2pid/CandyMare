#ifndef GAMELAYOUT_H
#define GAMELAYOUT_H

#include "sprite.h"
#include "Level.h"
#include "effect.h"
//#include "titbit.h"
//#include "gameitems.h"
#include "gameobjects.h"
#include "Storage.h"
#include "../h/NotificationSystem.h"
#include "../h/achivementSystem.h"

#include "gameMenuLayout.h"



void TransformAndLight(CIwSVec2* v, CIwColour* c, int32 numberPoints);
void RippleFunc(CIwSVec2* v, CIwColour* c, int32 points);

// The centre of the effect
CIwSVec2 g_EffectCentre;


class GameLayout
{
	
public:
	int16 talkAnchor[7];
	CIwSVec2 talkRegion;
	int talkImg;
	//CIw2DImage *pCanvas;
	int16 bgX;
	int16 bgY;
	int16 barHeight;
	/*int barAnchorX;
	int barMoveAnchorY;
	int barMenuAnchorY;
	int barHeight;*/
	int16 trayX;
	int16 trayY;
	int16 wTray;
	int16 hTray;

	float starScale[3];
	int16 starX[3];
	int16 starY;
	int16 trackX;
	int16 trackY;
	
	
	Sprite sHalo;
	Sprite sCandy;
	//Sprite sTray;
	Sprite spStar;
	Sprite spStar0;
	Sprite sTrack;
	Sprite spDone;
	//GameItems gItems;
	GameObjects gObj;
	//bool isStarred;
	//Click cStar[3]; 
	Click cBack;
	
	CIw2DImage* tHalo;
	CIw2DImage* tCandy;

	CIw2DImage* tBlock[50];
	//CIw2DImage* tTray;
	CIw2DImage* tBack;

	//particlesys
	CIw2DImage* tpStar;
	//CIw2DImage* tFinish;
	CIw2DImage* tToxic;
	CIw2DImage* tRhombus;

	CIw2DImage* tStar;
	CIw2DImage* tShroomEvil;
	CIw2DImage* tShroomGood;
	CIw2DImage* tOrangePortal;
	CIw2DImage* tBluePortal;

	
	CIw2DImage* tStatusStar0;
	CIw2DImage* tStatusStar;
	CIw2DImage* tTrack;
	
	CIw2DImage* tDone;

	s3eThread* animate_thread;
	GameMenuLayout *gameMenuLayout;

	bool isComplete;
	bool isIntoxicated;
	bool isMoved;

	GameLayout()
	{		
		isMoved = false;
		isComplete = false;
		isIntoxicated = false;
		gameMenuLayout = NULL;
		talkImg = 0;
		talkRegion.x = util.BLOCKSIZE*2;
		talkRegion.y = util.BLOCKSIZE;
		for(int i=0;i<7;i++)
			talkAnchor[i] = util.BLOCKSIZE*2*i;

		starScale[0] = 0.0f;
		starScale[1] = 0.0f;
		starScale[2] = 0.0f;
		tToxic = NULL;
		tShroomEvil = NULL;
		tShroomGood = NULL;
		tOrangePortal = NULL;
		tBluePortal = NULL;
		tpStar = NULL;
		tStar = NULL;
		//tFinish = NULL;
		tRhombus = NULL;
		tStatusStar = NULL;
		tStatusStar0 = NULL;
		for(int i=0;i<10;i++)
		{
			storage.sStarDump[i]=0;
		}
		tDone = util.getTexture("menu/done.png");
		tBack = util.getTexture("menu/menu.png");
		tStatusStar = util.getTexture("fx/fstar.png");
		tStatusStar0 = util.getTexture("fx/fstar0.png");
		tTrack = util.getTexture("menu/track.png");
		
		barHeight = 23.0f*util.em;
		int16 centerx = (util.widthGame-tDone->GetWidth())/2;
		int16 centery = (util.heightGame-tDone->GetHeight())/2;
		spDone.constructRaw(centerx,centery,util.LEFT,util.TOP,tDone);
		
		int adjustX = (util.widthDisplay-util.widthGame)/2;
		int adjustY = (util.heightDisplay-util.heightGame)/2;

		starY = adjustY+5*util.em;
		
		starX[0] = adjustX+(10*util.em);
		starX[1] = starX[0]+tStatusStar->GetWidth()+(5*util.em);
		starX[2] = starX[1]+tStatusStar->GetWidth()+(5*util.em);

		trackX = starX[2]+tStatusStar->GetWidth()+(5*util.em)-adjustX;
		trackY = 5*util.em+((tStatusStar->GetHeight()-tTrack->GetHeight())/2);
		
		sTrack.constructRaw(trackX,trackY,util.LEFT,util.TOP,tTrack);

		trackX=trackX+(tTrack->GetWidth())+(5*util.em)+adjustX;
		
		trackY = starY + tStatusStar->GetHeight() - font.AllerXL->GetHeight();
		
		spStar.constructRaw(starX[0],starY,util.LEFT,util.TOP,tStatusStar);
		spStar0.constructRaw(starX[0],starY,util.LEFT,util.TOP,tStatusStar0);
		
		gObj.setAdjustValues(adjustX,adjustY);
		gObj.setStarCord(starY+(tStatusStar->GetHeight()/2),starX[0]+(tStatusStar->GetWidth()/2),starX[1]+(tStatusStar->GetWidth()/2),starX[2]+(tStatusStar->GetWidth()/3));
		cBack.constructRaw(-tBack->GetWidth(),0,util.RIGHT,util.TOP,"",tBack);
		
		int w = util.widthGame;
		int h = util.heightGame;

		wTray = 9*util.BLOCKSIZE;
		hTray = 5*util.BLOCKSIZE;

		trayX = adjustX+(w - wTray)/2;
		trayY = adjustY+((h - hTray)/2)+barHeight;

		for(int i=0;i<50;i++)
		{
			tBlock[i] = NULL;
		}
	}

	void renderStar()
	{
		sTrack.render();
		char tmp[10];
		sprintf(tmp,"%d/%d",storage.sStarDump[1],storage.sStarDump[2]);
		
		Iw2DSetFont(font.AllerXL);
		Iw2DSetColour(0xff000000);
			Iw2DDrawString(tmp,CIwSVec2(trackX-1,trackY+1),CIwSVec2(util.widthGame,font.AllerXL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);	
			Iw2DDrawString(tmp,CIwSVec2(trackX-1,trackY-1),CIwSVec2(util.widthGame,font.AllerXL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
			Iw2DDrawString(tmp,CIwSVec2(trackX+1,trackY+1),CIwSVec2(util.widthGame,font.AllerXL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
			Iw2DDrawString(tmp,CIwSVec2(trackX+1,trackY-1),CIwSVec2(util.widthGame,font.AllerXL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		
		Iw2DSetColour(util.COLOR[0]);
		Iw2DDrawString(tmp,CIwSVec2(trackX,trackY),CIwSVec2(util.widthGame,font.AllerXL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		//Iw2DSetColour(util.COLOR[0]);

		if(gObj.starAchived==0)
		{
			spStar0.render(starX[0],starY);
			spStar0.render(starX[1],starY);
			spStar0.render(starX[2],starY);
			return;
		}
		else if(gObj.starAchived==1)
		{
			spStar.render(starX[0],starY,starScale[0]);
			spStar0.render(starX[1],starY);
			spStar0.render(starX[2],starY);
			return;
		}
		else if(gObj.starAchived==2)
		{
			spStar.render(starX[0],starY,starScale[0]);
			spStar.render(starX[1],starY,starScale[1]);
			spStar0.render(starX[2],starY);
			return;
		}
		else if(gObj.starAchived==3)
		{
			spStar.render(starX[0],starY,starScale[0]);
			spStar.render(starX[1],starY,starScale[1]);
			spStar.render(starX[2],starY,starScale[2]);
			return;
		}
	}

	CIw2DImage* loadTexture(int type)
	{
		if(type < 3)
		{
			if(tStar == NULL)
				tStar = util.getTexture("fx/gstar.png");
			if(tpStar == NULL)
				tpStar = util.getTexture("fx/star.png");
			if(tRhombus == NULL)
				tRhombus = util.getTexture("fx/rhombus.png");
			
			return tStar;
		}
		if(type == 3)
		{//mandatory hence particle loaded too
			if(tShroomEvil == NULL)
				tShroomEvil = util.getTexture("fx/evilshroom.png");
			if(tToxic == NULL)
				tToxic = util.getTexture("fx/toxic.png");
			return tShroomEvil;
		}
		else if(type == 4)
		{
			if(tShroomGood == NULL)
				tShroomGood = util.getTexture("fx/goodshroom.png");
			return tShroomGood;
		}
		else if(type == 5)
		{
			if(tOrangePortal == NULL)
				tOrangePortal = util.getTexture("fx/orange.png");
			return tOrangePortal;
		}
		else if(type == 6)
		{
			if(tBluePortal == NULL)
				tBluePortal = util.getTexture("fx/blue.png");
			return tBluePortal;
		}
	}

	void makeUnit(int t,int i,int j)
	{
		gObj.makeUnit(loadTexture(t),t,i,j,trayX-((util.widthDisplay-util.widthGame)/2),trayY-((util.heightDisplay-util.heightGame)/2));
		switch(t)
		{
		case 0:
		case 1:
		case 2:{
			gObj.setParticle(t,tpStar);
			gObj.setParticle(7,tRhombus);
			   break;
			   }
		case 3:
		case 4:{
			gObj.setParticle(t,tToxic);
			break;
			   }
		case 5:
		case 6:{
			//gObj.s
			}
		}
	}

	
	//to be depricated
	
	/*void constructStar(int x1,int y1,int x2,int y2,int x3,int y3)
	{
		gItems.initStar(trayX,trayY,x1,y1,x2,y2,x3,y3,tStar);
	}

	

	void constructShroom(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int type1,int type2,int type3,int type4)
	{
		gItems.initShroom(trayX,trayY,x1,y1,x2,y2,x3,y3,x4,y4,type1,type2,type3,type4,tShroomEvil,tShroomGood);
	}*/

	/*void constructTray()
	{
		char tmp[50];
		sprintf(tmp,"%d_%d.bmp",storage.userData.currTheme,storage.userData.currLevel);

		tTray = util.getTempTexture(tmp);
		//sTray.construct(trayX,trayY,util.LEFT,util.TOP,tTray);
		sTray.construct(-(util.widthDisplay/2),-(util.heightDisplay/2),util.CENTER,util.MIDDLE,tTray);
	}*/

	void constructCandy(int x,int y)
	{
		IwRandSeed((int32)s3eTimerGetMs()+x+y);
		int cID = IwRandMinMax(1,20);

		char tmp[50];
		sprintf(tmp,"village/candies/c%d.png",cID);

		tCandy = util.getTexture(tmp);

		//sCandy.constructRaw(x-(util.BLOCKSIZE/2),y-(util.BLOCKSIZE/2),util.LEFT,util.TOP,tCandy);
		sCandy.constructRaw(x+(util.BLOCKSIZE)-(tCandy->GetWidth()/2),y+(util.BLOCKSIZE/2)-(tCandy->GetHeight()/2),util.LEFT,util.TOP,tCandy);
		//cout<<x-(util.BLOCKSIZE/2)<<", "<<y-(util.BLOCKSIZE/2);
	}
	
	void constructHalo(int x,int y)
	{
		tHalo = util.getTexture("village/halo.png");

		sHalo.constructRaw(x,y-(util.BLOCKSIZE/2),util.LEFT,util.TOP,tHalo);
	}

	void renderToxicInit()
	{
		util.g_Frame++;

		const uint32 c_RegionSize = 32;

		//Calculate the top left of the logo
		//Offset by half a rectangle width so the rectangles are centred on the calculate points
		CIwSVec2 centre = CIwSVec2((int16)Iw2DGetSurfaceWidth() / 2, (int16)Iw2DGetSurfaceHeight() / 2);

		//Calculate the centre of the effect (it rotates around the edge of the screen as time passes)
		iwfixed angle = util.g_Frame*IW_FIXED(0.01);
		g_EffectCentre = CIwSVec2((int16)IwGeomSin(angle), (int16)IwGeomCos(angle)) * (Iw2DGetSurfaceWidth()/2) + CIwSVec2(util.widthDisplay/2,util.heightDisplay/2);

		//The input to the post-transform is in sub pixels (at 8x size)
		g_EffectCentre <<= 3;

		//Set the post transform function
		Iw2DSetPostTransformFn(TransformAndLight);
		//Iw2DSetPostTransformFn(RippleFunc);

	}

	void renderToxicEnd()
	{
		//Clear the post-transformation
		Iw2DSetPostTransformFn(NULL);
	}
	
	void renderRippleInit()
	{
		for(int i=0;i<gObj.rippleSystem.size();i++)
		{
			util.g_Frame+=(10*util.em);
			CIwSVec2 centre;
			centre.x = gObj.rippleSystem[i].x;
			centre.y = gObj.rippleSystem[i].y;
			
			g_EffectCentre = (centre * IW_FIXED(util.g_Frame));

			
			Iw2DSetPostTransformFn(RippleFunc);

			if(gObj.rippleSystem[i].life < 0)
			{
				gObj.rippleSystem.erase(i);
				util.g_Frame=0;
			}
			else
			{
				gObj.rippleSystem[i].life--;
			}
		}
	}

	void renderRippleEnd()
	{
		//Clear the post-transformation
		Iw2DSetPostTransformFn(NULL);
	}

	void constructHyptonizeHero()
	{
		talkImg = true;
	}

	void calculateAchivement(int level)
	{
		
		AchivementSystem as;
		as.getAchivements(storage.userData.achivement.globeTrotter,
			storage.userData.achivement.globeTrotter+storage.sStarDump[1],
			storage.userData.achivement.starCrazy,
			storage.userData.achivement.starCrazy+storage.sStarDump[0],
			storage.userData.achivement.rejectStar,
			storage.userData.achivement.rejectStar+3-storage.sStarDump[0],
			storage.userData.achivement.junkie,
			storage.userData.achivement.junkie+storage.sStarDump[4],
			storage.userData.achivement.medic,
			storage.userData.achivement.medic+storage.sStarDump[5],
			storage.userData.achivement.CaptainKirk,
			storage.userData.achivement.CaptainKirk+storage.sStarDump[3],
			storage.userData.achivement.toxicFinishes,
			isIntoxicated

		);

		CIwArray<int> leftovers = gObj.getLeftOvers();
		if(leftovers.size()>0)
		{
			//=========================
			bool check = false;//check for toxic shroom left
			for(int i=0;i<leftovers.size();i++)
			{
				if(leftovers[i] == 3)
				{
					check = true;
				}
			}
			if(check && !storage.userData.achivement.noToxication)
			{
				if(storage.sStarDump[4] == 0)
				{
					storage.userData.achivement.noToxication = true;
					//cout<<"\nnoToxication achivement";
					notificationSystem.pushNotification(19);
				}
			}
			//=========================
			check = false;//check for medic shroom left
			for(int i=0;i<leftovers.size();i++)
			{
				if(leftovers[i] == 4)
				{
					check = true;
				}
			}
			if(check && !storage.userData.achivement.noMedic)
			{
				if(storage.sStarDump[5] == 0)
				{
					storage.userData.achivement.noMedic = true;
					//cout<<"\nnoMedic achivement";
					notificationSystem.pushNotification(20);
				}
			}
			//=========================
			check = false;//check for all shroom left
			for(int i=0;i<leftovers.size();i++)
			{
				if(leftovers[i] == 4||leftovers[i] == 3)
				{
					check = true;
					break;
				}
			}
			if(check && !storage.userData.achivement.noShroom)
			{
				if(storage.sStarDump[4] == 0 && storage.sStarDump[5] == 0)
				{
					storage.userData.achivement.noShroom = true;
					//cout<<"\nnoShroom achivement";
					notificationSystem.pushNotification(21);
				}
			}
			//=========================
			check = false;//check for portals
			for(int i=0;i<leftovers.size();i++)
			{
				if(leftovers[i] == 6||leftovers[i] == 5)
				{
					check = true;
					break;
				}
			}

			if(check && !storage.userData.achivement.noTeleportsUsed)
			{
				if(storage.sStarDump[3] == 0)
				{
					storage.userData.achivement.noTeleportsUsed = true;
					//cout<<"\nnoTeleportsUsed achivement";
					notificationSystem.pushNotification(9);
				}
			}
		}

		storage.userData.achivement.globeTrotter+=storage.sStarDump[1];
		storage.userData.achivement.starCrazy+=storage.sStarDump[0];
		storage.userData.achivement.rejectStar+=3-storage.sStarDump[0];
		
		storage.userData.achivement.junkie+=storage.sStarDump[4];
		storage.userData.achivement.medic+=storage.sStarDump[5];
		storage.userData.achivement.CaptainKirk+=storage.sStarDump[3];

		if(storage.sStarDump[1]==storage.sStarDump[2])
		{
			storage.userData.achivement.perfectLevel[level] = true;
			//cout<<"\nShortest path taken";
			notificationSystem.pushNotification(10);

			if(storage.sStarDump[0] == 3)
			{
				//cout<<"\nPerfect Level!";
				notificationSystem.pushNotification(18);
			}
		}

		if(isIntoxicated)
			storage.userData.achivement.toxicFinishes++;

		
	}

	void calculateScore()
	{
		//int achivedStars = 0;
		
		
		//achivedStars = 3-gObj.getStarCount();
		uint16 level = ((storage.userData.currTheme-1)*20)+storage.userData.currLevel-1;
		//storage.userData.sStarDump[0]=gObj.starAchived;
		uint16 stepIO = storage.sStarDump[2];
		uint16 stepStorage = storage.userData.sStep[level];
		uint16 stepNow = storage.sStarDump[1];

		//flurry analytics
		

		if(stepStorage == 0)
		{//first run
			stepStorage = stepIO;
		}
		if(stepNow < stepStorage)
		{
			storage.userData.sStep[level] = stepNow; 
			storage.sStarDump[2] = stepNow;
		}
		else
		{
			storage.sStarDump[2] = stepStorage;
		}


		storage.sStarDump[0] = gObj.starAchived;	
		
		int storageStars = storage.userData.sStar[level];
		if(storageStars<gObj.starAchived)
		{
			storage.userData.sStar[level] = gObj.starAchived;
		}
		

		//check progress only on edge level
		if(storage.userData.sTheme == storage.userData.currTheme && storage.userData.sLevel == storage.userData.currLevel)
		{
			if(storage.userData.sLevel < 20)
			{
				if(storage.userData.sLevel == 1 && storage.userData.sTheme == 1)
				{
					//cout<<"\n\nbaby steps achivement";
					notificationSystem.pushNotification(2);
				}
				
				/*if(storage.userData.sLevel == 19 && storage.userData.sTheme == 3)
				{
					//cout<<"\n\ngame completed achivement";
					notificationSystem.pushNotification(2);
				}*/

				storage.userData.sLevel++;
				//cout<<"\nlevel progress!";
				notificationSystem.pushNotification(7);

				/*if (s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_IPHONE) 
				{
					//s3eIOSAppiraterUserDidSignificantEvent(true);
				}
				else*/
				#if defined(GOOGLE_PLAY)
					if(s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_ANDROID)
					{
						util.appiraterSystem.appiraterEventOccured();
					}
				#endif
			}
			else
			{
				
				if(storage.userData.sTheme<=2)
				{	
					storage.userData.sLevel = 1;
					storage.userData.sTheme++;
					//storage.userData.currTheme++;

					//cout<<"\nlevel progress!";
					notificationSystem.pushNotification(7);
					//cout<<"\ntheme progress!";
					notificationSystem.pushNotification(8);
				}
				else
				{
					//cout<<"\all 3 theme done!";					
					storage.userData.sLevel = 1;
					storage.userData.sTheme++;
					notificationSystem.pushNotification(22);					
					notificationSystem.pushFeed("Thank u for playing CandyMare.");
					notificationSystem.pushFeed("New updates coming soon!");
				}

			}
		}
		//		
		calculateAchivement(level);
	}

	void destructGameLayout()
	{
		if(gameMenuLayout!=NULL)
			gameMenuLayout->destruct();
		delete gameMenuLayout;gameMenuLayout = NULL;
		//delete pCanvas;
		//gItems.destruct();
		spStar.destruct();
		spStar0.destruct();
		cBack.destruct();
		spDone.destruct();
		
		if(tHalo!=NULL)
		delete tHalo;tHalo=NULL;
		if(tCandy!=NULL)
		delete tCandy;tCandy=NULL;
		if(tDone!=NULL)
		delete tDone;tDone=NULL;
		if(tpStar!=NULL)
		delete tpStar;tpStar=NULL;
		if(tToxic!=NULL)
		delete tToxic;tToxic=NULL;
		/*if(tFinish!=NULL)
		delete tFinish;tFinish=NULL;*/
		if(tRhombus!=NULL)
		delete tRhombus;tRhombus=NULL;
		

		if(tStatusStar!=NULL)
		delete tStatusStar;tStatusStar=NULL;
		if(tStatusStar0!=NULL)
		delete tStatusStar0;tStatusStar0=NULL;
		if(tTrack!=NULL)
		delete tTrack;tTrack=NULL;
		if(tBack!=NULL)
		delete tBack;tBack=NULL;
		/*if(tTray!=NULL)
		delete tTray;tTray=NULL;*/
		if(tStar!=NULL)
		delete tStar;tStar=NULL;
		if(tShroomEvil!=NULL)
		delete tShroomEvil;tShroomEvil=NULL;
		if(tShroomGood!=NULL)
		delete tShroomGood;tShroomGood=NULL;
		if(tOrangePortal!=NULL)
		delete tOrangePortal;tOrangePortal=NULL;
		if(tBluePortal!=NULL)
		delete tBluePortal;tBluePortal=NULL;

		
		for(int i=0;i<50;i++)
		{
			if(tBlock[i] != NULL)
			{//load if not loaded yet
				delete tBlock[i];tBlock[i] = NULL;
			}	
		}
		
	}

	~GameLayout()
	{
		
	}

	CIw2DImage* getTexture(int no)
	{
		/*if(no == 33 && util.gameState == util.PLAYING)//blank texture
			return NULL;*/
		
		if(tBlock[no] == NULL)
		{//load if not loaded yet
			util.mountTex();
			char tmp[50];
			/*if(no == 4)
			{
				IwRandSeed((int32)s3eTimerGetMs());
				int val = IwRandMinMax(1,6);
					sprintf(tmp,"%svillage/%d.%d.png",util.PATH,no,val);
			}
			else*/
			{
				sprintf(tmp,"%svillage/%d.png",util.PATH,no);
			}
			tBlock[no] = Iw2DCreateImage(tmp);
			util.unmount();
			return tBlock[no];
		}
		else
			return tBlock[no];
	}

	//==
	void constructGameMenu()
	{
		gameMenuLayout = new GameMenuLayout();
	}
	//==
	void destructGameMenu()
	{
		//animateCrowThreadEnd();
		gameMenuLayout->destruct();
		delete gameMenuLayout;gameMenuLayout = NULL;
	}	
	//==
};


//-----------------------------------------------------------------------------
// The following function transforms vertices and colours such that ripples
// appear spreading out from the centre
//-----------------------------------------------------------------------------
void TransformAndLight(CIwSVec2* v, CIwColour* c, int32 numberPoints)
{
	const int32 c_RippleFrequency = 8;//2
	const int32 c_RippleSpeed = 100;//250
	const int32 c_RippleStrength = IW_FIXED(0.010);//0.025

	//For each point/colour passed in
	while(numberPoints--)
	{
		CIwSVec2 toCentre = *v - g_EffectCentre;

		iwfixed dist = toCentre.GetLength();

		//Get the direction to the centre of the effect
		if( dist )
			toCentre.Normalise();

		//Calculate the ripple strength
		iwfixed ofs =
			IW_FIXED_MUL(
				IwGeomCos(dist*c_RippleFrequency-util.g_Frame*c_RippleSpeed),
				c_RippleStrength
			);

		//Offset this point according to the strength
		*v += toCentre * ofs;

		//Light based on the offset
		uint8 brightness = (uint8)MIN(255, ((ofs) + 0xa0));

		v++;

		//Set the light
		c->SetGrey(brightness);

		//Knock out red channel below the centre
		c->r -= (uint8)MAX(0, (toCentre.y * 0x20 / IW_GEOM_ONE));
		c++;

	}
}


//Iw2D supports an arbitrary post-transformation to be applied to all generated points/colours
void RippleFunc(CIwSVec2* v, CIwColour* c, int32 points)
{
	int32 g_RippleDuration = 100;
    //Get the centre of the ripple in subpixels (8 subpixels per pixel)
    //Apply the transform matrix to the centre, so it's in the correct place
    CIwSVec2 rippleCentre = (CIwSVec2)(Iw2DGetTransformMatrix().TransformVec(g_EffectCentre) << 1);

    while(points--)
    {
        CIwSVec2 dirToCentre = *v - rippleCentre;
		int32 distToCentre = dirToCentre.GetLength() / util.BLOCKSIZE;
        int32 rippleHeight = distToCentre*20 + (g_RippleDuration)*7 + IW_GEOM_ONE/2;
        if( distToCentre && rippleHeight >= 0  )
        {
            dirToCentre.Normalise();
            int ofs = IW_FIXED_MUL(IW_FIXED_MUL(util.BLOCKSIZE*(4<<3), g_RippleDuration*2), IwGeomSin(rippleHeight));
            *v += dirToCentre * ofs;//MAX(0, ofs);
        }
        c++;
        v++;
    }
}



#endif