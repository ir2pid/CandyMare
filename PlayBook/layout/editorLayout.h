#ifndef EDITORLAYOUT_H
#define EDITORLAYOUT_H
#include "util.h"
#include "Storage.h"

CIwColour g_Colours[] =
{
    { 0x00, 0x20, 0xff, 0xff },
    { 0x00, 0x40, 0xff, 0xff },
    { 0x00, 0x60, 0xff, 0xff },
    { 0x00, 0x80, 0xff, 0xff },
    { 0x00, 0xa0, 0xff, 0xff },
    { 0x00, 0xc0, 0xff, 0xff },
    { 0x00, 0xe0, 0xff, 0xff },
    { 0x00, 0xff, 0xff, 0xff },
};

class EditorLayout
{

public:
		enum MODE{
		ADD,
		SUB,
		NONE
	}mode;

	int bgX;
	int bgY;
	int barHeight;
	/*int barAnchorX;
	int barMoveAnchorY;
	int barMenuAnchorY;
	int barHeight;*/
	int trayX;
	int trayY;
	int wTray;
	int hTray;
	int tray[6][8];
	int x[8];
	int y[6];

	//Sprite bg;
	CIw2DImage* tAdd;
	CIw2DImage*	tSub;
	CIw2DImage* tColl0;
	CIw2DImage* tColl1;
	CIw2DImage* tSav;
	CIw2DImage* tBack;
	CIw2DImage* tTray;
	CIw2DImage* tEditorTray;

	CIw2DImage* tBlock[50];
	
	Sprite sTray;
	Sprite sEditorTray;

	Click cAdd;
	Click cSub;
	Click cColl;
	Click cSav;
	Click cBack;

	bool collision; 
	int heightRest;
	int heightOffset;
	int anchorAdd;
	int anchorSub;
	int anchorCollision;
	int anchorSave;
	int anchorBack;

	EditorLayout()
	{
		genTray();

		collision = true;
		mode = NONE;

		barHeight = 23.0f*util.em;
		
		int w = util.widthDisplay;
		int h = util.heightDisplay;

		wTray = 9*util.BLOCKSIZE;
		hTray = 5*util.BLOCKSIZE;

		trayX = (w - wTray)/2;
		trayY = ((h - hTray)/2)+barHeight;
		
		for(int i=0;i<50;i++)
		{
			tBlock[i] = NULL;
		}

		int startAnchor = (util.widthDisplay - (4*44*util.em))/4;

		heightRest = 20*util.em;
		heightOffset = 3*util.em;
		
		anchorAdd = startAnchor;
		anchorSub = startAnchor*2;
		anchorCollision = startAnchor*3;
		anchorSave = startAnchor*4;
		anchorBack = startAnchor*5;

		{//textures
			tAdd = util.getTexture("editor/add.png");
			tSub = util.getTexture("editor/sub.png");
			tColl0 = util.getTexture("editor/coll0.png");
			tColl1 = util.getTexture("editor/coll1.png");
			tSav = util.getTexture("editor/sav.png");
			tBack = util.getTexture("menu/back.png");
			tEditorTray = util.getTexture("tray/editor_tray.png");
			
		}

		sEditorTray.construct(0,0,util.LEFT,util.TOP,tEditorTray);

		cAdd.construct(anchorAdd,heightOffset,util.LEFT,util.TOP,"",tAdd);
		cSub.construct(anchorSub,heightOffset,util.LEFT,util.TOP,"",tSub);
		cColl.construct(anchorCollision,heightOffset,util.LEFT,util.TOP,"",tColl0,tColl1);
		cSav.construct(anchorSave,heightOffset,util.LEFT,util.TOP,"",tSav);
		cBack.construct(anchorBack,heightOffset,util.LEFT,util.TOP,"",tBack);
		
	}
	void destruct()
	{
		//cAdd.destruct();

		cAdd.destruct();
		cSub.destruct();
		cColl.destruct();
		cSav.destruct();
		cBack.destruct();

		if(tAdd)
			delete tAdd;tAdd=NULL;
		if(tSub)
			delete tSub;tSub=NULL;
		if(tColl0)
			delete tColl0;tColl0=NULL;
		if(tColl1)
			delete tColl1;tColl1=NULL;
		if(tSav)
			delete tSav;tSav=NULL;
		if(tBack)
			delete tBack;tBack=NULL;
		if(tEditorTray)
			delete tEditorTray;tEditorTray=NULL;
		if(tTray)
			delete tTray;tTray=NULL;
		
		

		for(int i=0;i<50;i++)
		{
			if(tBlock[i] != NULL)
			{//delete if loaded
				delete tBlock[i];tBlock[i] = NULL;
			}	
		}
	}
	

	~EditorLayout()
	{
		
	}

	CIw2DImage* getTexture(int no)
	{
		if(tBlock[no] == NULL)
		{//load if not loaded yet
			util.mountTex();
			char tmp[50];
			sprintf(tmp,"%seditor/%d.png",util.PATH,no);
			tBlock[no] = Iw2DCreateImage(tmp);
			util.unmount();
			return tBlock[no];
		}
		else
			return tBlock[no];
	}

	void genTray()
	{
		int w = util.widthDisplay/8;
		int h = util.heightDisplay/6;
		
		////cout<<"\n";
		for(int i = 0;i<8;i++)
		{	
			x[i] = w*i;
			////cout<<"\t x:"<<x[i];
		}

		////cout<<"\n";
		for(int i = 0;i<6;i++)
		{	
			y[i] = h*i;
			////cout<<"\t y:"<<y[i];
		}

		int k = 3;
		for(int i=0;i<6;i++)
		{
			////cout<<"\n";
			for(int j=0;j<8;j++)
			{
				////cout<<"\t"<<k;
				tray[i][j] = k;
				k++;
			}
		}
	}

	int getBlockID(int tx,int ty)
	{
		int i,j;

		for(j=1;j<8;j++)
		{
			if(tx<x[j])
				break;
		}
		for(i=1;i<6;i++)
		{
			if(ty<y[i])
				break;
		}

		int tmp = tray[i-1][j-1];

		return tmp;
	}

	void renderBlockTray()
	{
		sEditorTray.render();
		/*char num[3];
		
		for(int i=0;i<6;i++)
		{
			for(int j=0;j<8;j++)
			{
				//Iw2DSetColour(g_Colours[(i+j)%8]);
				//Iw2DFillRect(CIwSVec2(x[j],y[i]),CIwSVec2(x[1]-x[0],y[1]-y[0]));
				//Iw2DSetColour(0xffffffff);
				
				//Iw2DSetFont(font.);
				//Iw2DSetColour(0xffffffff);
		
				//sprintf(num,"%i",(i*8)+j+3);
				//Iw2DDrawString(num,CIwSVec2(x[j],y[i]),CIwSVec2(x[1]-x[0],y[1]-y[0]),IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);
				//Iw2DSetColour(0xffffffff);
				
			}
		}*/
	}

	void constructTray()
	{
		tTray = util.getTempTexture("screen.bmp");
		//sTray.construct(trayX,trayY,util.LEFT,util.TOP,tTray);
		sTray.construct(0,0,util.LEFT,util.TOP,tTray);
	}

	void renderTray()
	{
		//Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_ROT90); 
		sTray.render();
		//Iw2DSetImageTransform(IW_2D_IMAGE_TRANSFORM_NONE); 
		//IwGxSetScreenOrient(IW_GX_ORIENT_NONE);
	}

	void makeLevel(char *tmp)
	{
		storage.makeLevel(tmp);
	}
};
#endif