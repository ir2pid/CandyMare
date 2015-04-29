#ifndef THEMEINTROLAYOUT_H
#define THEMEINTROLAYOUT_H

#include <time.h>
#include "font.h"
#include "crow.h"

class ThemeIntroLayout
{

public:
	
	CIw2DImage* tBack;
	CIw2DImage* tCrow;
	CIw2DImage* tBg;
	
	//Click cBack;
	Crow crow;
	Sprite sBg;
	int fade;
	void construct()
	{
		
		//tBack = util.getTexture("menu/back.png");
		//cBack.constructRaw(-tBack->GetWidth(),0,util.RIGHT,util.TOP,"",tBack);
		
		tCrow = util.getTexture("fx/bat/bat.png");

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
		
		crow.init(tCrow);
		sBg.construct(0,0,util.LEFT,util.TOP,tBg);
		
	}
	
	void renderBG()
	{
		sBg.renderBG(CIwSVec2(util.widthDisplay,util.heightDisplay));
	}
	
	void render()
	{

		if(fade > 250)
			fade = 0;
		else
			fade+=5;

		CIwSVec2 topLeftLabel(0,0);
		CIwSVec2 regionLabel(util.widthDisplay,util.heightDisplay/2);
		CIwColour colorBlack;
		colorBlack.a = 255;
		colorBlack.r = 0;
		colorBlack.g = 0;
		colorBlack.b = 0;

		Iw2DSetFont(font.AllerL);
		switch(storage.userData.currTheme)
		{
		case 1:
			{
				Iw2DSetColour(colorBlack);
		CIwSVec2 topLeftLabela(1,1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabela,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelb(1,-1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabelb,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelc(-1,1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabelc,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabeld(-1,-1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabeld,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[8].a = fade;
				Iw2DSetColour(util.COLOR[8]);
				Iw2DDrawString("Act I: Halloween Creeps",topLeftLabel,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[8].a = 255;	
				break;
			}
		case 2:
			{				
				Iw2DSetColour(colorBlack);
		CIwSVec2 topLeftLabela(1,1);Iw2DDrawString("Act II: Dracula's Castle",topLeftLabela,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelb(1,-1);Iw2DDrawString("Act II: Dracula's Castle",topLeftLabelb,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelc(-1,1);Iw2DDrawString("Act II: Dracula's Castle",topLeftLabelc,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabeld(-1,-1);Iw2DDrawString("Act II: Dracula's Castle",topLeftLabeld,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[3].a = fade;
				Iw2DSetColour(util.COLOR[3]);
				Iw2DDrawString("Act II: Dracula's Castle",topLeftLabel,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[3].a = 255;
				break;
			}
		case 3:
			{
				Iw2DSetColour(colorBlack);
		CIwSVec2 topLeftLabela(1,1);Iw2DDrawString("Act III: Too Many Zombies",topLeftLabela,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelb(1,-1);Iw2DDrawString("Act III: Too Many Zombies",topLeftLabelb,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelc(-1,1);Iw2DDrawString("Act III: Too Many Zombies",topLeftLabelc,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabeld(-1,-1);Iw2DDrawString("Act III: Too Many Zombies",topLeftLabeld,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[1].a = fade;
				Iw2DSetColour(util.COLOR[1]);
				Iw2DDrawString("Act III: Too Many Zombies",topLeftLabel,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[1].a = 255;
				break;
			}
		default:
			{
				Iw2DSetColour(colorBlack);
				
		CIwSVec2 topLeftLabela(1,1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabela,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelb(1,-1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabelb,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabelc(-1,1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabelc,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
		CIwSVec2 topLeftLabeld(-1,-1);Iw2DDrawString("Act I: Halloween Creeps",topLeftLabeld,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[8].a = fade;
				Iw2DSetColour(util.COLOR[8]);
				Iw2DDrawString("Act I: Halloween Creeps",topLeftLabel,regionLabel,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//util.COLOR[8].a = 255;
				break;
			}
		}
		
		CIwColour color;
		color.a=fade;
		color.r=255;
		color.g=255;
		color.b=255;
		Iw2DSetColour(color);
		
		CIwSVec2 topLeftMsg(0,(util.heightDisplay*4)/5);
		CIwSVec2 regionMsg(util.widthDisplay,util.heightDisplay/5);

		Iw2DSetFont(font.AllerS);
		Iw2DDrawString("Touch screen to Continue",topLeftMsg,regionMsg,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
		Iw2DSetColour(0xffffffff);
	}
	
	void destruct()
	{	
		delete tBg;tBg = NULL;
		delete tCrow;tCrow = NULL;	
	}
};
#endif