#ifndef CROW_H
#define CROW_H

#include "sprite.h"

class Crow{

	Sprite crow[5];
	CIw2DImage* pTexture;

	int16 frameW;
	int16 frameH;
	short frame;
	
	int16 cordX[5];
	int16 cordY[5];
	int16 velX[5];
	int16 velY[5];

	//int16 centroid[2];

public:
	
	void init(CIw2DImage *t)
	{
		pTexture = t;
		frameW = pTexture->GetWidth()/6;
		frameH = pTexture->GetHeight();
		frame = 0;

		for(int i=0;i<5;i++)
		{
			IwRandSeed((int32)s3eTimerGetMs());
			int ancX = IwRandRange(util.widthDisplay);
			int ancY = IwRandRange(util.heightDisplay*0.5f);

			crow[i].construct(ancX,ancY,util.LEFT,util.TOP,pTexture);
			IwRandSeed((int32)s3eTimerGetMs());
			cordX[i] = IwRandMinMax(1,50);
			cordY[i] = i*20;
			velX[i] = 2;
			velY[i] = 2;
		}

	}

	void update()
	{
		if(frame == 5)
			frame = 0;
		else
			frame++;
		
		/*centroid[0] = 0;
		centroid[1] = 0;
		
		for(int i=0;i<5;i++)
		{
			centroid[0] += cordX[i];
			centroid[1] += cordY[i];
		}
		centroid[0] /= 5;
		centroid[1] /= 5;*/
		
		for(int i=0;i<5;i++)
		{

			cordX[i]+=velX[i];
			cordY[i]+=velY[i];
			

			if(cordX[i] > util.widthDisplay)
			{	//if(velX[i] > -5)
				velX[i]-=7;
			}
			else if(cordX[i] < 0)
			{	//if(velX[i] < 5)
				velX[i]+=7;
			}

			if(cordY[i] > util.heightDisplay*0.5)
			{	//if(velY[i] > -5)
				velY[i]-=7;
			}
			else if(cordY[i] < 0)
			{	//if(velY[i] < 5)
				velY[i]+=7;
			}
		}
		////cout<<"\ncentroid0:"<<centroid[0]<<" centroid1:"<<centroid[1];
		////cout<<"\nvelx0:"<<velX[0]<<" vely0:"<<velY[0]<<" cordx0:"<<cordX[0]<<" cordy0:"<<cordY[0];
	}

	void render()
	{
		crow[0].render(cordX[0],cordY[0],frameW*frame,0,frameW,frameH);
		/*crow[1].render(cordX[1],cordY[1],frameW*frame,0,frameW,frameH);
		crow[2].render(cordX[2],cordY[2],frameW*frame,0,frameW,frameH);
		crow[3].render(cordX[3],cordY[3],frameW*frame,0,frameW,frameH);
		crow[4].render(cordX[4],cordY[4],frameW*frame,0,frameW,frameH);*/
	}

	~Crow()
	{
		for(int i=0;i<5;i++)
		{
			crow[i].destruct();
		}
	}

};

#endif