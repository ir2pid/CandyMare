#ifndef PARTICLE_SYSTEM
#define PARTICLE_SYSTEM

#include "particle.h"
#include "util.h"

class ParticleSystem
{
	enum{
		STAR,
		HEART,
		TOXIC
	}pType;

	CIwArray<Particle> pArr;
	int particleCount;
	//CIw2DImage* pStar;
	//CIw2DImage* pFinish;
	//CIw2DImage* pToxic;
	/**/
public:
	ParticleSystem()
	{
		pArr.clear_optimised();
		//pStar = NULL;
	}

	void init(int count,int x,int y,CIw2DImage* pParticle,int color)
	{
		////cout<<"\nloading particles";
		
		particleCount = count;
		//pArr.clear();
		for(int i=0;i<particleCount;i++)
		{
			Particle p;
			p.init((i)+1,x,y,pParticle,color);
			pArr.push_back(p);
		}
	}

	void initG(int count,int x,int y,CIw2DImage* pParticle,int color)
	{
		////cout<<"\nloading particles";
		
		particleCount = count;
		//pArr.clear();
		for(int i=0;i<particleCount;i++)
		{
			Particle p;
			p.initHighG((i)+1,x,y,pParticle,color);
			pArr.push_back(p);
		}
	}

	void destruct()
	{
		pArr.clear_optimised();
	}

	void update()
	{
		for(int i=0;i<pArr.size();i++)
		{
			////cout<<"\nfizzing particles"<<pArr.size();
			if(!pArr[i].update())
				pArr.erase(i);
		}
	}

	int updateUnlimited()
	{
		int k=0;
		for(int i=0;i<pArr.size();i++)
		{
			////cout<<"\nfizzing particles"<<pArr.size();
			if(!pArr[i].update())
			{
				pArr.erase(i);
				k++;
			}
		}
		return k;
	}

	void render()
	{
		Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
		for(int i=0;i<pArr.size();i++)
		{
			pArr[i].render();
		}
		Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
	}

	~ParticleSystem()
	{
		/*delete pStar;
		pStar = NULL;*/
	}

	/*void setTexture(CIw2DImage* pstar,CIw2DImage* pfinish,CIw2DImage* ptoxic)
	{
		pStar = pstar;
		pFinish = pfinish;
		pToxic = ptoxic;
	}*/
};

#endif