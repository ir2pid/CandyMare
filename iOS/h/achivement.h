#ifndef ACHIVEMENT_H
#define ACHIVEMENT_H
#include "s3e.h"


class Achivement{

public:

	bool babyLevelCompleted;
	bool noTeleportsUsed;
	bool noToxication;
	bool noMedic;
	bool noShroom;

	bool perfectLevel[60];
	//bool allStarLevel[60]; from storage star
	//bool below100Step[60]; from storage step
	//int themeCompleted; from stheme
	//int levelCompleted; from slevel
	unsigned int globeTrotter;//landmark 50,250,500x,1000,1500,2000,2500,3000,3500 steps 
	unsigned int starCrazy; //10,50,100,150,200.. 
	unsigned int rejectStar;//10,50,100,150,200.. 
	unsigned int junkie; //5,10,15,20,25... 
	unsigned int medic; //5,10,15,20,25... 
	unsigned int CaptainKirk; //teleports 5,10,15,20,25... 
	unsigned int toxicFinishes;//5,10,15,20,25... 
	unsigned int quitter;//5,10,15,20,25... 
	//int arrow2knee; //5,10,15,20,25.... >>--(knee)-->
	
};

#endif