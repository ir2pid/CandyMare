#ifndef CART_H
#define CART_H
#include "s3e.h"
#include "s3eIOSAppStoreBilling.h"
#include "s3eDebug.h"
#include "stdio.h"
#include "Storage.h"

	//AppID:852EH7DBR9.com.noisyninja.candymare
	//CandyMare
	//AppleID:505243336
	//shared key:48f0aa6687384b349178a71ece6c0902
	//SKU:230586
	//BundleID:com.noisyninja.candymare
	//AppleID:505243336
	//ProductID:purchase
	//ipod imei:13b3b9d63fb44afffa74fec1741c0be21f40ac09

//purchase products:
//com.noisyninja.candymare.purchase
//upgrade
static bool allRestored;// = false;

// Input product identifying request and output purchase complete receipt
static s3ePaymentRequest g_PaymentRequest;
static s3eTransactionReceipt g_TransactionReceipt;
static s3ePaymentTransaction* g_CompletedPayment;// = NULL;

// Product information sent back from s3eIOSAppStoreBillingInit
static s3eProductInformation* g_ProductInformation;// = NULL;
static s3ePaymentTransaction* g_PaymentTransaction;// = NULL;

// Status string to print at bottom of screen


void ProductInfoCallback(s3eProductInformation* productInfo, void* userData);
void TransactionUpdateCallback(s3ePaymentTransaction* transaction, void* userData);
class Container{
public:
	bool purchaseButton;
	char g_StatusStr[150];
};
static void SetStatus(Container*,const char* statusStr, ...);

class Cart{
	
// Unique identifier for the product id to purchase.
const char* g_ProductID;// = "com.noisyninja.candymare.purchase";


const char* g_ProductID2;// = "com.noisyninja.candymare.purchase";

public:
	bool purchaseState;
	Container *container;
	Cart()
	{
		//sprintf(g_StatusStr,"%s","inactive state");
		purchaseState = false;
		container = new Container();
		container->purchaseButton = false;
		
	}

	void construct(bool purchase)
	{
		purchaseState = purchase;

		if(purchaseState)
		{	SetStatus(container,"THANK U 4 UR SUPPORT !");
			return ;
		}

		g_ProductID = "com.noisyninja.unlock";
		g_ProductID2 = "remove ad";

		g_CompletedPayment = NULL;
		g_ProductInformation = NULL;
		g_PaymentTransaction = NULL;
		allRestored = false;
		
		s3eIOSAppStoreBillingInit(ProductInfoCallback, TransactionUpdateCallback, container);

		if (!s3eIOSAppStoreBillingAvailable())
		{
			//if(!_DEBUG)
			{
				s3eDebugErrorShow(S3E_MESSAGE_CONTINUE, "in-app purchase only works on iPhone.");
				SetStatus(container,"in-app purchase only works on iPhone.");
				//s3eDeviceExit(1);
			}
		}

		// Set up product request
		strcpy(g_PaymentRequest.m_ProductID, g_ProductID);
		g_PaymentRequest.m_Quantity = 1;
		
		// Initialise the Micro-Transaction module and register for callbacks
		// when product & transaction information is available. Note that Micro-
		// Transaction has explicit Init & Terminate functions unlike most S3E
		// subdevices or EDK extensions.

		//Add button for requesting product information and restoring already purchased products
		//ResetButtons();
		
		//SetStatus("Waiting for user input to get product info for: %s", g_ProductID2);
		//SetStatus("Fetching product info...");
		if (s3eIOSAppStoreBillingRequestProductInformation(&g_ProductID, 1) == S3E_RESULT_SUCCESS)
        {
			SetStatus(container,"Fetching product info...");
		}           
		else
		{
			SetStatus(container,"Requesting product info FAILED");
		}
	}
	void update()
	{
		if (g_CompletedPayment)
		{
			// In a real app, the receipt would be checked and a server might provide
			// data before this function is called
			s3eIOSAppStoreBillingCompleteTransaction(g_CompletedPayment, S3E_TRUE);
			g_CompletedPayment = NULL;
		}
		

	}
	void purchase()
	{
		if (s3eIOSAppStoreBillingRequestPayment(&g_PaymentRequest))
                SetStatus(container,"Purchasing ...");
            else
                SetStatus(container,"Purchasing FAILED!");
	}
	/*void getDeviceType()
	{
		int i1= s3eDeviceGetInt(S3E_DEVICE_OS);
		int i2= s3eDeviceGetInt(S3E_DEVICE_ID);
		int i3= s3eDeviceGetInt(S3E_DEVICE_PHONE_NUMBER);
		uint32 i4= s3eDeviceGetInt(S3E_DEVICE_UNIQUE_ID);
		uint32 i5=IwHashString(s3eDeviceGetString(S3E_DEVICE_UNIQUE_ID));
		char ch1[50]; 
		char ch2[50]; 
		char ch3[50]; 
		char ch4[50]; 
		sprintf(ch1,"%s",s3eDeviceGetString(S3E_DEVICE_OS));
		sprintf(ch2,"%s",s3eDeviceGetString(S3E_DEVICE_ID));
		sprintf(ch3,"%s",s3eDeviceGetString(S3E_DEVICE_PHONE_NUMBER));
		sprintf(ch4,"%s",s3eDeviceGetString(S3E_DEVICE_UNIQUE_ID));
	}*/

	void setPurchaseState(bool state)
	{
		purchaseState = state;
	}
	
	void updatePurchaseState()
	{
		//purchaseButton = storage.userData.purchased;
	}
	void destruct()
	{
		if(container != NULL)
			delete container;container = NULL;
		 if (g_ProductInformation)
			s3eFree(g_ProductInformation);

		if (g_TransactionReceipt.m_ReceiptData)
			s3eFree(g_TransactionReceipt.m_ReceiptData);

		if (g_PaymentTransaction)
			s3eFree(g_PaymentTransaction);

		s3eIOSAppStoreBillingTerminate();
	}
};



	// Sets a string to be displayed beneath the buttons
	static void SetStatus(Container* cont,const char* statusStr, ...)
	{
		va_list args;
		va_start(args, statusStr);
		strcpy(cont->g_StatusStr, "");
		vsprintf(cont->g_StatusStr+strlen(cont->g_StatusStr), statusStr, args);
		va_end(args);
	}


/*
 * Callback functions
 *
 * This callback is called after the call to s3eIOSAppStoreBillingRequestPayment when
 * the state of a transaction has changed (i.e. an item as been successfully bought,
 * or an error occurred)
 */
void TransactionUpdateCallback(s3ePaymentTransaction* transaction, void* userData)
{
    s3eDebugTracePrintf("! TransactionUpdateCallback");	
	Container *container = (Container*)userData;

    switch (transaction->m_TransactionStatus)
    {
        case S3E_PAYMENT_STATUS_PENDING:
            s3eDebugTracePrintf("Buying %s (transaction '%s') in progress...", transaction->m_Request->m_ProductID, transaction->m_TransactionID);
            SetStatus(container,"Purchasing ...");
            break;

        case S3E_PAYMENT_STATUS_PURCHASED:
        case S3E_PAYMENT_STATUS_RESTORED:
            if (g_TransactionReceipt.m_ReceiptData)
                s3eFree(g_TransactionReceipt.m_ReceiptData);

            if (g_PaymentTransaction)
                s3eFree(g_PaymentTransaction);

            s3eDebugTracePrintf("S3E_PAYMENT_STATUS_PURCHASED");
            s3eDebugTracePrintf("g_PaymentRequest.m_ProductID %s", g_PaymentRequest.m_ProductID);
            s3eDebugTracePrintf("g_PaymentTransaction->m_Request->m_ProductID %s", transaction->m_Request->m_ProductID);

            // Check product ID of completed transaction
            if (!strcmp(transaction->m_Request->m_ProductID, g_PaymentRequest.m_ProductID))
            {
                s3eDebugTracePrintf("product ids match");

                // Retain the transaction so it can be verified and finalised
                // later. In this simple example, we only track 1 at a time and
                // just complete it on the next update callback.
                if (!g_CompletedPayment)
                {
                    transaction->m_Retain = S3E_TRUE;
                    g_CompletedPayment = transaction;
                }

                if (transaction->m_TransactionStatus == S3E_PAYMENT_STATUS_PURCHASED)
                {
					SetStatus(container,"Purchase completed!");
					util.flurryAnalytics.log("purchased");
					container->purchaseButton = false;
					storage.userData.purchased = true;					
					storage.saveStorage();
				}
                else
				{
                    SetStatus(container,"Products have been restored!");
					container->purchaseButton = false;
					storage.userData.purchased = true;
					storage.saveStorage();
				}

                // Copy transaction to local memory
                g_PaymentTransaction = (s3ePaymentTransaction*)s3eMalloc(sizeof(s3ePaymentTransaction));
                memcpy(g_PaymentTransaction, transaction, sizeof(s3ePaymentTransaction));

                // Point to local version of payment request identifier
                g_PaymentTransaction->m_Request = &g_PaymentRequest;

                // Copy receipt data to memory
                g_TransactionReceipt.m_ReceiptSize = transaction->m_TransactionReceipt->m_ReceiptSize;
                g_TransactionReceipt.m_ReceiptData = s3eMalloc(g_TransactionReceipt.m_ReceiptSize+1);
                memcpy(g_TransactionReceipt.m_ReceiptData, transaction->m_TransactionReceipt->m_ReceiptData, g_TransactionReceipt.m_ReceiptSize);
                g_PaymentTransaction->m_TransactionReceipt = &g_TransactionReceipt;

                // Make sure it's null terminated for convenient printing in this example
                char* endOfData = (char*)g_TransactionReceipt.m_ReceiptData + g_TransactionReceipt.m_ReceiptSize;
                *endOfData = '\0';

                //ResetButtons();
                //g_TransactionReceiptButton = NewButton("Display receipt");

                // g_PaymentTransaction is now a pointer to a local copy of the complete transaction information
                break;
            }
            else
            {
                // As we only have 1 product in this example, this should never happen.
                // The case should be catered for though, for example a transaction started when previously running
                // the application may complete on app start-up, before the app has obtained a list of products
                // to deal with.
                if (transaction->m_TransactionStatus == S3E_PAYMENT_STATUS_PURCHASED)
                    SetStatus(container,"Buying completed for unexpected product ID: %s!", transaction->m_Request->m_ProductID);
                else
                    SetStatus(container,"Restoring completed for unexpected product ID: %s!", transaction->m_Request->m_ProductID);
            }
            break;

        case S3E_PAYMENT_STATUS_FAILED_CLIENT_INVALID:
            SetStatus(container,"Buying FAILED. Client is not allowed to make the payment.");
            break;

        case S3E_PAYMENT_STATUS_FAILED_PAYMENT_CANCELLED:
            {
				SetStatus(container,"Buying FAILED. (Restored if already Purchased!)");				
				util.flurryAnalytics.log("failed/already purchased");
				break;
			}

        case S3E_PAYMENT_STATUS_FAILED_PAYMENT_INVALID:
            SetStatus(container,"Buying FAILED. Invalid parameter/purchase ID.");
            break;

        case S3E_PAYMENT_STATUS_FAILED_PAYMENT_NOT_ALLOWED:
            SetStatus(container,"Buying FAILED. Purchasing is disabled in device's Settings menu!");
            break;

        default:
            SetStatus(container,"Buying FAILED for unknown reason...");
            break;
    }
}

// This callback is called after the call to s3eIOSAppStoreBillingRequestProductInformation once
// product information is returned from the store.
void ProductInfoCallback(s3eProductInformation* productInfo, void* userData)
{	
    s3eDebugTracePrintf("! ProductInfoCallback %p", productInfo);
	Container *container = (Container*)userData;

	if(!s3eIOSAppStoreBillingGetInt(S3E_IOSAPPSTOREBILLING_CAN_MAKE_PAYMENTS))
	{
		s3eDebugTracePrintf("Purchasing disabled, please enable it from Settings menu to proceed.");

	}
    // Free info from any previous request
    if (g_ProductInformation)
        s3eFree(g_ProductInformation);

    // Copy productInfo since it will no longer be valid once this function returns
    g_ProductInformation = (s3eProductInformation*)s3eMalloc(sizeof(s3eProductInformation));
    memcpy(g_ProductInformation, productInfo, sizeof(s3eProductInformation));

    s3eDebugTracePrintf("m_ProductID=%s, m_LocalisedTitle=%s", g_ProductInformation->m_ProductID, g_ProductInformation->m_LocalisedTitle);

    switch (g_ProductInformation->m_ProductStoreStatus)
    {
        case S3E_PRODUCT_STORE_STATUS_VALID:
        {
            if (s3eIOSAppStoreBillingGetInt(S3E_IOSAPPSTOREBILLING_CAN_MAKE_PAYMENTS))
            {
				container->purchaseButton = true;
				SetStatus(container,"Price ( %s )",  g_ProductInformation->m_FormattedPrice,userData);
			}
            else
                SetStatus(container,"Price ( %s ). Cannot buy: Purchasing is disabled in device's Settings menu!", g_ProductInformation->m_FormattedPrice);
            //DeleteButtons();
            //g_ProductInfoButton = NewButton("Re-check product info");

            break;
        }
        case S3E_PRODUCT_STORE_STATUS_NO_CONNECTION:
            SetStatus(container,"Could not connect to store! Please check connection.");
            //ResetButtons();
            break;

        case S3E_PRODUCT_STORE_STATUS_RESTORE_FAILED:
            SetStatus(container,"Restore products failed! Please try again.");
            break;

        case S3E_PRODUCT_STORE_STATUS_RESTORE_COMPLETED:
           {			   
			    allRestored = true;
				break;
		   }
		case S3E_PRODUCT_STORE_STATUS_NOT_FOUND:
			 SetStatus(container,"Product not in store, Try later!");
			 break;
        default: // Item not found
            SetStatus(container,"Product not in store, Try later!");
            //ResetButtons();
    }

    s3eDebugTracePrintf("leaving ProductInfoCallback");
}

#endif