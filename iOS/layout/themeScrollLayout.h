#ifndef THEMESCROLLLAYOUT_H
#define THEMESCROLLLAYOUT_H

#include "sprite.h"
#include "storage.h"

class ThemeScrollLayout
{
	int bgX;
	int bgY;
	int sizeX;
	int sizeY;
	CIwSVec2 stripePoints[4][4];
	char jumble[17];
	int done;
	
public:
	//char text[35];
	bool touchOn;
	bool isValid;
	bool swiped;
	int themeID;
	int dx;
	int speed;
	int acc;
	int theme1x;
	int theme2x;
	int theme3x;
	int theme4x;
	int theme5x;
	int lensX;
	int lensY;
	int lensWidth;
	int lensHeight;
	int anchorX[5];

	//Sprite bg;
	//CIw2DImage* tScroll;
	CIw2DImage* tScroll[4];
	CIw2DImage* tArrow;
	//CIw2DImage* tNextScroll;
	CIw2DImage* tNext;
	CIw2DImage* tNext0;
	CIw2DImage* tBack;
	CIw2DImage* tLock0;
	//Sprite spScroll;
	Sprite spScroll[5];
	Sprite spLock;
	Sprite spNextScroll;
	Sprite spPrevScroll;
	Click cNext;
	Click cBack;
	
	int16 scrollY;
	int16 nextX;
	int16 prevX;

	ThemeScrollLayout()
	{
		acc = 20*util.em;
		isValid = true;
		themeID = 1;
		touchOn = false;
		swiped = false;
		sprintf(jumble,"%s","Halloween Creeps");
		done = 0;
		speed = 1;
		bgX = (util.widthDisplay-util.widthGame)/2;
		bgY = (util.heightDisplay-util.heightGame)/2;

		sizeX = util.widthGame;
		sizeY = util.heightGame;
		lensWidth = sizeX/2;
		lensHeight = sizeY/2;
		lensX = bgX+(sizeX - lensWidth)/2;
		lensY = bgY+(sizeY - lensHeight)/2;
		int16 width = util.widthGame;
		theme1x = 0;
		theme2x = width;
		theme3x = width*2;
		theme4x = width*3;
		theme5x = width*4;
		
		switch(storage.userData.currTheme)
		{
			case 1:{
					dx = theme1x;
					break;
					}
			case 2:{
					dx = theme2x;
					break;
					}
			case 3:{
					dx = theme3x;
					break;
					}
			default:
				dx = theme1x;
		}

		anchorX[0] = lensX-bgX;
		anchorX[1] = theme2x+anchorX[0];
		anchorX[2] = theme3x+anchorX[0];
		anchorX[3] = theme4x+anchorX[0];
		anchorX[4] = theme5x+anchorX[0];
		
		//cout<<"\nanchors are: \n"<<theme1x<<"\n"<<theme2x<<"\n"<<theme3x<<"\n"<<theme4x<<"\n"<<theme5x<<"\n";
		//if(util.gameRes == util.R480x320)
		{
			tScroll[0] = util.getBGTexture("theme/scroll1.jpg");
			tScroll[1] = util.getBGTexture("theme/scroll2.jpg");
			tScroll[2] = util.getBGTexture("theme/scroll3.jpg");
			tScroll[3] = util.getBGTexture("theme/scroll4.jpg");

			tArrow = util.getTexture("menu/arrow.png");
			//tNextScroll = util.getTexture("menu/tArrow.png");

			tNext = util.getTexture("menu/next.png");
			tNext0 = util.getTexture("menu/next0.png");
			tBack = util.getTexture("menu/back.png");
			tLock0 = util.getTexture("menu/lock0.png");
		}

		scrollY = (util.heightGame-tArrow->GetHeight())/2;
		nextX = -(10*util.em)-tArrow->GetWidth();
		prevX = 10*util.em;

		spNextScroll.constructRaw(nextX,scrollY,util.RIGHT,util.TOP,tArrow);
		spPrevScroll.constructRaw(prevX,scrollY,util.LEFT,util.TOP,tArrow);
		
		//spScroll.construct(bgX,bgY,util.LEFT,util.TOP,tScroll);
		spScroll[0].constructRaw(anchorX[0],lensY-bgY,util.LEFT,util.TOP,tScroll[0]);
		spScroll[1].constructRaw(anchorX[1],lensY-bgY,util.LEFT,util.TOP,tScroll[1]);
		spScroll[2].constructRaw(anchorX[2],lensY-bgY,util.LEFT,util.TOP,tScroll[2]);
		spScroll[3].constructRaw(anchorX[3],lensY-bgY,util.LEFT,util.TOP,tScroll[3]);
		spScroll[4].constructRaw(anchorX[4],lensY-bgY,util.LEFT,util.TOP,tScroll[3]);

		spLock.constructRaw((util.widthGame-tLock0->GetWidth())/2,(util.heightGame-tLock0->GetHeight())/2,util.LEFT,util.TOP,tLock0);
		
		
		//int16 buttonY;
		int16 ThemeSelX;
		//int16 backX;
		
		//buttonY = -tNext->GetHeight();//-(50*util.em);//lensY+lensHeight;//+(lensY-tNext->GetHeight())/2;
		ThemeSelX = (util.widthGame - tNext->GetWidth())/2;
		//backX = util.widthGame-ThemeSelX-tBack->GetWidth();;

		cNext.constructRaw(ThemeSelX,-tNext->GetHeight(),util.LEFT,util.BOTTOM,"",tNext,tNext0);
		cBack.constructRaw(-tBack->GetWidth(),0,util.RIGHT,util.TOP,"",tBack);

		setStripes(lensX,lensY,lensWidth,lensHeight);

	}
	void renderText()
	{
		//Iw2DSetColour(0xaa00ff00);
		//Iw2DDrawRect(CIwSVec2(0,0),CIwSVec2());
		Iw2DSetFont(font.AllerXL);
								
			//Iw2DSetColour(0xff000000);
			CIwSVec2 top1(util.widthDisplay,lensY-bgY);
			
			Iw2DSetColour(util.COLOR[8]);
			char temp[30];
			//char *text;
			

			if(themeID == 1)
				sprintf(temp,"ACT I : %s",jumble);
			else if(themeID == 2)
				sprintf(temp,"ACT II : %s",jumble);
			else if(themeID == 3)
				sprintf(temp,"ACT III : %s",jumble);
			else if(themeID == 4)
				sprintf(temp,"ACT IV : %s",jumble);
			else if(themeID == 5)
				sprintf(temp,"ACT V : %s",jumble);
			
			Iw2DDrawString(temp,CIwSVec2(0,0),top1,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);

			Iw2DSetColour(0xffffffff);
	}

	void jumbleText()
	{
		if(themeID == 1)
				sprintf(jumble,"%s","Halloween Creeps");
		else if(themeID == 2)
				sprintf(jumble,"%s","Dracula's Castle");
		else if(themeID == 3)
				sprintf(jumble,"%s","Too Many Zombies");
		else if(themeID == 4)
				sprintf(jumble,"%s","Comming Soon....");
		else if(themeID == 5)
				sprintf(jumble,"%s","Comming Soon....");
		/*
		IwRandSeed((int32)s3eTimerGetMs()+themeID);
		done = IwRandMinMax(5,10);
		for(int i=0;i<16;i++)
		{
			//w<91 && w>64
			//w<123 && w>96)
			i%2==1?jumble[i]+=done:jumble[i]-=done;
			
		}*/
	}

	/*void textUpdate()
	{
		if(done > 0)
		{
			for(int i=0;i<16;i++)
			{
				i%2==1?jumble[i]--:jumble[i]++;				
			}
			done--;
		}
	}*/

	void update()
	{
	
		
		if(themeID <= storage.userData.sTheme && themeID<4)
			isValid = true;
		else 
			isValid = false;



		if(touchOn)
		{
			
			return;
		}
		else 
		{
			if(!swiped)
			{

				if(dx >= (theme4x+theme5x)/2)
				{
					if(themeID != 5)
					{						
						themeID = 5;
						jumbleText();
					}
				}
				else if(dx >= (theme3x+theme4x)/2)
				{
					if(themeID != 4)
					{
						themeID = 4;
						jumbleText();
					}
				}
				else if(dx >= (theme2x+theme3x)/2)
				{
					if(themeID != 3)
					{
						themeID = 3;
						jumbleText();
					}
				}
				else if(dx >= (theme1x+theme2x)/2)
				{
					if(themeID != 2)
					{
						themeID = 2;
						jumbleText();
					}
				}
				else 
				{
					if(themeID != 1)
					{
						themeID = 1;
						jumbleText();
					}
				}
			}
			
		}

		if(themeID == 1)
		{
			//cout<<"\n dx is "<<dx<<" speed is "<<speed;
			speed<30?speed+=5:speed-=5;
			if(dx < theme1x)
			{
				dx = 0;
			}
			else if(dx > theme1x)
			{
				if(dx-speed > theme1x)
						dx-=speed;
					else
						dx--;
			}
			else
			{
				swiped = false;
			}
			
		}
		else if(themeID == 2)
		{
			//cout<<"\n dx is "<<dx<<" speed is "<<speed;
			speed<30?speed+=5:speed-=5;

			if(dx > theme2x)
			{
				if(dx-speed > theme2x)
					dx-=speed;
				else
					dx--;
			}
			else if(dx < theme2x)
			{
				if(dx+speed < theme2x)
					dx+=speed;
				else
					dx++;			
			}
			else
				swiped = false;
			
		}
		else if(themeID == 3)
		{
			//cout<<"\n dx is "<<dx<<" speed is "<<speed;
			speed<30?speed+=5:speed-=5;

			if(dx > theme3x)
			{
				if(dx-speed > theme3x)
					dx-=speed;
				else
					dx--;
			}
			else if(dx < theme3x)
			{
				if(dx+speed < theme3x)
					dx+=speed;
				else
					dx++;			
			}
			else
				swiped = false;
			
		}
		else if(themeID == 4)
		{
			//cout<<"\n dx is "<<dx<<" speed is "<<speed;
			speed<30?speed+=5:speed-=5;

			if(dx > theme4x)
			{
				if(dx-speed > theme4x)
					dx-=speed;
				else
					dx--;
			}
			else if(dx < theme4x)
			{
				if(dx+speed < theme4x)
					dx+=speed;
				else
					dx++;			
			}
			else
				swiped = false;
			
		}
		else if(themeID == 5)
		{
			//cout<<"\n dx is "<<dx<<" speed is "<<speed;
			speed<30?speed+=5:speed-=5;

			if(dx > theme5x)
			{
				if(dx-speed > theme5x)
					dx-=speed;
				else
					dx--;
			}
			else if(dx < theme5x)
			{
				if(dx+speed < theme5x)
					dx+=speed;
				else
					dx++;			
			}
			else
				swiped = false;
			
		}
		
	}

	void renderScroll()
	{
		//spScroll.render(bgX,bgY,dx,0,sizeX,sizeY);
		if(spScroll[0].x+spScroll[0].pTexture-dx>0 && spScroll[0].x-dx<util.widthDisplay)
			spScroll[0].render(-dx,1.0f);
		if(spScroll[1].x+spScroll[1].pTexture-dx>0 && spScroll[1].x-dx<util.widthDisplay)
			spScroll[1].render(-dx,1.0f);
		if(spScroll[2].x+spScroll[2].pTexture-dx>0 && spScroll[2].x-dx<util.widthDisplay)
			spScroll[2].render(-dx,1.0f);
		if(spScroll[3].x+spScroll[3].pTexture-dx>0 && spScroll[3].x-dx<util.widthDisplay)
			spScroll[3].render(-dx,1.0f);
		if(spScroll[4].x+spScroll[4].pTexture-dx>0 && spScroll[4].x-dx<util.widthDisplay)
			spScroll[4].render(-dx,1.0f);
		/*spScroll[1].render(-dx,1.0f);
		spScroll[2].render(-dx,1.0f);
		spScroll[3].render(-dx,1.0f);
		spScroll[4].render(-dx,1.0f);*/
		if(dx > 0)
		{
			spPrevScroll.render((uint8)4);
		}
		if(dx < theme5x)
		{
			spNextScroll.render((uint8)2);
		}
		
		
		Iw2DDrawRect(CIwSVec2(lensX,lensY),CIwSVec2(lensWidth,lensHeight));
		if(!isValid)
		{
			CIwColour color;
			color.SetGrey(60); 
			color.a = 155;
			Iw2DSetColour(color);
			Iw2DFillRect(CIwSVec2(lensX,lensY),CIwSVec2(lensWidth,lensHeight));
			Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
			Iw2DFillPolygon(stripePoints[0],4);
			//Iw2DFillPolygon(stripePoints[1],4);
			//Iw2DFillPolygon(stripePoints[2],4);
			Iw2DFillPolygon(stripePoints[3],4);
			spLock.render();
			Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
			Iw2DSetColour(0xffffffff);
		}
		

	}




	void destruct()
	{
		//spScroll.destruct();
		spLock.destruct();
		cNext.destruct();
		cBack.destruct();
		for(int i=0;i<4;i++)
		{
			spScroll[i].destruct();
			if(tScroll[i])
				delete tScroll[i];tScroll[i] = NULL;
		}
		/*if(tScroll)
			delete tScroll;tScroll = NULL;*/
		if(tLock0)
			delete tLock0;tLock0 = NULL;
		if(tArrow)
			delete tArrow;tArrow = NULL;
		/*if(tPrevScroll)
			delete tPrevScroll;tPrevScroll = NULL;*/
		if(tNext)
			delete tNext;tNext = NULL;
		if(tNext0)
			delete tNext0;tNext0 = NULL;
		if(tBack)
			delete tBack;tBack = NULL;

	}

	~ThemeScrollLayout()
	{
		
	}

	
	void setStripes(int x,int y,int width,int height)
	{
		int w = width;//util.widthDisplay;
		int h = height;//util.heightDisplay;
		int wGap = w/3;
		int hGap = h/3;
		int hsize = hGap/4;
		int wsize = wGap/4;

		//p1
		int p1x1 = 0+x;
		int p1x2 = wGap-wsize+x;
		int p1x3 = wGap+wsize+x;
		int p1x4 = 0+x;

		int p1y1 = hGap-hsize+y;
		int p1y2 = 0+y;
		int p1y3 = 0+y;
		int p1y4 = hGap+hsize+y;
		
		//p2
		int p2x1 = 0+x;
		int p2x2 = (wGap*2)-wsize+x;
		int p2x3 = (wGap*2)+wsize+x;
		int p2x4 = 0+x;

		int p2y1 = (hGap*2)-hsize+y;
		int p2y2 = 0+y;
		int p2y3 = 0+y;
		int p2y4 = (hGap*2)+hsize+y;
		
		//p3
		int p3x1 = wGap-wsize+x;
		int p3x2 = width+x;
		int p3x3 = width+x;
		int p3x4 = wGap+wsize+x;

		int p3y1 = height+y;
		int p3y2 = hGap-hsize+y;
		int p3y3 = hGap+hsize+y;
		int p3y4 = height+y;
		
		//p4
		int p4x1 = (wGap*2)-wsize+x;
		int p4x2 = width+x;
		int p4x3 = width+x;
		int p4x4 = (wGap*2)+wsize+x;

		int p4y1 = height+y;
		int p4y2 = (hGap*2)-hsize+y;
		int p4y3 = (hGap*2)+hsize+y;
		int p4y4 = height+y;

		//strip1
		stripePoints[0][0] = CIwSVec2(p1x1,p1y1);
		stripePoints[0][1] = CIwSVec2(p1x2,p1y2);
		stripePoints[0][2] = CIwSVec2(p1x3,p1y3);
		stripePoints[0][3] = CIwSVec2(p1x4,p1y4);
		
		//strip2
		stripePoints[1][0] = CIwSVec2(p2x1,p2y1);
		stripePoints[1][1] = CIwSVec2(p2x2,p2y2);
		stripePoints[1][2] = CIwSVec2(p2x3,p2y3);
		stripePoints[1][3] = CIwSVec2(p2x4,p2y4);

		//strip3
		stripePoints[2][0] = CIwSVec2(p3x1,p3y1);
		stripePoints[2][1] = CIwSVec2(p3x2,p3y2);
		stripePoints[2][2] = CIwSVec2(p3x3,p3y3);
		stripePoints[2][3] = CIwSVec2(p3x4,p3y4);
		
		//strip4
		stripePoints[3][0] = CIwSVec2(p4x1,p4y1);
		stripePoints[3][1] = CIwSVec2(p4x2,p4y2);
		stripePoints[3][2] = CIwSVec2(p4x3,p4y3);
		stripePoints[3][3] = CIwSVec2(p4x4,p4y4);

	}

};

#endif