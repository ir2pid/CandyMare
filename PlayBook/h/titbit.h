#ifndef STATICJIGSAW_H
#define STATICJIGSAW_H

class Titbit{

private:
	int x;
	int y;

	CIw2DImage *img;

	bool alpha; 
	
public:
	Titbit(int blockX,int blockY,CIw2DImage *image)
	{
		img = image;
		
		x = blockX + (util.BLOCKSIZE - img->GetWidth())/2;
		y = blockY + (util.BLOCKSIZE - img->GetHeight())/2;
		
	}
	
	void render()
	{

		//Iw2DSetAlphaMode  ( IW_2D_ALPHA_NONE    )   IW_2D_ALPHA_HALF IW_2D_ALPHA_ADD IW_2D_ALPHA_SUB 


	}

};

#endif