#ifndef LEVELENDLAYOUT_H
#define LEVELENDLAYOUT_H

#include "sprite.h"
#include "click.h"
#include "graphiti.h"
#include "util.h"

class LevelEndLayout
{
	int bgX;
	int bgY;
public:
	int frame;
	
	//CIw2DImage* tBg;
	CIw2DImage* tDialogBox;
	CIw2DImage* tStar;
	CIw2DImage* tStar0;
	CIw2DImage* tTrack;
	CIw2DImage* tNext;
	CIw2DImage* tLMenu;
	CIw2DImage* tReset;
	CIw2DImage* tFB;
	CIw2DImage* tZap;

	//Sprite sBg;
	Sprite sDialogBox;
	Sprite sStar;
	Sprite sStar0;
	Sprite sTrack;
	
	Click cFB;
	Click cZap;
	Click cNext;
	Click cLMenu;
	Click cReset;
	///int iTimer;
	//uint16 offset;//h & w same
	//int iAnim;

	int16 iTextAnchorY;
	int16 iTextAnchorX;
	int16 iStarAnchorY;
	int16 iStarAnchorX1;
	int16 iStarAnchorX2;
	int16 iStarAnchorX3;

	float scale[3];

	GraphitiSystem gs;
	bool dropGraphiti;
	LevelEndLayout()
	{
		
		util.setBG();

		frame = 0;
		dropGraphiti = false;
		gs.init(100*util.em);
		/*iTimer = 100;
		iStar = 3;
		iAnim = 0;	*/
		storage.saveStorage();
		scale[0] = 0.0;
		scale[1] = 0.0;
		scale[2] = 0.0;

		//tBg = util.getBgTile();//util.getTexture("menu/bg1bw.png");
		tDialogBox = util.getTexture("menu/dialogbox1.png");
		tStar = util.getTexture("fx/fstar.png");
		tStar0 = util.getTexture("fx/fstar0.png");
		tTrack = util.getTexture("menu/track.png");
		tLMenu = util.getTexture("menu/lvlendhome.png");
		tReset = util.getTexture("menu/lvlendreset.png");
		tNext = util.getTexture("menu/lvlendnext.png");
		tFB = util.getTexture("menu/fb0.png");
		tZap = util.getTexture("menu/zap.png");
		

    	int dialogX = (util.widthGame-tDialogBox->GetWidth())/2;
		int dialogY = (util.heightGame-tDialogBox->GetHeight())/2;

		
		//sBg.construct(0,0,util.LEFT,util.TOP,tBg);
		//sDialogBox.constructRaw(dialogX,dialogY,util.LEFT,util.TOP,tDialogBox);
		sDialogBox.constructRaw(-(tDialogBox->GetWidth()/2),dialogY,util.MIDDLE,util.TOP,tDialogBox);
		sStar.construct(dialogX,dialogY,util.LEFT,util.TOP,tStar);
		sStar0.construct(dialogX,dialogY,util.LEFT,util.TOP,tStar0);
				
		int fbx = (tFB->GetWidth());
		cFB.constructRaw(fbx,dialogY,util.MIDDLE,util.TOP,"",tFB,tFB);

		int zapx = -(tZap->GetWidth()*2);
		cZap.constructRaw(zapx,dialogY,util.MIDDLE,util.TOP,"",tZap,tZap);

		//bg.setTexture("menu/th1.png");
		int midscreen = util.widthDisplay/2;
		int resetX = -(tReset->GetWidth()/2);
		int menuX = resetX-tLMenu->GetWidth();
		int next = resetX+tReset->GetWidth();
		
		cNext.constructRaw(next,dialogY+tDialogBox->GetHeight(),util.MIDDLE,util.TOP,"",tNext,tNext);
		cReset.constructRaw(resetX,dialogY+tDialogBox->GetHeight(),util.MIDDLE,util.TOP,"",tReset,tReset);
		cLMenu.constructRaw(menuX,dialogY+tDialogBox->GetHeight(),util.MIDDLE,util.TOP,"",tLMenu,tLMenu);
		int nx = cNext.x;
		int rx = cReset.x;
		int mx = cLMenu.x;
		//cNext.constructRaw(dialogX,dialogY+tDialogBox->GetHeight(),util.LEFT,util.TOP,"",tNext,tNext);
		//cLMenu.constructRaw(dialogX+tDialogBox->GetWidth()-tLMenu->GetWidth(),dialogY+tDialogBox->GetHeight(),util.LEFT,util.TOP,"",tLMenu,tLMenu);
		//cReset.constructRaw(dialogX+tDialogBox->GetWidth()-tLMenu->GetWidth(),dialogY+tDialogBox->GetHeight(),util.LEFT,util.TOP,"",tReset,tReset);
		//cOption.construct(-150,250,util.RIGHT,util.TOP,"",tOption0,tOption1);
		//play.construct(
		iTextAnchorX = ((util.widthDisplay-util.widthGame)/2) + (util.widthGame/2);
		iStarAnchorY = (util.heightDisplay-tStar->GetHeight())/2 - (tStar->GetHeight()/2);	
		
		iTextAnchorY = (util.heightGame/2) + (tStar->GetHeight()/2);
		
		
		sTrack.constructRaw(-(tTrack->GetWidth()*3/2),iTextAnchorY,util.CENTER,util.TOP,tTrack);
		
		int16 adjust;
		if(tTrack->GetHeight()>font.AllerL->GetHeight())
			adjust = (tTrack->GetHeight()-font.AllerL->GetHeight())/2;
		else
			adjust = (font.AllerL->GetHeight() - tTrack->GetHeight())/2;
		
		iTextAnchorY = (util.heightDisplay)/2 + (tStar->GetHeight()/2);

		iTextAnchorY += adjust;

		int gap = tStar->GetWidth()/2;
		int dialogwidth = (util.widthDisplay - (4*tStar->GetWidth()))/2;
		iStarAnchorX1 = dialogwidth;
		iStarAnchorX2 = iStarAnchorX1 + tStar->GetWidth() + gap;//+tDialogBox->GetWidth();
		iStarAnchorX3 = iStarAnchorX2 + tStar->GetWidth() + gap;//+(tDialogBox->GetWidth()*2);
		
	}
	/*void renderTest()
	{	
		CIwMat2D rot;
		CIwVec2 anchor;
		anchor.x = 0;
		anchor.y = 0;
		CIwVec2 centre;
		centre.x = -100;
		centre.y = -25;
		iwfixed angle;
		angle = frame*IW_FIXED(0.01);
		rot.SetRot(angle, (CIwVec2)anchor);
		rot.SetTrans(CIwSVec2(100,1));
		Iw2DSetTransformMatrix(rot);
		Iw2DFillRect((CIwSVec2)centre, CIwSVec2(250,50));
		Iw2DSetTransformMatrix(CIwMat2D::g_Identity); 
		Iw2DFillRect(CIwSVec2(util.widthDisplay/2,util.heightDisplay/2), CIwSVec2(200,50));
		if(frame<25)
			frame++;
		//else 
			//frame = 0;
		//cout<<"\nframe:"<<frame;
	}*/
	void renderScore()
	{
		char tmp[9];
		sprintf(tmp,"%d/%d",storage.sStarDump[1],storage.sStarDump[2]);
		
		Iw2DSetFont(font.AllerL);
		Iw2DSetColour(0xff000000);
		Iw2DDrawString(tmp,CIwSVec2(iTextAnchorX,iTextAnchorY+1),CIwSVec2(util.widthGame,font.AllerL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_TOP);	
		//Iw2DDrawString(tmp,CIwSVec2(iTextAnchorX-1,iTextAnchorY-1),CIwSVec2(util.widthGame,font.AllerL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_TOP);
		Iw2DDrawString(tmp,CIwSVec2(iTextAnchorX+1,iTextAnchorY+1),CIwSVec2(util.widthGame,font.AllerL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_TOP);
		//Iw2DDrawString(tmp,CIwSVec2(iTextAnchorX+1,iTextAnchorY-1),CIwSVec2(util.widthGame,font.AllerL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_TOP);
					
		Iw2DSetColour(util.COLOR[0]);
		Iw2DDrawString(tmp,CIwSVec2(iTextAnchorX,iTextAnchorY),CIwSVec2(util.widthGame,font.AllerL->GetHeight()),IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_TOP);
	
	}

	void renderStars()
	{
		renderScore();
		sTrack.render();

		if(storage.sStarDump[0] == 3)
		{
			sStar.render(iStarAnchorX1,iStarAnchorY,scale[0]);
			sStar.render(iStarAnchorX2,iStarAnchorY,scale[1]);
			sStar.render(iStarAnchorX3,iStarAnchorY,scale[2]);
		}
		else if(storage.sStarDump[0] == 2)
		{
			sStar.render(iStarAnchorX1,iStarAnchorY,scale[0]);
			sStar.render(iStarAnchorX2,iStarAnchorY,scale[1]);
			sStar0.render(iStarAnchorX3,iStarAnchorY);
		}
		else if(storage.sStarDump[0] == 1)
		{
			sStar.render(iStarAnchorX1,iStarAnchorY,scale[0]);
			sStar0.render(iStarAnchorX2,iStarAnchorY);
			sStar0.render(iStarAnchorX3,iStarAnchorY);
		}
		else
		{
			sStar0.render(iStarAnchorX1,iStarAnchorY);
			sStar0.render(iStarAnchorX2,iStarAnchorY);
			sStar0.render(iStarAnchorX3,iStarAnchorY);
		}
	}
	void destruct()
	{
		gs.destruct();
		cNext.destruct();
		cLMenu.destruct();
		cFB.destruct();
		cZap.destruct();
		
		//delete tBg;tBg = NULL;
		delete tFB;tFB = NULL;
		delete tZap;tZap = NULL;
		delete tDialogBox;tDialogBox = NULL;
		delete tNext;tNext = NULL;
		delete tLMenu;tLMenu = NULL;
		delete tReset;tReset = NULL;		
		delete tStar;tStar = NULL;
		delete tStar0;tStar0 = NULL;
		delete tTrack;tTrack = NULL;
	}

	void FBPost()
	{
		
		//cout<<"\npost!"<<util.CENTER;
		int level = ((storage.userData.currTheme-1)*20)+storage.userData.currLevel;
		util.fb.post(level,storage.sStarDump[0],storage.sStarDump[1]);
	}
	
	void ZapPost()
	{
		if(HeyzapMarmaladeAvailable())
		{
			char tmp[250];
			int level = ((storage.userData.currTheme-1)*20)+storage.userData.currLevel;
			sprintf(tmp,"CandyMare Achivement! I just completed level %d with %d stars in %d moves",level,storage.sStarDump[0],storage.sStarDump[1]);

			checkinHeyzapWithMessage(tmp);
		}
	}

	~LevelEndLayout()
	{
		
	}
};

#endif