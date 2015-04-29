#ifndef UTIL_H
#define UTIL_H


#include "s3e.h"
#include "derbh.h"
#include <iostream.h>
#include "s3eIOSAppirater.h"
#include "fb.h"
#include "transitions2d.h"
#include "applifierSystem.h"
#include "flurryAnalytics.h"
//#include "HeyzapMarmalade.h"

//ios,sim
#define IOS
//!android,win32


static class Util
{

public:
	int32 g_Frame;
	//bool invert;
	//bool translateView;
	FB fb;
	ApplifierSystem applifierSystem;
	FlurryAnalytics flurryAnalytics;
	
	int32 widthGame;
	int32 heightGame;
	int32 widthDisplay;
	int32 heightDisplay;
	int32 anchorX;
	int32 anchorY;
	float em;
	char *PATH;
	int BLOCKSIZE;
	bool displayReset;
	bool isMute;
	CIw2DImage* pNotificationFrame;
	CIwTexture* tBG;
	//CIw2DImage* tBG;
	//white,darkyellow,cyan,lightblue,red,blue,green,purple,lime,orange
	CIwColour COLOR[10];

	enum AX{
			LEFT,
			CENTER,
			RIGHT,
			BASEX
		}aX;

	enum AY{
			TOP,
			MIDDLE,
			BOTTOM,
			BASEY
		}aY;

	enum GAMESTATE{
		INIT,
		LOADING,
		MENU,
		OPTION,
		INFO,
		TROPHY,
		CART,
		THEMESELECT,
		LEVELSELECT,
		THEMEINTRO,
		PLAYING,
		PLAYINGMENU,
		LEVELEND,
		EDITOR,
		EDITORTHEME,
		EDITORLEVEL,
		BLOCKSELECT,
		BLOCKDELETE
	}gameState,prevState;

	/*enum GAMERES{
		R320x240,	//em 0.75
		R480x320,	//em 1.0 down ratio 0.468
		R800x480,	//em 1.5
		R854x480,	//em 1.5
		R960x640,	//em 2.0
		R1024x600,	//em 1.87
		R1024x768,	//em 2.4
		RERROR
	}gameRes;*/
	
	Util()
	{
		g_Frame = 0;
		displayReset = false;
		pNotificationFrame = NULL;
		tBG = NULL;
		
	}
	
	void construct()
	{
		//invert = false;
		fb.construct();
		applifierSystem.construct();
		flurryAnalytics.construct();
		heightDisplay = Iw2DGetSurfaceHeight();
		widthDisplay = Iw2DGetSurfaceWidth();
		//displayReset = false;
		if(widthDisplay == 960 && heightDisplay == 640)
		{
			//gameRes = R960x640;
			widthGame = 960;
			heightGame = 640;	
			anchorX = (widthDisplay/2) - (widthGame/2);
			anchorY = (heightDisplay/2) - (heightGame/2);
			em = 2.0f;
			BLOCKSIZE = 101;			
			PATH = "./texture/960x640/";	
		}
		else if(widthDisplay >= 1024 && heightDisplay >= 768)
		{
			//gameRes = R1024x768;
			widthGame = 1024;
			heightGame = 768;
			anchorX = (widthDisplay/2) - (widthGame/2);
			anchorY = (heightDisplay/2) - (heightGame/2);
			em = 2.0f;
			BLOCKSIZE = 101;			
			PATH = "./texture/960x640/";
		}
		else//if(widthDisplay == 480 && heightDisplay == 320)//|| widthDisplay == 800 && heightDisplay == 600)
		{
			//gameRes = R480x320;
			widthGame = 480;
			heightGame = 320;	
			anchorX = (widthDisplay/2) - (widthGame/2);
			anchorY = (heightDisplay/2) - (heightGame/2);
			em = 1.0f;
			BLOCKSIZE = 50;
			PATH = "./texture/480x320/";
		}
		//else 
		
		/*
		if(widthDisplay == 854 && heightDisplay == 480)
		{
			gameRes = R854x480;
			widthGame = 854;
			heightGame = 480;	
			anchorX = (widthDisplay/2) - (widthGame/2);
			anchorY = (heightDisplay/2) - (heightGame/2);
			em = 1.5f;
			BLOCKSIZE = 84;		
			PATH = "./texture/854x480/";
		}
		if(widthDisplay == 960 && heightDisplay == 640)
		{
			gameRes = R960x640;
			widthGame = 960;
			heightGame = 640;	
			anchorX = (widthDisplay/2) - (widthGame/2);
			anchorY = (heightDisplay/2) - (heightGame/2);
			em = 2.0f;
			BLOCKSIZE = 101;			
			PATH = "./texture/960x640/";	
		}
		if(widthDisplay == 1024 && heightDisplay == 600)
		{
			gameRes = R1024x600;
			widthGame = 1024;
			heightGame = 600;	
			anchorX = (widthDisplay/2) - (widthGame/2);
			anchorY = (heightDisplay/2) - (heightGame/2);
			em = 1.87f;	
			BLOCKSIZE = 105;		
			PATH = "./texture/1024x600/";	
		}
		if(widthDisplay == 1024 && heightDisplay == 768)
		{
			gameRes = R1024x768;
			widthGame = 1024;
			heightGame = 768;	
			anchorX = (widthDisplay/2) - (widthGame/2);
			anchorY = (heightDisplay/2) - (heightGame/2);
			em = 2.4f;
			BLOCKSIZE = 105;			
			PATH = "./texture/1024x768/";		
		}*/

		setNotificationFrame();
		setColor();
	}
	void setColor()
	{				 //aabbggrr

		for(int i=0;i<10;i++)
		{
			COLOR[i].a = 255;
		}

		//white,darkyellow,cyan,lightblue,red,blue,green,purple,lime,orange
		COLOR[0].r = 255;	COLOR[0].g = 255;	COLOR[0].b = 255;//white
		COLOR[1].r = 255;	COLOR[1].g = 195;	COLOR[1].b = 0;//darkyellow
		COLOR[2].r = 255;	COLOR[2].g = 0;		COLOR[2].b = 255;//cyan
		COLOR[3].r = 155;	COLOR[3].g = 155;	COLOR[3].b = 255;//lightblue
		COLOR[4].r = 255;	COLOR[4].g = 0;		COLOR[4].b = 0;//red
		COLOR[5].r = 0;		COLOR[5].g = 0;		COLOR[5].b = 255;//blue
		COLOR[6].r = 0;		COLOR[6].g = 255;	COLOR[6].b = 0;//green
		COLOR[7].r = 150;	COLOR[7].g = 0;		COLOR[7].b = 255;//purple
		COLOR[8].r = 190;	COLOR[8].g = 255;	COLOR[8].b = 0;//lime
		COLOR[9].r = 255;	COLOR[9].g = 135;	COLOR[9].b = 0;//orange
		
	}

	void setNotificationFrame()
	{
		pNotificationFrame = getTexture("notify/frame.png");
	}

	CIw2DImage* getTexture(char *file)
	{
		mountTex();
		char tmp[50];
		sprintf(tmp,"%s%s",PATH,file);
		CIw2DImage *img = Iw2DCreateImage(tmp);
		unmount();
		return img;
	}
	CIw2DImage* getBGTexture(char *file)
	{
		mountMenuBG();
		char tmp[50];
		if(widthDisplay > 960)	
			sprintf(tmp,"%s%s","./texture/1024x768/",file);
		else
			sprintf(tmp,"%s%s",PATH,file);

		CIw2DImage *img = Iw2DCreateImage(tmp);
		unmount();
		return img;
	}
	CIw2DImage* getTempTexture(char *file)
	{
		char tmp[50];
		sprintf(tmp,"%s",file);
		CIw2DImage *img = Iw2DCreateImage(tmp);
		return img;
	}

	CIw2DImage* getTile(char *file)
	{
		mountTile();
		char tmp[50];
		sprintf(tmp,"texture/tile/%s",file);
		CIw2DImage *img = Iw2DCreateImage(tmp);
		unmount();
		return img;
	}


	
	CIw2DImage* getBgTile(bool isTrophy = false)
	{
		int16 num;
		if(isTrophy)
		{
			num = 5;
		}//trophy
		else
		{//jacko
			IwRandSeed((int32)s3eTimerGetMs());
			num = IwRandMinMax(0,5);//0-7
		}
			
			char *tile[6];
			tile[0] = "jacko1.jpg";
			tile[1] = "jacko2.jpg";
			tile[2] = "jacko3.jpg";
			tile[3] = "jacko4.jpg";
			tile[4] = "skull.jpg";
			tile[5] = "trophy.jpg";

			CIw2DImage *tTile = getTile(tile[num]);

			if(isValid(num))
			{
				//delete wall;
				delete tTile;
				return getTempTexture(tile[num]);
			}
			else
			{
				makeBg(tile[num],tTile);
				makeBg(tile[num],tTile);
				makeBg(tile[num],tTile);
				///TakeScreenshot(tile[num]);
				//delete wall;
				delete tTile;
				return getTempTexture(tile[num]);
			}
	}

	void setBG(bool isTrophy = false)
	{
		int16 num;
		if(isTrophy)
		{
			num = 5;
		}//trophy
		else
		{//jacko
			IwRandSeed((int32)s3eTimerGetMs());
			num = IwRandMinMax(0,5);//0-7
		}
			
			char *tile[6];
			tile[0] = "jacko1.jpg";
			tile[1] = "jacko2.jpg";
			tile[2] = "jacko3.jpg";
			tile[3] = "jacko4.jpg";
			tile[4] = "skull.jpg";
			tile[5] = "trophy.jpg";

			CIw2DImage *tTile = getTile(tile[num]);

			if(tBG != NULL)
				delete tBG;tBG = NULL;

			//IwGxFlush();
			makeBgBuffer(tile[num],tTile);
			IwGxFlush();
			tBG = Transitions2D::CaptureScreen();
			
	
			delete tTile;
			
			//CIw2DImage MyIw2DImage(MySurface);
			//IwGxFlush();
			//IwGxSwapBuffers();
	}

	void renderBG()
	{
			
		IwGxSetColClear(0, 0, 0, 0);
		IwGxClear();

#if defined(IOS)
		IwGxScreenOrient orient = IwGxGetScreenOrient();
		IwGxSetScreenOrient(IW_GX_ORIENT_NONE);		
#else 
		//IwGxSetScreenOrient(IW_GX_ORIENT_90);
#endif
		
		CIwMaterial* tMat;
		tMat = IW_GX_ALLOC_MATERIAL();
		tMat->SetTexture(tBG);
		
		IwGxSetMaterial(tMat);
#if defined(IOS)
		IwGxDrawRectScreenSpace(&CIwSVec2(0,0), &CIwSVec2(heightDisplay, widthDisplay));
#else 
		IwGxDrawRectScreenSpace(&CIwSVec2(0,0), &CIwSVec2(widthDisplay, heightDisplay));
#endif
		
		
		IwGxFlush();
		//IwGxSwapBuffers();
#if defined(IOS)
		IwGxSetScreenOrient(orient);
#endif
	}
	bool isValid(int16 id)
	{
		static s3eFile   *File; 
		
		char *tile[6];
		tile[0] = "jacko1.jpg";
		tile[1] = "jacko2.jpg";
		tile[2] = "jacko3.jpg";
		tile[3] = "jacko4.jpg";
		tile[4] = "skull.jpg";
		tile[5] = "trophy.jpg";


		File = s3eFileOpen(tile[id], "rb");
		
        if (File != NULL)
        {
			if (File)
				s3eFileClose(File);
			//translateView = true;
          return true;
        }
        else
        {
			//translateView = false;
            return false;
        }
	}

	bool isValid(char *filename)
	{
		static s3eFile   *File; 

		File = s3eFileOpen(filename, "rb");
		
        if (File != NULL)
        {
			if (File)
				s3eFileClose(File);
			//translateView = true;
          return true;
        }
        else
        {
			//translateView = false;
            return false;
        }
	}

	void TakeScreenshot()
	{

#if defined(IOS)
		int Height = Iw2DGetSurfaceWidth();//480
		int Width = Iw2DGetSurfaceHeight();//800
#else 
		int Width = Iw2DGetSurfaceWidth();//480
		int Height = Iw2DGetSurfaceHeight();//800
#endif
		
		int DataLength = Width * Height * 4;


		// Set size of the framebuffer (Screen size)

		// set the target framebuffer to read
		uint8 *buffer = new uint8[DataLength];
		glReadPixels(0, 0, Width, Height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

		// Set our flip buffer (explained in for loop)
		uint8 *bufferflipped = new uint8[DataLength];
		for(int y = 0; y < Height; y++)
		{
			for(int x = 0; x < Width * 4; x++)
			{
				// We need to flip the image as GL gts the pixels from top to bottom
				bufferflipped[((Height -1) - y) * Width * 4 + x]
					= buffer[y * 4 * Width + x];
			}
		}

		CIwTexture* pTexture = new CIwTexture;

		// Returns the texture's image object
		CIwImage& img = pTexture->GetImage();

		// Sets the image format (Unpalettised 32-bit, alpha) 
		img.SetFormat(CIwImage::ABGR_8888);
		// Set the Image Attributes
		img.SetWidth(Width);
		img.SetHeight(Height);

		// assign the buffer data to an image
		img.SetBuffers(bufferflipped, DataLength,NULL,NULL);

		img.SaveBmp("screen.bmp");
	 
		// Clean up our image buffers as they are no longer needed
		delete buffer;
		delete bufferflipped;
		delete pTexture;
	}

	void TakeScreenshot(char* file)
	{

#if defined(IOS)
		int Height = Iw2DGetSurfaceWidth();//480
		int Width = Iw2DGetSurfaceHeight();//800
#else 
		int Width = Iw2DGetSurfaceWidth();//480
		int Height = Iw2DGetSurfaceHeight();//800
#endif
		
		int DataLength = Width * Height * 4;


		// Set size of the framebuffer (Screen size)

		// set the target framebuffer to read
		uint8 *buffer = new uint8[DataLength];
		glReadPixels(0, 0, Width, Height, GL_RGBA, GL_UNSIGNED_BYTE, buffer);

		// Set our flip buffer (explained in for loop)
		uint8 *bufferflipped = new uint8[DataLength];
		for(int y = 0; y < Height; y++)
		{
			for(int x = 0; x < Width * 4; x++)
			{
				// We need to flip the image as GL gts the pixels from top to bottom
				bufferflipped[((Height -1) - y) * Width * 4 + x]
					= buffer[y * 4 * Width + x];
			}
		}

		CIwTexture* pTexture = new CIwTexture;

		// Returns the texture's image object
		CIwImage& img = pTexture->GetImage();

		// Sets the image format (Unpalettised 32-bit, alpha) 
		img.SetFormat(CIwImage::ABGR_8888);
		// Set the Image Attributes
		img.SetWidth(Width);
		img.SetHeight(Height);

		// assign the buffer data to an image
		img.SetBuffers(bufferflipped, DataLength,NULL,NULL);

		img.SaveBmp(file);
	 
		// Clean up our image buffers as they are no longer needed
		delete buffer;
		delete bufferflipped;
		delete pTexture;
	}
	void makeBgBuffer(char* file,CIw2DImage* tTile)
	{
		int16 wallX = anchorX;
		int16 wallY = anchorY;

			
		int w = widthDisplay;
		int h = heightDisplay;

		int tw = tTile->GetWidth();
		int th = tTile->GetHeight();
		

		 Iw2DSurfaceClear(0xffffffff);

		for(int i=0;i<w;i+=tw)
		{
			for(int j=0;j<h;j+=th)
			{
				/*if(i==tw || j ==th )
					continue;*/
				CIwSVec2 topLeft(i,j);
				Iw2DDrawImage(tTile,topLeft);
			}
		}
		
		// Iw2DSurfaceShow();
	}

	void makeBg(char* file,CIw2DImage* tTile)
	{
		int16 wallX = anchorX;
		int16 wallY = anchorY;

/*#if defined(IOS)
		int w = widthDisplay;
		int h = heightDisplay;
#else 
		int h = widthDisplay;
		int w = heightDisplay;
#endif		*/
			
		int w = widthDisplay;
		int h = heightDisplay;

		int tw = tTile->GetWidth();
		int th = tTile->GetHeight();
		 Iw2DSurfaceClear(0xffffffff);
		//CIw2DSurface *surface = Iw2DCreateSurface(w,h);
		//set display to buffer
		//Iw2DSetSurface( surface );
		//IwGxSetScreenOrient(IW_GX_ORIENT_90);
		//draw tile to buffer
		for(int i=0;i<w;i+=tw)
		{
			for(int j=0;j<h;j+=th)
			{
				/*if(i==tw || j ==th )
					continue;*/
				CIwSVec2 topLeft(i,j);
				Iw2DDrawImage(tTile,topLeft);
			}
		}
		/*if(wall != NULL)
		Iw2DDrawImage(wall,CIwSVec2(wallX,wallY));
		*/
		Iw2DSurfaceShow();
		TakeScreenshot(file);
		//Iw2DFinishDrawing();
	}
	
	void mountTex()
	{
		if(widthDisplay == 480)
			dzArchiveAttach("./data480x320.ninja");
		else// if(util.widthDisplay == 960)
			dzArchiveAttach("./data960x640.ninja");
		/*else if(util.widthDisplay == 1024)
			result = dzArchiveAttach("./data960x640.dz");*/

        /*if (result == S3E_RESULT_ERROR)
        {
            // An error occurred.
           //cout<<"Error attaching archive";
        }*/
	}
	
	void mountMenuBG()
	{		
		if(widthDisplay == 480)
			dzArchiveAttach("./data480x320.ninja");
		else if(widthDisplay == 960)
			dzArchiveAttach("./data960x640.ninja");
		else if(widthDisplay >= 1024)
			dzArchiveAttach("./data1024x768.ninja");

        /*if (result == S3E_RESULT_ERROR)
        {
            // An error occurred.
           //cout<<"Error attaching archive";
        }*/
	}
	void mountTile()
	{	
		dzArchiveAttach("./dataTile.ninja");

        /*if (result == S3E_RESULT_ERROR)
        {
            // An error occurred.
           //cout<<"Error attaching archive";
        }*/
	}

	void unmount()
	{
		// Detach the archive.
		dzArchiveDetach();
	}

	void appirateInit()
	{
		 if (s3eDeviceGetInt(S3E_DEVICE_OS) == S3E_OS_ID_IPHONE) {
        s3eIOSAppiraterParams(505243336, 2, 1, 1, 3, 
                              "Rate CandyMare !", "Please Rate this game if you liked it. Thanks for your support!", "Rate It Now",
                              "Rate Later ?", "Play some more and rate it later ?");
        s3eIOSAppiraterAppLaunched(true);
		s3eIOSAppiraterAppEnteredForeground(true);
		 }
	}
	void heyzapInit()
	{
		/*if ( HeyzapMarmaladeAvailable() )
		{
			loadHeyzap("com.noisyninja.candymare","fb249307571821667", true);
		}
		*/
	}
	uint32 setUDID()
	{
		IwRandSeed((int32)s3eTimerGetMs());
		int x = IwRand();
		IwRandSeed((int32)s3eTimerGetMs()+x);
		int y = IwRand();
		uint32 z = 4294967295 - (x+y);
		return z;
	}
	

	void destruct()
	{
		fb.destruct();
		flurryAnalytics.destruct();
		delete pNotificationFrame;pNotificationFrame = NULL;
		delete tBG;tBG = NULL;
		
	}
}util;

#endif