#ifndef TROPHYLAYOUT_H
#define TROPHYLAYOUT_H


#include "achivementUnit.h"
#include "click.h"
#include "sprite.h"

class TrophyLayout
{
	CIwArray<CIw2DImage*> pIcon;
	CIwArray<AchivementUnit> pAchivementUnit;
	
	CIw2DImage* tBack;
	CIw2DImage* tArrow;
	
	//CIw2DImage* tBg;

public:
	//Sprite sBg;
	CIw2DImage* tFrame;
	int pos;
	int acc;
	int limitU;
	int limitD;
	//int posD;

	Click cBack;
	Sprite spUp;
	Sprite spDown;
	
	void construct()
	{
		util.setBG(true);

		tFrame = util.getTexture("notify/frame.png");
		tBack = util.getTexture("menu/back.png");
		tArrow = util.getTexture("menu/arrow.png");
		cBack.constructRaw(-tBack->GetWidth(),0,util.RIGHT,util.TOP,"",tBack);
		spUp.constructRaw(-tArrow->GetWidth(),tArrow->GetHeight()*2,util.RIGHT,util.TOP,tArrow);
		spDown.constructRaw(-tArrow->GetWidth(),-tArrow->GetHeight(),util.RIGHT,util.BOTTOM,tArrow);
		
		//pos = tFrame->GetHeight();
		//posD = 0;
		acc = 15*util.em;
		int y = (util.heightDisplay-util.heightGame)/2;	
		limitU = y+tFrame->GetHeight();
		pos = limitU;//+tFrame->GetHeight();

		int gap;
		gap = util.widthDisplay/16;
		setAchivements(gap);

		//limitD = 0;
		//while (limitD>)
		limitD = -(pAchivementUnit.size()*tFrame->GetHeight());
		limitD = limitD + y + util.heightGame;
	}

	void setProgress(int &x, int count)
	{
		Iw2DSurfaceClear(0xff000000);

		//Iw2DSetColour(0xff000000);
		//Iw2DFillRect(CIwSVec2(0,0), CIwSVec2(util.widthDisplay,util.heightDisplay));
		char tmp[50];
		sprintf(tmp,"Loading user achivements: %d%%",count);

		util.renderBG();
		Iw2DSetFont(font.AllerM);
		CIwSVec2 regionLabel(util.widthDisplay,util.heightDisplay);
		CIwSVec2 topLeftLabel(0,0);

		Iw2DSetColour(0xff000000);
		CIwSVec2 regionLabela(util.widthDisplay+2,util.heightDisplay+2);
		CIwSVec2 regionLabelb(util.widthDisplay+2,util.heightDisplay-2);
		CIwSVec2 regionLabelc(util.widthDisplay-2,util.heightDisplay+2);
		CIwSVec2 regionLabeld(util.widthDisplay-2,util.heightDisplay-2);
		
		Iw2DDrawString(tmp,topLeftLabel,regionLabela,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DDrawString(tmp,topLeftLabel,regionLabelb,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DDrawString(tmp,topLeftLabel,regionLabelc,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DDrawString(tmp,topLeftLabel,regionLabeld,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		Iw2DSetColour(util.COLOR[8]);
		Iw2DDrawString(tmp,topLeftLabel,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				

		Iw2DSetColour(0xffffffff);
		Iw2DFillRect(CIwSVec2(0,(util.heightDisplay*9)/10), CIwSVec2(x,5));
		//IwGxFlush();
		//IwGxSwapBuffers();
		Iw2DSurfaceShow();
	}
	
	void setAchivements(int gap)
	{
		//tBg = util.getBgTile(true);//util.getTexture("menu/bg1bw.png");
		//sBg.construct(0,0,util.LEFT,util.TOP,tBg);
		
		//int x = (util.widthDisplay-util.widthGame)/2;
		int count = 5;
		int x = ((util.widthDisplay-tFrame->GetWidth())/2)-tArrow->GetWidth();
		int y = (util.heightDisplay-util.heightGame)/2;	
		int prog = gap;
		setProgress(gap,count);gap+=prog;
		setGameProgress(x,y);count = 5;
		setProgress(gap,count);gap+=prog;
		getGlobeTrotter(x,y);count = 10;
		setProgress(gap,count);gap+=prog;
		getTeleport(x,y);count = 15;
		setProgress(gap,count);gap+=prog;
		getShroom(x,y);count = 20;
		setProgress(gap,count);gap+=prog;
		getMedic(x,y);count = 25;
		setProgress(gap,count);gap+=prog;
		getStarCollector(x,y);count = 30;
		setProgress(gap,count);gap+=prog;
		getStarLost(x,y);count = 35;
		setProgress(gap,count);gap+=prog;
		getToxicFinish(x,y);count = 40;
		setProgress(gap,count);gap+=prog;
		getQuitter(x,y);count = 45;
		setProgress(gap,count);gap+=prog;
		getThemeUnlocks(x,y);count = 50;
		setProgress(gap,count);gap+=prog;
		checkBools(x,y);count = 55;
		setProgress(gap,count);gap+=prog;
		getPerfectLevel(x,y);count = 65;
		setProgress(gap,count);gap+=prog;
		getLevelUnlocks(x,y);count = 80;
		setProgress(gap,count);gap+=prog;
		getShortestPath(x,y);count = 99;
		setProgress(gap,count);gap+=prog;
		getAll3Star(x,y);count = 100;
		setProgress(gap,count);gap+=prog;

		if(pAchivementUnit.size() == 2)
		{
			pIcon.push_back(util.getTexture("notify/empty.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"No game progress made!");
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}

		Transitions2D::CaptureStartScreen();
	}
	void setGameProgress(int x,int y)
	{//star+levels
		//stars
		int tstars=0;
		for(int i=0;i<60;i++)
		{
			tstars+=storage.userData.sStar[i];
		}
		//level
		int tlevels = ((storage.userData.sTheme-1)*20)+storage.userData.sLevel-1;
		
		{//total notify
			int tot = tstars + tlevels;
			char tmp[50];
			sprintf(tmp,"%3.1f%% completed",((float)tot*100.0f)/240.0f);
			
			pIcon.push_back(util.getTexture("notify/Feed.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);


			pAchivementUnit.push_back(au);
		}
		
		{//star notify 
			
			pIcon.push_back(util.getTexture("notify/StarCollector.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"%d of %d Stars collected.",tstars,180);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		
		{//level notify
			pIcon.push_back(util.getTexture("notify/NewLevel.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			if(storage.userData.sTheme<4)
				sprintf(tmp,"%d of %d Levels completed.",tlevels,60);
			else
				sprintf(tmp,"%d of %d Levels completed.",60,60);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);			
			
		}
	}
	void checkBools(int x,int y)
	{
		//noteleport
		if(storage.userData.achivement.noTeleportsUsed)
		{
			pIcon.push_back(util.getTexture("notify/NoTeleport.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Completed level avoiding all teleports");
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		//noToxication
		if(storage.userData.achivement.noToxication)
		{
			pIcon.push_back(util.getTexture("notify/NoToxic.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Completed level avoiding toxication");
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		//noMedic;
		if(storage.userData.achivement.noMedic)
		{
			pIcon.push_back(util.getTexture("notify/NoMedic.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Completed level without medication");
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		//noShroom;
		if(storage.userData.achivement.noShroom)
		{
			pIcon.push_back(util.getTexture("notify/NoShroom.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Completed level avoiding all mushrooms");
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
	//baby level
		if(storage.userData.sTheme>1||storage.userData.sLevel>1)
		{
			pIcon.push_back(util.getTexture("notify/BabyLevel.png"));
			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Baby level completed!");
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
	}
	void getGlobeTrotter(int x,int y)
	{

		if(storage.userData.achivement.globeTrotter > 0)
		{
			pIcon.push_back(util.getTexture("notify/GlobeTrotter.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"GlobeTrotter steps: %u",storage.userData.achivement.globeTrotter);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		/*CIwArray<int> list = getMark(3,storage.userData.achivement.globeTrotter);

		for(int i=0;i<list.size();i++)
		{
			pIcon.push_back(util.getTexture("notify/GlobeTrotter.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"GlobeTrotter Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}
	void getTeleport(int x,int y)
	{
		if(storage.userData.achivement.CaptainKirk > 0)
		{
			pIcon.push_back(util.getTexture("notify/TeleportLandmark.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Teleports done: %u",storage.userData.achivement.CaptainKirk);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		/*CIwArray<int> list = getMark(4,storage.userData.achivement.CaptainKirk);

		for(int i=0;i<list.size();i++)
		{
			pIcon.push_back(util.getTexture("notify/TeleportLandmark.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"TeleportLandmark Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}
	void getShroom(int x,int y)
	{
		if(storage.userData.achivement.junkie>0)
		{
			pIcon.push_back(util.getTexture("notify/MushroomJunkie.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Mushroom junkie: %u",storage.userData.achivement.junkie);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		/*CIwArray<int> list = getMark(4,storage.userData.achivement.junkie);

		for(int i=0;i<list.size();i++)
		{
			pIcon.push_back(util.getTexture("notify/MushroomJunkie.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"MushroomJunkie Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}
	void getMedic(int x,int y)
	{
		if(storage.userData.achivement.medic>0)
		{
			pIcon.push_back(util.getTexture("notify/MedicineMan.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Medicine man: %u",storage.userData.achivement.medic);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}

		/*CIwArray<int> list = getMark(4,storage.userData.achivement.medic);

		for(int i=0;i<list.size();i++)
		{
			pIcon.push_back(util.getTexture("notify/MedicineMan.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"MedicineMan Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}
	void getPerfectLevel(int x,int y)
	{
		for(int i=0;i<60;i++)
		{	
			if(storage.userData.achivement.perfectLevel[i] && storage.userData.sStar[i]==3)
			{
				pIcon.push_back(util.getTexture("notify/PerfectLevel.png"));

				AchivementUnit au;
				au.init(tFrame,pIcon[pIcon.size()-1]);
				char tmp[50];
				sprintf(tmp,"Perfect level %d,shortest path + 3stars",i+1);
				au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

				pAchivementUnit.push_back(au);
			}
		}
	}
	void getShortestPath(int x,int y)
	{
		for(int i=0;i<60;i++)
		if(storage.userData.achivement.perfectLevel[i])
		{
			pIcon.push_back(util.getTexture("notify/ShortestPath.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Shortest path taken in Level %d",i+1);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
	}
	void getAll3Star(int x,int y)
	{
		for(int i=0;i<60;i++)
		{	
			if(storage.userData.sStar[i]==3)
			{
				pIcon.push_back(util.getTexture("notify/Allstar.png"));

				AchivementUnit au;
				au.init(tFrame,pIcon[pIcon.size()-1]);
				char tmp[50];
				sprintf(tmp,"3stars achived in Level %d",i+1);
				au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

				pAchivementUnit.push_back(au);
			}
		}
	}

	void getStarLost(int x,int y)
	{
		if(storage.userData.achivement.rejectStar>0)
		{
			pIcon.push_back(util.getTexture("notify/StarLost.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Stars Lost: %u",storage.userData.achivement.rejectStar);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		/*CIwArray<int> list = getMark(2,storage.userData.achivement.rejectStar);

		for(int i=0;i<list.size();i++)
		{	
			pIcon.push_back(util.getTexture("notify/StarLost.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Stars Lost Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}

	void getStarCollector(int x,int y)
	{
		if(storage.userData.achivement.starCrazy>0)
		{
			pIcon.push_back(util.getTexture("notify/StarCollector.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Total Stars collected: %u",storage.userData.achivement.starCrazy);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		/*CIwArray<int> list = getMark(2,storage.userData.achivement.starCrazy);

		for(int i=0;i<list.size();i++)
		{	
			pIcon.push_back(util.getTexture("notify/StarCollector.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Star Collector Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}
	void getQuitter(int x,int y)
	{
		if(storage.userData.achivement.quitter>0)
		{
			pIcon.push_back(util.getTexture("notify/Quitter.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Game quits: %u",storage.userData.achivement.quitter);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		/*CIwArray<int> list = getMark(4,storage.userData.achivement.quitter);
		for(int i=0;i<list.size();i++)
		{	
			pIcon.push_back(util.getTexture("notify/Quitter.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Quitter Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}
	void getToxicFinish(int x,int y)
	{
		if(storage.userData.achivement.toxicFinishes>0)
		{
			pIcon.push_back(util.getTexture("notify/ToxicFinish.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Toxic finishes: %u",storage.userData.achivement.toxicFinishes);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}
		/*CIwArray<int> list = getMark(4,storage.userData.achivement.toxicFinishes);
		for(int i=0;i<list.size();i++)
		{	
			pIcon.push_back(util.getTexture("notify/ToxicFinish.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Toxic Finish Landmark (%d)",list[i]);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
		}*/
	}
	void getThemeUnlocks(int x,int y)
	{
		//all theme check
		if(storage.userData.sTheme == 4)// && storage.userData.sLevel == 20 )
		{

			//all 3 theme
			pIcon.push_back(util.getTexture("notify/all3theme.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Theme pack 1 finished!");
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
			
			//theme3
			pIcon.push_back(util.getTexture("notify/ThemeCompleted.png"));

			/*AchivementUnit au2;
			au2.init(tFrame,pIcon[pIcon.size()-1]);
			memset(tmp,0,50);
			sprintf(tmp,"Theme %d completed!",3);
			au2.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au2);*/
		}

		int i = storage.userData.sTheme;
		//individual theme check
		while(i>1)
		{
			pIcon.push_back(util.getTexture("notify/ThemeCompleted.png"));

			AchivementUnit au;
			au.init(tFrame,pIcon[pIcon.size()-1]);
			char tmp[50];
			sprintf(tmp,"Theme %d completed!",i-1);
			au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

			pAchivementUnit.push_back(au);
			i--;
		}
	}
	void getLevelUnlocks(int x,int y)
	{
		int t = storage.userData.sTheme;
		int l = storage.userData.sLevel;
		int k = 1;
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<21;j++)
			{
				if(i<t)
				{
					pIcon.push_back(util.getTexture("notify/LevelCompleted.png"));
					AchivementUnit au;
					au.init(tFrame,pIcon[pIcon.size()-1]);
					char tmp[50];
					sprintf(tmp,"Level %d completed!",k);
					au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

					pAchivementUnit.push_back(au);

				}
				else if(i == t && j < l)
				{
					pIcon.push_back(util.getTexture("notify/LevelCompleted.png"));
					AchivementUnit au;
					au.init(tFrame,pIcon[pIcon.size()-1]);
					char tmp[50];
					sprintf(tmp,"Level %d completed!",k);
					au.construct(x,y+(tFrame->GetHeight()*(pAchivementUnit.size())),tmp);

					pAchivementUnit.push_back(au);
				}
				else 
					break;
				k++;
			}
		}
		
	}
	
	void render()
	{
		//Iw2DDrawRect(CIwSVec2(0,0),CIwSVec2(util.widthDisplay,tFrame->GetHeight()));
		for(int i=0;i<pAchivementUnit.size();i++)
		{
			int tmpy = pos+(i*tFrame->GetHeight());
			if(tmpy > -tFrame->GetHeight() && tmpy < util.heightDisplay+tFrame->GetHeight())
				pAchivementUnit[i].render(tmpy,tFrame,pIcon[i]);
		}
	}

	void normalize()
	{
		////cout<<"\nacc"<<pos;
		if(pos> 0 && pos%tFrame->GetHeight()!=0)
		{
			pos-=2;
		}
		else if(pos < 0 && pos%tFrame->GetHeight()!=0)
		{
			pos+=2;
		}
				
	}
	
	CIwArray<int> getMark(int id,int value)
	{
		//id 1 progression 1,5,10....(5x)
		//id 2 progression 10,50,100...((5x)*10)
		//id 3 progression 50,250,500,750...((5x)*10*5)
		//id 4 progression 5,10,15...(5x: {x>0})
		if(id == 1)
			return prog1(value);
		else if(id == 2)
			return prog2(value);
		else if(id == 3)
			return prog3(value);
		else
			return prog4(value);
	}

	CIwArray<int> prog1(int value)
	{
		CIwArray<int> tmp;
		tmp.push_back(-1);
		/*if(value == 0)
			return 0;
		else if(value == 1)
			return 1;
		else return ((value/5)+1);*/
		return tmp;
		
	}

	CIwArray<int> prog2(int value)
	{
		CIwArray<int> tmp;
		
		if(value >= 10)
			tmp.push_back(10);

		int i = value/50;
		for(int j= 1;j<=i;j++)
		{
			int t = j*50;
			tmp.push_back(t);
		}	

		return tmp;
	}

	CIwArray<int> prog3(int value)
	{
		CIwArray<int> tmp;


		if(value >= 50)
			tmp.push_back(50);
		if(value >= 250)
			tmp.push_back(250);

		int i = value/500;
		for(int j= 1;j<=i;j++)
		{
			int t = j*500;
			tmp.push_back(t);
		}	

		return tmp;
	}

	CIwArray<int> prog4(int value)
	{
		CIwArray<int> tmp;

		if(value >= 5)
			tmp.push_back(5);
		if(value >= 10)
			tmp.push_back(10);
		

		int i=value/25;
		for(int j=1;j<=i;j++)
		{
			int t = j*5;
			tmp.push_back(t);
		}
		return tmp;
	}
	void destruct()
	{
		/*if(tBg)
			delete tBg;tBg = NULL;*/

		delete tArrow;tArrow=NULL;
		delete tFrame;tFrame=NULL;
		delete tBack;tBack=NULL;

		for(int i=0;i<pAchivementUnit.size();i++)
		{
			pAchivementUnit[i].destruct();
		}
		
		for(int i=0;i<pIcon.size();i++)
		{
			delete pIcon[i];pIcon[i] = NULL;
		}
		pIcon.clear_optimised();
	}

};
#endif
