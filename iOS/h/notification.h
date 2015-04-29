#ifndef NOTIFICATION_H
#define NOTIFICATION_H

class Notification
{
	char *text;
	int posY;
	int life;
	int stall;
	bool swing;
public:

	void construct(char *c,CIw2DImage* pframe)
	{
		int i=0;
		while(c[i]!=NULL)
			i++;
		
		text = new char[i+1];
		strcpy(text,c);
		
		swing = false;
		
		life = pframe->GetHeight();
		stall = 30;
		posY = -life;
	}

	void render(int frameX,int objXY,int textX,CIwSVec2 region,CIw2DImage* pframe,CIw2DImage* pIcon)
	{
		Iw2DDrawImage(pframe,CIwSVec2(frameX,posY));
		Iw2DDrawImage(pIcon,CIwSVec2(frameX+(objXY*1.5),objXY+posY));
		CIwSVec2 topLeft(textX,objXY+posY);
		//Iw2DSetColour(0xffffffff);
		//Iw2DDrawRect(topLeft,region);

		Iw2DSetFont(font.AllerS);
								
		Iw2DSetColour(0xff000000);
		CIwSVec2 top1(textX+2,objXY+posY);
		Iw2DDrawString(text,top1,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		CIwSVec2 top2(textX-2,objXY+posY);
		Iw2DDrawString(text,top2,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		CIwSVec2 top3(textX,objXY+2+posY);
		Iw2DDrawString(text,top3,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);
		CIwSVec2 top4(textX,objXY-2+posY);
		Iw2DDrawString(text,top4,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);

		Iw2DSetColour(0xffffffff);
		Iw2DDrawString(text,topLeft,region,IW_2D_FONT_ALIGN_LEFT,IW_2D_FONT_ALIGN_CENTRE);

	}

	bool update()
	{//false to kill
		////cout<<"\nposY "<<posY;
		if(posY <= 0 && !swing)
		{
			posY+=5;
			return true;
		}
		else if(posY > -life)
		{
			if(--stall>0)
			{
				posY = 1;
				return true;
			}
			else 
			{
				swing = true;
				posY-=5;
				return true;
			}

		}
		else
			return false;
		/*if(--life<0)
		{
			//cout<<"\nkilled notification";
			return false;
		}
		else 
			return true;*/

	}

	void destruct()
	{
		if(text != NULL)
			delete text;text=NULL;
	}
};
#endif