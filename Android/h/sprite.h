#ifndef SPRITE_H
#define SPRITE_H

#include <iostream.h>
#include "util.h"
	
class Sprite
{

public:
	CIw2DImage* pTexture;  
	int x;
	int y;

	void construct(float virtualX,float virtualY,int16 anchorX,int16 anchorY,CIw2DImage* pImage)
	{
		pTexture = pImage;
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

		//cout<<"\n<<<<<<<<<<<<construct s x:"<<x<<" y:"<<y;
		
	}
	void constructRaw(float virtualX,float virtualY,int16 anchorX,int16 anchorY,CIw2DImage* pImage)
	{
		pTexture = pImage;
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

		//cout<<"\n<<<<<<<<<<<<construct s x:"<<x<<" y:"<<y;
		
	}

	void setTexture(CIw2DImage* tmp)
	{
		pTexture = tmp;
	}

	void setTexture(char *file)
	{
		char tmp[50];
		sprintf(tmp,"%s%s",util.PATH,file);
		pTexture = Iw2DCreateImage(tmp);
	}

	CIw2DImage* GetTexture()
	{
		return pTexture;
	}

	void destruct()
	{
		/*if(pTexture != NULL)
			delete pTexture;pTexture = NULL;*/
	}

	void render(CIw2DImage* tmp)
	{
		Iw2DDrawImage(tmp,CIwSVec2(x,y));
	}

	void render()
	{
		Iw2DDrawImage(pTexture,CIwSVec2(x,y));
	}

	void renderBG(CIwSVec2 size)
	{
		Iw2DDrawImage(pTexture,CIwSVec2(0,0),size);
	}
 
	void render(int16 dy)
	{
		Iw2DDrawImage(pTexture,CIwSVec2(x,y+dy));
	}

	void render(int16 dx,float scale)
	{
		Iw2DDrawImage(pTexture,CIwSVec2(x+dx,y));
	}
	
	void render(int16 dx,float scale,CIwSVec2 size)
	{
		Iw2DDrawImage(pTexture,CIwSVec2(x+dx,y),size);
	}

	void render(int8 dx,int8 dy)
	{
		Iw2DDrawImage(pTexture,CIwSVec2(x+dx,y+dy));
	}

	void render(float scale)
	{
		int dx = pTexture->GetWidth()*scale;
		int dy = pTexture->GetHeight()*scale;
		int ddx = (pTexture->GetWidth()-dx)/2;
		int ddy = (pTexture->GetHeight()-dy)/2;
		//Iw2DDrawRect(CIwSVec2(x,y),CIwSVec2(pTexture->GetWidth(),pTexture->GetHeight()));
		Iw2DDrawImage(pTexture,CIwSVec2(x+ddx,y+ddy),CIwSVec2(dx,dy));
	}

	void render(int16 tx,int16 ty,float scale)
	{
		
		int dx = pTexture->GetWidth()*scale;
		int dy = pTexture->GetHeight()*scale;
		int ddx = (pTexture->GetWidth()-dx)/2;
		int ddy = (pTexture->GetHeight()-dy)/2;

		Iw2DDrawImage(pTexture,CIwSVec2(tx+ddx,ty+ddy),CIwSVec2(dx,dy));
		
	}
	
	void render(int16 tx,int16 ty,bool isRotate)
	{
		
		if(isRotate)
		{
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT270);
			Iw2DDrawImage(pTexture,CIwSVec2(tx,ty));
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE);
		}
		else
		{
			Iw2DDrawImage(pTexture,CIwSVec2(tx,ty));
		}
		
	}

	void render(int16 tx,int16 ty)
	{
		Iw2DDrawImage(pTexture,CIwSVec2(tx,ty));
	}

	
	void render(int16 x,int16 y,int16 offsetx,int16 offsety,int16 dx,int16 dy)
	{
		Iw2DDrawImageRegion(pTexture,CIwSVec2(x,y),CIwSVec2(offsetx,offsety),CIwSVec2(dx,dy));
	}
	void render(int16 offsetx,int16 offsety,int16 dx,int16 dy)
	{
		////cout<<"\noffx"<<offsetx;
		Iw2DDrawImageRegion(pTexture,CIwSVec2(x,y),CIwSVec2(offsetx,offsety),CIwSVec2(dx,dy));
	}

	void render(double angle)
	{
		//Make a matrix which is a simple rotate around screen centre by the current angle
		iwfixed iwangle = ABS(angle)*IW_FIXED(0.01);
		CIwMat2D rot;
		rot.SetRot(iwangle, CIwVec2(x+(pTexture->GetWidth()/2),y+(pTexture->GetHeight()/2)));
		Iw2DSetTransformMatrix(rot);
		Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
		Iw2DDrawImage(pTexture,CIwSVec2(x,y));
		Iw2DDrawImage(pTexture,CIwSVec2(x,y));
		Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		//Reset identity transform
		Iw2DSetTransformMatrix(CIwMat2D::g_Identity);
	}

	void render(uint8 orientation)
	{//1 0,2 90,3 180,4 270
		if(orientation == 1)
		{	
			//Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT90); 
			Iw2DDrawImage(pTexture,CIwSVec2(x,y));
			//Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
		}
		else if(orientation == 2)
		{	
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT90); 
			Iw2DDrawImage(pTexture,CIwSVec2(x,y));
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
		}
		else if(orientation == 3)
		{	
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT180); 
			Iw2DDrawImage(pTexture,CIwSVec2(x,y));
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
		}
		else if(orientation == 4)
		{	
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT270); 
			Iw2DDrawImage(pTexture,CIwSVec2(x,y));
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
		}
		else if(orientation == 5)
		{	
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_FLIP_X); 
			Iw2DDrawImage(pTexture,CIwSVec2(x,y));
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
		}
		else if(orientation == 6)
		{	
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_FLIP_Y); 
			Iw2DDrawImage(pTexture,CIwSVec2(x,y));
			Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
		}

		
	}

	~Sprite()
	{
		/*if(pTexture)
			delete pTexture;pTexture=NULL;*/
	}
};
#endif