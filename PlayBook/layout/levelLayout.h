#ifndef LEVELLAYOUT_H
#define LEVELLAYOUT_H

#include "sprite.h"
#include "Storage.h"
#include "clicksheet.h"

class LevelLayout
{
	int bgX;
	int bgY;

public:

	/*class Animate{
		CIwArray<Click> cObj;
		CIwArray<int> cObjX;
		CIwArray<int> cObjY;
	};*/

	//Sprite bg;
	uint16 levelStart;
	int16 iMiniStarX[15];//20*3
	int16 iMiniStarY[4];//20*3
	bool type[60];//20*3
	uint8 active[20];
	//CIw2DImage* tBg;
	CIw2DImage* tBoxSheet;
	CIw2DImage* tBox01;
	CIw2DImage* tBox1;
	CIw2DImage* tBox02;
	CIw2DImage* tBox2;
	CIw2DImage* tBox03;
	CIw2DImage* tBox3;
	CIw2DImage* tBoxStar;
	CIw2DImage* tBoxStar0;
	CIw2DImage* tBack;
	//Sprite sBg;
	Sprite spBoxStar;
	Sprite spBoxStar0;
	Click cBack;
	//CIw2DImage* tBoxb;
	ClickSheet cLevel[20];
	float frame;

	LevelLayout()
	{
		util.setBG();

		levelStart = (20*(storage.userData.currTheme-1));
		//cout<<"\nshowing levels "<<levelStart<<" to "<<levelStart+20;

		frame = 0.0f;

		for(int i=0;i<20;i++)
		{
			if(storage.userData.currTheme<storage.userData.sTheme)
				active[i] = 1;
			else if(i+1 < storage.userData.sLevel)
				active[i] = 1;
			else if(i+1 == storage.userData.sLevel)
				active[i] = 0;
			else
				active[i] = -1;
		}

		//tBg = util.getBgTile();//util.getTexture("menu/bg1bw.png");
		tBoxSheet = util.getTexture("level/boxsheet.png");
		tBox1 = util.getTexture("level/box1.png");
		tBox01 = util.getTexture("level/box01.png");
		tBox2 = util.getTexture("level/box2.png");
		tBox02 = util.getTexture("level/box02.png");
		tBox3 = util.getTexture("level/box3.png");
		tBox03 = util.getTexture("level/box03.png");
		tBoxStar = util.getTexture("level/boxstar.png");
		tBoxStar0 = util.getTexture("level/boxstar0.png");
		tBack = util.getTexture("menu/back.png");

		//sBg.constructRaw(0,0,util.LEFT,util.TOP,tBg);
		spBoxStar.constructRaw(0,0,util.TOP,util.LEFT,tBoxStar);
		spBoxStar0.constructRaw(0,0,util.TOP,util.LEFT,tBoxStar0);
		cBack.constructRaw(-tBack->GetWidth(),0,util.RIGHT,util.TOP,"",tBack);
		
		int hRegion = (util.heightGame-tBack->GetHeight())/4;
		int wRegion = util.widthGame/5;

		int hGap = (hRegion - tBox1->GetHeight())/2;
		int wGap = (wRegion - tBox1->GetWidth())/2;
		
		//if(util.gameRes == util.R480x320)
		{
			/*bg.construct(0,0,util.TOP,util.LEFT);
			bg.setTexture("menu/th1.png");*/
			//for(int i=0;i<5;i++)
			int head = tBack->GetHeight();
			int adjustX = (util.widthDisplay-util.widthGame)/2;
			int adjustY = (util.heightDisplay-util.heightGame)/2;
			int k =0;

			for(int i=0;i<4;i++)
			{	for(int j=0;j<5;j++)
				{	
					char tmp[5];
					sprintf(tmp,"%i",levelStart+k+1);//counting from 1
					IwRandSeed((int32)s3eTimerGetMs()+i+j);
					switch(IwRandMinMax(1,4))
					{
					case 1:
						cLevel[k].constructRaw(wGap+(wRegion*j),head+hGap+(hRegion*i),util.LEFT,util.TOP,tmp,tBox1,tBox01);
						break;
					case 2:
						cLevel[k].constructRaw(wGap+(wRegion*j),head+hGap+(hRegion*i),util.LEFT,util.TOP,tmp,tBox2,tBox02);
						break;
					case 3:
						cLevel[k].constructRaw(wGap+(wRegion*j),head+hGap+(hRegion*i),util.LEFT,util.TOP,tmp,tBox3,tBox03);
						break;
					default:
						cLevel[k].constructRaw(wGap+(wRegion*j),head+hGap+(hRegion*i),util.LEFT,util.TOP,tmp,tBox3,tBox03);
					}
					cLevel[k].setSpriteSheet(tBoxSheet);
					if(i == 0)
						genStarX(adjustX+wGap+(wRegion*j),k);
					if(j == 0)
						genStarY(head+adjustY+hGap+(hRegion*i),i);

					genStar(i,j,k);

					k++;
				}
			}
		}
	}

	void genStar(int i,int j,int k)
	{
		// = storage.userData.currTheme;
		//int level = (i*5)+j;
		
		int tmp = levelStart+k;//counting from 0
		int num =k*3;
		if(storage.userData.sStar[tmp]==3)
		{
			type[num] = true;
			type[num+1] = true;
			type[num+2] = true;
		}
		else if(storage.userData.sStar[tmp]==2)
		{
			type[num] = true;
			type[num+1] = true;
			type[num+2] = false;
		}
		else if(storage.userData.sStar[tmp]==1)
		{
			type[num] = true;
			type[num+1] = false;
			type[num+2] = false;
		}
		else
		{
			type[num] = false;
			type[num+1] = false;
			type[num+2] = false;
		}
	}

	void genStarY(int y,int i)
	{
		iMiniStarY[i] = y + tBox1->GetHeight() - ((tBoxStar->GetHeight()/2));//*3)/2);
	}

	void genStarX(int x,int k)
	{
		
		int gap = (tBox1->GetWidth()-(3*tBoxStar->GetWidth()))/4;
		iMiniStarX[(k*3)] = x + gap;
		iMiniStarX[(k*3)+1] = iMiniStarX[(k*3)] + gap + tBoxStar->GetWidth();
		iMiniStarX[(k*3)+2] = iMiniStarX[(k*3)+1] + gap + tBoxStar->GetWidth();
	}

	void renderMiniStars()
	{
		for(int i=0;i<20;i++)
		{
			if(active[i] == true)
			{
				if(type[(i*3)] == true)
					spBoxStar.render(iMiniStarX[(i*3)%15],iMiniStarY[i/5]);
				else
					spBoxStar0.render(iMiniStarX[(i*3)%15],iMiniStarY[i/5]);

				if(type[(i*3)+1] == true)
					spBoxStar.render(iMiniStarX[((i*3)+1)%15],iMiniStarY[i/5]);
				else
					spBoxStar0.render(iMiniStarX[((i*3)+1)%15],iMiniStarY[i/5]);

				if(type[(i*3)+2] == true)
					spBoxStar.render(iMiniStarX[((i*3)+2)%15],iMiniStarY[i/5]);
				else
					spBoxStar0.render(iMiniStarX[((i*3)+2)%15],iMiniStarY[i/5]);
			}
			else
				break;
		}
	}

	void update()
	{
		if(frame <  3.75)
			frame+=0.25;
		else 
			frame = 0.0;
	}

	void destruct()
	{
		/*if(tBg)
			delete tBg;tBg = NULL;*/
		if(tBoxSheet)
			delete tBoxSheet;tBoxSheet = NULL;
		if(tBox1)
			delete tBox1;tBox1 = NULL;
		if(tBox01)
			delete tBox01;tBox01 = NULL;
		if(tBox2)
			delete tBox2;tBox2 = NULL;
		if(tBox02)
			delete tBox02;tBox02 = NULL;
		if(tBox3)
			delete tBox3;tBox3 = NULL;
		if(tBox03)
			delete tBox03;tBox03 = NULL;
		if(tBoxStar)
			delete tBoxStar;tBoxStar = NULL;
		if(tBoxStar0)
			delete tBoxStar0;tBoxStar0 = NULL;
		if(tBack)
			delete tBack;tBack = NULL;

		for(int i=0;i<20;i++)
			cLevel[i].destruct();

		spBoxStar.destruct();
		spBoxStar0.destruct();
		cBack.destruct();

	}
	~LevelLayout()
	{
				
	}
};

#endif