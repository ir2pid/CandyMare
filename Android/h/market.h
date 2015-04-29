#ifndef MARKET_H
#define MARKET_H
#include "IwGameMarket.h"
//#include "Storage.h"

namespace{

	char *status;
	int32 StatusdHandler(void* caller, void* data)
	{
		switch(IIwGameMarket::getMarket()->getStatus())
		{
			
		case 0:
			{
				status = "MS_IDLE";
				break;
			}
		case 1:
			{
				status = "MS_PURCHASING";
				break;
			}
		case 2:
			{
				status = "MS_PURCHASE_COMPLETED";
				break;
			}
		case 3:
			{
				status = "MS_RESTORE_COMPLETED";
				break;
			}
		case 4:
			{
				status = "MS_ERROR_CLIENT_INVALID";
				break;
			}
		case 5:
			{
				status = "MS_ERROR_PAYMENT_CANCELLED";
				break;
			}
		case 6:
			{
				status = "MS_ERROR_PAYMENT_INVALID";
				break;
			}
		case 7:
			{
				status = "MS_ERROR_PAYMENT_NOT_ALLOWED";
				break;
			}
		case 8:
			{
				status = "MS_ERROR_PURCHASE_UNKNOWN";
				break;
			}
		case 9:
			{
				status = "MS_ERROR_PURCHASE_DISABLED";
				break;
			}
		case 10:
			{
				status = "MS_ERROR_NO_CONNECTION";
				break;
			}
		case 11:
			{
				status = "MS_ERROR_RESTORE_FAILED";
				break;
			}
		case 12:
			{
				status = "MS_ERROR_UNKNOWN_PRODUCT";
				break;
			}			
		default:
				status = "MS_ERROR_UNKNOWN_PRODUCT";
		}

		return 1;
	}

	int32 PurchaseComplete(void* caller, void* data)
	{
		int type = IIwGameMarket::getMarket()->getLastPurchaseID();
		if (type == 1) // purchased
		{
			//storage.userData.purchased = (storage.userData.UDID%10)+5;
		}
		return 1;
	}

	int32 ProductInfo(void* caller, void* data)
	{
		/*CIwGameMarketProduct *prod = IIwGameMarket::getMarket()->getP();
		if (prod->type == 1) // purchased
		{
			//storage.userData.purchased = (storage.userData.UDID%10)+5;
		}*/
		return 1;
	}

	int32 PurchaseError(void* caller, void* data)
	{
		// Display an error to the user
		return 1;
	}	
	
}

class Market
{
	void construct()
	{
		
		IIwGameMarket::Create();
		IIwGameMarket::getMarket()->setReceiptAvailableHandler(PurchaseComplete, NULL);
		IIwGameMarket::getMarket()->setErrorHandler(PurchaseError, NULL);
		IIwGameMarket::getMarket()->setStatusChangedHandler(StatusdHandler,NULL);
	}

	void init()
	{
		// Which OS are we running
		int os = s3eDeviceGetInt(S3E_DEVICE_OS);
		// Create product 1
		CIwGameMarketProduct* product = new CIwGameMarketProduct();
		product->Consumable = false;
		product->ID = 1;
		product->Name = "purchase";
		if (os == S3E_OS_ID_IPHONE)
			product->ExternalID = "com.noisyninja.candymare.purchase";
		/*else
			product->ExternalID = "purchase";*/
		product->Purchased = false;
		IIwGameMarket::getMarket()->addProduct(product);


		// Create product 2
		product = new CIwGameMarketProduct();
		product->Consumable = false;
		product->ID = 2;
		product->Name = "upgrade";
		if (os == S3E_OS_ID_IPHONE)
		product->ExternalID = "upgrade";
		/*else
		product->ExternalID = "upgrade";*/
		product->Purchased = false;
		IIwGameMarket::getMarket()->addProduct(product);

	}

	void update()
	{
		IIwGameMarket::getMarket()->Update();
	}

	void destruct()
	{
		IIwGameMarket::Destroy();
	}
	void getPrice()
	{
		/*if (IIwGameMarket::getMarket()->)
		{

		}*/
	}
	void purchase()
	{
		if (IIwGameMarket::getMarket()->PurchaseProduct(1))
		{

		}
	}

	void isPurchased()
	{
		/*if(((storage.userData.UDID%10)+5) == storage.userData.purchased)
			return true;
		else
			return false;*/
	}
};
#endif