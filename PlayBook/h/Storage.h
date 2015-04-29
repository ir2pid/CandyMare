#ifndef STORAGE_H
#define STORAGE_H

#include "IwTextParserITX.h"
#include <iostream.h>	

#include "Level.h"
//#include "Cart.h"
#include "achivement.h"
#include "IwHashString.h"

// simple managed class - for this example, objects of this type
	// can only exist within an object of type CSingleParent (see below)
	//-----------------------------------------------------------------------------
	class CChild : public CIwManaged
	{
	public:
		IW_MANAGED_DECLARE(CChild);

		CChild()
			:// iStar(0),
			iMove(0)//,
			//iChecksum(0)
			{}

		// function invoked by the text parser when parsing attributes for objects of this type
		virtual bool ParseAttribute(CIwTextParserITX *pParser, const char *pAttrName);

		// function invoked by the text parser when the object definition end is encountered
		virtual void ParseClose(CIwTextParserITX *pParser);

		//int32       iStar;
		int32       iMove;
		//int32       iChecksum;

		CIwStringS  r_11;
		CIwStringS  r_12;
		CIwStringS  r_13;
		CIwStringS  r_14;
		CIwStringS  r_15;

		CIwStringS  r_21;
		CIwStringS  r_22;
		CIwStringS  r_23;
		CIwStringS  r_24;
		CIwStringS  r_25;
	};

	// define class name function
	IW_MANAGED_IMPLEMENT(CChild);

	// managed class (singleton) that contains another managed class (CChild)
	//-----------------------------------------------------------------------------
	class CSingleParent : public CIwManaged
	{
	private:
		// singleton pointer
		static CSingleParent    *s_Singleton;

	public:
		IW_MANAGED_DECLARE(CSingleParent);

		CSingleParent()
			: m_Child(NULL)
		{
			s_Singleton = this;
		}

		~CSingleParent()
		{
			if (m_Child)
			{
				delete m_Child;
			}

			s_Singleton = NULL;
		}

		// public access to the singleton object
		static CSingleParent *Get()
		{
			return s_Singleton;
		}

		// CIwManaged::ParseAttribute is not overridden here - i.e. the only permitted attribute is 'name'

		// function invoked by the text parser when the object definition end is encountered
		virtual void ParseClose(CIwTextParserITX *pParser);

		CChild  *m_Child;

	};
	//-----------------------------------------------------------------------------

	// define class name function
	IW_MANAGED_IMPLEMENT(CSingleParent);

		
	// CChild implementation

	// function invoked by the text parser when parsing attributes for objects of this type
	//-----------------------------------------------------------------------------
	bool CChild::ParseAttribute(CIwTextParserITX* pParser, const char* pAttrName)
	{
		/*if (!strcmp(pAttrName, "iStar"))
		{
			int32 tmp;
			pParser->ReadInt32(&tmp);
			iStar = tmp;
		}
		else */
		if (!strcmp(pAttrName, "iMove"))
		{
			int32 tmp;
			pParser->ReadInt32(&tmp);
			iMove = tmp;
		}
		/*else if (!strcmp(pAttrName, "iChecksum"))
		{
			int32 tmp;
			pParser->ReadInt32(&tmp);
			iChecksum = tmp;
		}*/
		else if (!strcmp(pAttrName, "r_11"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_11 = line;
		}
		else if (!strcmp(pAttrName, "r_12"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_12 = line;
		}
		else if (!strcmp(pAttrName, "r_13"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_13 = line;
		}
		else if (!strcmp(pAttrName, "r_14"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_14 = line;
		}
		else if (!strcmp(pAttrName, "r_15"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_15 = line;
		}
		
		else if (!strcmp(pAttrName, "r_21"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_21 = line;
		}
		else if (!strcmp(pAttrName, "r_22"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_22 = line;
		}
		else if (!strcmp(pAttrName, "r_23"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_23 = line;
		}
		else if (!strcmp(pAttrName, "r_24"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_24 = line;
		}
		else if (!strcmp(pAttrName, "r_25"))
		{
			char line[27];
			// read firstname
			pParser->ReadString(line, 27);
			r_25 = line;
		}
		else
		// call base function
			return CIwManaged::ParseAttribute(pParser, pAttrName);

		return true;
	}
	// function invoked by the text parser when the object definition end is encountered
	//-----------------------------------------------------------------------------
	void CChild::ParseClose(CIwTextParserITX* pParser)
	{
		// we know that this object has been parsed in the context of a CSingleParent object
		CSingleParent *parent = (CSingleParent *)IwGetTextParserITX()->GetObject(-1);

		// set the child of parent to this
		parent->m_Child = this;
	}

	// CSingleParent implementation

	// function invoked by the text parser when the object definition end is encountered
	//-----------------------------------------------------------------------------
	void CSingleParent::ParseClose(CIwTextParserITX* pParser)
	{
		// if a CSingleParent block is encountered in the ITX file then set the singleton

		if (s_Singleton && (s_Singleton != this) )
			delete s_Singleton;

		s_Singleton = this;
	}
	//-----------------------------------------------------------------------------

	// define class factory functions
	IW_CLASS_FACTORY(CChild);
	IW_CLASS_FACTORY(CSingleParent);

	// CSingleParent singleton
	CSingleParent *CSingleParent::s_Singleton = NULL;

	class UserData{
	public:
		uint32 UDID;
		bool snd;
		bool vib;
		int sTheme;
		int sLevel;
		int currTheme;
		int currLevel;
		uint8 sStar[60];
		uint32 sStep[60];
		Achivement achivement;
		//uint32 sStarDump[10];//0 stars 1 moves 2 original moves 3 teleport, 4 toxic, 5 cure score(level*moves*star) 64

		UserData()
		{
			UDID = util.setUDID();
			snd = true;
			vib = true;

			sTheme = 1;
			sLevel = 1;

			currTheme = 1;
			currLevel = 1;

			for(int i=0;i<60;i++)
			{
				sStar[i] = 0;
				sStep[i] = 0;
				achivement.perfectLevel[60] = false;//means shortest path is taken
			}
						
			achivement.noTeleportsUsed = false;
			achivement.noToxication = false;
			achivement.noMedic = false;
			achivement.noShroom = false;
		
			achivement.globeTrotter = 0;
			achivement.starCrazy = 0;
			achivement.rejectStar = 0;
			achivement.junkie = 0;
			achivement.medic = 0;
			achivement.CaptainKirk = 0;
			//achivement.arrow2knee = 0;
			achivement.toxicFinishes = 0;
			achivement.quitter = 0;

			//setSteps();
			
			
		}

		void setSteps()
		{
			sStep[0] = 15;
			sStep[1] = 13;
			sStep[2] = 4;
			sStep[3] = 24;
			sStep[4] = 32;

			sStep[5] = 49;
			sStep[6] = 73;
			sStep[7] = 45;
			sStep[8] = 26;
			sStep[9] = 34;

			sStep[10] = 26;
			sStep[11] = 25;
			sStep[12] = 25;
			sStep[13] = 22;
			sStep[14] = 22;

			sStep[15] = 14;
			sStep[16] = 62;
			sStep[17] = 28;
			sStep[18] = 58;
			sStep[19] = 27;

			sStep[20] = 48;
			sStep[21] = 36;
			sStep[22] = 36;
			sStep[23] = 48;
			sStep[24] = 39;

			sStep[25] = 19;
			sStep[26] = 25;
			sStep[27] = 51;
			sStep[28] = 37;
			sStep[29] = 28;

			sStep[30] = 32;
			sStep[31] = 39;
			sStep[32] = 33;
			sStep[33] = 54;
			sStep[34] = 46;

			sStep[35] = 66;
			sStep[36] = 28;
			sStep[37] = 63;
			sStep[38] = 61;
			sStep[39] = 71;

			sStep[40] = 119;
			sStep[41] = 37;
			sStep[42] = 99;
			sStep[43] = 23;
			sStep[44] = 60;
			
			sStep[45] = 35;
			sStep[46] = 21;
			sStep[47] = 44;
			sStep[48] = 58;
			sStep[49] = 44;

			sStep[50] = 48;
			sStep[51] = 36;
			sStep[52] = 70;
			sStep[53] = 49;
			sStep[54] = 128;

			sStep[55] = 55;
			sStep[56] = 65;
			sStep[57] = 81;
			sStep[58] = 142;
			sStep[59] = 68;
		}
	};

class Storage
{

private:
		
		Level *level;
		
public:
		uint32 sStarDump[10];
		UserData userData;

	Storage()
	{
		//construct();
	}

	~Storage()
	{
		//destruct();
	}
//----------------------------------------------------------------------------------------
		//implementation below
//----------------------------------------------------------------------------------------
	void construct()
	{
		level = NULL;
		// register the classes with the class factory - this is required for parsing
		
		IW_CLASS_REGISTER(CChild);
		IW_CLASS_REGISTER(CSingleParent);
		//Cart cart;
		//cart.getDeviceType();
		//securestorageblob
		s3eResult r = s3eSecureStorageGet(&userData, sizeof(userData));
		if (r == S3E_RESULT_ERROR) 
		{
			r = s3eSecureStoragePut(&userData, sizeof(userData));
		}
		
	}

	void saveStorage()
	{
		s3eResult r = s3eSecureStoragePut(&userData, sizeof(userData));
	}

	void destruct()
	{
		s3eResult r = s3eSecureStoragePut(&userData, sizeof(userData));
		if (r == S3E_RESULT_ERROR) 
		{
			//cout<<"\n\n!!!!!!!error storing profile";
		}
		else
		{
			//cout<<"\n\n!!!!!!!profile data stored";
		}

		if(level!=NULL)
			delete level;level = NULL;
	}

	int getLevel()
	{
		return ((userData.currTheme-1)*20)+userData.currLevel-1;
	}

	Level parseLevel()
	{
		Level level;
		//new CIwTextParserITX;
		new CIwTextParserITX();

		IwGetTextParserITX()->SetAssertOnUnrecognisedTokens(false);
		// parse the file
		char tmp[50];
		//if(userData.currLevel < 10)
		//	sprintf(tmp,"./level/level%d_0%d.itx",userData.currTheme,userData.currLevel);
		//else
		////cout<<"\ntrying to read from ram";
		//sprintf(tmp,"./level/level%i_%i.itx",userData.currTheme,userData.currLevel);
		//if(IwGetTextParserITX()->ParseFile(tmp) != NULL)
		//{	
		//	//cout<<"\nram level not found trying to read from gles1\n\n";
			sprintf(tmp,"./level/level%d_%d.itx",userData.currTheme,userData.currLevel);

			IwGetTextParserITX()->ParseFile(tmp);
			
		//}

		

		// the singleton exists at this point since it has been parsed
		CSingleParent *parent = CSingleParent::Get();

		//level.setTime(parent->m_Child->iStar);
		
		uint16 lvl = ((userData.currTheme-1)*20)+userData.currLevel-1;
		if(parent->m_Child->iMove == 0)
		{
			
			if(userData.sStep[lvl] > 0)
				level.setMove(userData.sStep[lvl]);
			else
				level.setMove(999);
		}
		else
		{
			if(userData.sStep[lvl] < parent->m_Child->iMove && userData.sStep[lvl] != 0)
				level.setMove(userData.sStep[lvl]);
			else
				level.setMove(parent->m_Child->iMove);
			
		}
		
		//level.setChecksum(parent->m_Child->iChecksum);

		/*userData.sStarDump[60] = parent->m_Child->iTime;
		userData.sStarDump[61] = parent->m_Child->iMove;
		userData.sStarDump[62] = lvl;*/

		uint16 len = parent->m_Child->r_11.length();
//1
		const char *c = parent->m_Child->r_11.c_str();
		const char *c2 = parent->m_Child->r_21.c_str();
		setArr(0,&level,c,c2,len);


//2
		c = parent->m_Child->r_12.c_str();
		c2 = parent->m_Child->r_22.c_str();
		setArr(1,&level,c,c2,len);
//3
		c = parent->m_Child->r_13.c_str();
		c2 = parent->m_Child->r_23.c_str();
		setArr(2,&level,c,c2,len);
//4
		c = parent->m_Child->r_14.c_str();
		c2 = parent->m_Child->r_24.c_str();
		setArr(3,&level,c,c2,len);
//5
		c = parent->m_Child->r_15.c_str();
		c2 = parent->m_Child->r_25.c_str();
		setArr(4,&level,c,c2,len);
		
		//cout<<"\nParsed level below\n";
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<9;j++)
			{
				//cout<<level.array1[i][j]<<" ";
			}
			//cout<<"\n";
		}
		////cout<<"\nParsed level above\n";
		

		// clear up data
		delete CSingleParent::Get();

		// destroy the text parser
		delete IwGetTextParserITX();


		////cout<<jigSaw.size();
		return level;

	}

	void setArr(int col,Level *level,const char *c,const char *c2,int len)
	{

		//array
			uint16 r = 0x0;

			uint16 j=0x0;
			uint16 t=0x0;
			
			while(j<len)
			{
				////cout<<"\n!!!!!!!!!!!"<<j<<"of"<<len;
				if(c[j]!='.')
				{
					t = (t*10)+c[j]-48;
				}
				else
				{
					if(t!=0)
					{
						level->jigSize++;
						level->array1[col][r] = t;
					}
					
					r++;
					t = 0;
				}
				
				j++;
			}
			if(t>0)
			{
				level->jigSize++;
			}
			level->array1[col][r] = t;


			//array2
			r = 0x0;
			j=0x0;
			t=0x0;

			
			while(j<len)
			{
				////cout<<"\n!!!!!!!!!!!"<<j<<"of"<<len;
				if(c2[j]!='.')
				{
					t = (t*10)+c2[j]-48;
				}
				else
				{
					if(t!=0)
					{	
						level->jigSize++;
						level->array2[col][r] = t;
					}
					
					r++;
					t = 0;
				}
				
				j++;
			}
			if(t!=0)
				level->array2[col][r] = t;
	}

	void makeLevel(char *tmp)
	{
		//Open file for reading in binary to prevent the crlf translation
		char HEAD[] = {"CSingleParent\r\n{\r\n\tname	level01\r\n\tCChild\r\n\t{\r\n\t\tiStar\t0\r\n\t\tiMove\t0\r\n\t\tiChecksum\t0\r\n\t"};
		char TAIL[] = {"\r\n\t}\r\n}"};
		static char* levelData = NULL;
		
		levelData = (char*)s3eMallocBase(strlen(HEAD)+strlen(tmp)+strlen(TAIL));
		
		sprintf(levelData,"%s%s%s",HEAD,tmp,TAIL);
        
		s3eFreeBase((void*)tmp);
		char fileName[40];

		//mobile
		//===================================================================
		s3eFileMakeDirectory("level");
		sprintf(fileName,"level/level%i_%i.itx",userData.currTheme,userData.currLevel);
		s3eFile* FileHandle = s3eFileOpen(fileName,"wb");
		static char g_ErrorString[256];      
		
		if (FileHandle == NULL)
        {
            //error has occurred
            // Something went wrong during opening of the file
            // retrieve error for display
                  
            s3eFileGetError();
            strcpy(g_ErrorString, s3eFileGetErrorString());
			IwGxPrintString(0, 60, g_ErrorString);
        }

		int size = strlen(levelData);
		s3eFileWrite(levelData,size,1,FileHandle);
		s3eFileClose(FileHandle);
		s3eFreeBase((void*)levelData);

		//===================================================================

		/*
		//pc
		
		//===================================================================
		
		sprintf(fileName,"./data-gles1/level/level%i_%i.itx",userData.currTheme,userData.currLevel);
		FileHandle = s3eFileOpen(fileName,"wb");  
		
		if (FileHandle == NULL)
        {
            //error has occurred
            // Something went wrong during opening of the file
            // retrieve error for display
                  
            s3eFileGetError();
            strcpy(g_ErrorString, s3eFileGetErrorString());
			IwGxPrintString(0, 60, g_ErrorString);
        }

		s3eFileWrite(levelData,size,1,FileHandle);
		s3eFileClose(FileHandle);
		s3eFreeBase((void*)levelData);

		//===================================================================
		*/
	}

	/*
	char* getMatrix()
	{
		char NL[] = {"\r\n\t"};
		//char *tmp = NULL;
		char *tmp =  (char*)s3eMallocBase(33);
		for(int i=0;i<layout.jigSaw.size();i++)
		{
			char t[1];
			////cout<<"\n JIGsaw:"<<layout.jigSaw[i].getCode();
			if(layout.jigSaw[i].getColumn() == 0)
			sprintf(t,"%i",layout.jigSaw[i].getCode());
			strcpy(tmp,t);
		}
		return tmp;

	}
	*/

}storage;

#endif


