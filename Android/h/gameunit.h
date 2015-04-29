#ifndef GAMEUNIT_H
#define GAMEUNIT_H
#include "Sprite.h"

class GameUnit :public Sprite{

	//bool active;//achived or not
public:
	int16 type;
	int16 blockx;
	int16 blocky;

	GameUnit(){};

	void init(CIw2DImage* p,int t,int cx,int cy,int bx,int by)
	{
		constructRaw(cx,cy,util.LEFT,util.TOP,p);
		type = t;
		blockx = bx;
		blocky = by;
	}

};

#endif