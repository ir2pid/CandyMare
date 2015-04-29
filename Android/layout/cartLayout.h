#ifndef CARTLAYOUT_H
#define CARTLAYOUT_H

#include <time.h>
#include "font.h"
#include "cart.h"
#include "util.h"

class CartLayout
{
	//CIw2DImage* tLogo;
	
	CIw2DImage* tBack;
	CIw2DImage* tPurchase;
	CIw2DImage* tRemoveAd1;
	CIw2DImage* tRemoveAd2;
	CIwGameString text;

public:
	Click cBack;
	Click cPurchase;
	//Sprite sLogo;
	Sprite sRemoveAd;
	//Sprite sRemoveAd2;
	Cart cart;
	int showPurchaseY;
	int hidePurchaseY;
	float count;
	void construct()
	{
		util.setBG();
		count = 0.0f;
		cart.construct(storage.userData.purchased);

		//tLogo = util.getTexture("menu/logo.png");
		tBack = util.getTexture("menu/back.png");
		tPurchase = util.getTexture("cart/purchase.png");
		tRemoveAd1 = util.getTexture("cart/removead1.png");
		tRemoveAd2 = util.getTexture("cart/removead2.png");
		//sLogo.constructRaw(0,0,util.LEFT,util.TOP,tLogo);
		int x1 = (util.widthDisplay-tRemoveAd1->GetWidth())/2;
		int y1 = 0;
		sRemoveAd.constructRaw(x1,y1,util.LEFT,util.TOP,tRemoveAd1);
		//sRemoveAd2.constructRaw((util.widthDisplay-tRemoveAd1->GetWidth())/2,tLogo->GetHeight(),util.LEFT,util.TOP,tRemoveAd2);
    	int purchaseX = (util.widthGame-tPurchase->GetWidth())/2;
		showPurchaseY = util.heightDisplay-tPurchase->GetHeight();
		hidePurchaseY = util.heightDisplay;
		cPurchase.constructRaw(purchaseX,hidePurchaseY,util.LEFT,util.TOP,"",tPurchase);

		cBack.constructRaw(-tBack->GetWidth(),-1.5*tBack->GetHeight(),util.RIGHT,util.BOTTOM,"",tBack);


	}

	void destruct()
	{
		cart.destruct();
		cPurchase.destruct();
		cBack.destruct();
		/*sIcon1.destruct();
		sIcon2.destruct();
		sIcon3.destruct();
		sIcon4.destruct();
		//sDialogBox.destruct();
		
		delete tIcon1;tIcon1 = NULL;
		delete tIcon2;tIcon2 = NULL;
		delete tIcon3;tIcon3 = NULL;
		delete tIcon4;tIcon4 = NULL;*/
			
		delete tRemoveAd1;tRemoveAd1 = NULL;
		delete tRemoveAd2;tRemoveAd2 = NULL;
		delete tBack;tBack = NULL;
		//delete tLogo;tLogo = NULL;
		delete tPurchase;tPurchase = NULL;
	}
	void renderLogo()
	{
		//sLogo.render(IwRandRange(3*util.em)+(tLogo->GetWidth()/2),IwRandRange(3*util.em)-(tLogo->GetHeight())/4,0.5f);
		
		//Iw2DSetColour(util.COLOR[IwRandRange(9)]);
		//Iw2DSetAlphaMode(IW_2D_ALPHA_ADD);
		//	sLogo.render(IwRandRange(3*util.em)+(tLogo->GetWidth()/2),IwRandRange(3*util.em)-(tLogo->GetHeight())/4,0.5f);
		//Iw2DSetAlphaMode(IW_2D_ALPHA_NONE);
		//Iw2DSetColour(util.COLOR[0]);
		if(cart.purchaseState)
			sRemoveAd.render(tRemoveAd2);
		else
			sRemoveAd.render(tRemoveAd1);

	}
	void renderConsole()
	{
		Iw2DSetFont(font.AllerM);
		CIwSVec2 textReg(util.widthDisplay,util.heightDisplay-tPurchase->GetHeight()-tRemoveAd1->GetHeight());	

		Iw2DSetColour(util.COLOR[0]);
		CIwSVec2 topLeft(0,tRemoveAd1->GetHeight());
		char tmp[153];
		//updatePurchaseState();
		if(count < 1.0f)
		{
			sprintf(tmp,"%s -",cart.container->g_StatusStr);
		}
		else if(count < 2.0f)
		{
			sprintf(tmp,"%s \\",cart.container->g_StatusStr);
		}
		else if(count < 3.0f)
		{
			sprintf(tmp,"%s |",cart.container->g_StatusStr);
		}
		else if(count < 4.0f)			
		{			
			sprintf(tmp,"%s /",cart.container->g_StatusStr);
		}
		else
		{
			sprintf(tmp,"%s -",cart.container->g_StatusStr);			
			count = 0.0f;
		}
			
		count+=0.5f;

		Iw2DDrawString(tmp,topLeft,textReg,IW_2D_FONT_ALIGN_CENTRE,IW_2D_FONT_ALIGN_CENTRE);		

	}

	void update()
	{
		cart.update();
		////cout<<"\ncart.purchaseButton"<<cart.container->purchaseButton;
		////cout<<"\ncPurchase.y"<<cPurchase.y;
		////cout<<"\nshowPurchaseY"<<showPurchaseY;
		////cout<<"\nhidePurchaseY"<<hidePurchaseY;
		if(cart.container->purchaseButton)
		{
			if(cPurchase.y>showPurchaseY)
			{
				cPurchase.y -= 10;
			}
			else
			{
				cPurchase.y = showPurchaseY;
			}	
		}
		else
		{
			if(cPurchase.y<hidePurchaseY)
			{
				cPurchase.y += 10;
			}
			else
			{
				cPurchase.y = hidePurchaseY;
			}	
		}
	
	}

	void toMakePurchase()
	{
		cart.purchase();
	}

	
};
#endif