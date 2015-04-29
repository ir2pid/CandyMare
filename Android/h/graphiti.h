#ifndef GRAPHITI_H
#define GRAPHITI_H

#include <time.h>
#include "Iw2D.h"
#include "IwGx.h"
#include "util.h"

class GraphitiParticle
{
	
	//CIwColour color;
	int colorID;
	//int lifetime; 
	CIwSVec2 pos;//(1.0,1.0,1.0);            // position of the particle
	float speed;//(1.0,1.0,1.0);          // speed of the particle
	CIwMat2D rot;

	CIwVec2 centre;
	iwfixed angle;
public:
	
	bool type;//0 rect,1 round

	void init(int no)
	{
			
		IwRandSeed((int32)s3eTimerGetMs()+no);
		colorID = IwRandMinMax(0,10);

		//color.a = 255;
		//color.r = util.COLOR[id].r;
		//color.g = util.COLOR[id].g;
		//color.b = util.COLOR[id].b;

		IwRandSeed((int32)s3eTimerGetMs()+no+3);
		pos.x = IwRandMinMax(0,util.widthDisplay);
		pos.y = IwRandMinMax(-1.5*util.heightDisplay,0);

		speed = IwRandMinMax(1,4)*util.em;

		int rndm = IwRandMinMax(30,55)*util.em;
		
		centre.x = pos.x;
		centre.y = pos.y;
		
		angle = rndm*IW_FIXED(0.01);

		if(rndm%4 == 0)
		{
			type = true;//round
		}
		else 
			type = false;//rect
		//cout<<"\nInitialized with Color R:"<<(int)color.r<<" G:"<<(int)color.g<<" B:"<<(int)color.b;
		//cout<<"\npos"<<pos.x<<","<<pos.y;
		//cout<<"\n speed"<<speed;
	}
	
	bool update()
	{
		//lifetime--;
		pos.y += speed;
		speed += 1/(speed);

		if(pos.y > util.heightDisplay)
			return false;
		else
			return true;
		/*if(lifetime<0)
			return false;
		else
			return true;*/
	}

	void renderRect(CIwSVec2 size)
	{
		Iw2DSetColour(util.COLOR[colorID]);
		//Iw2DSetColour(0xff0000ff);
		
		//Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
		rot.SetRot(angle);//,false);// (CIwVec2)centre);
		rot.SetTrans(pos);
		Iw2DSetTransformMatrix(rot);

			Iw2DFillRect(CIwSVec2(0,0), size);
			Iw2DFillRect(CIwSVec2(0,0), size); 
			
		//Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		Iw2DSetColour(0xff000000);
			Iw2DDrawRect(CIwSVec2(0,0), size); 
		
		Iw2DSetTransformMatrix(CIwMat2D::g_Identity);
				
		Iw2DSetColour(0xffffffff);    
	}

	void renderHex(CIwSVec2 *vertices)
	{

		Iw2DSetColour(util.COLOR[colorID]);
		//Iw2DSetColour(0xff0000ff);
		
		//Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
		rot.SetRot(angle);//,false);// (CIwVec2)centre);
		rot.SetTrans(pos);
		Iw2DSetTransformMatrix(rot);
		
			Iw2DFillPolygon(vertices,6);
			Iw2DFillPolygon(vertices,6);

		//Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		Iw2DSetColour(0xff000000);
			Iw2DDrawPolygon(vertices,6,true);
		
		Iw2DSetTransformMatrix(CIwMat2D::g_Identity);
				
		Iw2DSetColour(0xffffffff);    
	}
};

class GraphitiSystem{
	
	CIwArray<GraphitiParticle> pArr;
	int particleCount;
	CIwSVec2 size;
	CIwSVec2 vertices[6];
	public:
	GraphitiSystem()
	{
		pArr.clear_optimised();
		size.x = 12*util.em;
		size.y = 6*util.em;
		vertices[0].x = ((float)size.y)/4.0;
		vertices[0].y = 0;
		vertices[1].x = ((float)size.y)/4.0*3.0;
		vertices[1].y = 0;
		vertices[2].x = size.y;
		vertices[2].y = ((float)size.y)/2.0;
		vertices[3].x = vertices[1].x;
		vertices[3].y = size.y;
		vertices[4].x = vertices[0].x;
		vertices[4].y = size.y;
		vertices[5].x = 0;
		vertices[5].y = vertices[2].y;
		//pStar = NULL;
	}

	void init(int count)
	{
		////cout<<"\nloading particles";
		
		particleCount = count;
		//pArr.clear();
		for(int i=0;i<particleCount;i++)
		{
			GraphitiParticle p;
			p.init((i)+1);
			pArr.push_back(p);
		}
	}


	void destruct()
	{
		pArr.clear_optimised();
	}

	bool update()
	{
		bool flag = false;
		for(int i=0;i<pArr.size();i++)
		{
			////cout<<"\nfizzing particles"<<pArr.size();
			if(!pArr[i].update())
			{
				pArr.erase(i);
				flag = true;
			}
		}
		return flag;
	}


	void render()
	{
		for(int i=0;i<pArr.size();i++)
		{
			if(pArr[i].type)
				pArr[i].renderHex(vertices);
			else
				pArr[i].renderRect(size);
		}
	}

	~GraphitiSystem()
	{
		/*delete pStar;
		pStar = NULL;*/
	}

};

#endif