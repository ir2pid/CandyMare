#ifndef FONT_H
#define FONT_H

#include "s3e.h"
#include "Iw2D.h"
#include "IwResManager.h"
#include "Util.h"
#include <iostream>

static class Font{

	CIwResGroup* fontGroup; 
public:
	
	CIw2DFont* AllerS;//info,notofication
	CIw2DFont* AllerM;//,levelselect
	CIw2DFont* AllerL;//levelend
	CIw2DFont* AllerXL;//gameplay

	Font()
	{
		AllerS = NULL;
		AllerM = NULL;
		AllerL = NULL;
		AllerXL = NULL;
	}

	void genFont()
	{//only after layout and load of group
			
		if((util.widthGame == 480 && util.heightGame == 320) ||
			(util.widthGame == 640 && util.heightGame == 480) ||
			(util.widthGame == 640 && util.heightGame == 360)	
			)
		{//480x320
			//cout<<"\nloading font480x320.group";
			IwGetResManager()->LoadGroup("./texture/480x320/font.group"); 
		}/*
		else if(util.widthGame == 800 && util.heightGame == 480)
		{//800x480 
			//cout<<"\nloading font800x480.group";
			IwGetResManager()->LoadGroup("./texture/800x480/font.group"); 
		}
		else if((util.widthGame == 854 && util.heightGame == 480) ||
			(util.widthGame == 800 && util.heightGame == 600) ||
			(util.widthGame == 960 && util.heightGame == 540))
		{//845x480 || 800x600 || 960x540
			//cout<<"\nloading font854x480.group";
			IwGetResManager()->LoadGroup("./texture/854x480/font.group"); 
		}*/
		else// if(util.widthGame == 960 && util.heightGame == 640)
		{//960x640
			//cout<<"\nloading font960x640.group";
			IwGetResManager()->LoadGroup("./texture/960x640/font.group"); 
		}/*
		else if(util.widthGame == 1024 && util.heightGame == 600)
		{//1024x600
			//cout<<"\nloading font1024x600.group";
			IwGetResManager()->LoadGroup("./texture/1024x600/font.group"); 
		}*/
		/*else// if((util.widthGame == 1024 && util.heightGame == 768) ||
			//(util.widthGame == 1280 && util.heightGame == 800) ||
			//(util.widthGame == 1366 && util.heightGame == 768))
		{//1024x768
			//cout<<"\nloading font1024x768.group";
			IwGetResManager()->LoadGroup("./texture/1024x768/font.group"); 
		}*//*
		else
		{
			//util.gameRes = util.RERROR;
			//cout<<"\n fallback loading font480x320.group";
			//load dummy stuffs to avoid errors
			IwGetResManager()->LoadGroup("./texture/480x320/font.group");
		}*/

			fontGroup = IwGetResManager()->GetGroupNamed("font"); 
			
			AllerS = Iw2DCreateFontResource("AllerS");
			AllerM = Iw2DCreateFontResource("AllerM");
			AllerL = Iw2DCreateFontResource("AllerL");
			AllerXL = Iw2DCreateFontResource("AllerXL");


	}

	void genFontClear()
	{
		if(AllerS)
			delete AllerS;AllerS = NULL;
		if(AllerM)
			delete AllerM;AllerM = NULL;
		if(AllerL)
			delete AllerL;AllerL = NULL;
		if(AllerXL)
			delete AllerXL;AllerXL = NULL;

		IwGetResManager()->DestroyGroup("font"); 
	}

	void genWrite(char* str,CIw2DFont* ftemp,int x,int y,int w,int h,CIw2DFontAlign alignx,CIw2DFontAlign aligny)
	{
		/*
		enum CIw2DFontAlign
		{
			IW_2D_FONT_ALIGN_TOP,
			IW_2D_FONT_ALIGN_LEFT = IW_2D_FONT_ALIGN_TOP,
			IW_2D_FONT_ALIGN_CENTRE,
			IW_2D_FONT_ALIGN_BOTTOM,
			IW_2D_FONT_ALIGN_RIGHT = IW_2D_FONT_ALIGN_BOTTOM,
		};
		*/

		    Iw2DSetFont(ftemp);

			// Draw in black
			//Iw2DSetAlphaMode(IW_2D_ALPHA_NONE );
			
			Iw2DSetColour(0xff00ff00);

			// Render the text into a 100x100 region
			CIwSVec2 region(w, h);

			// Centred on the centre of the surface
			CIwSVec2 topLeft(x,y);

			// Draw the string into the region
			Iw2DDrawString(str, topLeft, region, alignx, aligny);
			Iw2DSetColour(0xffffffff);
	}

}font;

#endif

