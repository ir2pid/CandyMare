#ifndef PARTICLE_H
#define PARTICLE_H

#include <time.h>

class Particle
{
	CIw2DImage* pParticle;
	uint8 color;
  int lifetime;                       // total lifetime of the particle
  //float decay;                          // decay speed of the particle
  //CIwFVec2 color(1.0,1.0,1.0);          // color values of the particle
  CIwFVec2 pos;//(1.0,1.0,1.0);            // position of the particle
  CIwFVec2 speed;//(1.0,1.0,1.0);          // speed of the particle
  //int color;
  //boolean active;                       // is particle active or not?
public:
	

	void init(int no,int posX,int posY,CIw2DImage* pparticle,int iColor)
	{
		pParticle = pparticle;
		color = iColor;
		pos.x = posX;
		pos.y = posY;
	
		IwRandSeed((int32)s3eTimerGetMs()+no);
		int div = no%4;
		if(div==0)
		{

			speed.x = IwRandMinMax(1,20)*util.em;
			speed.y = IwRandMinMax(1,15)*util.em;
		}
		else if(div==1)
		{
			speed.x = -IwRandMinMax(1,20)*util.em;
			speed.y = IwRandMinMax(1,15)*util.em;
		}
		else if(div==2)
		{
			speed.x = IwRandMinMax(1,20)*util.em;
			speed.y = -IwRandMinMax(1,15)*util.em;
		}
		else if(div==3)
		{
			speed.x = -IwRandMinMax(1,20)*util.em;
			speed.y = -IwRandMinMax(1,15)*util.em;
		}
		lifetime= IwRandMinMax(5,15)*util.em;
		//color = IwRandMinMax(0,6);
		////cout<<"\nlifetime "<<lifetime;
	}

	void initHighG(int no,int posX,int posY,CIw2DImage* pparticle,int iColor)
	{
		pParticle = pparticle;
		color = iColor;
		pos.x = posX;
		pos.y = posY;
	
		IwRandSeed((int32)s3eTimerGetMs()+no);
		int div = no%2;
		/*if(div==0)
		{

			speed.x = IwRandMinMax(1,20)*util.em;
			speed.y = IwRandMinMax(1,16)*util.em;
		}
		else if(div==1)
		{
			speed.x = -IwRandMinMax(1,20)*util.em;
			speed.y = IwRandMinMax(1,16)*util.em;
		}*/
		if(div==0)
		{
			speed.x = IwRandMinMax(1,15)*util.em;
			speed.y = -IwRandMinMax(1,10)*util.em;
		}
		else if(div==1)
		{
			speed.x = -IwRandMinMax(1,15)*util.em;
			speed.y = -IwRandMinMax(1,10)*util.em;
		}
		lifetime= IwRandMinMax(5,15)*util.em;
		//color = IwRandMinMax(0,6);
		////cout<<"\nlifetime "<<lifetime;
	}

	bool update()
	{
		lifetime--;
		pos.x+=speed.x;
		pos.y+=speed.y;
		speed.y += 1;
		if(lifetime<0)
			return false;
		else
			return true;
	}

	void renderToxic()
	{
		Iw2DSetColour(util.COLOR[4]);//0xaa00ffff);// // Set blue 
		
			Iw2DDrawImage(pParticle,CIwSVec2(pos.x,pos.y));
			Iw2DDrawImage(pParticle,CIwSVec2(pos.x,pos.y));

		//Iw2DFillRect(CIwSVec2(pos.x,pos.y), CIwSVec2(2,2)); // Fill blue 
		Iw2DSetColour(0xffffffff);
		// Iw2DSetTransformMatrix(CIwMat2D::g_Identity); 
		//Iw2DDrawRect(CIwSVec2(0, 0), CIwSVec2(10,10)); // Draw red outline 
	}

	void render()
	{
		Iw2DSetColour(util.COLOR[color]);//0xaa00ffff);// // Set blue 
			Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
			Iw2DDrawImage(pParticle,CIwSVec2(pos.x,pos.y));
			Iw2DDrawImage(pParticle,CIwSVec2(pos.x,pos.y));
		Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		//Iw2DFillRect(CIwSVec2(pos.x,pos.y), CIwSVec2(2,2)); // Fill blue 
		Iw2DSetColour(0xffffffff);
		// Iw2DSetTransformMatrix(CIwMat2D::g_Identity); 
		//Iw2DDrawRect(CIwSVec2(0, 0), CIwSVec2(10,10)); // Draw red outline 
	}
};

#endif