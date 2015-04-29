#ifndef CLICKSHEET_H
#define CLICKSHEET_H

#include "util.h"
#include "click.h"
	
class ClickSheet :public Click
{
	int sheetW;
	
	//CIw2DImage* pTextureSheet; 
public:
	
	void setSpriteSheet(CIw2DImage* Sheet)
	{
		//pTextureSheet = Sheet;
					
		sheetW = Sheet->GetWidth()/4;
		//h = pTextureOn->GetHeight();
	}
	
	void render(bool bSwitch,CIw2DFont* ftemp)
	{
		Click::render(bSwitch,ftemp);
	}

	void render(bool bSwitch)
	{
		Click::render(bSwitch);
	}

	void render(bool bSwitch,CIw2DFont* ftemp,int frame,CIw2DImage* pTextureSheet)
	{
		CIwSVec2 topLeft(x,y);
		CIwSVec2 region(sheetW,h);
		CIwSVec2 offset((sheetW*frame),0);
		////cout<<"\n\n"<<frame<<"offset"<<(sheetW*frame);
		if(bSwitch)
		{
			Iw2DSetColour(0xffaaffaa);
			Iw2DDrawImageRegion(pTextureSheet,topLeft,offset,region);
			Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
			//Iw2DDrawImage(pTextureOn,topLeft);
			Iw2DDrawImageRegion(pTextureSheet,topLeft,offset,region);

			Iw2DSetColour(0xffffffff);	
			
			Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
			if(ftemp)
			{
				Iw2DSetFont(ftemp);
								
				Iw2DSetColour(0xff000000);
				CIwSVec2 top1(x+2,y);
				Iw2DDrawString(text,top1,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//CIwSVec2 top2(x-1,y);
				//Iw2DDrawString(text,top2,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				CIwSVec2 top3(x,y+2);
				Iw2DDrawString(text,top3,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//CIwSVec2 top4(x,y-1);
				//Iw2DDrawString(text,top4,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
				Iw2DSetColour(0xffa5d2ff);
				
				Iw2DDrawString(text,topLeft,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
			
				Iw2DSetColour(0xffffffff);
			}
		}
		else
		{
			
			Iw2DDrawImageRegion(pTextureSheet,topLeft,offset,region);
			if(ftemp)
			{
				Iw2DSetFont(ftemp);

				Iw2DSetColour(0xff000000);
				CIwSVec2 top1(x+2,y);
				Iw2DDrawString(text,top1,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//CIwSVec2 top2(x-1,y);
				//Iw2DDrawString(text,top2,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				CIwSVec2 top3(x,y+2);
				Iw2DDrawString(text,top3,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//CIwSVec2 top4(x,y-1);
				//Iw2DDrawString(text,top4,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				
				Iw2DSetColour(0xffa5d2ff);
				
				Iw2DDrawString(text,topLeft,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
			
				Iw2DSetColour(0xffffffff);
			}
		}
	}
};
#endif