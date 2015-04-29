#ifndef INFOLAYOUT_H
#define INFOLAYOUT_H

#include <time.h>
#include "font.h"

class InfoLayout
{
public:
	char *text[10];
	char *jumble[10];
	int size[10];
	int y[10];
	int delay;
	int row;
	int column;
	CIw2DImage* tBack;
	Click cBack;
	int done;
	
	CIw2DImage* tIw;
	Sprite sIw;
	CIwSVec2 shiftLogo;

	void construct()
	{
		row = 0;
		column = 0;
		tBack = util.getTexture("menu/back.png");
		cBack.constructRaw(-tBack->GetWidth(),0,util.RIGHT,util.TOP,"",tBack);
		tIw = util.getTile("iw.png");
		shiftLogo.x = tIw->GetWidth()*((util.em/4.0f));
		shiftLogo.y = tIw->GetHeight()*((util.em/4.0f));
		sIw.construct(-tIw->GetWidth()+shiftLogo.x,-tIw->GetHeight()+shiftLogo.y,util.RIGHT,util.BOTTOM,tIw);
		//add http://www.allvectors.com,http://www.vecteezy.com,
		//font http://www.fontsquirrel.com/, http://www.dafont.com,http://www.ffonts.net/

		makeText(0,"MADE BY: Noisy Ninja");
		makeText(1,"Thanks: Baruch Richter,Mat Hopwood,iMr,roo,nullsquared,DeceasedSuperiorTechnician");
		makeText(2,"VECTORS: VectorVaco.com, pixEden.com, GraphicsFuel.com, MediaLoot.com");
		makeText(3,"dezignus.com, VectorOpenStock.com, VectorLady.com, allvectors.com,");
		makeText(4," WowVectors.com, DownloadFreeVector.com, SixRevisions.comh, vecteezy.com");
		makeText(5,"AUDIO: nosoapradio.us,freesound.org.  VOICE: Pushkin.");
		makeText(6,"Most vectors & Sounds are licensed under CC-Attribution 3.0");
		makeText(7,"Apologies in case we forgot to credit you, please contact us immediately!");
		makeText(8,"Contact: spriteninjas@gmail.com, Web: noisyninja.co.cc");
		makeText(9,"Follow us at www.facebook.com\\CandyMareApp\\");
		
		int gap = util.heightGame/11;
		int adjustY = (util.heightDisplay-util.heightGame)/2;

		y[0] = adjustY+gap;
		y[1] = y[0]+gap;
		y[2] = y[1]+gap;
		y[3] = y[2]+gap;
		y[4] = y[3]+gap;
		y[5] = y[4]+gap;
		y[6] = y[5]+gap;
		y[7] = y[6]+gap;
		y[8] = y[7]+gap;
		y[9] = y[8]+gap;
	}

	void makeText(int i,char *c)
	{
		delay = 0;
		//text part
		IwRandSeed((int32)s3eTimerGetMs()+i);
		int len=0;
		while(c[len]!=NULL)
		{
			len++;
		}
		
		text[i] = new char[len+1];
		jumble[i] = new char[len+1];
		size[i] = len;
		
		strcpy(text[i],c);
		strcpy(jumble[i],c);

		len = 0;
		while(c[len]!=NULL)
		{
			int w = text[i][len];
			if(w<91 && w>64)
				jumble[i][len] = IwRandMinMax(jumble[i][len]-5,jumble[i][len]+5);
			else if(w<123 && w>96)
				jumble[i][len] = IwRandMinMax(jumble[i][len]-5,jumble[i][len]+5);
			else 
				jumble[i][len] = w;
			len++;
		}
		//cout<<"";

	}
	void render()
	{

		Iw2DSetFont(font.AllerS);
								
		CIwSVec2 region(util.widthDisplay,100);
		
		if(column == 10)
		{
			/*Iw2DSetColour(0xff222222);
			for(int i=0;i<10;i++)
			{
				CIwSVec2 top1(-1,y[i]-1);
				Iw2DDrawString(jumble[i],top1,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
				CIwSVec2 top2(-1,y[i]+1);
				Iw2DDrawString(jumble[i],top2,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
				CIwSVec2 top3(1,y[i]-1);
				Iw2DDrawString(jumble[i],top3,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
				CIwSVec2 top4(1,y[i]+1);
				Iw2DDrawString(jumble[i],top4,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
			}*/
			
			Iw2DSetColour(util.COLOR[8]);
				
			for(int i=0;i<10;i++)
			{
				CIwSVec2 topLeft(0,y[i]);
				Iw2DDrawString(jumble[i],topLeft,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
			}
			Iw2DSetColour(0xffffffff);
			return;
		}

		for(int j=0;j<column+1;j++)
		{	
			if(j == 10)
				break;
			/*Iw2DSetColour(0xff222222);
			for(int i=0;i<10;i++)
			{
				CIwSVec2 top1(-1,y[j]-1);
				Iw2DDrawString(jumble[j],top1,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
				CIwSVec2 top2(-1,y[j]+1);
				Iw2DDrawString(jumble[j],top2,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
				CIwSVec2 top3(1,y[j]-1);
				Iw2DDrawString(jumble[j],top3,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
				CIwSVec2 top4(1,y[j]+1);
				Iw2DDrawString(jumble[j],top4,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
			}*/
			
			Iw2DSetColour(util.COLOR[8]);
				
			for(int i=0;i<10;i++)
			{
				CIwSVec2 topLeft(0,y[j]);
				Iw2DDrawString(jumble[j],topLeft,region,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_TOP);
			}
			
			Iw2DSetColour(0xffffffff);
		}
	}

	void update()
	{
		if(column < 10)
		{
			row = 0;
			done = size[column];
			for(int i=0;i<size[column];i++)
			{
				if(jumble[column][row]<text[column][row])
					jumble[column][row]++;
				else if(jumble[column][row]>text[column][row])
					jumble[column][row]--;
				else done --;
					row++;
			}
			
		}

		if(done == 0 && column < 10)
			column++;
		////cout<<"column "<<column;
	}

	void destruct()
	{
		for(int i=0;i<10;i++)
		{
			delete text[i];
			text[i] = NULL;
			delete jumble[i];
			jumble[i] = NULL;
		}
		
		delete tIw;tIw = NULL;
		delete tBack;tBack = NULL;
	
	}
};
#endif