#ifndef LAYOUT_H
#define LAYOUT_H

#include "s3eThread.h"
#include <unistd.h>

#include "menuLayout.h"
#include "cartLayout.h"
#include "themeLayout.h"
#include "themeScrollLayout.h"
#include "themeIntroLayout.h"
#include "levelLayout.h"
#include "levelEndLayout.h"
#include "gameLayout.h"
#include "editorLayout.h"
#include "trophyLayout.h"
#include "../h/Jigsaw.h"
#include "../h/Level.h"
#include "../h/SoundPlayer.h"
#include "../h/vibrate.h"
#include "../h/util.h"
#include "../h/ParticleSystem.h"
#include "../h/NotificationSystem.h"
#include "../h/tray.h"

#define DELAY50 50
#define DELAY80 80
#define DELAY100 100
#define DELAY150 150
#define DELAY200 200
#define DELAY300 300
#define DELAY500 500
#define DELAY1500 1500
#define DELAY5000 5000
#define DELAY15000 15000
#define DELAY30000 30000

//reuse canvas
//#define REUSE_CANVAS
//ios,sim
#define IOS
//!android,win32
/*
//fix inverse landscape
IwGxScreenOrient orient = (s3eSurfaceGetInt(S3E_SURFACE_DEVICE_BLIT_DIRECTION) == 3 ? IW_GX_ORIENT_270 : IW_GX_ORIENT_90);
IwGxSetScreenOrient(orient);
*/
//TIMER
static int32 NotifyModuleT(void *systemData, void *userData);
static int32 TalkModuleT(void *systemData, void *userData);
static int32 RenderCrowT(void *systemData, void *userData);
static int32 RenderCrowT2(void *systemData, void *userData);
static int32 RenderGameObjectsT(void *systemData, void *userData);
static int32 RenderMainT(void *systemData, void *userData);
static int32 RenderLevelEndStarT1(void *systemData, void *userData);
static int32 RenderLevelEndStarT2(void *systemData, void *userData);
static int32 RenderLevelEndStarT3(void *systemData, void *userData);
static int32 RenderGameplayStarT1(void *systemData, void *userData);
static int32 RenderGameplayStarT2(void *systemData, void *userData);
static int32 RenderGameplayStarT3(void *systemData, void *userData);


void* NotifyModule(void* arg);
void* TalkModule(void* arg);
void* RenderCrow(void* arg);
void* RenderCrow2(void* arg);
void* RenderGameObjects(void* arg);
void* RenderMain(void* arg);

void* RenderLevelEndStar1(void* arg);
void* RenderLevelEndStar2(void* arg);
void* RenderLevelEndStar3(void* arg);

void* RenderGameplayStar1(void* arg);
void* RenderGameplayStar2(void* arg);
void* RenderGameplayStar3(void* arg);
//THREAD
void* NotifyModule(void* arg);
void* TalkModule(void* arg);
void* RenderCrow(void* arg);
void* RenderCrow2(void* arg);
void* RenderGameObjects(void* arg);
void* RenderMain(void* arg);

void* RenderLevelEndStar1(void* arg);
void* RenderLevelEndStar2(void* arg);
void* RenderLevelEndStar3(void* arg);

void* RenderGameplayStar1(void* arg);
void* RenderGameplayStar2(void* arg);
void* RenderGameplayStar3(void* arg);
//void* Blur(void* arg);

class Layout{

private:
	s3eThread* notify_thread;
	s3eThread* talk_thread;
	s3eThread* animtoxicRender_thread;
	s3eThread* animgameobj_thread;
	s3eThread* animcrow_thread;
	s3eThread* animcrow_thread2;
	s3eThread* animlevelendstar_thread[3];
	s3eThread* animgameplaystar_thread[3];
	//s3eThread* blur_thread;
	
public:
	//NotificationSystem notificationSystem;
	MenuLayout *menuLayout;
	ThemeIntroLayout *themeIntroLayout;
	CartLayout *cartLayout;
	ThemeLayout *themeLayout;
	ThemeScrollLayout *themeScrollLayout;
	LevelLayout *levelLayout;
	LevelEndLayout *levelEndLayout;
	GameLayout *gameLayout;
	TrophyLayout *trophyLayout;
	EditorLayout *editorLayout;
	CIwArray<Jigsaw> jigSaw;	
	CIwSVec2 stripePoints[4][4];


	uint16 isTalking;
	
		
	void construct()
	{
		isTalking = 0;
		talk_thread = NULL;
		notify_thread = NULL;
		//notifyThreadInit();
		notificationSystem.construct();
		soundPlayer.construct();		
	}
	void destruct()
	{
		notificationSystem.destruct();
		jigSaw.clear();
		soundPlayer.destruct();
	}
	void update()
	{	
		soundPlayer.update();
	}
	~Layout()
	{
		
	}
	
	
	
//==
	void constructMenu()
	{
		menuLayout = new MenuLayout();
		menuLayout->construct();
		animateCrowThreadInit();
	}
//==
	void destructMenu()
	{
		animateCrowThreadEnd();		

		//s3eDeviceYield(500);
		menuLayout->destruct();
		delete menuLayout;menuLayout = NULL;
	}
	
//==
	void constructThemeIntro()
	{
		themeIntroLayout = new ThemeIntroLayout();
		themeIntroLayout->construct();
		animateCrowThreadInit2();
	}
//==
	void destructThemeIntro()
	{
		animateCrowThreadEnd2();

		//s3eDeviceYield(500);
		themeIntroLayout->destruct();
		delete themeIntroLayout;themeIntroLayout = NULL;
	}
	
//==
	void constructCart()
	{
		cartLayout = new CartLayout();
		cartLayout->construct();
	}
//==
	void destructCart()
	{
		//animateCrowThreadEnd();
		cartLayout->destruct();
		delete cartLayout;cartLayout = NULL;
	}

//==
	void constructTrophy()
	{
		trophyLayout = new TrophyLayout();
		trophyLayout->construct();
	}
//==
	void destructTrophy()
	{
		//animateCrowThreadEnd();
		trophyLayout->destruct();
		delete trophyLayout;trophyLayout = NULL;
	}

//==
	void constructThemeScrollSelect()
	{
		themeScrollLayout = new ThemeScrollLayout();
	}
	void destructThemeScrollSelect()
	{
		themeScrollLayout->destruct();
		delete themeScrollLayout;themeScrollLayout = NULL;
	}	
//==
	void constructThemeSelect()
	{
		themeLayout = new ThemeLayout();
	}
	void destructThemeSelect()
	{
		themeLayout->destruct();
		delete themeLayout;themeLayout = NULL;
	}		
//==
	void constructLevelSelect()
	{
		levelLayout = new LevelLayout();
	}
	void destructLevelSelect()
	{
		levelLayout->destruct();
		delete levelLayout;levelLayout = NULL;
	}	

//==

	void constructGameLevel(Level level)
	{
		//
		bool hyptonizeFlag = false;
		gameLayout = new GameLayout();
		
		storage.sStarDump[2] = level.getMove();
	
		jigSaw.clear();
			{//joseblock
				Jigsaw jig;
			
				jigSaw.push_back(jig);
			}
			{//tequilablock
				Jigsaw jig;
				
				jigSaw.push_back(jig);
			}
			int k = 3;
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<9;j++)
				{
					
					if(level.array1[i][j]>4 && level.array1[i][j]!=34 && level.array1[i][j]!=35 && level.array1[i][j]!=36 && level.array1[i][j]!=37 && level.array1[i][j]!=38&& level.array1[i][j]!=39&& level.array1[i][j]!=40)
					{			
						pushIntermediateBlock(level.array1[i][j],i,j,k++,false);
					}
					else if(level.array1[i][j]==3)
					{//hero
						jigSaw[0].construct(level.array1[i][j],i,j,1,false);
						jigSaw[0].setImg(gameLayout->getTexture(level.array1[i][j]));
						//construct halo
						
					}
					else if(level.array1[i][j]==4)
					{//destination
						jigSaw[1].construct(level.array1[i][j],i,j,2,false);
						jigSaw[1].setImg(gameLayout->getTexture(level.array1[i][j]));
						
					}
					else if(level.array1[i][j]==34)
					{//star1
						gameLayout->makeUnit(0,j,i);
					}
					else if(level.array1[i][j]==35)
					{//star2
						gameLayout->makeUnit(1,j,i);
					}
					else if(level.array1[i][j]==36)
					{//star3
						gameLayout->makeUnit(2,j,i);
					}
					else if(level.array1[i][j]==37)
					{//evilshroom
						gameLayout->makeUnit(3,j,i);
						hyptonizeFlag = true;
					}
					else if(level.array1[i][j]==38)
					{//goodshroom
						gameLayout->makeUnit(4,j,i);
					}
					else if(level.array1[i][j]==39)
					{//orangeportal
						gameLayout->makeUnit(5,j,i);
						gameLayout->gObj.portals[2].x = k;
						pushIntermediateBlock(level.array1[i][j],i,j,k++,false);
					}
					else if(level.array1[i][j]==40)
					{//blueportal
						gameLayout->makeUnit(6,j,i);
						gameLayout->gObj.portals[2].y = k;
						pushIntermediateBlock(level.array1[i][j],i,j,k++,false);
					}
				}
			}
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<9;j++)
				{
					
					if(level.array2[i][j]>4 && level.array2[i][j]!=34 && level.array2[i][j]!=35 && level.array2[i][j]!=36 && level.array2[i][j]!=37 && level.array2[i][j]!=38 && level.array2[i][j]!=39 && level.array2[i][j]!=40)
					{			
						pushIntermediateBlock(level.array2[i][j],i,j,k++,false);
					}
					else if(level.array2[i][j]==3)
					{//destination
						jigSaw[0].construct(level.array2[i][j],i,j,1,false);
						jigSaw[0].setImg(gameLayout->getTexture(level.array2[i][j]));
						
					}
					else if(level.array2[i][j]==4)
					{//hero
						jigSaw[1].construct(level.array2[i][j],i,j,2,false);
						jigSaw[1].setImg(gameLayout->getTexture(level.array2[i][j]));
						
					}
					else if(level.array2[i][j]==34)
					{//star1
						gameLayout->makeUnit(0,j,i);
						/*tmpX[0] = j;
						tmpY[0] = i;*/
					}
					else if(level.array2[i][j]==35)
					{//star2
						gameLayout->makeUnit(1,j,i);
						/*tmpX[1] = j;
						tmpY[1] = i;*/
					}
					else if(level.array2[i][j]==36)
					{//star3
						gameLayout->makeUnit(2,j,i);
					}
					else if(level.array2[i][j]==37)
					{//evilshroom
						gameLayout->makeUnit(3,j,i);
						hyptonizeFlag = true;
					}
					else if(level.array2[i][j]==38)
					{//goodshroom
						gameLayout->makeUnit(4,j,i);
					}
					else if(level.array2[i][j]==39)
					{//orangeportal
						gameLayout->makeUnit(4,j,i);
					}
					else if(level.array2[i][j]==40)
					{//blueportal
						gameLayout->makeUnit(4,j,i);
					}
				}
			}
			if(hyptonizeFlag == true)
			{
				gameLayout->constructHyptonizeHero();
			}
			/*CIw2DImage *tTile = util.getBgTile();//storage.userData.currTheme,storage.userData.currLevel);
			char tmp[50];
			sprintf(tmp,"%d_%d.bmp",storage.userData.currTheme,storage.userData.currLevel);

#if defined(REUSE_CANVAS)
			if(util.isValid(tmp))
			{//skip if file exists
			
				//cout<<"\nskipping drawcanvas!!";
				delete tTile;

				gameLayout->constructTray();
				animateGameObjThreadInit();
				if(talk_thread==NULL)
					talkThreadInit();
				return;
			}
#endif
			drawCanvas(gameLayout,tTile,tmp);
			drawCanvas(gameLayout,tTile,tmp);
			drawCanvas(gameLayout,tTile,tmp);
			//TakeScreenshot();
			util.TakeScreenshot(tmp);
			delete tTile;

			
			gameLayout->constructTray();*/

			setCanvas();

			animateGameObjThreadInit();
			if(talk_thread==NULL)
				talkThreadInit();
	}
	void genXtras()
	{
		int r = tray.getCordx(jigSaw[1].row)-(util.widthDisplay-util.widthGame)/2;
		int c = tray.getCordy(jigSaw[1].column)-(util.heightDisplay-util.heightGame)/2;
		gameLayout->constructHalo(r,c);
		gameLayout->constructCandy(r,c);
	}
	void pushIntermediateBlock(int id, int i, int j,int k,bool editable)
	{
		Jigsaw jig;
		jig.construct(id,i,j,k++,editable);
		jig.setImg(gameLayout->getTexture(id));
		jigSaw.push_back(jig);
		//cout<<"\njigSaw size "<<jigSaw.size();
	}

	void pushBlock(int code, int i, int j)
	{
		Jigsaw jig;
		int id = jigSaw[jigSaw.size()-1].id;
		jig.construct(code,i,j,id+1,true);
		jig.setImg(editorLayout->getTexture(code));
		jigSaw.push_back(jig);
		//cout<<"\njigSaw size "<<jigSaw.size();
	}

	void destructGameLevel()
	{
		toxicThreadEnd();
		animateGameObjThreadEnd();
		talkThreadEnd();
		animGameplayStarThreadEnd();

		//s3eDeviceYield(500);
		jigSaw.clear_optimised();
		gameLayout->destructGameLayout();
		
		delete gameLayout;gameLayout = NULL;
	}	
//==

//==

	void constructEditorLevel(Level level)
	{
		editorLayout = new EditorLayout();

		jigSaw.clear();
			{//joseblock
				Jigsaw jig;
				jigSaw.push_back(jig);
			}
			{//tequilablock
				Jigsaw jig;
				jigSaw.push_back(jig);
			}
			int k = 3;
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<9;j++)
				{
					
					if(level.array1[i][j]>4)
					{
						Jigsaw jig;
						jig.construct(level.array1[i][j],i,j,k++,true);
						jig.setImg(editorLayout->getTexture(level.array1[i][j]));
						jigSaw.push_back(jig);
						//cout<<"\njigSaw size "<<jigSaw.size();
					}
					else if(level.array1[i][j]==3)
					{//joseblock
						jigSaw[0].construct(level.array1[i][j],i,j,1,true);
						jigSaw[0].setImg(editorLayout->getTexture(level.array1[i][j]));
					}
					else if(level.array1[i][j]==4)
					{//tequilablock
						jigSaw[1].construct(level.array1[i][j],i,j,2,true);
						jigSaw[1].setImg(editorLayout->getTexture(level.array1[i][j]));
					}
				}
			}

			
			for(int i=0;i<5;i++)
			{
				for(int j=0;j<9;j++)
				{
					
					if(level.array2[i][j]>4)
					{
						Jigsaw jig;
						jig.construct(level.array2[i][j],i,j,k++,true);
						jig.setImg(editorLayout->getTexture(level.array2[i][j]));
						jigSaw.push_back(jig);
						//cout<<"\njigSaw size "<<jigSaw.size();
					}
					else if(level.array2[i][j]==3)
					{//joseblock
						jigSaw[0].construct(level.array2[i][j],i,j,1,true);
						jigSaw[0].setImg(editorLayout->getTexture(level.array2[i][j]));
					}
					else if(level.array2[i][j]==4)
					{//tequilablock
						jigSaw[1].construct(level.array2[i][j],i,j,2,true);
						jigSaw[1].setImg(editorLayout->getTexture(level.array2[i][j]));
					}
				}
			}
			CIw2DImage *tTile = util.getBgTile();

			drawCanvas(editorLayout,tTile);
			drawCanvas(editorLayout,tTile);
			drawCanvas(editorLayout,tTile);
			util.TakeScreenshot();
			delete tTile;
			editorLayout->constructTray();
	}
	void destructEditorLevel()
	{
		jigSaw.clear_optimised();
		editorLayout->destruct();
		delete editorLayout;editorLayout = NULL;
	}	
//==	

		
//==
	void constructLevelEnd()
	{
		levelEndLayout = new LevelEndLayout();
		animLevelEndStarThreadInit(storage.sStarDump[0]);
	}
	void destructLevelEnd()
	{
		animLevelEndStarThreadEnd();
		
		//s3eDeviceYield(500);
		levelEndLayout->destruct();
		delete levelEndLayout;levelEndLayout = NULL;
	}	
//==

	void setCanvas()
	{
		int16 num;
		
		
			IwRandSeed((int32)s3eTimerGetMs());
			num = IwRandMinMax(0,4);//0-7
					
			char *tile[5];
			tile[0] = "jacko1.jpg";
			tile[1] = "jacko2.jpg";
			tile[2] = "jacko3.jpg";
			tile[3] = "jacko4.jpg";
			tile[4] = "skull.jpg";

			CIw2DImage *tTile = util.getTile(tile[num]);
			
			//IwGxFlush();
			util.makeBgBuffer(tile[num],tTile);
			//IwGxFlush();
			//util.tBG = Transitions2D::CaptureScreen();
			
		 //return;
		CIw2DImage *tUnit = util.getTexture("tray/unit.png");
		int a=0;
		for(int i=gameLayout->trayX;i<gameLayout->trayX+gameLayout->wTray,a<9;i+=util.BLOCKSIZE)
		{
			
			int b=0;////cout<<"\n"<<a;
			for(int j=gameLayout->trayY-2;j<gameLayout->trayY+gameLayout->hTray,b<5;j+=util.BLOCKSIZE)
			{
				
				bool flag = false;
				for(int k=0;k<jigSaw.size();k++)
				{
					int x = jigSaw.size();
					int r = jigSaw[k].row;
					int c = jigSaw[k].column;
					int code = jigSaw[k].getCode();
					if(r == a && c == b && code == 33)
					{	
						flag = true;break;
					}
				}

				if(!flag)
				{
					CIwSVec2 topLeft(i,j);
					Iw2DDrawImage(tUnit,topLeft);
				}
				b++;
			}
			a++;
		}
		
		
		if(util.tBG != NULL)
			delete util.tBG;util.tBG = NULL;

		IwGxFlush();
		util.tBG = Transitions2D::CaptureScreen();
		
		delete tTile;
		delete tUnit;

		
	}

	bool drawCanvas(GameLayout *gameLayout,CIw2DImage *tTile,char *file)
	{
		
#if defined(IOS)
	Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT270); 
	Iw2DDrawImage(tTile,CIwSVec2(0,0));
	Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
#else 
	Iw2DDrawImage(tTile,CIwSVec2(0,0));		
#endif

		CIw2DImage *tUnit = util.getTexture("tray/unit.png");
		int a=0;
		for(int i=gameLayout->trayX;i<gameLayout->trayX+gameLayout->wTray,a<9;i+=util.BLOCKSIZE)
		{
			
			int b=0;////cout<<"\n"<<a;
			for(int j=gameLayout->trayY-2;j<gameLayout->trayY+gameLayout->hTray,b<5;j+=util.BLOCKSIZE)
			{
				
				bool flag = false;
				for(int k=0;k<jigSaw.size();k++)
				{
					int x = jigSaw.size();
					int r = jigSaw[k].row;
					int c = jigSaw[k].column;
					int code = jigSaw[k].getCode();
					if(r == a && c == b && code == 33)
					{	
						flag = true;break;
					}
				}

				if(!flag)
				{
					CIwSVec2 topLeft(i,j);
					Iw2DDrawImage(tUnit,topLeft);
				}
				b++;
			}
			a++;
		}
		
		
		Iw2DSurfaceShow();
		//Iw2DFinishDrawing();
		delete tUnit;
		util.TakeScreenshot(file);
		return false;
	}
	
	void drawCanvas(EditorLayout *editorLayout,CIw2DImage *tTile)
	{
		CIw2DImage *tUnit = util.getTexture("tray/unit.png");

		int w = util.widthDisplay;
		int h = util.heightDisplay;
		
		int tw = tTile->GetWidth();
		int th = tTile->GetHeight();
		 Iw2DSurfaceClear(0xffffffff);
		//draw tile to buffer
		for(int i=0;i<w;i+=tw)
		{
			for(int j=0;j<h;j+=th)
			{
				/*if(i==tw || j ==th )
					continue;*/
				CIwSVec2 topLeft(i,j);
				Iw2DDrawImage(tTile,topLeft);
			}
		}

		int a=0;
		for(int i=editorLayout->trayX;i<editorLayout->wTray;i+=util.BLOCKSIZE)
		{
			
			int b=0;////cout<<"\n"<<a;
			for(int j=editorLayout->trayY-2;j<editorLayout->hTray+util.BLOCKSIZE;j+=util.BLOCKSIZE)
			{
				
				bool flag = false;
				for(int k=0;k<jigSaw.size();k++)
				{
					int x = jigSaw.size();
					int r = jigSaw[k].row;
					int c = jigSaw[k].column;
					int code = jigSaw[k].getCode();
					if(r == a && c == b && code == 33)
					{	
						flag = true;break;
					}
				}

				if(!flag)
				{
					CIwSVec2 topLeft(i,j);
					Iw2DDrawImage(tUnit,topLeft);
				}
				b++;
			}
			a++;
		}
		
		Iw2DSurfaceShow();
		//Iw2DFinishDrawing();

		delete tUnit;
		util.TakeScreenshot();
	}

	
	void grayscale200()
	{
		//getStripes();
		CIwColour color;
		//color.SetGrey(150); 
		color.a = 150;
		color.r = 200;
		color.g = 200;
		color.b = 200;
		Iw2DSetColour(color);
		Iw2DSetAlphaMode(IW_2D_ALPHA_SUB);
		Iw2DFillRect(CIwSVec2(0,0), CIwSVec2(util.widthDisplay,util.heightDisplay));
		
		Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		Iw2DSetColour(0xffffffff);
	}
	
	void grayscale100()
	{
		//getStripes();
		CIwColour color;
		//color.SetGrey(150); 
		color.a = 150;
		color.r = 0;
		color.g = 0;
		color.b = 0;
		Iw2DSetColour(color);
		//Iw2DSetAlphaMode(IW_2D_ALPHA_SUB);
		Iw2DFillRect(CIwSVec2(0,0), CIwSVec2(util.widthDisplay,util.heightDisplay));
		
		//Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		Iw2DSetColour(0xffffffff);
	}

	void toxicThreadInit()
	{
		/*if (!s3eThreadAvailable())
		{
			s3eDebugErrorPrintf("s3eThread extension not present");
			return;
		}
		animtoxicRender_thread = s3eThreadCreate(RenderMain, NULL, NULL);	*/	

		s3eTimerSetTimer(DELAY80, &RenderMainT, NULL);
	}

	void toxicThreadEnd()
	{
		/*util.g_Frame = 0;
		gameLayout->talkImg = 0;
		s3eThreadCancel(animtoxicRender_thread);
		animtoxicRender_thread = NULL;*/
		s3eTimerCancelTimer(RenderMainT,NULL);
	}

	
	void animateGameObjThreadInit()
	{
		/*
		if (!s3eThreadAvailable())
		{
			s3eDebugErrorPrintf("s3eThread extension not present");
			return;
		}

		animgameobj_thread = s3eThreadCreate(RenderGameObjects, NULL, NULL);		
		*/
		
		s3eTimerSetTimer(DELAY80, &RenderGameObjectsT, NULL);
	}

	void animateGameObjThreadEnd()
	{
		/*
		s3eThreadCancel(animgameobj_thread);
		animgameobj_thread = NULL;
		*/
		s3eTimerCancelTimer(RenderGameObjectsT,NULL);
	}

	
	void animateCrowThreadInit()
	{
		/*if (!s3eThreadAvailable())
		{
			s3eDebugErrorPrintf("s3eThread extension not present");
			return;
		}

		animcrow_thread = s3eThreadCreate(RenderCrow, NULL, NULL);*/
		s3eTimerSetTimer(DELAY80, &RenderCrowT, NULL);
	}

	void animateCrowThreadEnd()
	{
		/*s3eThreadCancel(animcrow_thread);
		animcrow_thread = NULL;*/
		s3eTimerCancelTimer(RenderCrowT,NULL);
	}

	void animateCrowThreadInit2()
	{
		/*if (!s3eThreadAvailable())
		{
			s3eDebugErrorPrintf("s3eThread extension not present");
			return;
		}

		animcrow_thread2 = s3eThreadCreate(RenderCrow2, NULL, NULL);
		*/
		
		s3eTimerSetTimer(DELAY80, &RenderCrowT2, NULL);
	}

	void animateCrowThreadEnd2()
	{
		/*s3eThreadCancel(animcrow_thread2);
		animcrow_thread2 = NULL;*/
		
		s3eTimerCancelTimer(RenderCrowT2,NULL);
	}

	
	void animLevelEndStarThreadInit(int id)
	{
		/*
		if (!s3eThreadAvailable())
		{
			s3eDebugErrorPrintf("s3eThread extension not present");
			return;
		}
		if(id == 1)
		{
			animlevelendstar_thread[0] = s3eThreadCreate(RenderLevelEndStar1, NULL, NULL);
			
		}
		else if(id == 2)
		{
			animlevelendstar_thread[0] = s3eThreadCreate(RenderLevelEndStar1, NULL, NULL);
			
			animlevelendstar_thread[1] = s3eThreadCreate(RenderLevelEndStar2, NULL, NULL);
			
		}
		else if(id == 3)
		{
			animlevelendstar_thread[0] = s3eThreadCreate(RenderLevelEndStar1, NULL, NULL);
			
			animlevelendstar_thread[1] = s3eThreadCreate(RenderLevelEndStar2, NULL, NULL);
			
			animlevelendstar_thread[2] = s3eThreadCreate(RenderLevelEndStar3, NULL, NULL);
			
		}*/
		if(id == 1)
		{
			s3eTimerSetTimer(DELAY1500, &RenderLevelEndStarT1, NULL);
		}
		else if(id == 2)
		{
			s3eTimerSetTimer(DELAY1500, &RenderLevelEndStarT1, NULL);
			
			s3eTimerSetTimer(DELAY1500, &RenderLevelEndStarT2, NULL);
			
		}
		else if(id == 3)
		{
			s3eTimerSetTimer(DELAY1500, &RenderLevelEndStarT1, NULL);
			
			s3eTimerSetTimer(DELAY1500, &RenderLevelEndStarT2, NULL);
			
			s3eTimerSetTimer(DELAY1500, &RenderLevelEndStarT3, NULL);
			
		}
	}

	void animLevelEndStarThreadEnd()
	{
		/*s3eThreadCancel(animlevelendstar_thread[0]);
		s3eThreadCancel(animlevelendstar_thread[1]);
		s3eThreadCancel(animlevelendstar_thread[2]);
		
		animlevelendstar_thread[0] = NULL;
		animlevelendstar_thread[1] = NULL;
		animlevelendstar_thread[2] = NULL;*/
		s3eTimerCancelTimer(RenderLevelEndStarT1,NULL);
		s3eTimerCancelTimer(RenderLevelEndStarT2,NULL);
		s3eTimerCancelTimer(RenderLevelEndStarT3,NULL);
	}


	void animGameplayStarThreadInit(int id)
	{
		/*if (!s3eThreadAvailable())
		{
			s3eDebugErrorPrintf("s3eThread extension not present");
			return;
		}
		if(id == 1)
		{
			animgameplaystar_thread[0] = s3eThreadCreate(RenderGameplayStar1, NULL, NULL);
			
		}
		else if(id == 2)
		{
			animgameplaystar_thread[1] = s3eThreadCreate(RenderGameplayStar2, NULL, NULL);
			
		}
		else if(id == 3)
		{
			animgameplaystar_thread[2] = s3eThreadCreate(RenderGameplayStar3, NULL, NULL);
			
		}*/
		if(id == 1)
		{
			s3eTimerSetTimer(DELAY50, &RenderGameplayStarT1, NULL);
		}
		else if(id == 2)
		{
			s3eTimerSetTimer(DELAY50, &RenderGameplayStarT1, NULL);
			s3eTimerSetTimer(DELAY50, &RenderGameplayStarT2, NULL);
		}
		else if(id == 3)
		{
			s3eTimerSetTimer(DELAY50, &RenderGameplayStarT1, NULL);
			s3eTimerSetTimer(DELAY50, &RenderGameplayStarT2, NULL);
			s3eTimerSetTimer(DELAY50, &RenderGameplayStarT3, NULL);
		}
		
		soundPlayer.playStar();
	}

	void animGameplayStarThreadEnd()
	{
		/*s3eThreadCancel(animgameplaystar_thread[0]);
		s3eThreadCancel(animgameplaystar_thread[1]);
		s3eThreadCancel(animgameplaystar_thread[2]);
		
		animgameplaystar_thread[0];
		animgameplaystar_thread[1];
		animgameplaystar_thread[2];*/
		s3eTimerCancelTimer(RenderGameplayStarT1,NULL);
		s3eTimerCancelTimer(RenderGameplayStarT2,NULL);
		s3eTimerCancelTimer(RenderGameplayStarT3,NULL);
	}

	void talkThreadInit()
	{
		/*if (!s3eThreadAvailable())
		{
			s3eDebugErrorPrintf("s3eThread extension not present");
			return;
		}

		talk_thread = s3eThreadCreate(TalkModule, NULL, NULL);*/
		
		s3eTimerSetTimer(DELAY15000, &TalkModuleT, NULL);
	}

	void talkThreadEnd()
	{
		/*s3eThreadCancel(talk_thread);
		talk_thread = NULL;*/
		s3eTimerCancelTimer(TalkModuleT,NULL);
	}

}layout;


void* RenderGameObjects(void* arg)
{
		
	int peak = 10*util.em;

	while (!s3eDeviceCheckQuitRequest())
	{
		if ((util.gameState != util.PLAYING && util.gameState != util.PLAYINGMENU) || layout.gameLayout==NULL)
			break;
		////cout<<"\nTrans"<<layout.gameLayout->gObj.amountTranslate;
		if(layout.gameLayout->gObj.dirTrans)
		{
			if(layout.gameLayout->gObj.amountTranslate<peak)
			{
				layout.gameLayout->gObj.amountTranslate++;
			}
			else
			{
				layout.gameLayout->gObj.dirTrans = false;
			}

		}
		else
		{
			if(layout.gameLayout->gObj.amountTranslate>-peak)
			{
				layout.gameLayout->gObj.amountTranslate--;
			}
			else
			{
				layout.gameLayout->gObj.dirTrans = true;
			}
		}

		if(layout.gameLayout->gObj.dirScale)
		{
			if(layout.gameLayout->gObj.amountScale >= 1.0)
			{	
				layout.gameLayout->gObj.dirScale = false;
			}
			else
			{
				layout.gameLayout->gObj.amountScale+=0.01;
			}
		}
		else
		{
			if(layout.gameLayout->gObj.amountScale <= 0.8)
			{
				layout.gameLayout->gObj.dirScale = true;
			}
			else
			{
				layout.gameLayout->gObj.amountScale-=0.01;
			}
		}

		if(layout.isTalking == 1)
		{
			IwRandSeed((int32)s3eTimerGetMs());
			layout.gameLayout->talkImg = IwRandMinMax(0,5);
		}
		/*else if(!layout.gameLayout->isIntoxicated)
			layout.gameLayout->talkImg = 0;*/

		s3eDeviceYield(50);
		
	}
	
	return NULL;
}

void* RenderCrow(void* arg)
{

	//	s3eDeviceYield(500);
	while (!s3eDeviceCheckQuitRequest())
	{
		
		if ( util.gameState != util.MENU || util.gameState != util.OPTION || layout.menuLayout==NULL )
			break;

		layout.menuLayout->crow.update();
			
		s3eDeviceYield(80);	
	}
	
	return NULL;
}

void* RenderCrow2(void* arg)
{

	//	s3eDeviceYield(500);
	while (!s3eDeviceCheckQuitRequest())
	{
		
		if ( util.gameState != util.THEMEINTRO || layout.themeIntroLayout==NULL)
			break;

		layout.themeIntroLayout->crow.update();
			
		s3eDeviceYield(80);	
	}
	
	return NULL;
}

void* RenderMain(void* arg)
{

	while (!s3eDeviceCheckQuitRequest())
	{
		if (util.gameState != util.PLAYING || util.gameState != util.PLAYINGMENU || layout.gameLayout == NULL || layout.gameLayout->isIntoxicated != true)
			break;
		else if(layout.gameLayout->talkImg == 5)
		{	
			layout.gameLayout->talkImg = 6;
		}
		else
		{
			layout.gameLayout->talkImg = 5;
		}
		s3eDeviceYield(300);
	}
	
	return NULL;
}

void* RenderLevelEndStar1(void* arg)
{
	s3eDeviceYield(1250);
	while (!s3eDeviceCheckQuitRequest())
	{
		if (util.gameState != util.LEVELEND || layout.levelEndLayout == NULL)
			break;
		
		if (layout.levelEndLayout->scale[0]>1.0f)
		{
			layout.levelEndLayout->scale[0]=1.0f;
			if(!layout.levelEndLayout->dropGraphiti)
				layout.levelEndLayout->dropGraphiti=true;
			//cout<<"\nexit RenderLevelEndStar1";
			break;
		}
		else
		{
			//cout<<"\nin RenderLevelEndStar1";
			layout.levelEndLayout->scale[0]+=0.09f;
		}
		
		s3eDeviceYield(50);		
	}
	//soundPlayer.playStar();
	return NULL;
}
void* RenderLevelEndStar2(void* arg)
{
	s3eDeviceYield(1250);
	while (!s3eDeviceCheckQuitRequest())
	{
		if (util.gameState != util.LEVELEND || layout.levelEndLayout == NULL)
			break;

		else if(layout.levelEndLayout->scale[1]>1.0f)
		{
			layout.levelEndLayout->scale[1]=1.0f;
			if(!layout.levelEndLayout->dropGraphiti)
				layout.levelEndLayout->dropGraphiti=true;
			//cout<<"\nexit RenderLevelEndStar1";
			break;
		}
		else
		{
			//cout<<"\nin RenderLevelEndStar2";
			layout.levelEndLayout->scale[1]+=0.09f;
		}
		
		s3eDeviceYield(50);		
	}
	//soundPlayer.playStar();
	return NULL;
}
void* RenderLevelEndStar3(void* arg)
{
	s3eDeviceYield(1250);
	while (!s3eDeviceCheckQuitRequest())
	{
		if (util.gameState != util.LEVELEND || layout.levelEndLayout == NULL)
			break;

		else if (layout.levelEndLayout->scale[2]>1.0f)
		{
			layout.levelEndLayout->scale[2]=1.0f;
			if(!layout.levelEndLayout->dropGraphiti)
				layout.levelEndLayout->dropGraphiti=true;
			//cout<<"\nexit RenderLevelEndStar1";
			break;
		}
		else
		{
			//cout<<"\nin RenderLevelEndStar3";
			layout.levelEndLayout->scale[2]+=0.09f;
		}
		
		s3eDeviceYield(50);		
	}
	//soundPlayer.playStar();
	return NULL;
}

void* RenderGameplayStar1(void* arg)
{
	while (!s3eDeviceCheckQuitRequest())
	{
		if (util.gameState != util.PLAYING || util.gameState != util.PLAYINGMENU || layout.gameLayout == NULL)
			break;
		else if(layout.gameLayout->starScale[0]>1.0f)
		{
			layout.gameLayout->starScale[0]=1.0f;
			//cout<<"\nexit RenderGameplayStar1";
			break;
		}
		else
		{
			//cout<<"\nin RenderGameplayStar1";
			layout.gameLayout->starScale[0]+=0.19f;
		}
		
		s3eDeviceYield(50);		
	}
	return NULL;
}

void* RenderGameplayStar2(void* arg)
{
	while (!s3eDeviceCheckQuitRequest())
	{
		if (util.gameState != util.PLAYING || util.gameState != util.PLAYINGMENU || layout.gameLayout == NULL)
			break;
		else if(layout.gameLayout->starScale[1]>1.0f)
		{
			layout.gameLayout->starScale[1]=1.0f;
			//cout<<"\nexit RenderGameplayStar2";
			break;
		}
		else
		{
			//cout<<"\nin RenderGameplayStar2";
			layout.gameLayout->starScale[1]+=0.19f;
		}
		
		s3eDeviceYield(50);		
	}
	return NULL;
}

void* RenderGameplayStar3(void* arg)
{

	while (!s3eDeviceCheckQuitRequest())
	{
		if (util.gameState != util.PLAYING || util.gameState != util.PLAYINGMENU || layout.gameLayout == NULL)
			break;
		else if(layout.gameLayout->starScale[2]>1.0f)
		{
			layout.gameLayout->starScale[2]=1.0f;
			//cout<<"\nexit RenderGameplayStar3";
			break;
		}
		else
		{
			//cout<<"\nin RenderGameplayStar3";
			layout.gameLayout->starScale[2]+=0.19f;
		}
		
		s3eDeviceYield(50);		
	}
	return NULL;
}


void* TalkModule(void* arg)
{
	s3eDeviceYield(1000);
	while (!s3eDeviceCheckQuitRequest())
	{		
		//cout<<"\nTalk thread on";
		if (util.gameState != util.PLAYING || layout.gameLayout == NULL)
			break;
		else if(!layout.gameLayout->isIntoxicated && util.gameState == util.PLAYING)
		{
			//cout<<"\nTalking";
			layout.isTalking = 1;
			soundPlayer.playTalk(&layout.isTalking);
		}
		s3eDeviceYield(5000);				
	}
	return NULL;
}


//TIMERS

static int32 RenderCrowT(void *systemData, void *userData)
{

	layout.menuLayout->crow.update();

	s3eTimerSetTimer(DELAY80, &RenderCrowT, NULL);
	
	return NULL;
}

static int32 RenderCrowT2(void *systemData, void *userData)
{

	layout.themeIntroLayout->crow.update();

	s3eTimerSetTimer(DELAY80, &RenderCrowT2, NULL);

	return NULL;
}

static int32 RenderMainT(void *systemData, void *userData)
{

	if(layout.gameLayout->talkImg == 5)
	{	
		layout.gameLayout->talkImg = 6;
	}
	else
	{
		layout.gameLayout->talkImg = 5;
	}
	
	s3eTimerSetTimer(DELAY100, &RenderMainT, NULL);

	return NULL;
}

static int32 RenderLevelEndStarT1(void *systemData, void *userData)
{
	
		if (layout.levelEndLayout->scale[0]>1.0f)
		{
			layout.levelEndLayout->scale[0]=1.0f;
			if(!layout.levelEndLayout->dropGraphiti)
				layout.levelEndLayout->dropGraphiti=true;
			//cout<<"\nexit RenderLevelEndStar1";

		}
		else
		{
			//cout<<"\nin RenderLevelEndStar1";
			layout.levelEndLayout->scale[0]+=0.19f;
			s3eTimerSetTimer(DELAY50, &RenderLevelEndStarT1, NULL);
		}
		
	return NULL;
}


static int32 RenderLevelEndStarT2(void *systemData, void *userData)
{

		if(layout.levelEndLayout->scale[1]>1.0f)
		{
			layout.levelEndLayout->scale[1]=1.0f;
			if(!layout.levelEndLayout->dropGraphiti)
				layout.levelEndLayout->dropGraphiti=true;
			//cout<<"\nexit RenderLevelEndStar1";
		}
		else
		{
			//cout<<"\nin RenderLevelEndStar2";
			layout.levelEndLayout->scale[1]+=0.19f;
			s3eTimerSetTimer(DELAY50, &RenderLevelEndStarT2, NULL);
		}
			
	
	//soundPlayer.playStar();
	return NULL;
}


static int32 RenderLevelEndStarT3(void *systemData, void *userData)
{

		if (layout.levelEndLayout->scale[2]>1.0f)
		{
			layout.levelEndLayout->scale[2]=1.0f;
			if(!layout.levelEndLayout->dropGraphiti)
				layout.levelEndLayout->dropGraphiti=true;
			//cout<<"\nexit RenderLevelEndStar1";
		}
		else
		{
			//cout<<"\nin RenderLevelEndStar3";
			layout.levelEndLayout->scale[2]+=0.19f;
			s3eTimerSetTimer(DELAY50, &RenderLevelEndStarT3, NULL);
		}
			

	return NULL;
}

static int32 RenderGameplayStarT1(void *systemData, void *userData)
{

		if(layout.gameLayout->starScale[0]>1.0f)
		{
			layout.gameLayout->starScale[0]=1.0f;
		}
		else
		{
			layout.gameLayout->starScale[0]+=0.19f;
			s3eTimerSetTimer(DELAY50, &RenderGameplayStarT1, NULL);
		}
		
	return NULL;
}

static int32 RenderGameplayStarT2(void *systemData, void *userData)
{
		
	if(layout.gameLayout->starScale[1]>1.0f)
	{
		layout.gameLayout->starScale[1]=1.0f;

	}
	else
	{
			//cout<<"\nin RenderGameplayStar2";
		layout.gameLayout->starScale[1]+=0.19f;
		s3eTimerSetTimer(DELAY50, &RenderGameplayStarT2, NULL);
	}
		
	return NULL;
}

static int32 RenderGameplayStarT3(void *systemData, void *userData)
{

	if(layout.gameLayout->starScale[2]>1.0f)
	{
		layout.gameLayout->starScale[2]=1.0f;
	}
	else
	{
		//cout<<"\nin RenderGameplayStar3";
		layout.gameLayout->starScale[2]+=0.19f;
		s3eTimerSetTimer(DELAY50, &RenderGameplayStarT3, NULL);
	}
	
	return NULL;
}


static int32 RenderGameObjectsT(void *systemData, void *userData)
{
		
	int peak = 10*util.em;

	////cout<<"\nTrans"<<layout.gameLayout->gObj.amountTranslate;
	if(layout.gameLayout->gObj.dirTrans)
	{
		if(layout.gameLayout->gObj.amountTranslate<peak)
		{
			layout.gameLayout->gObj.amountTranslate++;
		}
		else
		{
			layout.gameLayout->gObj.dirTrans = false;
		}

	}
	else
	{
		if(layout.gameLayout->gObj.amountTranslate>-peak)
		{
			layout.gameLayout->gObj.amountTranslate--;
		}
		else
		{
			layout.gameLayout->gObj.dirTrans = true;
		}
	}
		if(layout.gameLayout->gObj.dirScale)
	{
		if(layout.gameLayout->gObj.amountScale >= 1.0)
		{	
			layout.gameLayout->gObj.dirScale = false;
		}
		else
		{
			layout.gameLayout->gObj.amountScale+=0.01;
		}
	}
	else
	{
		if(layout.gameLayout->gObj.amountScale <= 0.8)
		{
			layout.gameLayout->gObj.dirScale = true;
		}
		else
		{
			layout.gameLayout->gObj.amountScale-=0.01;
		}
	}

	if(layout.isTalking == 1)
	{
		IwRandSeed((int32)s3eTimerGetMs());
		layout.gameLayout->talkImg = IwRandMinMax(0,5);
	}

		
	s3eTimerSetTimer(DELAY50, &RenderGameObjectsT, NULL);
	return NULL;
}

static int32 TalkModuleT(void *systemData, void *userData)
{

	layout.isTalking = 1;
	soundPlayer.playTalk(&layout.isTalking);
			
	s3eTimerSetTimer(DELAY30000, &TalkModuleT, NULL);
	return NULL;
}


#endif