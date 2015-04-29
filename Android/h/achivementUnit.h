#ifndef ACHIVEMENTUNIT_H
#define ACHIVEMENTUNIT_H

#include "s3e.h"


class AchivementUnit{
public:
	int x;
	int y;
	int xIcon;
	int yIcon;
	int xText;
	int yText;
	int xTextRegion;
	int yTextRegion;
	char* text;

	void init(CIw2DImage *pFrame,CIw2DImage *pIcon)
	{
		xIcon = ((pFrame->GetWidth()*1)/10);
		yIcon = (pFrame->GetHeight()-pIcon->GetHeight())/2;

		xText = xIcon+pIcon->GetWidth()+((pFrame->GetWidth()*1)/10);
		yText = (pFrame->GetHeight()*1)/10;

		xTextRegion = pFrame->GetWidth()-xText-((pFrame->GetWidth()*1)/10);
		yTextRegion = pFrame->GetHeight()-((pFrame->GetHeight()*1)/5);
	}

	void construct(int xc,int yc,char *c)
	{
		x = xc;
		y = yc;
		/*xIcon+=x;
		yIcon+=y;
		xText+=x;
		yText+=y;
		xTextRegion+=x;
		yTextRegion+=y;*/

		//pos = p;

		text = NULL;

		//text part
		int i=0;
		while(c[i]!=NULL)
			i++;
		
		if(i>0)
		{
			text = new char[i+1];
			strcpy(text,c);
		}
	}
	
	void render(CIw2DImage *pFrame)
	{
		CIwSVec2 topLeft(x,y);
		Iw2DDrawImage(pFrame,topLeft);
	}

	void render(int y,CIw2DImage *pFrame,CIw2DImage *pIcon)
	{
		CIwSVec2 topLeft(x,y);
		Iw2DDrawImage(pFrame,topLeft);
		CIwSVec2 topLeftIcon(x+xIcon,y+yIcon);
		Iw2DDrawImage(pIcon,topLeftIcon);


		CIwSVec2 region(xTextRegion,yTextRegion);
		Iw2DSetFont(font.AllerM);
								
		Iw2DSetColour(0xff000000);
		CIwSVec2 top1(x+xText+1,y+yText);
		Iw2DDrawString(text,top1,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		CIwSVec2 top2(x+xText-1,y+yText);
		Iw2DDrawString(text,top2,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		CIwSVec2 top3(x+xText,y+yText+1);
		Iw2DDrawString(text,top3,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		CIwSVec2 top4(x+xText,y+yText-1);
		Iw2DDrawString(text,top4,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);

		Iw2DSetColour(0xffffffff);
		CIwSVec2 topLeftText(x+xText,y+yText);		
		Iw2DDrawString(text,topLeftText,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
				
	}

	void destruct()
	{
		if(text != NULL)
		delete text;text=NULL;
	}
};

#endif