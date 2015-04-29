#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "sprite.h"
#include "effect.h"
#include "ParticleSystem.h"
#include "gameunit.h"


class GameObjects
{
	enum Type{
		STAR1,
		STAR2,
		STAR3,
		GOODSHROOM,
		EVILSHROOM,
		PORTAL1,
		PORTAL2
	};
	
	
	//particles
	CIw2DImage* psStar;
	//CIw2DImage* pFinish;
	CIw2DImage* pRhombus;
	CIw2DImage* pToxic;
	class Vec8
	{
	public:
		uint8 x;
		uint8 y;
		Vec8()
		{
			x = 0;
			y = 0;
		}
		Vec8(uint8 a,uint8 b)
		{
			x = a;
			y = b;
		}
	};
	
	CIwArray<GameUnit> arrGameUnit;

	int16 starY;
	int16 starX1;
	int16 starX2;
	int16 starX3;

public:
	CIwArray<Effect> rippleSystem;	
	CIwArray<Vec8> portals;//0 orange 1 blue
	int8 starAchived;
	bool dirTrans;//1 up, -1 down, -2 left, 2 right
	bool dirScale;//1.0 to 0.8
	int16 amountTranslate;
	float amountScale;
	ParticleSystem pSystem;
	uint16 adjustX;
	uint16 adjustY;
	GameObjects()
	{
		psStar = NULL;
		//pFinish = NULL;
		pToxic = NULL;
		starAchived = 0;
		dirTrans = true;
		dirScale = true;
		amountTranslate = 0;
		amountScale = 1.0;
		//arrGameUnit.clear();
		//portals.push_back(Vec8(0,0));
		//portals.push_back(Vec8(0,0));
	}

	void setAdjustValues(int adx,int ady)
	{
		adjustX = adx;
		adjustY = ady;
	}
	void setStarCord(int y,int x1,int x2,int x3)
	{
		starY = y;
		starX1 = x1;
		starX2 = x2;
		starX3 = x3;
	}

	void setParticle(int t,CIw2DImage* p)
	{
		switch(t)
		{
		case 0:
		case 1:
		case 2:{
			psStar = p;
			break;
			   }
		case 3:
		case 4:{
			pToxic = p;
			break;
			   }
		case 7:{
			pRhombus = p;
			break;
			   }
		default:{
			//cout<<"unknown particle id";
			}
		}
	}

	void makeUnit(CIw2DImage* pImg,int type,int x,int y,int trayX,int trayY)
	{
		int x1 = trayX+(x*util.BLOCKSIZE);
		int y1 = trayY+(y*util.BLOCKSIZE);
		int wGap;
		int hGap;
		if(type == 5)
		{
			
			wGap = ((2*util.BLOCKSIZE) - (pImg->GetWidth()/3))/2;
			hGap = (util.BLOCKSIZE - (pImg->GetHeight()))/2;
			if(portals.size()>0)
			{
				portals[0].x = x;	
				portals[0].y = y;
				portals[2].x = 0;
			}
			else
			{
				portals.push_back(Vec8(0,0));
				portals.push_back(Vec8(0,0));
				portals.push_back(Vec8(0,0));
				portals[0].x = x;	
				portals[0].y = y;
				portals[2].x = 0;
			}
		}
		else if(type == 6)
		{
			wGap = ((2*util.BLOCKSIZE) - (pImg->GetWidth()/3))/2;
			hGap = (util.BLOCKSIZE - (pImg->GetHeight()))/2;	
			if(portals.size()>0)
			{
				portals[1].x = x;	
				portals[1].y = y;
				portals[2].y = 0;
			}
			else
			{
				portals.push_back(Vec8(0,0));
				portals.push_back(Vec8(0,0));
				portals.push_back(Vec8(0,0));
				portals[1].x = x;	
				portals[1].y = y;
				portals[2].y = 0;
			}
		}
		else
		{
			wGap = (util.BLOCKSIZE - pImg->GetWidth())/2;
			hGap = (util.BLOCKSIZE - pImg->GetHeight())/2;
		}

		GameUnit g;
		
		g.init(pImg,type,x1+wGap,y1+hGap,x,y);
		arrGameUnit.push_back(g);
		//cout<<"\npushed unit "<<arrGameUnit[arrGameUnit.size()-1].type<<",@ "<<x<<","<<y<<", size "<<arrGameUnit.size()<<" x:"<<x1+wGap<<" y:"<<y1+hGap;

	}

	
	CIwArray<uint8> update(int x,int y)
	{
		CIwArray<uint8> retVal;
		retVal.clear();
		for(int i=0;i<arrGameUnit.size();i++)
		{
			//cout<<"\niteration"<<i;
			if((x == arrGameUnit[i].blockx||x+1 == arrGameUnit[i].blockx) && y == arrGameUnit[i].blocky)
			{
				uint8 ret;
				if(arrGameUnit[i].type < 3)//star
				{
						Effect e;
						e.x = arrGameUnit[i].x+util.BLOCKSIZE;
						e.y = arrGameUnit[i].y+(util.BLOCKSIZE/2);
						rippleSystem.push_back(e);

					starAchived++;
					pSystem.init(10,arrGameUnit[i].x,arrGameUnit[i].y,psStar,1);
					pSystem.initG(5,arrGameUnit[i].x,arrGameUnit[i].y,pRhombus,0);
					if(starAchived == 1)
					{
						pSystem.initG(7,starX1,starY,pRhombus,0);
						pSystem.initG(5,starX1,starY,psStar,1);
					}
					if(starAchived == 2)
					{
						pSystem.initG(7,starX2,starY,pRhombus,0);
						pSystem.initG(5,starX2,starY,psStar,1);
					}
					if(starAchived == 3)
					{
						pSystem.initG(7,starX3,starY,pRhombus,0);
						pSystem.initG(5,starX3,starY,psStar,1);
					}
					ret = arrGameUnit[i].type;
					retVal.push_back(ret);
				
					//cout<<"\nerased unit "<<(int)arrGameUnit[i].type;//<<",size "<<arrGameUnit.size();
					arrGameUnit.erase(i);
					i=-1;
					continue;
				}
				if(arrGameUnit[i].type == 3)//shroomevil
				{
					pSystem.init(10,arrGameUnit[i].x,arrGameUnit[i].y,pToxic,4);
					pSystem.init(5,arrGameUnit[i].x,arrGameUnit[i].y,pRhombus,0);
					
					ret = arrGameUnit[i].type;
					retVal.push_back(ret);
					//cout<<"\nerased unit "<<(int)arrGameUnit[i].type;//<<",size "<<arrGameUnit.size();
					arrGameUnit.erase(i);
					i=-1;
					continue;
				}
				if(arrGameUnit[i].type == 4)//shroomgood
				{
					pSystem.init(10,arrGameUnit[i].x,arrGameUnit[i].y,pToxic,6);
					pSystem.init(5,arrGameUnit[i].x,arrGameUnit[i].y,pRhombus,0);
					
					ret = arrGameUnit[i].type;
					retVal.push_back(ret);
					//cout<<"\nerased unit "<<(int)arrGameUnit[i].type;//<<",size "<<arrGameUnit.size();
					arrGameUnit.erase(i);
					i=-1;
					continue;
				}
				if(arrGameUnit[i].type == 5 && x == arrGameUnit[i].blockx)//check for full overlap too
				{
						Effect e;
						e.x = arrGameUnit[i].x+util.BLOCKSIZE;
						e.y = arrGameUnit[i].y+(util.BLOCKSIZE/2);
						rippleSystem.push_back(e);

					pSystem.init(5,arrGameUnit[i].x,arrGameUnit[i].y,psStar,4);
					pSystem.init(7,arrGameUnit[i].x+(util.BLOCKSIZE),arrGameUnit[i].y,pRhombus,0);
					pSystem.init(10,adjustX+((portals[1].x+1)*util.BLOCKSIZE),adjustY+((portals[1].y+1)*util.BLOCKSIZE),psStar,2);
					
					ret = arrGameUnit[i].type;
					retVal.push_back(ret);
					//cout<<"\nerased unit "<<(int)arrGameUnit[i].type;//<<",size "<<arrGameUnit.size();
				}
				if(arrGameUnit[i].type == 6 && x == arrGameUnit[i].blockx)//check for full overlap too
				{
						Effect e;
						e.x = arrGameUnit[i].x+util.BLOCKSIZE;
						e.y = arrGameUnit[i].y+(util.BLOCKSIZE/2);
						rippleSystem.push_back(e);

					pSystem.init(5,arrGameUnit[i].x,arrGameUnit[i].y,psStar,2);
					pSystem.init(7,arrGameUnit[i].x+(util.BLOCKSIZE),arrGameUnit[i].y,pRhombus,0);
					pSystem.init(10,adjustX+((portals[0].x+1)*util.BLOCKSIZE),adjustY+((portals[0].y+1)*util.BLOCKSIZE),psStar,4);
					ret = arrGameUnit[i].type;
					retVal.push_back(ret);
					//cout<<"\nerased unit "<<(int)arrGameUnit[i].type;//<<",size "<<arrGameUnit.size();
				}
	
			}//if overlap
		}//for
		
		//cout<<"\nreturn size"<<retVal.size();
		return retVal;//no overlap
		
	}

	void render()
	{

		pSystem.render();

		for(int i=0;i<arrGameUnit.size();i++)
		{
			if(arrGameUnit[i].type < 3 )
				arrGameUnit[i].render(amountTranslate);
			else if(arrGameUnit[i].type < 5)
				arrGameUnit[i].render(amountScale);
			else
				arrGameUnit[i].render((abs(amountTranslate)%3)*2*util.BLOCKSIZE,0,util.BLOCKSIZE*2,util.BLOCKSIZE);
		}
	}

	CIwArray<int> getLeftOvers()
	{
		CIwArray<int> leftovers;
		for(int i=0;i<arrGameUnit.size();i++)
		{
			leftovers.push_back(arrGameUnit[i].type);
		}
		return leftovers;
	}

	//deprecated
	/*int16 getStarCount()
	{
		int16 starCount = 0;
		for(int i=0;i<arrGameUnit.size();i++)
		{
				if(arrGameUnit[i].type<3)
					starCount++;
		}
		return starCount;
	}*/

};


#endif