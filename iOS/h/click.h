#ifndef CLICK_H
#define CLICK_H

#include "util.h"
	
class Click
{

public:
	int x;
	int y;
	int w;
	int h;

	CIw2DImage* pTextureOff;  
	CIw2DImage* pTextureOn;   
		
	char* text;

	Click()
	{
		text = NULL;
	}

	void construct(float virtualX,float virtualY,int anchorX,int anchorY,char *c,CIw2DImage* on,CIw2DImage* off)
	{
		text = NULL;
		pTextureOn = on;
		pTextureOff = off;

		w = pTextureOn->GetWidth();
		h = pTextureOn->GetHeight();
		
		//text part
		int i=0;
		while(c[i]!=NULL)
			i++;
		
		if(i>0)
		{
			text = new char[i+1];
			strcpy(text,c);
		}

		if(anchorX == util.LEFT)
		{
			x = (virtualX*util.em)+util.anchorX;
		}
		if(anchorX == util.CENTER)
		{
			x = (virtualX*util.em)+(util.widthDisplay/2);
		}
		if(anchorX == util.RIGHT)
		{
			x = (virtualX*util.em)+util.widthGame+((util.widthDisplay-util.widthGame)/2);
		}
		if(anchorX == util.BASEX)
		{
			x = (virtualX*util.em)+util.anchorX;
		}

		if(anchorY == util.TOP)
		{
			y = (virtualY*util.em)+util.anchorY;
		}
		if(anchorY == util.MIDDLE)
		{
			y = (virtualY*util.em)+(util.heightDisplay/2);
		}
		if(anchorY == util.BOTTOM)
		{
			y = (virtualY*util.em)+util.heightGame+((util.heightDisplay-util.heightGame)/2);
		}
		if(anchorY == util.BASEY)
		{
			y = (virtualY*util.em)+util.anchorY;
		}
		
	}
	
	void constructRaw(float virtualX,float virtualY,int anchorX,int anchorY,char *c,CIw2DImage* on,CIw2DImage* off)
	{
		text = NULL;
		pTextureOn = on;
		pTextureOff = off;


		w = pTextureOn->GetWidth();
		h = pTextureOn->GetHeight();
		
		//text part
		int i=0;
		while(c[i]!=NULL)
			i++;
		
		if(i>0)
		{
			text = new char[i+1];
			strcpy(text,c);
		}

		if(anchorX == util.LEFT)
		{
			x = (virtualX)+util.anchorX;
		}
		if(anchorX == util.CENTER)
		{
			x = (virtualX)+(util.widthDisplay/2);
		}
		if(anchorX == util.RIGHT)
		{
			x = (virtualX)+util.widthGame+((util.widthDisplay-util.widthGame)/2);
		}
		if(anchorX == util.BASEX)
		{
			x = (virtualX)+util.anchorX;
		}

		if(anchorY == util.TOP)
		{
			y = (virtualY)+util.anchorY;
		}
		if(anchorY == util.MIDDLE)
		{
			y = (virtualY)+(util.heightDisplay/2);
		}
		if(anchorY == util.BOTTOM)
		{
			y = (virtualY)+util.heightGame+((util.heightDisplay-util.heightGame)/2);
		}
		if(anchorY == util.BASEY)
		{
			y = (virtualY)+util.anchorY;
		}
		
	}
	void construct(float virtualX,float virtualY,int anchorX,int anchorY,char *c,CIw2DImage* on)
	{
		text = NULL;
		pTextureOn = on;
		pTextureOff = on;
		

		w = pTextureOn->GetWidth();
		h = pTextureOn->GetHeight();
		
		//text part
		//text part
		int i=0;
		while(c[i]!=NULL)
			i++;

		if(i>0)
		{
			text = new char[i+1];
			strcpy(text,c);
		}

		if(anchorX == util.LEFT)
		{
			x = (virtualX*util.em)+util.anchorX;
		}
		if(anchorX == util.CENTER)
		{
			x = (virtualX*util.em)+(util.widthDisplay/2);
		}
		if(anchorX == util.RIGHT)
		{
			x = (virtualX*util.em)+util.widthGame+((util.widthDisplay-util.widthGame)/2);
		}
		if(anchorX == util.BASEX)
		{
			x = (virtualX*util.em)+util.anchorX;
		}

		if(anchorY == util.TOP)
		{
			y = (virtualY*util.em)+util.anchorY;
		}
		if(anchorY == util.MIDDLE)
		{
			y = (virtualY*util.em)+(util.heightDisplay/2);
		}
		if(anchorY == util.BOTTOM)
		{
			y = (virtualY*util.em)+util.heightGame+((util.heightDisplay-util.heightGame)/2);
		}
		if(anchorY == util.BASEY)
		{
			y = (virtualY*util.em)+util.anchorY;
		}
		
	}
	
	void constructRaw(float virtualX,float virtualY,int anchorX,int anchorY,char *c,CIw2DImage* on)
	{
		text = NULL;
		pTextureOn = on;
		pTextureOff = on;
		

		w = pTextureOn->GetWidth();
		h = pTextureOn->GetHeight();
		
		//text part
		//text part
		int i=0;
		while(c[i]!=NULL)
			i++;

		if(i>0)
		{
			text = new char[i+1];
			strcpy(text,c);
		}

		if(anchorX == util.LEFT)
		{
			x = (virtualX)+util.anchorX;
		}
		if(anchorX == util.CENTER)
		{
			x = (virtualX)+(util.widthDisplay/2);
		}
		if(anchorX == util.RIGHT)
		{
			x = (virtualX)+util.widthGame+((util.widthDisplay-util.widthGame)/2);
		}
		if(anchorX == util.BASEX)
		{
			x = (virtualX)+util.anchorX;
		}

		if(anchorY == util.TOP)
		{
			y = (virtualY)+util.anchorY;
		}
		if(anchorY == util.MIDDLE)
		{
			y = (virtualY)+(util.heightDisplay/2);
		}
		if(anchorY == util.BOTTOM)
		{
			y = (virtualY)+util.heightGame+((util.heightDisplay-util.heightGame)/2);
		}
		if(anchorY == util.BASEY)
		{
			y = (virtualY)+util.anchorY;
		}
		
	}
	void setTexture(char *file1,char *file2)
	{
		char tmp[50];

		sprintf(tmp,"%s%s",util.PATH,file1);
		pTextureOn = Iw2DCreateImage(tmp);

		sprintf(tmp,"%s%s",util.PATH,file2);
		pTextureOff = Iw2DCreateImage(tmp);

		w = pTextureOn->GetWidth();
		h = pTextureOn->GetHeight();
	}
	/*void setText(CIw2DImage* On,CIw2DImage* Off)
	{

	}*/
	void setTexture(CIw2DImage* On,CIw2DImage* Off)
	{
		pTextureOn = On;
		pTextureOff = Off;
					
		w = pTextureOn->GetWidth();
		h = pTextureOn->GetHeight();
	}
	
	void destruct()
	{
		if(text != NULL)
		delete text;text=NULL;
		/*if(pTextureOn)
			delete pTextureOn;pTextureOn=NULL;
		if(pTextureOff)
			delete pTextureOff;pTextureOff=NULL;
		if(text)*/
			//delete text;text=NULL;
	}

	bool listen(int lx,int ly)
	{
		if(lx>x && ly>y && lx<x+w && ly<y+h)
		{
			return true;
		}
		
		return false;
	}

	void render(bool bSwitch,CIw2DFont* ftemp)
	{
		CIwSVec2 topLeft(x,y);
		CIwSVec2 region(w, h);
		if(bSwitch)
		{
			Iw2DSetColour(0xffaaffaa);
			Iw2DDrawImage(pTextureOn,topLeft);
			Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
			Iw2DDrawImage(pTextureOn,topLeft);
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

			Iw2DDrawImage(pTextureOn,topLeft);
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
	
	void render(CIw2DFont* ftemp)
	{//blue levelbox
		CIwSVec2 topLeft(x,y);
		CIwSVec2 region(w, h);
		
		//Iw2DSetColour(util.COLOR[2]);
		Iw2DDrawImage(pTextureOn,topLeft);
		Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
		Iw2DDrawImage(pTextureOn,topLeft);
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
	
	void render(bool bSwitch)//click and off
	{
		CIwSVec2 topLeft(x,y);
		if(bSwitch)
		{
			
			Iw2DDrawImage(pTextureOn,topLeft);
			Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
			Iw2DDrawImage(pTextureOn,topLeft);
			Iw2DSetColour(0xffffffff);	
			Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		}
		else
		{			
				Iw2DDrawImage(pTextureOff,topLeft);			
		}
	}

	void render(bool click,bool state)//click and on/off
	{
		CIwSVec2 topLeft(x,y);
		if(click)
		{
				Iw2DSetColour(0xffaaffaa);
			if(state)
			{	
				Iw2DDrawImage(pTextureOn,topLeft);
				Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
				Iw2DDrawImage(pTextureOn,topLeft);
			}
			else
			{
				Iw2DDrawImage(pTextureOff,topLeft);
				Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
				Iw2DDrawImage(pTextureOff,topLeft);
			}

			Iw2DSetColour(0xffffffff);	
			Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		}
		else
		{
			if(state)
				Iw2DDrawImage(pTextureOn,topLeft);
			else
				Iw2DDrawImage(pTextureOff,topLeft);
		}
	}
	
	void render()//only true no click
	{
		CIwSVec2 topLeft(x,y);
		Iw2DDrawImage(pTextureOn,topLeft);
	}

	void render(int dx,int dy)//only true no click
	{
		CIwSVec2 topLeft(dx,dy);
		Iw2DDrawImage(pTextureOn,topLeft);
	}

	~Click()
	{
		/*if(pTextureOn)
			delete pTextureOn;pTextureOn=NULL;
		if(pTextureOff)
			delete pTextureOff;pTextureOff=NULL;
		*/
		//if(text != NULL)
			
	}
};
#endif