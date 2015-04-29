
#ifndef TOUCH_H
#define TOUCH_H

#include "s3e.h"
#include "IwDebug.h"
#include "IwGxPrint.h"
#include "Iw2D.h"
#include "../layout/layout.h"
#include "storage.h"
#include "Tray.h"
#include "Collision.h"
#include "AudioPlayer.h"
#include "../h/NotificationSystem.h"
#include <math.h>
//#include "iad.h"
#include <Math.h>

using namespace std;

class Touch
{
	//int blockSize;
	bool touchOn; 
	bool collisionCheckUp;
	bool collisionCheckDown;
	bool collisionCheckLeft;
	bool collisionCheckRight;
	
public:
	//IAd *iad;
	int touchX; 
	int touchY; 
	int touch_oldX; 
	int touch_oldY; 
	int BLOCK3_4th; 
	int BLOCK1_10th;
	enum touchAxis{
		axisX,
		axisY,
		axisNone}tAxis;

	int touchID;
	Touch()
	{
		//BLOCK3_4th = util.BLOCKSIZE*80/100;
		//BLOCK1_10th = util.BLOCKSIZE*5/100;
		//BLOCK3_4th = util.BLOCKSIZE/20;
		//BLOCK1_10th = util.BLOCKSIZE*4/5;
		//iad = NULL;
		//BLOCK3_4th = 40;
		//BLOCK1_10th = 5;
		//blockSize = size;
		//touchOn = false;
		//touchID = 0;
		refresh(false);
	}
	/*void setIad(IAd *_iad)
	{
		iad = _iad;
	}*/
	void getTouch()
	{
		touchX = s3ePointerGetX();
		touchY = s3ePointerGetY();
		//if(iad->isShown())
		//touchY - iad->isShown();
	}
	Touch(int size)
	{
		//blockSize = size;
		refresh(false);
	}
	void setBlockDelta()//int b34,int b110)
	{
		BLOCK3_4th = util.BLOCKSIZE*80/100;
		BLOCK1_10th = util.BLOCKSIZE*5/100;
		//BLOCK3_4th = b34;
		//BLOCK1_10th = b110;
	}
	void resetDeltaX()
	{
		//touchX = 0;
		touch_oldX = touchX; 
		//touchOn = false;
	}	
	void resetDeltaY()
	{
		//touchY = 0;	
		touch_oldY = touchY;
		//touchOn = false;
	}

	void refresh(bool id)
	{	
		//touchX = 0;
		//touchY = 0;	
		if(id)
		{	
			touchOn = false;
			touchID = 0;
		}
		tAxis = axisNone;
		
		touch_oldX = touchX; 
		touch_oldY = touchY;

		collisionCheckUp = false;
		collisionCheckDown = false;
		collisionCheckLeft = false;
		collisionCheckRight = false;
	}
	int getDelta()
	{
		return sqrt(SQR(touchX-touch_oldX)-SQR(touchY-touch_oldY));
	}
	int getDeltaX()
	{
		if(tAxis == axisNone || tAxis == axisX)
			return touchX-touch_oldX;
		else
			return 0;
	}
	int getDeltaY()
	{
		if(tAxis == axisNone || tAxis == axisY)
			return touchY-touch_oldY;
		else
			return 0;
	}
	
	inline void toTrophy()
	{
		util.gameState = util.TROPHY;
		util.displayReset = true;
	}

	inline void toToggleMute()
	{
		if(storage.userData.snd)
		{
			audioPlayer.stopMusic();
			storage.userData.snd = false;
		}
		else
		{
			storage.userData.snd = true;
			audioPlayer.playMenu(storage.userData.snd);
		}
	}

	inline void toToggleVibrate()
	{
		if(storage.userData.vib)
			storage.userData.vib = false;
		else
			storage.userData.vib = true;
	}
	
	inline void toInfo()
	{
		//audioPlayer.playCredits(storage.userData.snd);
		toExitMenuOption();
		util.gameState = util.INFO;
		util.displayReset = true;
	}
	

	inline void toExitInfo()
	{		
		//audioPlayer.playMenu(storage.userData.snd);
		util.gameState = util.MENU;
		util.prevState = util.INFO;
		util.displayReset = true;
	}
	inline void toExitTrophy()
	{
		util.gameState = util.MENU;
		util.displayReset = true;
	}

	inline void toExitMenuOption()
	{
		layout.menuLayout->destructOptionMenuLayout();
		util.gameState = util.MENU;
	}

	inline void toGameMenuQuit()
	{		
		util.flurryAnalytics.logRestartQuit(storage.getLevel());
		audioPlayer.playMenu(storage.userData.snd);
		layout.gameLayout->gameMenuLayout->quit();
		util.prevState = util.PLAYINGMENU;
		util.gameState = util.LEVELSELECT;
		util.displayReset = true;
	}
	inline void toGameMenuReset()
	{		
		util.flurryAnalytics.logRestartQuit(storage.getLevel());
		audioPlayer.playGameplay(storage.userData.snd);
		layout.gameLayout->gameMenuLayout->quit();
		//cout<<"\n!!!!!!!!!level set as"<<(10*(storage.userData.currTheme-1))+storage.userData.currLevel;
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;

		util.displayReset = true;
		util.gameState = util.PLAYING;
		util.prevState = util.PLAYINGMENU;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}
	inline void toGameMenuResume()
	{
		layout.gameLayout->destructGameMenu();
		util.gameState = util.PLAYING;
	}

	inline void toEndLevel()
	{
		refresh(true);
		soundPlayer.playEndTalk();
		audioPlayer.stopMusic();		
		soundPlayer.playEnd();

		vibrate.vibrate01();
		//cout<<"\n finished";
		
		layout.jigSaw[0].setRow(layout.jigSaw[1].row);
		layout.jigSaw[0].setColumn(layout.jigSaw[1].column);
		//happy face
		layout.gameLayout->talkImg = 3;
		layout.gameLayout->spDone.render();
		
		
		util.prevState = util.PLAYING;
		util.gameState = util.LEVELEND;
		//cout<<"\n!!!!!!!!!statechange"<<util.gameState;
		util.displayReset = true;
	}


	inline void toExitLevelEndToMenu()
	{
		audioPlayer.playMenu(storage.userData.snd);
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		util.gameState = util.MENU;
		util.prevState = util.LEVELEND;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;

	}	
	bool showIntro()
	{
		if(storage.userData.currLevel % 21 == 0 || storage.userData.currLevel == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	inline void exitThemeIntroToGame()
	{
		util.displayReset = true;
		util.gameState = util.PLAYING;
		util.prevState = util.THEMEINTRO;
	}

	inline void calculateProgress()
	{
		if( storage.userData.currLevel < 20 )
		{				
			storage.userData.currLevel++;
			//cout<<"\nto next level "<<storage.userData.currLevel;				
		}
		else
		{
			if(storage.userData.currTheme<=2)			
			{
				storage.userData.currTheme++;
				storage.userData.currLevel=1;
			}
			else	
			{
				storage.userData.currTheme=1;
				storage.userData.currLevel=1;
			}
		}
	}
	inline void toExitlevelEndToNextLevel()
	{
		
		calculateProgress();
		util.displayReset = true;
		if(!showIntro())
			util.gameState = util.PLAYING;
		else
			util.gameState = util.THEMEINTRO;
		util.prevState = util.LEVELEND;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}
	inline void toExitlevelReset()
	{
		util.displayReset = true;		
		util.gameState = util.PLAYING;	
		util.prevState = util.LEVELEND;
	}
	
	inline void toLevelGame(int level)
	{
		storage.userData.currLevel = level;
		//cout<<"\n!!!!!!!!!level set as"<<(10*(storage.userData.currTheme-1))+level;
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		
		util.displayReset = true;
		if(!showIntro())
			util.gameState = util.PLAYING;
		else
			util.gameState = util.THEMEINTRO;
		util.prevState = util.LEVELSELECT;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
		
	}

	inline void toExitCart()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;

		util.displayReset = true;
		util.gameState = util.MENU;
		util.prevState = util.CART;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}
	inline void toExitEditorToMenu()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		util.gameState = util.MENU;
		util.prevState = util.EDITOR;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}
	inline void toMenuOption()
	{
		util.gameState = util.OPTION;
		util.displayReset = true;
	}
	inline void toCart()
	{
		util.gameState = util.CART;
		util.prevState = util.MENU;
		util.displayReset = true;
	}

	inline void toExitGameToMenu()
	{
		util.gameState = util.PLAYINGMENU;
		util.displayReset = true;
	}

	inline void toMenuThemeSelect()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		util.gameState = util.THEMESELECT;
		util.prevState = util.MENU;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	inline void toThemeLevelSelect(int theme)
	{
		storage.userData.currTheme = theme;
		//cout<<"\n!!!!!!!!!theme set as"<<theme;
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		
		util.gameState = util.LEVELSELECT;
		util.prevState = util.THEMESELECT;
		
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
		
	}

	inline void toEdThemeEdLevelSelect(int theme)
	{
		storage.userData.currTheme = theme;
		//cout<<"\n!!!!!!!!!theme set as"<<theme;
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
	
		util.gameState = util.EDITORLEVEL;
		util.prevState = util.EDITORTHEME;
		
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	inline void toExitThemeToMenu()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		util.gameState = util.MENU;
		util.prevState = util.THEMESELECT;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	inline void toExitLevelTheme()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		util.gameState = util.THEMESELECT;
		util.prevState = util.LEVELSELECT;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	
	inline void toMenuEdThemeSel()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		util.gameState = util.EDITORTHEME;
		util.prevState = util.MENU;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	inline void toEdLevelEditor(int level)
	{
		storage.userData.currLevel = level;
		//cout<<"\n!!!!!!!!!level set as"<<level;
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.displayReset = true;
		util.gameState = util.EDITOR;
		util.prevState = util.EDITORLEVEL;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	inline void toBlockSelect()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.gameState = util.BLOCKSELECT;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	inline void toBlockDelete()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.gameState = util.BLOCKDELETE;
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}

	inline void toSaveLevel()
	{
		char *tmp = NULL;
		//cout<<"\nsaving level...";
		layout.editorLayout->makeLevel(getTrayMatrix());
		//cout<<"\nlevel saved sucessfully!";
	}
	
	inline void toReturnEditor()
	{
		//cout<<"\n!!!!!!!!!statechange from"<<util.gameState;
		util.gameState = util.EDITOR;
		tray.genCollisionMap(layout.jigSaw);
		//cout<<"\n!!!!!!!!!statechange to"<<util.gameState;
	}


	char* getTrayMatrix()
	{
		char *temp =  (char*)s3eMallocBase(500);
		char r1[5][40];
		char r2[5][40];
		//cout<<"\ndumping level:";
		for(int i=0;i<5;i++)
		{
			int row[9] = {0,0,0,0,0,0,0,0,0};
			int row2[9] = {0,0,0,0,0,0,0,0,0};

			for(int j=0;j<9;j++)
			{
				char *tmp = (char*)s3eMallocBase(3);
				for(int k=0;k<layout.jigSaw.size();k++)
				{
					if(layout.jigSaw[k].column == i && layout.jigSaw[k].row == j)
					{
						if(row[j] == 0)
							row[j] = layout.jigSaw[k].getCode();
						else
							row2[j] = layout.jigSaw[k].getCode();
					}
				}
			}
			
			sprintf(r1[i],"\r\n\t\t r_1%i\t%02i.%02i.%02i.%02i.%02i.%02i.%02i.%02i.%02i",i+1,row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8]);
			sprintf(r2[i],"\r\n\t\t r_2%i\t%02i.%02i.%02i.%02i.%02i.%02i.%02i.%02i.%02i",i+1,row2[0],row2[1],row2[2],row2[3],row2[4],row2[5],row2[6],row2[7],row2[8]);
			//cout<<"\nr1"<<i<<":"<<r1[i];
			//cout<<"\nr2"<<i<<":"<<r2[i];
		}
		//cout<<"\n";
		//cout<<"\nend of dumping level:";

		sprintf(temp,"\r\n\t%s%s%s%s%s\r\n\r\n\r\n\t%s%s%s%s%s",r1[0],r1[1],r1[2],r1[3],r1[4],r2[0],r2[1],r2[2],r2[3],r2[4]);
		return temp;
	}

	void levelEndTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				
	//========================================================
				if(layout.levelEndLayout->cNext.listen(touchX, touchY))
				{//cNext
					touchOn = true;
					touchID = 1;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.levelEndLayout->cNext.render(true);
				}
				else
				{
					layout.levelEndLayout->cNext.render(false);
				}//cNext
	//========================================================
				if(layout.levelEndLayout->cReset.listen(touchX, touchY))
				{//cReset
					touchOn = true;
					touchID = 2;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.levelEndLayout->cReset.render(true);
				}
				else
				{
					layout.levelEndLayout->cReset.render(false);
				}//cReset
	//========================================================
				if(layout.levelEndLayout->cLMenu.listen(touchX, touchY))
				{//cLMenu
					touchOn = true;
					touchID = 3;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.levelEndLayout->cLMenu.render(true);
				}
				else
				{
					layout.levelEndLayout->cLMenu.render(false);
				}//cLMenu
				
	//========================================================
				if(layout.levelEndLayout->cFB.listen(touchX, touchY))
				{//cLMenu
					touchOn = true;
					touchID = 4;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.levelEndLayout->cFB.render(true);
				}
				else
				{
					layout.levelEndLayout->cFB.render(false);
				}//cFB


				return;
			}//!touchOn
			else
			{
				////cout<<"\n>>>>>>>>>>>>>>touchED";
	//========================================================
				if(touchID == 1 && layout.levelEndLayout->cNext.listen(touchX, touchY))
				{
					layout.levelEndLayout->cNext.render(true);
				}
				else
				{
					layout.levelEndLayout->cNext.render(false);
				}
	//========================================================
				if(touchID == 2 && layout.levelEndLayout->cReset.listen(touchX, touchY))
				{
					layout.levelEndLayout->cReset.render(true);
				}
				else
				{
					layout.levelEndLayout->cReset.render(false);
				}
	//========================================================
				if(touchID == 3 && layout.levelEndLayout->cLMenu.listen(touchX, touchY))
				{
					layout.levelEndLayout->cLMenu.render(true);
				}
				else
				{
					layout.levelEndLayout->cLMenu.render(false);
				}
	//========================================================
				if(touchID == 4 && layout.levelEndLayout->cFB.listen(touchX, touchY))
				{
					layout.levelEndLayout->cFB.render(true);
				}
				else
				{
					layout.levelEndLayout->cFB.render(false);
				}
	//========================================================
				return;
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	if(touchID == 1)
				{
				
					toExitlevelEndToNextLevel();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 2)
				{
					toExitlevelReset();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 3)
				{
					toExitLevelEndToMenu();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 4)
				{
					layout.levelEndLayout->FBPost();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
			}

			touchOn = false;
			touchID = 0;
			layout.levelEndLayout->cNext.render(false);
			layout.levelEndLayout->cReset.render(false);
			layout.levelEndLayout->cFB.render(false);
			layout.levelEndLayout->cLMenu.render(false);
			return;
		}	
	}
	
	void menuTouchwSocial()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				////cout<<"\n>>>>>>>>>>>>>>touchOn";
				//if(touchX<200 && touchY<200)
				//{
					//touchOn = true;
					//touchID = 100;
				//}
	//========================================================
				if(layout.menuLayout->cPlay.listen(touchX, touchY))
				{//play
					touchOn = true;
					touchID = 1;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cPlay.render(true);
				}
				else
				{
					layout.menuLayout->cPlay.render(false);
				}//play
	//========================================================
				if(layout.menuLayout->cOption.listen(touchX, touchY))
				{//settings
					touchOn = true;
					touchID = 2;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cOption.render(true);
				}
				else
				{
					layout.menuLayout->cOption.render(false);
				}//settings
				
	//========================================================
				if(layout.menuLayout->cTrophy.listen(touchX, touchY))
				{//trophy
					touchOn = true;
					touchID = 3;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cTrophy.render(true);
				}
				else
				{
					layout.menuLayout->cTrophy.render(false);
				}//trophy
	//========================================================
				if(layout.menuLayout->cCart.listen(touchX, touchY))
				{//cart
					touchOn = true;
					touchID = 4;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cCart.render(true);
				}
				else
				{
					layout.menuLayout->cCart.render(false);
				}//cart
	//========================================================
				if(layout.menuLayout->cFb.listen(touchX, touchY))
				{//fb
					touchOn = true;
					touchID = 5;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cFb.render(true);
				}
				else
				{
					layout.menuLayout->cFb.render(false);
				}//fb
				
	//========================================================
				if(layout.menuLayout->cTw.listen(touchX, touchY))
				{//tw
					touchOn = true;
					touchID = 6;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cTw.render(true);
				}
				else
				{
					layout.menuLayout->cTw.render(false);
				}//tw

			}//!touchOn
			else
			{
				////cout<<"\n>>>>>>>>>>>>>>touchED";
	//========================================================
				if(touchID == 1 && layout.menuLayout->cPlay.listen(touchX, touchY))
				{
					layout.menuLayout->cPlay.render(true);
				}
				else
				{
					layout.menuLayout->cPlay.render(false);
				}
	//========================================================
				if(touchID == 2 && layout.menuLayout->cOption.listen(touchX, touchY))
				{
					layout.menuLayout->cOption.render(true);
				}
				else
				{
					layout.menuLayout->cOption.render(false);
				}
	//========================================================
				if(touchID == 3 && layout.menuLayout->cTrophy.listen(touchX, touchY))
				{
					layout.menuLayout->cTrophy.render(true);
				}
				else
				{
					layout.menuLayout->cTrophy.render(false);
				}
	//========================================================
				if(touchID == 4 && layout.menuLayout->cCart.listen(touchX, touchY))
				{
					layout.menuLayout->cCart.render(true);
				}
				else
				{
					layout.menuLayout->cCart.render(false);
				}
	//========================================================
				if(touchID == 5 && layout.menuLayout->cFb.listen(touchX, touchY))
				{
					layout.menuLayout->cFb.render(true);
				}
				else
				{
					layout.menuLayout->cFb.render(false);
				}
	//========================================================
				if(touchID == 6 && layout.menuLayout->cTw.listen(touchX, touchY))
				{
					layout.menuLayout->cTw.render(true);
				}
				else
				{
					layout.menuLayout->cTw.render(false);
				}
	//========================================================
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	
				if(touchID == 1)
				{
				
					toMenuThemeSelect();
					//touchOn = false;
					//touchID = 0;
					//return;

				}
				else if(touchID == 2)
				{
					toMenuOption();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 3)
				{
					toTrophy();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 4)
				{
					toCart();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 5)
				{
					layout.menuLayout->toFb();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 6)
				{
					layout.menuLayout->toTw();
				///	touchOn = false;
				//	touchID = 0;
				//	return;
				}
				else if(touchID == 100)
				{
					toMenuEdThemeSel();
				}
			}

			touchOn = false;
			touchID = 0;
			layout.menuLayout->cOption.render(false);
			layout.menuLayout->cPlay.render(false);
			layout.menuLayout->cTrophy.render(false);
			layout.menuLayout->cCart.render(false);
			layout.menuLayout->cFb.render(false);
			layout.menuLayout->cTw.render(false);
			return;
		}
	}
	void themeIntroTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				touchOn = true;
				touchID = 100;
			}
		}
		else
		{
			if(touchOn)
			{
				if(touchID == 100)
				{
					exitThemeIntroToGame();
				}
			}
			touchOn = false;
			touchID = 0;
		}
	}
	void menuTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				////cout<<"\n>>>>>>>>>>>>>>touchOn";
				//if(touchX<200 && touchY<200)
				//{
					//touchOn = true;
					//touchID = 100;
				//}
	//========================================================
				if(layout.menuLayout->cPlay.listen(touchX, touchY))
				{//play
					touchOn = true;
					touchID = 1;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cPlay.render(true);
				}
				else
				{
					layout.menuLayout->cPlay.render(false);
				}//play
	//========================================================
				if(layout.menuLayout->cOption.listen(touchX, touchY))
				{//settings
					touchOn = true;
					touchID = 2;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cOption.render(true);
				}
				else
				{
					layout.menuLayout->cOption.render(false);
				}//settings
				
	//========================================================
				if(layout.menuLayout->cTrophy.listen(touchX, touchY))
				{//settings
					touchOn = true;
					touchID = 3;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cTrophy.render(true);
				}
				else
				{
					layout.menuLayout->cTrophy.render(false);
				}//settings

	//========================================================
				if(layout.menuLayout->cCart.listen(touchX, touchY))
				{//cart
					touchOn = true;
					touchID = 4;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->cCart.render(true);
				}
				else
				{
					layout.menuLayout->cCart.render(false);
				}//cart
	//========================================================
				
			}//!touchOn
			else
			{
				////cout<<"\n>>>>>>>>>>>>>>touchED";
	//========================================================
				if(touchID == 1 && layout.menuLayout->cPlay.listen(touchX, touchY))
				{
					layout.menuLayout->cPlay.render(true);
				}
				else
				{
					layout.menuLayout->cPlay.render(false);
				}
	//========================================================
				if(touchID == 2 && layout.menuLayout->cOption.listen(touchX, touchY))
				{
					layout.menuLayout->cOption.render(true);
				}
				else
				{
					layout.menuLayout->cOption.render(false);
				}
	//========================================================
				if(touchID == 3 && layout.menuLayout->cTrophy.listen(touchX, touchY))
				{
					layout.menuLayout->cTrophy.render(true);
				}
				else
				{
					layout.menuLayout->cTrophy.render(false);
				}
	//========================================================
				if(touchID == 4 && layout.menuLayout->cCart.listen(touchX, touchY))
				{
					layout.menuLayout->cCart.render(true);
				}
				else
				{
					layout.menuLayout->cCart.render(false);
				}

	//========================================================
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	
				if(touchID == 1)
				{
				
					toMenuThemeSelect();
					//touchOn = false;
					//touchID = 0;
					//return;

				}
				else if(touchID == 2)
				{
					toMenuOption();
					//touchOn = false;
					///touchID = 0;
					//return;
				}
				else if(touchID == 3)
				{
					toMenuOption();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 4)
				{
					toCart();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				
				else if(touchID == 100)
				{
					toMenuEdThemeSel();
				}
			}

			touchOn = false;
			touchID = 0;
			layout.menuLayout->cOption.render(false);
			layout.menuLayout->cPlay.render(false);
			layout.menuLayout->cTrophy.render(false);
			layout.menuLayout->cCart.render(false);
			return;
		}
	}

	void infoTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				////cout<<"\n>>>>>>>>>>>>>>touchOn";
				
	//========================================================
				if(layout.menuLayout->infoLayout->cBack.listen(touchX, touchY))
				{//back
					touchOn = true;
					touchID = 1;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->infoLayout->cBack.render(true);
				}
				else
				{
					layout.menuLayout->infoLayout->cBack.render(false);
				}//back
	
			}//!touchOn
			else
			{
				////cout<<"\n>>>>>>>>>>>>>>touchED";
	//========================================================
				if(touchID == 1 && layout.menuLayout->infoLayout->cBack.listen(touchX, touchY))
				{
					layout.menuLayout->infoLayout->cBack.render(true);
				}
				else
				{
					layout.menuLayout->infoLayout->cBack.render(false);
				}
	//========================================================
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	
				if(touchID == 1)
				{
				
					toExitInfo();
					touchOn = false;
					touchID = 0;
					//return;

				}
			}

			touchOn = false;
			touchID = 0;
			layout.menuLayout->infoLayout->cBack.render(false);
			return;
		}
	}
	
	void trophyTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);
		//	//cout<<"\n>>>>>>>>>>>>oy<<"<<touch_oldY<<">y<<"<<touchY<<">acc<<"<<layout.trophyLayout->pos;
		
			if(!touchOn)
			{
				////cout<<"\n>>>>>>>>>>>>>>touchOn";
				touchOn = true;
				//touch_oldX = touchX;
				touch_oldY = touchY;
	//========================================================
				if(layout.trophyLayout->cBack.listen(touchX, touchY))
				{//back
					touchOn = true;
					touchID = 1;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.trophyLayout->cBack.render(true);
				}
				else
				{
					layout.trophyLayout->cBack.render(false);
				}//back
	
			}//!touchOn
			else
			{
				////cout<<"\n>>>>>>>>>>>>>>touchED";
	//========================================================
				if(touchID == 1 && layout.trophyLayout->cBack.listen(touchX, touchY))
				{
					layout.trophyLayout->cBack.render(true);
				}
				else
				{
					layout.trophyLayout->cBack.render(false);
				}
	//========================================================

				if(touch_oldY-touchY < 0 && layout.trophyLayout->pos<=layout.trophyLayout->limitU)	
				{
					layout.trophyLayout->pos +=layout.trophyLayout->acc ;
				}
				else if(touch_oldY-touchY > 0 && layout.trophyLayout->pos>=layout.trophyLayout->limitD)	
				{
					layout.trophyLayout->pos -=layout.trophyLayout->acc ;
				}
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	
				if(touchID == 1)
				{
				
					toExitTrophy();
					//touchOn = false;
					//touchID = 0;
					//return;

				}

				touchOn = false;
				touchID = 0;
				touch_oldX = 0;
				touch_oldY = 0;
				touchX = 0;
				touchY = 0;
			}
			layout.trophyLayout->normalize();
			
			layout.trophyLayout->cBack.render(false);
			return;
		}
	}

	void themeScrollTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			layout.themeScrollLayout->touchOn = true;
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				//layout.themeScrollLayout->speed = 1;
				touchOn = true;
				touch_oldX = touchX;
				touch_oldY = touchY;
				
	//========================================================
				//if(layout.themeScrollLayout->speed == 0)
				{
					if(layout.themeScrollLayout->isValid)
					{
						if(layout.themeScrollLayout->cNext.listen(touchX, touchY))
						{//ok

							touchOn = true;
							touchID = 1;
							vibrate.vibrate10();
							soundPlayer.playPress();
							layout.themeScrollLayout->cNext.render(true);
						}
						else
						{
							layout.themeScrollLayout->cNext.render();
						}//ok
					}
					else
					{
						touchID = 0;
						layout.themeScrollLayout->cNext.render(false);
					}
				}
	//========================================================
	//========================================================
				if(layout.themeScrollLayout->cBack.listen(touchX, touchY))
				{//back
					touchOn = true;
					touchID = 2;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.themeScrollLayout->cBack.render(true);
				}
				else
				{
					layout.themeScrollLayout->cBack.render(false);
				}//back
	//========================================================
			


				return;
			}
			else
			{
				
	//========================================================
				//if(layout.themeScrollLayout->speed == 0)
				{
					if(layout.themeScrollLayout->isValid)
					{
						if(touchID == 1 && layout.themeScrollLayout->cNext.listen(touchX, touchY))
						{
							layout.themeScrollLayout->cNext.render(true);
						}
						else
						{
							layout.themeScrollLayout->cNext.render();
						}
					}
					else
					{
						if(touchID == 1)
							touchID = 0;
						layout.themeScrollLayout->cNext.render(false);
					}
				}
	//========================================================

	//========================================================
				if(touchID == 2 && layout.themeScrollLayout->cBack.listen(touchX, touchY))
				{
					layout.themeScrollLayout->cBack.render(true);
				}
				else
				{
					layout.themeScrollLayout->cBack.render(false);
				
	//========================================================

				//if(layout.themeScrollLayout->dx < layout.themeScrollLayout->theme5x && layout.themeScrollLayout->dx > layout.themeScrollLayout->theme1x)
				/*if(touch_oldX-touchX < -layout.themeScrollLayout->acc && layout.themeScrollLayout->dx-50 > 0)	
				{
					layout.themeScrollLayout->dx -=layout.themeScrollLayout->acc ;
				}
				else if(touch_oldX-touchX > layout.themeScrollLayout->acc && layout.themeScrollLayout->dx+layout.themeScrollLayout->acc < layout.themeScrollLayout->theme5x)	
					layout.themeScrollLayout->dx +=layout.themeScrollLayout->acc ;
				else if(layout.themeScrollLayout->dx+(touch_oldX-touchX) > 0 && layout.themeScrollLayout->dx+(touch_oldX-touchX) < layout.themeScrollLayout->theme5x)
					layout.themeScrollLayout->dx +=touch_oldX-touchX;
					*/
				if(touch_oldX-touchX < -layout.themeScrollLayout->acc && layout.themeScrollLayout->dx-50 > 0)	
				{
					layout.themeScrollLayout->dx -=layout.themeScrollLayout->acc ;
						if(layout.themeScrollLayout->themeID>1 && !layout.themeScrollLayout->swiped)
						{
							soundPlayer.playScroll();
							layout.themeScrollLayout->themeID--;
							layout.themeScrollLayout->jumbleText();
							//cout<<"\n\n\nchange theme-"<<layout.themeScrollLayout->themeID;
							touchOn = false;
							layout.themeScrollLayout->swiped = true;
						}
				}
				else if(touch_oldX-touchX > layout.themeScrollLayout->acc && layout.themeScrollLayout->dx+layout.themeScrollLayout->acc < layout.themeScrollLayout->theme5x)	
				{
					layout.themeScrollLayout->dx +=layout.themeScrollLayout->acc ;	
						if(layout.themeScrollLayout->themeID<5 && !layout.themeScrollLayout->swiped)
						{	
							soundPlayer.playScroll();
							layout.themeScrollLayout->themeID++;
							layout.themeScrollLayout->jumbleText();
							//cout<<"\n\n\nchange theme+"<<layout.themeScrollLayout->themeID;
							touchOn = false;	
							layout.themeScrollLayout->swiped = true;
						}
				}
				else if(layout.themeScrollLayout->dx+(touch_oldX-touchX) > 0 && layout.themeScrollLayout->dx+(touch_oldX-touchX) < layout.themeScrollLayout->theme5x)
				{
					layout.themeScrollLayout->dx +=touch_oldX-touchX;
					layout.themeScrollLayout->swiped = false;
					/*if(touch_oldX-touchX < -layout.themeScrollLayout->acc)
					{
					}
					else if(touch_oldX-touchX > layout.themeScrollLayout->acc)
					{						
					}*/
				}
				return;
				}
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			layout.themeScrollLayout->touchOn = false;
			if(touchOn)
			{	
				
				if(touchID == 1)
				{					

					//cout<<"level selected : "<<layout.themeScrollLayout->themeID;
					toThemeLevelSelect(layout.themeScrollLayout->themeID);

					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else if(touchID == 2)
				{
					toExitThemeToMenu();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				else
				{					
					layout.themeScrollLayout->jumbleText();
				}
			}

			touchOn = false;
			touchID = 0;
			
			
			layout.themeScrollLayout->cBack.render(false);
			if(layout.themeScrollLayout->isValid)
			{
				layout.themeScrollLayout->cNext.render();
			}
			else
			{
				layout.themeScrollLayout->cNext.render(false);
			}
			return;
		}
	}
	
	void cartTouch()
	{
		
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			touchX = s3ePointerGetX();
			touchY = s3ePointerGetY();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				
	//========================================================
				if(layout.cartLayout->cBack.listen(touchX, touchY))
				{//th1
					touchOn = true;
					touchID = 1;
					soundPlayer.playPress();
					layout.cartLayout->cBack.render(true);
				}
				else
				{
					layout.cartLayout->cBack.render(false);
				}//back
	//========================================================
	//========================================================
				if(layout.cartLayout->cart.container->purchaseButton)
				{
					if(layout.cartLayout->cPurchase.listen(touchX, touchY))
					{//th1
						touchOn = true;
						touchID = 2;
						soundPlayer.playPress();
						layout.cartLayout->cPurchase.render(true);
					}
					else
					{
						layout.cartLayout->cPurchase.render(false);
					}//buy
				}
	//========================================================
							
			}//!touchOn
			else
			{
				////cout<<"\n>>>>>>>>>>>>>>touchED";
	//========================================================
				if(touchID == 1 && layout.cartLayout->cBack.listen(touchX, touchY))
				{
					layout.cartLayout->cBack.render(true);
				}
				else
				{
					layout.cartLayout->cBack.render(false);
				}		
	//========================================================
				if(layout.cartLayout->cart.container->purchaseButton)
				{
					if(touchID == 2 && layout.cartLayout->cPurchase.listen(touchX, touchY))
					{
						layout.cartLayout->cPurchase.render(true);
					}
					else
					{
						layout.cartLayout->cPurchase.render(false);
					}	
				}
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	
				if(touchID == 1)
				{
					toExitCart();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
				if(touchID == 2)
				{
					layout.cartLayout->toMakePurchase();
					//touchOn = false;
					//touchID = 0;
					//return;
				}
			}

			touchOn = false;
			touchID = 0;
			layout.cartLayout->cBack.render(false);
			if(layout.cartLayout->cart.container->purchaseButton)
			{
				layout.cartLayout->cPurchase.render(false);
			}
			return;
		}
	}

	
	void themeTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				
	//========================================================
				if(layout.themeLayout->cTh1.listen(touchX, touchY))
				{//th1
					touchOn = true;
					touchID = 1;
					soundPlayer.playPress();
					layout.themeLayout->cTh1.render(true);
				}
				else
				{
					layout.themeLayout->cTh1.render(false);
				}//th1
	//========================================================
				
	//========================================================
				if(layout.themeLayout->cTh2.listen(touchX, touchY))
				{//th2
					touchOn = true;
					touchID = 2;
					soundPlayer.playPress();
					layout.themeLayout->cTh2.render(true);
				}
				else
				{
					layout.themeLayout->cTh2.render(false);
				}//th2
	//========================================================
	//========================================================
				if(layout.themeLayout->cTh3.listen(touchX, touchY))
				{//th1
					touchOn = true;
					touchID = 3;
					soundPlayer.playPress();
					layout.themeLayout->cTh3.render(true);
				}
				else
				{
					layout.themeLayout->cTh3.render(false);
				}//th1
	//========================================================
	//========================================================
				if(layout.themeLayout->cTh4.listen(touchX, touchY))
				{//th1
					touchOn = true;
					touchID = 4;
					soundPlayer.playPress();
					layout.themeLayout->cTh4.render(true);
				}
				else
				{
					layout.themeLayout->cTh4.render(false);
				}//th1
	//========================================================
	//========================================================
				if(layout.themeLayout->cTh5.listen(touchX, touchY))
				{//th1
					touchOn = true;
					touchID = 5;
					soundPlayer.playPress();
					layout.themeLayout->cTh5.render(true);
				}
				else
				{
					layout.themeLayout->cTh5.render(false);
				}//th1
	//========================================================
								
				return;
			}//!touchOn
			else
			{
				////cout<<"\n>>>>>>>>>>>>>>touchED";
	//========================================================
				if(touchID == 1 && layout.themeLayout->cTh1.listen(touchX, touchY))
				{
					layout.themeLayout->cTh1.render(true);
				}
				else
				{
					layout.themeLayout->cTh1.render(false);
				}
	//========================================================
	//========================================================
				if(touchID == 2 && layout.themeLayout->cTh2.listen(touchX, touchY))
				{
					layout.themeLayout->cTh2.render(true);
				}
				else
				{
					layout.themeLayout->cTh2.render(false);
				}
	//========================================================
	//========================================================
				if(touchID == 3 && layout.themeLayout->cTh3.listen(touchX, touchY))
				{
					layout.themeLayout->cTh3.render(true);
				}
				else
				{
					layout.themeLayout->cTh3.render(false);
				}
	//========================================================
	//========================================================
				if(touchID == 4 && layout.themeLayout->cTh4.listen(touchX, touchY))
				{
					layout.themeLayout->cTh4.render(true);
				}
				else
				{
					layout.themeLayout->cTh4.render(false);
				}
	//========================================================
	//========================================================
				if(touchID == 5 && layout.themeLayout->cTh5.listen(touchX, touchY))
				{
					layout.themeLayout->cTh5.render(true);
				}
				else
				{
					layout.themeLayout->cTh5.render(false);
				}
	//========================================================
																				
				return;
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	if(touchID > 0)
				{
					if(util.gameState == util.THEMESELECT)
						toThemeLevelSelect(touchID);
					else
						toEdThemeEdLevelSelect(touchID);

					touchOn = false;
					touchID = 0;
					//return;
				}
			}

			touchOn = false;
			touchID = 0;
			layout.themeLayout->cTh1.render(false);
			layout.themeLayout->cTh2.render(false);
			layout.themeLayout->cTh3.render(false);
			layout.themeLayout->cTh4.render(false);
			layout.themeLayout->cTh5.render(false);
			
			return;
		}
	}

	
	void levelTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

			if(!touchOn)
			{//!ontouch
				for(int i=0;i<20;i++)
				{
					if(layout.levelLayout->active[i] == 1)
					{
						if(layout.levelLayout->cLevel[i].listen(touchX, touchY))
						{//
							touchOn = true;
							touchID = i+1;
							vibrate.vibrate10();
							soundPlayer.playPress();
							layout.levelLayout->cLevel[i].render(true,font.AllerM);
						}
						else
						{
							layout.levelLayout->cLevel[i].render(false,font.AllerM);
						}//
					}
					else if(layout.levelLayout->active[i] == 0)
					{
						if(layout.levelLayout->cLevel[i].listen(touchX, touchY))
						{//
							touchOn = true;
							touchID = i+1;
							vibrate.vibrate10();
							soundPlayer.playPress();
							//layout.levelLayout->cLevel[i].render(true,font.AllerM);
							layout.levelLayout->cLevel[i].render(true,font.AllerM,(int)layout.levelLayout->frame,layout.levelLayout->tBoxSheet);
						}
						else
						{
							layout.levelLayout->cLevel[i].render(false,font.AllerM,(int)layout.levelLayout->frame,layout.levelLayout->tBoxSheet);
						}//
					}
					else
					{
						layout.levelLayout->cLevel[i].render(false);
					}
				
				}

				if(layout.levelLayout->cBack.listen(touchX, touchY))
				{//back
					touchOn = true;
					touchID = 101;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.levelLayout->cBack.render(true);
				}
				else
				{
					layout.levelLayout->cBack.render(false);
				}//back

			}
			else
			{//ontouch
				for(int i=0;i<20;i++)
				{
					if(layout.levelLayout->active[i] == 1 )
					{
						if(touchID == i+1 && layout.levelLayout->cLevel[i].listen(touchX, touchY))
						{//
							layout.levelLayout->cLevel[i].render(true,font.AllerM);
						}
						else
						{
							layout.levelLayout->cLevel[i].render(false,font.AllerM);
						}//
					}
					else if(layout.levelLayout->active[i] == 0)
					{
						if(touchID == i+1 && layout.levelLayout->cLevel[i].listen(touchX, touchY))
						{//
							//layout.levelLayout->cLevel[i].render(true,font.AllerM);
							layout.levelLayout->cLevel[i].render(true,font.AllerM,(int)layout.levelLayout->frame,layout.levelLayout->tBoxSheet);
						}
						else
						{
							layout.levelLayout->cLevel[i].render(false,font.AllerM,(int)layout.levelLayout->frame,layout.levelLayout->tBoxSheet);
						}//
					}
					else
					{
						layout.levelLayout->cLevel[i].render(false);
					}
				}
				
				if(touchID == 2 && layout.levelLayout->cBack.listen(touchX, touchY))
				{
					layout.levelLayout->cBack.render(true);
				}
				else
				{
					layout.levelLayout->cBack.render(false);
				}

			}
		}//no touch
		else
		{
			if(touchOn)
			{	
				
				////cout<<"\nhadtouchOn";
				for(int i=0;i<20;i++)
				{
		//========================================================
					if(touchID == i+1)
					{
						//cout<<"\nload level "<<i+1;
						//toLevelSelect();
						toLevelGame(touchID);
						touchOn = false;
						touchID = 0;
						//return;
					}
		//========================================================
				}

					if(touchID == 101)
					{
						//cout<<"\nexit level select";
						//toLevelSelect();
						toExitLevelTheme();
						touchOn = false;
						touchID = 0;
						//return;
					}
			}
			
			for(int i=0;i<20;i++)
			{
				if(layout.levelLayout->active[i] == 1)
				{
					layout.levelLayout->cLevel[i].render(false,font.AllerM);
				}
				else if(layout.levelLayout->active[i] == 0)
				{
					layout.levelLayout->cLevel[i].render(false,font.AllerM,(int)layout.levelLayout->frame,layout.levelLayout->tBoxSheet);
				}
				else
				{
					layout.levelLayout->cLevel[i].render(false);
				}
			}
			
			layout.levelLayout->cBack.render(false);

			touchOn = false;
			touchID = 0;

			return;
		}
	}
			
		
	void edLevelTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			touchX = s3ePointerGetX();
			touchY = s3ePointerGetY();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
				////cout<<"\ntouchOn";
				for(int i=0;i<20;i++)
				{
		//========================================================
					if(layout.levelLayout->cLevel[i].listen(touchX, touchY))
					{//th1
						touchOn = true;
						touchID = i+1;
						soundPlayer.playPress();
						layout.levelLayout->cLevel[i].render(true,font.AllerM);
					}
					else
					{
						layout.levelLayout->cLevel[i].render(false,font.AllerM);
					}//th1
		//========================================================
				}		
				return;
			}//!touchOn
			else
			{
				
				////cout<<"\ntouchOff";
				for(int i=0;i<20;i++)
				{
		//========================================================
					if(touchID == i+1 && layout.levelLayout->cLevel[i].listen(touchX, touchY))
					{
						layout.levelLayout->cLevel[i].render(true,font.AllerM);
					}
					else
					{
						layout.levelLayout->cLevel[i].render(false,font.AllerM);
					}
		//========================================================
				}														
				return;
			}
		}
		else
		{//no touch
			
			if(touchOn)
			{	
				
				////cout<<"\nhadtouchOn";
				for(int i=0;i<20;i++)
				{
		//========================================================
					if(touchID == i+1)
					{
						//cout<<"\nload level "<<i+1;
						//toLevelSelect();
						toEdLevelEditor(touchID);
						touchOn = false;
						touchID = 0;
						//return;
					}
		//========================================================
				}
			}
			
			for(int i=0;i<20;i++)
			{
				layout.levelLayout->cLevel[i].render(false,font.AllerM);
			}
			touchOn = false;
			touchID = 0;

			return;
		}
	}
	void gameMenuTouch()
	{
		
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			touchX = s3ePointerGetX();
			touchY = s3ePointerGetY();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
			
	//========================================================
				if(layout.gameLayout->gameMenuLayout->cQuit.listen(touchX, touchY))
				{//cQuit
					touchOn = true;
					touchID = 1;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.gameLayout->gameMenuLayout->cQuit.render(true);
				}
				else
				{
					layout.gameLayout->gameMenuLayout->cQuit.render(false);
				}//cQuit
	//========================================================
				if(layout.gameLayout->gameMenuLayout->cReset.listen(touchX, touchY))
				{//cReset
					touchOn = true;
					touchID = 2;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.gameLayout->gameMenuLayout->cReset.render(true);
				}
				else
				{
					layout.gameLayout->gameMenuLayout->cReset.render(false);
				}//cReset

	//========================================================
				if(layout.gameLayout->gameMenuLayout->cResume.listen(touchX, touchY))
				{//cResume
					touchOn = true;
					touchID = 3;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.gameLayout->gameMenuLayout->cResume.render(true);
				}
				else
				{
					layout.gameLayout->gameMenuLayout->cResume.render(false);
				}//cResume

				//return;
			}//!touchOn
			else
			{
	
	//========================================================
				if(touchID == 1 && layout.gameLayout->gameMenuLayout->cQuit.listen(touchX, touchY))
				{
					layout.gameLayout->gameMenuLayout->cQuit.render(true);
				}
				else
				{
					layout.gameLayout->gameMenuLayout->cQuit.render(false);
				}
	//========================================================
	//========================================================
				if(touchID == 2 && layout.gameLayout->gameMenuLayout->cReset.listen(touchX, touchY))
				{
					layout.gameLayout->gameMenuLayout->cReset.render(true);
				}
				else
				{
					layout.gameLayout->gameMenuLayout->cReset.render(false);
				}
	//========================================================
	//========================================================
				if(touchID == 3 && layout.gameLayout->gameMenuLayout->cResume.listen(touchX, touchY))
				{
					layout.gameLayout->gameMenuLayout->cResume.render(true);
				}
				else
				{
					layout.gameLayout->gameMenuLayout->cResume.render(false);
				}
	//========================================================
				//return;
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	
				if(touchID == 1)
				{
					toGameMenuQuit();
					touchOn = false;
					touchID = 0;
					return;
				}
				else if(touchID == 2)
				{
					toGameMenuReset();
					touchOn = false;
					touchID = 0;
					return;
				}
				else if(touchID == 3)
				{
					toGameMenuResume();
					touchOn = false;
					touchID = 0;
					return;
				}
			}

			touchOn = false;
			touchID = 0;
			layout.gameLayout->gameMenuLayout->cQuit.render(false);
			layout.gameLayout->gameMenuLayout->cReset.render(false);
			layout.gameLayout->gameMenuLayout->cResume.render(false);
			return;
		}
	}
	void menuOptionTouch()
	{
		
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			//char g_Status[50];
			getTouch();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);

		
			if(!touchOn)
			{
			
	//========================================================
				if(layout.menuLayout->optionMenuLayout->cMute.listen(touchX, touchY))
				{//cMute
					touchOn = true;
					touchID = 1;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->optionMenuLayout->cMute.render(true,storage.userData.snd);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cMute.render(false,storage.userData.snd);
				}//cMute
	//========================================================
				if(layout.menuLayout->optionMenuLayout->cVib.listen(touchX, touchY))
				{//cVib
					touchOn = true;
					touchID = 2;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->optionMenuLayout->cVib.render(true,storage.userData.vib);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cVib.render(false,storage.userData.vib);
				}//cVib
				
	//========================================================
				if(layout.menuLayout->optionMenuLayout->cInfo.listen(touchX, touchY))
				{//cInfo
					touchOn = true;
					touchID = 3;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->optionMenuLayout->cInfo.render(true);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cInfo.render(false);
				}//cInfo

	//========================================================
				if(layout.menuLayout->optionMenuLayout->cQuit.listen(touchX, touchY))
				{//cQuit
					touchOn = true;
					touchID = 4;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.menuLayout->optionMenuLayout->cQuit.render(true);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cQuit.render(false);
				}//cQuit

				return;
			}//!touchOn
			else
			{
	
	//========================================================
				if(touchID == 1 && layout.menuLayout->optionMenuLayout->cMute.listen(touchX, touchY))
				{
					layout.menuLayout->optionMenuLayout->cMute.render(true,storage.userData.snd);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cMute.render(false,storage.userData.snd);
				}
	//========================================================
	//========================================================
				if(touchID == 2 && layout.menuLayout->optionMenuLayout->cVib.listen(touchX, touchY))
				{
					layout.menuLayout->optionMenuLayout->cVib.render(true,storage.userData.vib);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cVib.render(false,storage.userData.vib);
				}
	//========================================================
	//========================================================
				if(touchID == 3 && layout.menuLayout->optionMenuLayout->cInfo.listen(touchX, touchY))
				{
					layout.menuLayout->optionMenuLayout->cInfo.render(true);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cInfo.render(false);
				}
	//========================================================
	//========================================================
				if(touchID == 4 && layout.menuLayout->optionMenuLayout->cQuit.listen(touchX, touchY))
				{
					layout.menuLayout->optionMenuLayout->cQuit.render(true);
				}
				else
				{
					layout.menuLayout->optionMenuLayout->cQuit.render(false);
				}
	//========================================================
				return;
			}
		}
		else
		{//no touch
			////cout<<"\n>>>>>>>>>>>>>>touchOff";
			if(touchOn)
			{	
				if(touchID == 1)
				{
					toToggleMute();
					touchOn = false;
					touchID = 0;
					return;
				}
				else if(touchID == 2)
				{
					toToggleVibrate();
					touchOn = false;
					touchID = 0;
					return;
				}
				else if(touchID == 3)
				{
					toInfo();
					touchOn = false;
					touchID = 0;
					return;
				}
				else if(touchID == 4)
				{
					toExitMenuOption();
					touchOn = false;
					touchID = 0;
					return;
				}
			}

			touchOn = false;
			touchID = 0;
			layout.menuLayout->optionMenuLayout->cInfo.render(false);
			layout.menuLayout->optionMenuLayout->cVib.render(false,storage.userData.vib);
			layout.menuLayout->optionMenuLayout->cMute.render(false,storage.userData.snd);
			layout.menuLayout->optionMenuLayout->cQuit.render(false);
			return;
		}
	}

	void gameTouch()
	{
		
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			
			////cout<<"tAxis "<<tAxis;
			char g_Status[50];
			/*if(!layout.jigSaw[touchID-1].b&&!layout.jigSaw[touchID-1].t&&!layout.jigSaw[touchID-1].l&&!layout.jigSaw[touchID-1].r)
			{
				collision.checkCollision(touchID);
			}*/
			////cout<<"\ndeltaX"<<getDeltaX();


			touchX = s3ePointerGetX();
			touchY = s3ePointerGetY();
			
			

			////cout<<layout.gameLayout->isIntoxicated<<" intoxicated\n";
						
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);
			memset(g_Status,0,50);
			
			
			if(!touchOn || touchID == 0)
			{
				
				touch_oldX = touchX; 
				touch_oldY = touchY;
				
				touchOn = true;
				touchID = tray.getBlockID(touch_oldX,touch_oldY);

				
			//========================================================
				if(layout.gameLayout->cBack.listen(touchX, touchY))
				{//sav
					touchOn = true;
					touchID = 1005;
					vibrate.vibrate10();
					soundPlayer.playPress();
					layout.gameLayout->cBack.render(true);
					refresh(false);
					return;
				}
				else
				{
					layout.gameLayout->cBack.render(false);
				}//sav
			//========================================================
			}
			else
			{
				if(layout.gameLayout->isIntoxicated)
				{//check for intoxication	
					touchX = touch_oldX + (touch_oldX-touchX);
					touchY = touch_oldY + (touch_oldY-touchY);
				////cout<<"\nintoxicated!!";
				}

				//========================================================
				if(touchID == 1005)// && layout.gameLayout->cBack.listen(touchX, touchY))
				{
					layout.gameLayout->cBack.render(true);
					//refresh(false);
					return;
				}
				else
				{
					layout.gameLayout->cBack.render(false);
					//refresh(true);
					//return;
				}
				//========================================================
			}
			
			//else if(tAxis == axisNone)
			{
				if(std::abs(touch_oldX-touchX) > std::abs(touch_oldY-touchY) || tAxis == axisX)
				{//horizontal swipe
					////cout<<"\ngo horizontal swipe !!";
					if(!collisionCheckRight) 
					{//collisionCheck = false
						tAxis = axisX;
						
					
						if(touch_oldX-touchX < -BLOCK1_10th)
						{
							//cout<<"\ngo swipe right!!";
							collision.clearExpBlock(touchID);
							if(collision.checkCollision(touchID,1))
							{
								//cout<<"\n collision!";
								vibrate.vibrate00();
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);

								int tmp = tray.getBlockID(touch_oldX,touch_oldY);
								if(tmp!=0 && layout.jigSaw[tmp-1].isMovable && !layout.gameLayout->isMoved)					
									touchID = tmp;
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckRight = true;
							}
						
						}
					}
					else
					{
						if(touch_oldX-touchX < -BLOCK3_4th)
						{
							if(layout.jigSaw[touchID-1].addRow())
								addMove();
							refresh(layout.gameLayout->isIntoxicated);
							
						}
					}
					if(!collisionCheckLeft) 
					{//collisionCheck = false
						tAxis = axisX;
						
					
						if(touch_oldX-touchX > BLOCK1_10th)
						{
							//cout<<"\ngo swipe left!!";
							collision.clearExpBlock(touchID);
							if(collision.checkCollision(touchID,2))
							{
								//cout<<"\n collision!";
								vibrate.vibrate00();
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);

								int tmp = tray.getBlockID(touch_oldX,touch_oldY);
								if(tmp!=0 && layout.jigSaw[tmp-1].isMovable && !layout.gameLayout->isMoved)				
									touchID = tmp;
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckLeft = true;
							}
						
						}
					}
					else
					{
						if(touch_oldX-touchX > BLOCK3_4th)
						{
							if(layout.jigSaw[touchID-1].subRow())
								addMove();
							refresh(layout.gameLayout->isIntoxicated);
							
						}
					}
				}	
				
				if((std::abs(touch_oldX-touchX) < std::abs(touch_oldY-touchY))|| tAxis == axisY)
				{//vertical movement
					////cout<<"\ngo vertical swipe !!";
				
					if(!collisionCheckDown) 
					{//collisionCheck = false
						tAxis = axisY;
					
						if(touch_oldY-touchY < -BLOCK1_10th)
						{
							//cout<<"\ngo swipe down!!";
							collision.clearExpBlock(touchID);
							if(collision.checkCollision(touchID,4))
							{
								//cout<<"\n collision!";
								vibrate.vibrate00();
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);

								int tmp = tray.getBlockID(touch_oldX,touch_oldY);
								if(tmp!=0 && layout.jigSaw[tmp-1].isMovable && !layout.gameLayout->isMoved)					
									touchID = tmp;
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckDown = true;
							}
						
						}
					}
					else
					{
						if(touch_oldY-touchY < -BLOCK3_4th)
						{
							if(layout.jigSaw[touchID-1].addColumn())
								addMove();
							refresh(layout.gameLayout->isIntoxicated);
							
						}
					}
					if(!collisionCheckUp) 
					{//collisionCheck = false
						tAxis = axisY;
						if(touch_oldY-touchY > BLOCK1_10th)
						{
							
							//cout<<"\ngo swipe up!!";
							//tAxis = axisY;
							collision.clearExpBlock(touchID);
							if(collision.checkCollision(touchID,3))
							{
								//cout<<"\n collision!";
								vibrate.vibrate00();
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);

								int tmp = tray.getBlockID(touch_oldX,touch_oldY);
								if(tmp!=0 && layout.jigSaw[tmp-1].isMovable && !layout.gameLayout->isMoved)									
									touchID = tmp;
								
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckUp = true;
							}
						}
					}
					else
					{
						if(touch_oldY-touchY > BLOCK3_4th)
						{
							if(layout.jigSaw[touchID-1].subColumn())
								addMove();
							refresh(layout.gameLayout->isIntoxicated);
							
						}
					}
							
				}
			}
			
			//sprintf(g_Status, "\nBlock selected: %d @%d/%d\nmove:%d,%d",touchID, tray.getBlocki(touchX), tray.getBlockj(touchY), touch_oldX-touchX, touch_oldY-touchY);
				//IwGxPrintString(0,60,g_Status,0);
			/*else
			{
				//sprintf(g_Status, "\nBlock moved: %d/%d", touch_oldX-touchX, touch_oldY-touchY);
				//IwGxPrintString(0,60,g_Status,0);
			}*/
		}
		else 
		{
			if(touchOn)
			{				
				if(touchID == 1005)
				{					
					//toThemeSelect();
					toExitGameToMenu();
					touchOn = false;
					touchID = 0;
					return;
				}
				layout.gameLayout->isMoved = false;

				tray.genCollisionMap(layout.jigSaw);
				touchOn = false;
				touchID = 0;
				collisionCheckUp = false;
				collisionCheckDown = false;
				collisionCheckLeft = false;
				collisionCheckRight = false;
			}
			layout.gameLayout->isMoved = false;
			layout.gameLayout->cBack.render(false);
		}
		
	}


	
	void editorTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			////cout<<"tAxis "<<tAxis;
			char g_Status[50];
			/*if(!layout.jigSaw[touchID-1].b&&!layout.jigSaw[touchID-1].t&&!layout.jigSaw[touchID-1].l&&!layout.jigSaw[touchID-1].r)
			{
				collision.checkCollision(touchID);
			}*/
			////cout<<"\ndeltaX"<<getDeltaX();
			touchX = s3ePointerGetX();
			touchY = s3ePointerGetY();
			
			
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);
			memset(g_Status,0,50);
			
			
			if(!touchOn || touchID == 0)
			{
				touch_oldX = touchX; 
				touch_oldY = touchY;
				touchOn = true;
				touchID = tray.getBlockID(touch_oldX,touch_oldY);
				if(util.gameState == util.BLOCKDELETE)
				{	
					if(touchID < 50 && touchID > 2)
					{
						for(int i=0;i<layout.jigSaw.size();i++)
						{
							if(layout.jigSaw[i].id == touchID)
							{
								layout.jigSaw.erase(i);
							}
						}
						for(int i=0;i<layout.jigSaw.size();i++)
						{
								layout.jigSaw[i].setId(i+1);
						}
					}
					tray.genCollisionMap(layout.jigSaw);
					util.gameState = util.EDITOR;
				}
			//========================================================
				if(layout.editorLayout->cAdd.listen(touchX, touchY))
				{//add
					touchOn = true;
					touchID = 1001;
					soundPlayer.playPress();
					layout.editorLayout->cAdd.render(true);
				}
				else
				{
					layout.editorLayout->cAdd.render(false);
				}//add
			//========================================================

			//========================================================
				if(layout.editorLayout->cSub.listen(touchX, touchY))
				{//sub
					touchOn = true;
					touchID = 1002;
					soundPlayer.playPress();
					layout.editorLayout->cSub.render(true);
				}
				else
				{
					layout.editorLayout->cSub.render(false);
				}//sub
			//========================================================

			//========================================================
				if(layout.editorLayout->cColl.listen(touchX, touchY))
				{//coll
					touchOn = true;
					touchID = 1003;
					soundPlayer.playPress();
					if(layout.editorLayout->collision == true)
						layout.editorLayout->cColl.render(false);
					else
						layout.editorLayout->cColl.render(true);
				}
				else
				{
					if(layout.editorLayout->collision == true)
						layout.editorLayout->cColl.render(false);
					else
						layout.editorLayout->cColl.render(true);

				}//coll
			//========================================================

			//========================================================
				if(layout.editorLayout->cSav.listen(touchX, touchY))
				{//sav
					touchOn = true;
					touchID = 1004;
					soundPlayer.playPress();
					layout.editorLayout->cSav.render(true);
				}
				else
				{
					layout.editorLayout->cSav.render(false);
				}//sav
			//========================================================

			//========================================================
				if(layout.editorLayout->cBack.listen(touchX, touchY))
				{//sav
					touchOn = true;
					touchID = 1005;
					soundPlayer.playPress();
					layout.editorLayout->cBack.render(true);
				}
				else
				{
					layout.editorLayout->cBack.render(false);
				}//sav
			//========================================================
			}//!touch
			else
			{
			//========================================================
				if(touchID == 1001 && layout.editorLayout->cAdd.listen(touchX, touchY))
				{
					layout.editorLayout->cAdd.render(true);
				}
				else
				{
					layout.editorLayout->cAdd.render(false);
				}
			//========================================================
			
			//========================================================
				if(touchID == 1002 && layout.editorLayout->cSub.listen(touchX, touchY))
				{
					layout.editorLayout->cSub.render(true);
				}
				else
				{
					layout.editorLayout->cSub.render(false);
				}
			//========================================================
			
			//========================================================
				if(touchID == 1003 && layout.editorLayout->cColl.listen(touchX, touchY))
				{
					if(layout.editorLayout->collision == true)
						layout.editorLayout->cColl.render(false);
					else
						layout.editorLayout->cColl.render(true);
				}
				else
				{
					if(layout.editorLayout->collision == true)
						layout.editorLayout->cColl.render(false);
					else
						layout.editorLayout->cColl.render(true);
				}
			//========================================================
			
			//========================================================
				if(touchID == 1004 && layout.editorLayout->cSav.listen(touchX, touchY))
				{
					layout.editorLayout->cSav.render(true);
				}
				else
				{
					layout.editorLayout->cSav.render(false);
				}
			//========================================================

			//========================================================
				if(touchID == 1005 && layout.editorLayout->cBack.listen(touchX, touchY))
				{
					layout.editorLayout->cBack.render(true);
				}
				else
				{
					layout.editorLayout->cBack.render(false);
				}
			//========================================================
			}

			//else if(tAxis == axisNone)
			{
				if(std::abs(touch_oldX-touchX) > std::abs(touch_oldY-touchY)|| tAxis == axisX)
				{//horizontal swipe
					//cout<<"\ngo horizontal swipe !!";
					if(!collisionCheckRight && layout.editorLayout->collision == true) 
					{//collisionCheck = false
						tAxis = axisX;
						
					
						if(touch_oldX-touchX < -BLOCK1_10th)
						{
							////cout<<"\ngo swipe right!!";
							collision.clearExpBlock(touchID);
							if(collision.checkCollisionEdit(touchID,1))
							{
								//cout<<"\n collision!";
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckRight = true;
							}
						
						}
					}
					else
					{
						if(touch_oldX-touchX < -BLOCK3_4th)
						{
							layout.jigSaw[touchID-1].addRow();
							//addMove();
							refresh(false);
							
						}
					}
					if(!collisionCheckLeft && layout.editorLayout->collision == true) 
					{//collisionCheck = false
						tAxis = axisX;
						
					
						if(touch_oldX-touchX > BLOCK1_10th)
						{
							//cout<<"\ngo swipe left!!";
							collision.clearExpBlock(touchID);
							if(collision.checkCollisionEdit(touchID,2))
							{
								//cout<<"\n collision!";
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckLeft = true;
							}
						
						}
					}
					else
					{
						if(touch_oldX-touchX > BLOCK3_4th)
						{
							layout.jigSaw[touchID-1].subRow();
							//addMove();
							refresh(false);
							
						}
					}
				}	
				
				if((std::abs(touch_oldX-touchX) < std::abs(touch_oldY-touchY))|| tAxis == axisY)
				{//vertical movement
				//	//cout<<"\ngo vertical swipe !!";
				
					if(!collisionCheckDown && layout.editorLayout->collision == true) 
					{//collisionCheck = false
						tAxis = axisY;
					
						if(touch_oldY-touchY < -BLOCK1_10th)
						{
							//cout<<"\ngo swipe down!!";
							collision.clearExpBlock(touchID);
							if(collision.checkCollisionEdit(touchID,4))
							{
								//cout<<"\n collision!";
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckDown = true;
							}
						
						}
					}
					else
					{
						if(touch_oldY-touchY < -BLOCK3_4th)
						{
							layout.jigSaw[touchID-1].addColumn();
							//addMove();
							refresh(false);
							
						}
					}
					if(!collisionCheckUp && layout.editorLayout->collision == true) 
					{//collisionCheck = false
						tAxis = axisY;
						if(touch_oldY-touchY > BLOCK1_10th)
						{
							
							//cout<<"\ngo swipe up!!";
							//tAxis = axisY;
							collision.clearExpBlock(touchID);
							if(collision.checkCollisionEdit(touchID,3))
							{
								//cout<<"\n collision!";
								refresh(false);
								tray.genCollisionMap(layout.jigSaw);
								
							}
							else
							{
								//cout<<"\n\n no collision!";
								collisionCheckUp = true;
							}
						}
					}
					else
					{
						if(touch_oldY-touchY > BLOCK3_4th)
						{
							layout.jigSaw[touchID-1].subColumn();
							//addMove();
							refresh(false);
							
						}
					}
							
				}
			}
			
			//sprintf(g_Status, "\nBlock selected: %d @%d/%d\nmove:%d,%d",touchID, tray.getBlocki(touchX), tray.getBlockj(touchY), touch_oldX-touchX, touch_oldY-touchY);
				//IwGxPrintString(0,60,g_Status,0);
			
		}
		else
		{//touchOff
			if(touchOn)
			{	
				if(touchID == 1001)
				{
				
					toBlockSelect();
					touchOn = false;
					touchID = 0;
					return;

				}
				
				if(touchID == 1002)
				{
				
					//toThemeSelect();
					toBlockDelete();
					touchOn = false;
					touchID = 0;
					return;

				}
				
				if(touchID == 1003)
				{
				
					//toThemeSelect();
					if(layout.editorLayout->collision == true)
						layout.editorLayout->collision = false;
					else
						layout.editorLayout->collision = true;
					tray.genCollisionMap(layout.jigSaw);
					touchOn = false;
					touchID = 0;
					return;
				}

				if(touchID == 1004)
				{
				
					//toThemeSelect();
					toSaveLevel();
					touchOn = false;
					touchID = 0;
					return;

				}

				if(touchID == 1005)
				{
				
					//toThemeSelect();
					toExitEditorToMenu();
					touchOn = false;
					touchID = 0;
					return;
				}

				tray.genCollisionMap(layout.jigSaw);
				touchOn = false;
				touchID = 0;
				collisionCheckUp = false;
				collisionCheckDown = false;
				collisionCheckLeft = false;
				collisionCheckRight = false;
			}

			layout.editorLayout->cAdd.render(false);
			layout.editorLayout->cSub.render(false);
			
			if(layout.editorLayout->collision == true)
				layout.editorLayout->cColl.render(false);
			else
				layout.editorLayout->cColl.render(true);

			layout.editorLayout->cSav.render(false);
			layout.editorLayout->cBack.render(false);

			
			//refresh();
		}
	}

	void blockSelectTouch()
	{
		if (s3ePointerGetState(S3E_POINTER_BUTTON_SELECT) == 1)
		{
			vibrate.vibrate10();
			soundPlayer.playPress();
			//char g_Status[50];
  			touchX = s3ePointerGetX();
			touchY = s3ePointerGetY();
			//sprintf(g_Status, "\nPointer event detected. x=%d, y=%d", touchX, touchY);
			//util.cbufferAppend(g_Status);
			//IwGxPrintSetColour(0,255,0);
			//IwGxPrintString(0,50,g_Status,0);
			int blockIs = layout.editorLayout->getBlockID(touchX,touchY);
			//cout<<"\ngot block id "<<blockIs;
			layout.pushBlock(blockIs,3,3);
			toReturnEditor();
			/*Jigsaw jig;
			jig.construct(level.array1[i][j],i,j,k++);
			jig.setImg(layout.editorLayout->getTexture(level.array1[i][j]));
			jigSaw.push_back(jig);
			//cout<<"\njigSaw size "<<jigSaw.size();
			*/
		}
	}

	inline void addMove()
	{
		storage.sStarDump[1]++;
		layout.gameLayout->isMoved = true;
		if(util.gameState == util.PLAYING)
		{
			if(layout.gameLayout->isComplete)
			{
				if((layout.jigSaw[0].row == layout.jigSaw[1].row) && (layout.jigSaw[0].column == layout.jigSaw[1].column))
					toEndLevel();
			}

			CIwArray<uint8> type = layout.gameLayout->gObj.update(layout.jigSaw[0].row,layout.jigSaw[0].column);
			//layout.gameLayout->gItems.getCheck(layout.jigSaw[0].row,layout.jigSaw[0].column);
			//int isToxic = layout.gameLayout->gItems.getShroomCheck(layout.jigSaw[0].row,layout.jigSaw[0].column);
			if(type.size() == 0)
			{
				vibrate.vibrate00();
				soundPlayer.playSwipe();
				return;
			}
			else if(type.size() == 1)
			{
				
				vibrate.vibrate00();
				if(type[0] < 3)
				{
					
					soundPlayer.playStar();
					if(layout.gameLayout->gObj.starAchived == 1)
					{
						layout.animGameplayStarThreadInit(1);
					}
					else if(layout.gameLayout->gObj.starAchived == 2)
						layout.animGameplayStarThreadInit(2);
					else if(layout.gameLayout->gObj.starAchived == 3)
						layout.animGameplayStarThreadInit(3);
					
					
					//layout.gameLayout->isStarred = true;
					return;
				}
				else if(type[0] == 3)
				{
					storage.sStarDump[4]++;
					soundPlayer.playToxicated();
					//layout.jigSaw[0].setImg(layout.gameLayout->tHyptonizedBlock);
					//layout.gameLayout->tBlock[0] = layout.gameLayout->tHyptonizedBlock;
					if(layout.gameLayout->isIntoxicated)
					{
						layout.toxicThreadEnd();
						layout.gameLayout->isIntoxicated = false;
						layout.gameLayout->talkImg = 4;
						storage.sStarDump[5]++;
					}
					else
					{
						layout.toxicThreadInit();
						layout.gameLayout->isIntoxicated = true;
						storage.sStarDump[4]++;
					}
					return;
				}
				else if(type[0] == 4)
				{
					storage.sStarDump[5]++;
					soundPlayer.playToxicated();
					if(layout.gameLayout->isIntoxicated)
					{
						layout.toxicThreadEnd();
						layout.gameLayout->isIntoxicated = false;
						layout.gameLayout->talkImg = 4;
						storage.sStarDump[5]++;
					}
					else
					{
						layout.toxicThreadInit();
						layout.gameLayout->isIntoxicated = true;
						storage.sStarDump[4]++;
					}
					return;
					//layout.jigSaw[0].setImg(layout.gameLayout->tNormalBlock);
					//layout.gameLayout->tBlock[0] = layout.gameLayout->tNormalBlock;
				}
				else if(type[0] == 5)
				{
					storage.sStarDump[3]++;
					soundPlayer.playTeleport();
					layout.jigSaw[0].setRow(layout.gameLayout->gObj.portals[1].x);
					layout.jigSaw[0].setColumn(layout.gameLayout->gObj.portals[1].y);
					return;
				}
				else if(type[0] == 6)
				{
					storage.sStarDump[3]++;
					soundPlayer.playTeleport();
					layout.jigSaw[0].setRow(layout.gameLayout->gObj.portals[0].x);
					layout.jigSaw[0].setColumn(layout.gameLayout->gObj.portals[0].y);
					return;
				}
			}//size 1
			else if(type.size() == 2)
			{
				vibrate.vibrate00();
				if(type[0] < 3 || type[1] < 3)
				{

					soundPlayer.playStar();
					if(layout.gameLayout->gObj.starAchived == 1)
						layout.animGameplayStarThreadInit(1);
					if(layout.gameLayout->gObj.starAchived == 2)
						layout.animGameplayStarThreadInit(2);
					if(layout.gameLayout->gObj.starAchived == 3)
						layout.animGameplayStarThreadInit(3);
				}
				if(type[0] == 3 || type[1] == 3)
				{
					soundPlayer.playToxicated();
					//layout.jigSaw[0].setImg(layout.gameLayout->tHyptonizedBlock);
					//layout.gameLayout->tBlock[0] = layout.gameLayout->tHyptonizedBlock;
					if(layout.gameLayout->isIntoxicated)
					{
						layout.toxicThreadEnd();
						layout.gameLayout->isIntoxicated = false;
						layout.gameLayout->talkImg = 4;
						storage.sStarDump[5]++;
					}
					else
					{
						layout.toxicThreadInit();
						layout.gameLayout->isIntoxicated = true;
						storage.sStarDump[4]++;
					}
				}
				if(type[0] == 4 || type[1] == 4)
				{
					storage.sStarDump[5]++;
					soundPlayer.playToxicated();
					if(layout.gameLayout->isIntoxicated)
					{
						layout.toxicThreadEnd();
						layout.gameLayout->isIntoxicated = false;
						layout.gameLayout->talkImg = 4;
						storage.sStarDump[5]++;
					}
					else
					{
						layout.toxicThreadInit();
						layout.gameLayout->isIntoxicated = true;
						storage.sStarDump[4]++;
					}
					//layout.jigSaw[0].setImg(layout.gameLayout->tNormalBlock);
					//layout.gameLayout->tBlock[0] = layout.gameLayout->tNormalBlock;
				}
				if(type[0] == 5 || type[1] == 5)
				{
					storage.sStarDump[3]++;
					soundPlayer.playTeleport();
					layout.jigSaw[0].setRow(layout.gameLayout->gObj.portals[1].x);
					layout.jigSaw[0].setColumn(layout.gameLayout->gObj.portals[1].y);
				}
				if(type[0] == 6 || type[1] == 6)
				{
					storage.sStarDump[3]++;
					soundPlayer.playTeleport();
					layout.jigSaw[0].setRow(layout.gameLayout->gObj.portals[0].x);
					layout.jigSaw[0].setColumn(layout.gameLayout->gObj.portals[0].y);
				}
			}//size 2
		}
	}

}touch;


#endif