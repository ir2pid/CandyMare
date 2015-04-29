/*
 * This file is part of the Marmalade SDK Code Samples.
 *
 * Copyright (C) 2001-2011 Ideaworks3D Ltd.
 * All Rights Reserved.
 *
 * This source code is intended only as a supplement to Ideaworks Labs
 * Development Tools and/or on-line documentation.
 *
 * THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
 * PARTICULAR PURPOSE.
 */

#include <iostream.h>
#include "s3e.h"
#include "Iw2D.h"
#include "IwGx.h"
#include "transitions2d.h"
#include "derbh.h"
//#include "iad.h"

#include "../layout/layout.h"
#include "font.h"
#include "game.h"
#include "touch.h"
#include "util.h"
#include "tray.h"
#include "Storage.h"
#include "AudioPlayer.h"
#include "../h/NotificationSystem.h"
#include "../h/feed.h"

//ios,sim
#define IOS
#define ROTATE_HALO
//!android,win32

//int32 iADMinimised(void* systemData, void* userData);
//int32 iADMaximised(void* systemData, void* userData);
//int32 iADFailed(void* systemData, void* userData);

int32 ScreenSizeChangeCallback(void* systemData, void* userData);

void CGame::cleanupRes()
{
	s3eSurfaceUnRegister(S3E_SURFACE_SCREENSIZE, ScreenSizeChangeCallback);
	
	if(util.prevState == util.MENU)
			layout.destructMenu();
	else if(util.prevState == util.CART)
			layout.destructCart();
	else if(util.prevState == util.TROPHY)
			layout.destructTrophy();
	else if(util.prevState == util.THEMESELECT)
		layout.destructThemeScrollSelect();
	else if(util.prevState == util.THEMEINTRO)
		layout.destructThemeIntro();
	else if(util.prevState == util.LEVELSELECT)
			layout.destructLevelSelect();
	else if(util.prevState == util.PLAYING || util.prevState == util.PLAYINGMENU)
		layout.destructGameLevel();
	/*else if(util.prevState == util.PLAYINGMENU)
		layout.destructGameMenu();*/
	else if(util.prevState == util.EDITORLEVEL)
		layout.destructLevelSelect();
	else if(util.prevState == util.EDITORTHEME)
		layout.destructThemeSelect();
	else if(util.prevState == util.EDITOR || util.prevState == util.BLOCKDELETE || util.prevState == util.BLOCKSELECT)
		layout.destructEditorLevel();
	else if(util.prevState == util.LEVELEND)
		layout.destructLevelEnd();
	
}

void CGame::setupRes()
{	
	s3eSurfaceRegister(S3E_SURFACE_SCREENSIZE, ScreenSizeChangeCallback, NULL);
	
	if(util.gameState == util.MENU)
	{
		//iAd->show();
		/*if(!storage.userData.purchased)
		{
			util.applifierSystem.showBanner(util.widthDisplay);

			adWhirl.hideAd();
		}*/
		feed.pushFeed();
		layout.constructMenu();
		//layout.menuLayout->constructOptionMenuLayout();
	}
	else if(util.gameState == util.CART)
	{		
		//util.applifierSystem.showFeatureGames();
		layout.constructCart();
	}
	else if(util.gameState == util.TROPHY)
	{
		//util.applifierSystem.hideBanner();
		//util.applifierSystem.showInterstatial();
		//audioPlayer.playCredits(storage.userData.snd);
		layout.constructTrophy();
	}
	else if(util.gameState == util.THEMESELECT)
	{
		//util.applifierSystem.showAnimated();
		layout.constructThemeScrollSelect();
	}
	else if(util.gameState == util.THEMEINTRO)
	{
		layout.constructThemeIntro();
	}
	else if(util.gameState == util.EDITORTHEME)
	{
		layout.constructThemeSelect();
	}
	else if(util.gameState == util.LEVELSELECT || util.gameState == util.EDITORLEVEL)
	{
		//util.applifierSystem.showCustomInterstitial();
		//iAd->show();
		if(!storage.userData.purchased)
		{
			adWhirl.hideAd();
		}
		layout.constructLevelSelect();
	}
	else if(util.gameState == util.PLAYING)
	{
		//iAd->hide();
		if(!storage.userData.purchased)
		{
			adWhirl.hideAd();
		}
		audioPlayer.playGameplay(storage.userData.snd);
		layout.constructGameLevel(storage.parseLevel());
		//touch.setBlockDelta(util.BLOCKSIZE*4/5,util.BLOCKSIZE/20);
		tray.construct(util.BLOCKSIZE,layout.gameLayout->trayX,layout.gameLayout->trayY);
		tray.genCollisionMap(layout.jigSaw);
		layout.genXtras();
	}
	else if(util.gameState == util.PLAYINGMENU)
	{
		layout.gameLayout->constructGameMenu();
	}
	else if(util.gameState == util.EDITOR)
	{
		//set 0_00 as file name
		//storage.userData.currTheme = 0;
		//storage.userData.currLevel = 0;

		layout.constructEditorLevel(storage.parseLevel());
		tray.construct(util.BLOCKSIZE,layout.editorLayout->trayX,layout.editorLayout->trayY);
		tray.genCollisionMap(layout.jigSaw);
	}
	else if(util.gameState == util.LEVELEND)
	{
		layout.constructLevelEnd();
	}
	touch.refresh(true);
	util.prevState = util.gameState;
}

CGame::CGame()
{
	/*if(s3eUDIDAvailable())
		UDID = getUDIDiOS();
	else
		UDID = "unknown";*/
	//spSplash.setTexture(Iw2DCreateImage("./texture/splash.png"));
	//storage.construct();
	//IwGxSetScreenOrient(IW_GX_ORIENT_90);
	//setIAd();
	//iAd = new IAd();
	//touch.setIad(iAd);
	//iAd->show();
	/*if(!storage.userData.purchased)
	{
	}*/

	util.construct();
	touch.setBlockDelta();
	util.appirateInit();
	util.heyzapInit();
	storage.construct();
	layout.construct();//loads sound
	audioPlayer.playMenu(storage.userData.snd);
	
	//tInvert = NULL;
	tSplash = util.getTexture("menu/splash.png");
	spSplash.constructRaw(-tSplash->GetWidth(),-tSplash->GetHeight(),util.RIGHT,util.BOTTOM,tSplash);
	
	//storage.construct
	util.gameState = util.INIT;
	util.prevState = util.INIT;
	s3eSurfaceRegister(S3E_SURFACE_SCREENSIZE, ScreenSizeChangeCallback, NULL);
	font.genFont();
	adService.constructHttp();
	if(!storage.userData.purchased)
	{
		adWhirl.construct();
		adWhirl.hideAd();
		adService.construct();
		adService.initMediators();
		adService.show(true);
		//util.applifierSystem.showBanner(util.widthDisplay);
	}
	feed.initFeed();
	layout.constructMenu();
	util.gameState = util.MENU;
	util.prevState = util.MENU;
}


CGame::~CGame()
{
	/*if(UDID != NULL)
		delete UDID;UDID = NULL;*/
	//delete iAd;
	util.destruct();

	adService.destructHttp();
	if(!storage.userData.purchased)
	{
		adService.destruct();
	}

	//layout.notifyThreadEnd();
	delete tSplash;
	spSplash.destruct();

	//storage.destruct();
	//layout.;
	if(util.gameState == util.MENU || util.gameState == util.OPTION || util.gameState == util.INFO)
		layout.destructMenu();
	else if(util.gameState == util.CART)
		layout.destructCart();
	else if(util.gameState == util.TROPHY)
		layout.destructTrophy();
	else if(util.gameState == util.THEMESELECT)
		layout.destructThemeScrollSelect();
	else if(util.gameState == util.EDITORTHEME)
		layout.destructThemeSelect();
	else if(util.gameState == util.LEVELSELECT || util.gameState == util.EDITORLEVEL)
		layout.destructLevelSelect();
	else if(util.gameState == util.PLAYING || util.gameState == util.PLAYINGMENU)
		layout.destructGameLevel();
	else if(util.gameState == util.EDITOR || util.gameState == util.BLOCKSELECT || util.gameState == util.BLOCKDELETE)
		layout.destructEditorLevel();
	else if(util.gameState == util.LEVELEND)
		layout.destructLevelEnd();

	layout.destruct();
	
	/*if(tInvert)
		delete tInvert;tInvert = NULL;*/


	font.genFontClear();
	storage.saveStorage();	
	storage.destruct();
	feed.destruct();
}


void CGame::Update()
{
	if(util.displayReset)
	{
		
		util.displayReset = false;
		if(util.gameState != util.MENU && util.gameState != util.OPTION)
		{
			if(!storage.userData.purchased)
			{
				util.applifierSystem.hideBanner();
			}
		}
		if(util.prevState == util.INFO)
		{	
			layout.menuLayout->destructInfoLayout();
			if(!storage.userData.purchased)
			{
				util.applifierSystem.showBanner(util.widthDisplay);
			}
			util.prevState = util.gameState;
			return;
		}
		if(util.gameState == util.PLAYINGMENU)
		{
			layout.gameLayout->constructGameMenu();
			layout.gameLayout->gameMenuLayout->construct();
			return;
		}
		if(util.gameState == util.OPTION)
		{
			//spSplash.render();
			layout.menuLayout->constructOptionMenuLayout();
			layout.menuLayout->optionMenuLayout->construct();
			//overrider
			//Iw2DSurfaceShow();
			return;
		}
		if(util.gameState == util.INFO)
		{			
			layout.menuLayout->constructInfoLayout();
			layout.menuLayout->infoLayout->construct();
			return;
		}

		RenderWOFlush();
		spSplash.render();
		// show the surface	
		Iw2DSurfaceShow();
		if(util.prevState == util.PLAYING)
		{//delay gameplay end
			
			layout.gameLayout->calculateScore();
			s3eDeviceYield(1000);
		}
		if(util.gameState != util.TROPHY)
			Transitions2D::CaptureStartScreen();

		//clean old layout
		cleanupRes();
		
		//figure transition direction
		bool transitionDir = false;
		bool isLevelEnd = false;
		bool isPlaying = false;
		//bool isTrophy = false;
		
		
		if(util.gameState == util.PLAYING)
			isPlaying = true;
		else if(util.prevState == util.LEVELEND || util.gameState == util.LEVELEND)
		{
			if(util.gameState == util.PLAYING)
			{
				isPlaying = true;
			}
			else
			{
				isLevelEnd = true;
				//clean touch to fix home touch bug/tendency
				touch.refresh(1);
			}
		}		
		/*else if(util.gameState == util.TROPHY)
		{
			isTrophy = true;
		}*/

		if(util.gameState > util.prevState)
			transitionDir = false;
		else
			transitionDir = true;
		


		setupRes();

		
		//if(util.gameState != util.TROPHY)
		{	
			RenderWOFlush();
			Transitions2D::CaptureEndScreen();
			if(isLevelEnd)
			{	
				if(transitionDir)
					Transitions2D::SlideRight();
				else
					Transitions2D::SlideLeft();
			}
			else if(isPlaying || util.gameState == util.TROPHY)
			{
				Transitions2D::Fade();
			}
			else// if(util.gameState != util.TROPHY)
			{	
				if(transitionDir)
					Transitions2D::SlideDown();
				else
					Transitions2D::SlideUp();
			}

			s3eDeviceYield(500);
			//util.translateView = false;
		}

		if(util.gameState == util.THEMESELECT)
		{
			if(!storage.userData.purchased)
			{
				adWhirl.showAd();
			}
		}
		if(util.gameState == util.MENU)
		{
			if(!storage.userData.purchased)
			{
				util.applifierSystem.showBanner(util.widthDisplay);
				adWhirl.hideAd();
			}
		}
		//else
		{
			delete Transitions2D::mStartTexture;
			Transitions2D::mStartTexture = NULL;
			delete Transitions2D::mEndTexture;
			Transitions2D::mEndTexture = NULL;
		}

	}
	IwGetSoundManager()->Update();
}


void CGame::Render()
{
    // game render goes here

    // for example, clear to black (the order of components is ABGR)
    Iw2DSurfaceClear(0xff000000);
		
	notificationSystem.update();
	//Render code
    if(util.gameState == util.MENU)
	{ 
		//if (ApplifierCrossPromotionPauseRenderer() == false)  
		{
			menuRender();
		}
	}
	else if(util.gameState == util.THEMEINTRO)
	{ 		
			themeIntroRender();		
	}
    else if(util.gameState == util.CART)
	{
		cartRender();
	}
	else if(util.gameState == util.TROPHY)
	{
		trophyRender();
	}
	else if(util.gameState == util.OPTION)
	{
		menuOptionRender();
	}
	else if(util.gameState == util.INFO)
	{
		infoRender();
	}
	else if(util.gameState == util.THEMESELECT)
	{
		themeScrollRender();
	}
	else if(util.gameState == util.LEVELSELECT)
	{
		levelRender();
	}
	else if(util.gameState == util.PLAYING)
	{
		gameRender();
	}
	else if(util.gameState == util.PLAYINGMENU)
	{
		gameMenuRender();
	}
	else if(util.gameState == util.EDITOR || util.gameState == util.BLOCKDELETE)
	{
		editorRender();
	}
	else if(util.gameState == util.BLOCKSELECT)
	{
		blockSelectRender();
	}
	else if(util.gameState == util.EDITORTHEME)
	{
		edThemeRender();
	}
	else if(util.gameState == util.EDITORLEVEL)
	{
		edLevelRender();
	}
	else if(util.gameState == util.LEVELEND)
	{
		levelEndRender();
	}
	
	notificationSystem.render();
	 
	
	if(!storage.userData.purchased)
	{
		adService.update();
	}

	IwGxFlush();
	IwGxSwapBuffers();
	Iw2DSurfaceShow();
}


void CGame::RenderWOFlush()
{
    // game woflush render goes here

    Iw2DSurfaceClear(0xff000000);
	
    if(util.prevState == util.MENU)
	{
		menuRender();
	}
	if(util.prevState == util.THEMEINTRO)
	{
		themeIntroRender();
	}
    else if(util.prevState == util.CART)
	{
		cartRender();
	}
	else if(util.prevState == util.TROPHY)
	{
		trophyRender();
	}
	else if(util.prevState == util.OPTION)
	{
		menuOptionRender();
	}
	else if(util.prevState == util.INFO)
	{
		infoRender();
	}
	else if(util.prevState == util.THEMESELECT)
	{
		themeScrollRender();
	}
	else if(util.prevState == util.LEVELSELECT)
	{
		levelRender();
	}
	else if(util.prevState == util.PLAYING)
	{
		gameRenderWOTouch();
	}
	else if(util.prevState == util.PLAYINGMENU)
	{
		gameMenuRender();
	}
	else if(util.prevState == util.EDITOR || util.prevState == util.BLOCKDELETE)
	{
		editorRender();
	}
	else if(util.prevState == util.BLOCKSELECT)
	{
		blockSelectRender();
	}
	else if(util.prevState == util.EDITORTHEME)
	{
		edThemeRender();
	}
	else if(util.prevState == util.EDITORLEVEL)
	{
		edLevelRender();
	}
	else if(util.prevState == util.LEVELEND)
	{
		levelEndRender();
	}
	
	notificationSystem.update();
	notificationSystem.render();
	if(!storage.userData.purchased)
	{
		adService.update();
	}
	
}
void CGame::infoRender()
{
	menuRenderWOTouch();
	layout.grayscale200();
	layout.menuLayout->infoLayout->render();
	layout.menuLayout->infoLayout->sIw.render(util.em/4.0f);
	layout.menuLayout->infoLayout->update();
	touch.infoTouch();
	//touch.menuOptionTouch();
}
void CGame::menuOptionRender()
{
	menuRenderWOTouch();
	layout.grayscale200();
	layout.menuLayout->optionMenuLayout->update();
	touch.menuOptionTouch();
}
void CGame::gameMenuRender()
{
	gameRenderWOTouch();
	layout.grayscale200();
	/*layout.gameLayout->gameMenuLayout->cQuit.render();
	layout.gameLayout->gameMenuLayout->cReset.render();
	layout.gameLayout->gameMenuLayout->cResume.render();*/
	layout.gameLayout->gameMenuLayout->update();
	touch.gameMenuTouch();
}

void CGame::menuRender()
{
	layout.menuLayout->renderBG();//sBg.render();
	layout.menuLayout->renderLogo();
	//layout.menuLayout->renderCompleteTag();
	layout.menuLayout->crow.render();
	
	if(layout.menuLayout->showSocial)
		touch.menuTouchwSocial();
	else
		touch.menuTouch();
}
void CGame::themeIntroRender()
{
	
	layout.themeIntroLayout->sBg.render();
	layout.themeIntroLayout->render();
	layout.themeIntroLayout->crow.render();
	
	touch.themeIntroTouch();

}
void CGame::cartRender()
{
	
	//layout.cartLayout->sDialogBox.render();
	//layout.cartLayout->renderConsole();
	//layout.cartLayout->update();
	/*layout.cartLayout->sIcon1.render();
	layout.cartLayout->sIcon2.render();
	layout.cartLayout->sIcon3.render();
	layout.cartLayout->sIcon4.render();*/
	layout.cartLayout->renderLogo();
	layout.cartLayout->renderConsole();
	layout.cartLayout->update();
		touch.cartTouch();
}
void CGame::trophyRender()
{
	/*
#if defined(IOS)
	layout.trophyLayout->sBg.render(0,0,true);
#else 
	layout.trophyLayout->sBg.render(0,0,false);
#endif*/
	util.renderBG();
	layout.trophyLayout->render();
	touch.trophyTouch();
	layout.trophyLayout->spUp.render();
	layout.trophyLayout->spDown.render((uint8)6);
}
void CGame::menuRenderWOTouch()
{
	layout.menuLayout->renderBG();//sBg.render();
	layout.menuLayout->renderLogo();
	//layout.menuLayout->renderCompleteTag();
	layout.menuLayout->crow.render();
}

void CGame::themeRender()
{
	layout.themeLayout->cTh2.render(false);
	layout.themeLayout->cTh3.render(false);
	layout.themeLayout->cTh4.render(false);
	layout.themeLayout->cTh5.render(false);
	touch.themeTouch();
}

void CGame::themeScrollRender()
{
	layout.themeScrollLayout->renderScroll();
	layout.themeScrollLayout->update();
	layout.themeScrollLayout->renderText();
	touch.themeScrollTouch();
}

void CGame::levelRender()
{
/*#if defined(IOS)
	layout.levelLayout->sBg.render(0,0,true);
#else
	layout.levelLayout->sBg.render(0,0,false);
#endif*/
	util.renderBG();
	layout.grayscale100();
	touch.levelTouch();
	layout.levelLayout->update();
	layout.levelLayout->renderMiniStars();
}

void CGame::edThemeRender()
{
	layout.themeLayout->cTh2.render(false);
	layout.themeLayout->cTh3.render(false);
	layout.themeLayout->cTh4.render(false);
	layout.themeLayout->cTh5.render(false);
	touch.themeTouch();
}
void CGame::edLevelRender()
{
	touch.edLevelTouch();
}
void CGame::gameRenderWOTouch()
{
	
	if(layout.gameLayout->isIntoxicated)
	{
		layout.gameLayout->renderToxicInit();
/*#if defined(IOS)
	layout.gameLayout->sTray.render(0,0,true);
#else
	layout.gameLayout->sTray.render(0,0,false);
#endif*/

		util.renderBG();
/*
#if defined(ROTATE_HALO)
		if(layout.gameLayout->gObj.dirScale)
		{	
			double turn;
			turn = abs((int)(layout.gameLayout->gObj.amountScale*100));
			layout.gameLayout->sHalo.render(turn);
			////cout<<"\n up "<<turn<<" "<<layout.gameLayout->gObj.amountScale;
		}
		else
		{	
			double turn;
			turn = 80+(100-abs((int)(layout.gameLayout->gObj.amountScale*100)));
			layout.gameLayout->sHalo.render(turn);
			////cout<<"\n down "<<turn<<" "<<layout.gameLayout->gObj.amountScale;
		}

#else
	layout.gameLayout->sHalo.render((double)layout.gameLayout->gObj.amountTranslate);
#endif*/

		for(int i=layout.jigSaw.size()-1;i>=0;i--)
		{
			//int dx = touch.getDeltaX();
			//int dy = touch.getDeltaY();
			int r = layout.jigSaw[i].row;
			int c = layout.jigSaw[i].column;
			
				if(i==0)
				{
					layout.gameLayout->sCandy.render();
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c),CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
				}
				else //if(layout.jigSaw[i].code!=33)
				{
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));
					if(i == 1)
					{
						gameHaloRender();
						layout.gameLayout->sCandy.render();
					}
				}
			//}

		}
		
		layout.gameLayout->renderStar();
		
		//render objects and particle system
		layout.gameLayout->gObj.render();

		layout.gameLayout->gObj.pSystem.update();
	

		layout.gameLayout->renderToxicEnd();
		
	}
	else
	{

/*#if defined(IOS)
	layout.gameLayout->sTray.render(0,0,true);
#else
	layout.gameLayout->sTray.render(0,0,false);
#endif*/

		util.renderBG();
/*
#if defined(ROTATE_HALO)
		if(layout.gameLayout->gObj.dirScale)
		{	
			double turn;
			turn = abs((int)(layout.gameLayout->gObj.amountScale*100));
			layout.gameLayout->sHalo.render(turn);
			////cout<<"\n up "<<turn<<" "<<layout.gameLayout->gObj.amountScale;
		}
		else
		{	
			double turn;
			turn = 80+(100-abs((int)(layout.gameLayout->gObj.amountScale*100)));
			layout.gameLayout->sHalo.render(turn);
			////cout<<"\n down "<<turn<<" "<<layout.gameLayout->gObj.amountScale;
		}

#else
	layout.gameLayout->sHalo.render((double)layout.gameLayout->gObj.amountTranslate);
#endif*/

		for(int i=layout.jigSaw.size()-1;i>=0;i--)
		{
			//int dx = touch.getDeltaX();
			//int dy = touch.getDeltaY();
			int r = layout.jigSaw[i].row;
			int c = layout.jigSaw[i].column;
			
				if(i==0)
				{
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c),CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
				}else
				{
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));	
					if(i == 1)
					{
						gameHaloRender();
						layout.gameLayout->sCandy.render();
					}
				}
			//}

		}

		layout.gameLayout->renderStar();
		layout.gameLayout->gObj.render();

		layout.gameLayout->gObj.pSystem.update();

	}
	
	if(util.gameState == util.LEVELEND)
	{	
		layout.gameLayout->spDone.render();
		return;
	}
}

void CGame::gameRender()
{
	
	if(layout.gameLayout->isIntoxicated)
	{
		layout.gameLayout->renderToxicInit();
		
		layout.gameLayout->renderRippleInit();
/*#if defined(IOS)
	layout.gameLayout->sTray.render(0,0,true);
#else
	layout.gameLayout->sTray.render(0,0,false);
#endif*/

		util.renderBG();

		for(int i=layout.jigSaw.size()-1;i>=0;i--)
		{
			int dx = touch.getDeltaX();
			int dy = touch.getDeltaY();
			int r = layout.jigSaw[i].row;
			int c = layout.jigSaw[i].column;
			if(touch.touchID == layout.jigSaw[i].id)
			{
				layout.gameLayout->renderToxicEnd();

				if(layout.jigSaw[i].isMovable)
				{
					Iw2DSetColour(0xaa00ff00);
					if(i==0)
					{						
						layout.jigSaw[i].render(tray.getCordx(r)+dx,tray.getCordy(c)+dy,CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
					}
					//else if(layout.jigSaw[i].code!=33)
					
					else
					{
					//Iw2DSetColour(0xaa00ff00);
						layout.jigSaw[i].render(tray.getCordx(r)+dx,tray.getCordy(c)+dy);
					}
					

				}
				else
				{
				Iw2DSetColour(0xaa0000ff);
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));
					if(i == 1)
					{
						gameHaloRender();
						layout.gameLayout->sCandy.render();
					}
				}

				Iw2DSetColour(0xffffffff);
				layout.gameLayout->renderToxicInit();
			}
			else
			{
				if(i==0)
				{
					
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c),CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
				}
				else
				{
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));
					if(i == 1)
					{
						gameHaloRender();
						layout.gameLayout->sCandy.render();
					}
				}// if(layout.jigSaw[i].code!=33)
				
			}

		}
		
		layout.gameLayout->renderStar();
		//layout.gameLayout->sCandy.render();

		
		//render objects and particle system
		layout.gameLayout->gObj.render();

		layout.gameLayout->gObj.pSystem.update();
	
		touch.gameTouch();

		layout.gameLayout->renderToxicEnd();
		
	}
	else
	{
		layout.gameLayout->renderRippleInit();
/*#if defined(IOS)
	layout.gameLayout->sTray.render(0,0,true);
#else
	layout.gameLayout->sTray.render(0,0,false);
#endif*/
		
		util.renderBG();
		
		for(int i=layout.jigSaw.size()-1;i>=0;i--)
		{
			int dx = touch.getDeltaX();
			int dy = touch.getDeltaY();
			int r = layout.jigSaw[i].row;
			int c = layout.jigSaw[i].column;
			if(touch.touchID == layout.jigSaw[i].id)
			{
				if(layout.jigSaw[i].isMovable)
				{
					Iw2DSetColour(0xaa00ff00);
					if(i==0)
					{						
						layout.jigSaw[i].render(tray.getCordx(r)+dx,tray.getCordy(c)+dy,CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
					}
					else 
					{
						layout.jigSaw[i].render(tray.getCordx(r)+dx,tray.getCordy(c)+dy);
					}					

				}
				else
				{
					Iw2DSetColour(0xaa0000ff);
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));
					if(i == 1)
					{
						gameHaloRender();
						layout.gameLayout->sCandy.render();
					}
						Iw2DSetColour(0xaa00ff00);
				
				}
				
					Iw2DSetColour(0xffffffff);
			}
			else
			{
				if(i==0)
				{
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c),CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
				}
				else
				{	
					layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));
					if(i == 1)
					{
						gameHaloRender();
						layout.gameLayout->sCandy.render();
					}
				}
				
			}

		}
		
		layout.gameLayout->renderRippleEnd();

		layout.gameLayout->renderStar();
		//layout.gameLayout->sCandy.render();



		layout.gameLayout->gObj.render();
		touch.gameTouch();

		layout.gameLayout->gObj.pSystem.update();

	}

	if(util.gameState == util.LEVELEND)
	{	
		layout.gameLayout->spDone.render();
		//gameEndRender();
		return;
	}

}//gamerender

void CGame::gameHaloRender()
{
	
#if defined(ROTATE_HALO)
		if(layout.gameLayout->gObj.dirScale)
		{	
			double turn;
			turn = abs((int)(layout.gameLayout->gObj.amountScale*100));
			layout.gameLayout->sHalo.render(turn);
			////cout<<"\n up "<<turn<<" "<<layout.gameLayout->gObj.amountScale;
		}
		else
		{	
			double turn;
			turn = 80+(100-abs((int)(layout.gameLayout->gObj.amountScale*100)));
			layout.gameLayout->sHalo.render(turn);
			////cout<<"\n down "<<turn<<" "<<layout.gameLayout->gObj.amountScale;
		}
		
#else
	layout.gameLayout->sHalo.render((double)layout.gameLayout->gObj.amountTranslate);
#endif
}
void CGame::gameEndRender()
{	
	/*
	if(layout.gameLayout->isIntoxicated)
	{
		layout.gameLayout->renderToxicInit();
#if defined(IOS)
	layout.gameLayout->sTray.render(0,0,true);
#else
	layout.gameLayout->sTray.render(0,0,false);
#endif
		for(int i=layout.jigSaw.size()-1;i>=0;i--)
		{
			int dx = touch.getDeltaX();
			int dy = touch.getDeltaY();
			int r = layout.jigSaw[i].row;
			int c = layout.jigSaw[i].column;
			
			if(i==0)
				layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c),CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
			else
				layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));
			
		}
		layout.gameLayout->renderStar();
		//render objects and particle system
		layout.gameLayout->gObj.render();
		layout.gameLayout->gObj.pSystem.update();
		layout.gameLayout->renderToxicEnd();
		
	}
	else
	{
#if defined(IOS)
	layout.gameLayout->sTray.render(0,0,true);
#else
	layout.gameLayout->sTray.render(0,0,false);
#endif
		
		for(int i=layout.jigSaw.size()-1;i>=0;i--)
		{
			int dx = touch.getDeltaX();
			int dy = touch.getDeltaY();
			int r = layout.jigSaw[i].row;
			int c = layout.jigSaw[i].column;
			
			if(i==0)
				layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c),CIwSVec2(layout.gameLayout->talkAnchor[layout.gameLayout->talkImg],0),layout.gameLayout->talkRegion);
			else
				layout.jigSaw[i].render(tray.getCordx(r),tray.getCordy(c));
			
		}

		layout.gameLayout->renderStar();
		layout.gameLayout->gObj.render();

		layout.gameLayout->gObj.pSystem.update();

	}
		//cout<<"\n\nsuccess!";
		//cout<<"\n\nsuccess!";
		layout.gameLayout->spDone.render();*/
		//s3eDeviceYield(1500);
	
}//gameendrender


void CGame::editorRender()
{
#if defined(IOS)
	layout.editorLayout->sTray.render(0,0,true);
#else
	layout.editorLayout->sTray.render(0,0,false);
#endif
		/*//ios
		Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT270); 
		layout.editorLayout->sTray.render();
		//ios
		Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); */

			CIwArray<Jigsaw>::iterator it;	
			it=(layout.jigSaw).end();
				
			do
			{
				it--;
				int dx = touch.getDeltaX();
				int dy = touch.getDeltaY();
				int r = it->row;
				int c = it->column;
				if(touch.touchID == it->id)
				{
					if(it->isMovable)
					{
						//it->render(tray.getCordx(r)+dx,tray.getCordy(c)+dy);
						Iw2DSetColour(0xaa00ff00);
						//Iw2DSetAlphaMode(IW_2D_ALPHA_SUB);//  IW_2D_ALPHA_HALF IW_2D_ALPHA_ADD IW_2D_ALPHA_SUB 
						it->render(tray.getCordx(r)+dx,tray.getCordy(c)+dy);
						Iw2DSetColour(0xffffffff);

					}
					else
					{
						//it->render(tray.getCordx(r),tray.getCordy(c));
						Iw2DSetColour(0xaa0000ff);
						it->render(tray.getCordx(r),tray.getCordy(c));
						Iw2DSetColour(0xffffffff);
					}
					
				}
				else
					it->render(tray.getCordx(r),tray.getCordy(c));

				
			}while( it!=(layout.jigSaw).begin());

			touch.editorTouch();
}

void CGame::levelEndRender()
{
	/*
#if defined(IOS)
	layout.levelEndLayout->sBg.render(0,0,true);
#else
	layout.levelEndLayout->sBg.render(0,0,false);
#endif
	*/
	util.renderBG();
	layout.levelEndLayout->sDialogBox.render();
	//layout.levelEndLayout->cFB.render();
	layout.levelEndLayout->renderStars();
	touch.levelEndTouch();
	if(layout.levelEndLayout->dropGraphiti)
	{
		layout.levelEndLayout->gs.render();
		if(layout.levelEndLayout->gs.update())
		{
			if(!storage.userData.purchased)
			{
				adWhirl.showAd();
			}
		}
	}
	//layout.levelEndLayout->renderTest();
	//layout.levelEndLayout->cLMenu.render(false,NULL);
	//layout.levelEndLayout->cNext.render(false,NULL);
}

void CGame::blockSelectRender()
{
	layout.editorLayout->renderBlockTray();
	touch.blockSelectTouch();
}


/*void CGame::Console()
{
	char c[18];
	//memset(0,'\0', 17);
	sprintf(c,"%iX%i,em:%1.2f",util.widthDisplay,util.heightDisplay,util.em);
	IwGxPrintString(0, 10, c);
	//sprintf(c,"cS %i : pS %i",util.gameState,util.prevState);
	
	//unsigned int UDID = s3eDeviceGetInt(S3E_DEVICE_UNIQUE_ID);
	sprintf(c,"UDID %u",storage.userData.UDID);
	IwGxPrintString(0, 50, c);
	////cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nUDID IS:"<<UDID;
}*/

/*
void CGame::setIAd()
{
	//Setup application callbacks
	s3eIOSIAdRegister(S3E_IOSIAD_CALLBACK_AD_STARTING, iADMaximised, NULL);
	s3eIOSIAdRegister(S3E_IOSIAD_CALLBACK_AD_FINISHED, iADMinimised, NULL);
	s3eIOSIAdRegister(S3E_IOSIAD_CALLBACK_FAILED, iADFailed, NULL);
}

*/
int32 ScreenSizeChangeCallback(void* systemData, void* userData)
{
	//cout<<"\ndisplay reset";
		
		util.displayReset = true;
		
		/*if(util.displayReset)
		{
			util.destruct();
			util.construct();
		}*/

		return 0;
}
/*
int32 iADMinimised(void* systemData, void* userData)
{
    //Application resume information here
    return 1;
}

int32 iADMaximised(void* systemData, void* userData)
{
    //Application pause information here
    return 1;
}

int32 iADFailed(void* systemData, void* userData)
{
    //Application failed information here
    //failcode = *(int *)systemData;
	//noIAd = true;
    return 1;
}
*/