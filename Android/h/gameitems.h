#ifndef GAMEITEMS_H
#define GAMEITEMS_H

#include "sprite.h"
#include "ParticleSystem.h"
#include "gameunit.h"

class GameItems{//deprecated


	int blockX[3];
	int blockY[3];

	int shroomX[8];
	int shroomY[8];

	int8 shroomType[4];//0 achived,-1 evil,1 good

	ParticleSystem pSystem;
	int life;//0 means exhausted, -1 means unlimited 150 show 3, 100 show 2 50 show 1
	int8 pitch;
	int8 top;
	bool dir;//true = up false = down
	Sprite spStar[3];
	Sprite spShroom[3];
	
	CIw2DImage* pStar;
	CIw2DImage* psStar;
	CIw2DImage* pFinish;
	CIw2DImage* pToxic;
	CIw2DImage* pEvilShroom;
	CIw2DImage* pGoodShroom;


public:

	bool achived[3];

	GameItems()
	{
		
		pStar = NULL;
		psStar = NULL;
		pFinish = NULL;
		pToxic = NULL;
		pEvilShroom = NULL;
		pGoodShroom = NULL;
	}
	

	void initPS(CIw2DImage* psstar, CIw2DImage* pfinish, CIw2DImage* ptoxic)
	{
		psStar = psstar;
		pFinish = pfinish;
		pToxic = ptoxic;
		//pSystem.setTexture(psStar,pfinish,ptoxic);
	}

	void makeUnit(int type,int x,int y,int trayX,int trayY)
	{
		int x1 = trayX+(x*util.BLOCKSIZE);
		int y1 = trayY+(y*util.BLOCKSIZE);

		int wGap = (util.BLOCKSIZE - pEvilShroom->GetWidth())/2;
		int hGap = (util.BLOCKSIZE - pEvilShroom->GetHeight())/2;

		//GameUnit g;
		/*switch (type)
		{
			case STAR1:
			{
				break;
			}
			case STAR2:
			{
				break;
			}
			case STAR3:
			{
				break;
			}
			case GOODSHROOM:
			{
				break;
			}
			case EVILSHROOM:
			{
				break;
			}
			case PORTAL1:
			{
				break;
			}
			case PORTAL2:
			{
				break;
			}
		}*/
		//g.init(type,x1+wGap,y1+hGap,x,y);
		//arrGameUnit.push_back(g);
	//	//cout<<"\npushed unit "<<arrGameUnit[arrGameUnit.size()-1].type<<",size "<<arrGameUnit.size();

	}

	void updateUnit(int x,int y)//-evilshrooom,0 no overlap,1 star1,2 star2,3 star3,4 goodshroom,5 portal1,6 portal2 
	{
		/*for(int i=0;i<arrGameUnit.size();i++)
		{
			if((x == arrGameUnit[i].blockx||x+1 == arrGameUnit[i].blockx) && y == arrGameUnit[i].blocky)
			{
				int ret = arrGameUnit[i].type;
				if(arrGameUnit[i].type<3)
					pSystem.init(10,arrGameUnit[i].x,arrGameUnit[i].y,pToxic,5+ret);
				
				//cout<<"\nerased unit "<<arrGameUnit[i].type<<",size "<<arrGameUnit.size();
				arrGameUnit.erase(i);
				//return ret;
			}
		}*/
	}

	void initShroom(int trayX,int trayY,int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4,int type1,int type2,int type3,int type4,CIw2DImage* evilShroom,CIw2DImage* goodShroom)
	{
		pEvilShroom = evilShroom;
		pGoodShroom = goodShroom;

		shroomType[0] = type1;
		shroomType[1] = type2;
		shroomType[2] = type3;
		shroomType[3] = type4;

		shroomX[0] = a1;
		shroomY[0] = b1;
		shroomX[1] = a2;
		shroomY[1] = b2;		
		shroomX[2] = a3;
		shroomY[2] = b3;
		shroomX[3] = a4;
		shroomY[3] = b4;

		int x1 = trayX+(a1*util.BLOCKSIZE);
		int y1 = trayY+(b1*util.BLOCKSIZE);
		int x2 = trayX+(a2*util.BLOCKSIZE);
		int y2 = trayY+(b2*util.BLOCKSIZE);
		int x3 = trayX+(a3*util.BLOCKSIZE);
		int y3 = trayY+(b3*util.BLOCKSIZE);
		int x4 = trayX+(a4*util.BLOCKSIZE);
		int y4 = trayY+(b4*util.BLOCKSIZE);

		int wGap = (util.BLOCKSIZE - pEvilShroom->GetWidth())/2;
		int hGap = (util.BLOCKSIZE - pEvilShroom->GetHeight())/2;

		if(type1 == -1)
			spShroom[0].construct(x1+wGap,y1+hGap,util.LEFT,util.TOP,pEvilShroom);
		else if(type1 == 1)
			spShroom[0].construct(x1+wGap,y1+hGap,util.LEFT,util.TOP,pGoodShroom);

		if(type2 == -1)
			spShroom[1].construct(x2+wGap,y2+hGap,util.LEFT,util.TOP,pEvilShroom);
		else if(type2 == 1)
			spShroom[1].construct(x2+wGap,y2+hGap,util.LEFT,util.TOP,pGoodShroom);

		if(type3 == -1)
			spShroom[2].construct(x3+wGap,y3+hGap,util.LEFT,util.TOP,pEvilShroom);
		else if(type3 == 1)
			spShroom[2].construct(x3+wGap,y3+hGap,util.LEFT,util.TOP,pGoodShroom);

		if(type4 == -1)
			spShroom[3].construct(x4+wGap,y4+hGap,util.LEFT,util.TOP,pEvilShroom);
		else if(type4 == 1)
			spShroom[3].construct(x4+wGap,y4+hGap,util.LEFT,util.TOP,pGoodShroom);

	}

	void initStar(int trayX,int trayY,int a1,int b1,int a2,int b2,int a3,int b3,CIw2DImage* star)
	{
		pStar = star;

		blockX[0] = a1;
		blockX[1] = a2;
		blockX[2] = a3;

		blockY[0] = b1;
		blockY[1] = b2;
		blockY[2] = b3;

		
		int x1 = trayX+(a1*util.BLOCKSIZE);
		int y1 = trayY+(b1*util.BLOCKSIZE);
		int x2 = trayX+(a2*util.BLOCKSIZE);
		int y2 = trayY+(b2*util.BLOCKSIZE);
		int x3 = trayX+(a3*util.BLOCKSIZE);
		int y3 = trayY+(b3*util.BLOCKSIZE);

		achived[0]=false;
		achived[1]=false;
		achived[2]=false;
		
		life = -1;//768;
		
		pitch = 0;
		top = 7*util.em;
		dir = true;
		
		int wGap = (util.BLOCKSIZE - pStar->GetWidth())/2;
		int hGap = (util.BLOCKSIZE - pStar->GetHeight())/2;

		spStar[0].construct(x1+wGap,y1+hGap,util.LEFT,util.TOP,pStar);
		spStar[1].construct(x2+wGap,y2+hGap,util.LEFT,util.TOP,pStar);
		spStar[2].construct(x3+wGap,y3+hGap,util.LEFT,util.TOP,pStar);
	}

	void destruct()
	{
		/*delete pEvilShroom;
		pEvilShroom = NULL;

		delete pGoodShroom;
		pGoodShroom = NULL;*/
		
		/*delete pStar;
		pStar = NULL;*/
		
		pSystem.destruct();
	}

	~GameItems()
	{
		//pSystem.destruct();
		//delete pStar;
		//pStar = NULL;
	}

	void update()
	{
		pSystem.update();
		pSystem.render();
	}
	void render()
	{
		renderStars();
		renderShrooms();
	}

	void renderShrooms()
	{
		if(shroomType[0] != 0)
			spShroom[0].render();
		if(shroomType[1] != 0)
			spShroom[1].render();
		if(shroomType[2] != 0)
			spShroom[2].render();
		if(shroomType[3] != 0)
			spShroom[3].render();
	}

	void renderStars()
	{
		
		if(dir)
		{	
			if(pitch>top)
				dir = false;
			pitch++;
		}
		else
		{
			if(pitch<-top)
				dir = true;
			pitch--;
		}
		//CIwColour color;
		//color.r = 255;
		//color.g = 255;
		//color.b = 255;
		
		if(life>510)
		{
			life--;
			if(!achived[0])
				spStar[0].render(pitch);
			if(!achived[1])
				spStar[1].render(pitch);
			
			//color.a = (life-510);
			//Iw2DSetColour(color);
			if(!achived[2])
				spStar[2].render(pitch);
			
			//Iw2DSetColour(0xffffffff);
			return;
		}
		else if(life == -1)
		{
			if(!achived[0])
				spStar[0].render(pitch);
			if(!achived[1])
				spStar[1].render(pitch);
			if(!achived[2])
				spStar[2].render(pitch);
			
			return;
		}
		else if(life>255)
		{
			life--;
			if(!achived[0])
				spStar[0].render(pitch);

			//color.a = (life-255);
			//Iw2DSetColour(color);
			if(!achived[1])
				spStar[1].render(pitch);
			
			//Iw2DSetColour(0xffffffff);
			return;
		}
		else if(life>0)
		{
			life--;

			//color.a = (life)*3;
			//Iw2DSetColour(color);
			if(!achived[0])
				spStar[0].render(pitch);
			
			//Iw2DSetColour(0xffffffff);
			return;
		}
		
	}

	int getShroomCheck(int x,int y)
	{//return 0 for no hit, 1 for evil hit, 2 for good hit

		if(shroomType[0] !=0 && (x == shroomX[0]||x+1 == shroomX[0]) && y == shroomY[0])
		{
			int ret = shroomType[0];
			pSystem.init(10,spShroom[0].x,spShroom[0].y,pToxic,5+ret);
			shroomType[0] = 0;
			return ret;
		}
		
		if(shroomType[1] !=0 && (x == shroomX[1]||x+1 == shroomX[1]) && y == shroomY[1])
		{
			int ret = shroomType[1];
			pSystem.init(10,spShroom[1].x,spShroom[1].y,pToxic,5+ret);
			shroomType[1] = 0;
			return ret;
			
		}

		if(shroomType[2] !=0 && (x == shroomX[2]||x+1 == shroomX[2]) && y == shroomY[2])
		{
			int ret = shroomType[2];
			pSystem.init(10,spShroom[2].x,spShroom[2].y,pToxic,5+ret);
			shroomType[2] = 0;
			return ret;
			
		}

		if(shroomType[3] !=0 && (x == shroomX[3]||x+1 == shroomX[3]) && y == shroomY[3])
		{
			int ret = shroomType[3];
			pSystem.init(10,spShroom[3].x,spShroom[3].y,pToxic,5+ret);
			shroomType[3] = 0;
			return ret;
			
		}
		return 0;
	}
	
	void getCheck(int x,int y)
	{

		////cout<<"\n"<<"\n"<<"\n"<<"\n";
		////cout<<"\n"<<x<<"\t"<<y;
		////cout<<"\n"<<blockX[0]<<"\t"<<blockY[0];
		////cout<<",\t"<<blockX[1]<<"\t"<<blockY[1];
		////cout<<",\t"<<blockX[2]<<"\t"<<blockY[2];
		////cout<<"\n"<<"\n"<<"\n"<<"\n";
		
		if(!achived[0] && (x == blockX[0]||x+1 == blockX[0]) && y == blockY[0])
		{
			pSystem.init(10,spStar[0].x,spStar[0].y,psStar,1);
			achived[0] = true;
			return;// true;
		}
		else if(!achived[1] && (x == blockX[1]||x+1 == blockX[1]) && y == blockY[1])
		{
			pSystem.init(10,spStar[1].x,spStar[1].y,psStar,1);
			achived[1] = true;
			return;// true;
		}
		else if(!achived[2] && (x == blockX[2]||x+1 == blockX[2]) && y == blockY[2])
		{
			pSystem.init(10,spStar[2].x,spStar[2].y,psStar,1);
			achived[2] = true;
			return;// true;
		}
	}

};
#endif