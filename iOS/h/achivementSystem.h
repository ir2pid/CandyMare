#ifndef ACHIVEMENTSYSTEM_H
#define ACHIVEMENTSYSTEM_H
#include "s3e.h"
#include "iostream.h"

class AchivementSystem{

public:
//CIwArray<AchivementUnit>
	void getAchivements(int stepO,int stepN,int starO,int starN,int rejO,int rejN,int junkieO,int junkieN,int medicO,int medicN,int kirkO,int kirkN,int toxicCount,bool istoxic)
	{
		int a = getMark(3,stepO);
		int b = getMark(3,stepN);
		if(a < b)
		{
			//cout<<"\n\nnew globe-trotter landmark"<<stepN; 
			notificationSystem.pushNotification(3);
		}
		
		a = getMark(2,starO);
		b = getMark(2,starN);
		if(a < b)
		{
			//cout<<"\n\nnew star-gobbler landmark"<<starN; 
			notificationSystem.pushNotification(12);
		}
		if(starN-starO == 3)
		{
			//cout<<"\n\nall stars taken"<<starN; 
			notificationSystem.pushNotification(17);
		}
		
		a = getMark(2,rejO);
		b = getMark(2,rejN);
		if(a < b)
		{
			//cout<<"\n\nnew star-missed landmark"<<rejN; 
			notificationSystem.pushNotification(13);
		}

		a = getMark(4,junkieO);
		b = getMark(4,junkieN);
		if(a < b)
		{
			//cout<<"\n\nnew mushroom junkie landmark"<<junkieN; 
			notificationSystem.pushNotification(6);
		}
		
		a = getMark(4,medicO);
		b = getMark(4,medicN);
		if(a < b)
		{
			//cout<<"\n\nnew mushroom medic landmark"<<junkieN; 
			notificationSystem.pushNotification(5);
		}

		a = getMark(4,kirkO);
		b = getMark(4,kirkN);
		if(a < b)
		{
			//cout<<"\n\nnew teleport landmark"<<junkieN; 
			notificationSystem.pushNotification(14);
		}

		if(istoxic)
		{
			notificationSystem.pushNotification(16);
			a = getMark(4,toxicCount);
			b = getMark(4,toxicCount+1);
			if(a < b)
			{
				//cout<<"\n\nnew toxic finish landmark"<<toxicCount+1;
				notificationSystem.pushNotification(23);
			}
		}
	}
	
	void getQuits(int quit)
	{
		
		//cout<<"\n\narrow 2 knee"<<quit+1;
		notificationSystem.pushNotification(1);
		int a = getMark(4,quit);
		int b = getMark(4,quit+1);
		if(a < b)
		{
			//cout<<"\n\nnew Quitter landmark"<<quit+1;
			notificationSystem.pushNotification(11);
		}


	}

	int getMark(int id,int value)
	{
		//id 1 progression 1,5,10....(5x)
		//id 2 progression 10,50,100...((5x)*10)
		//id 3 progression 50,250,500,750...((5x)*10*5)
		//id 4 progression 5,10,25,50,75...(5,10,[25x: {x>0}])
		if(id == 1)
			return prog1(value);
		else if(id == 2)
			return prog2(value);
		else if(id == 3)
			return prog3(value);
		else
			return prog4(value);
	}

	int prog1(int value)
	{
		if(value == 0)
			return 0;
		else if(value == 1)
			return 1;
		else return ((value/5)+1);
	}

	int prog2(int value)
	{
		if(value < 10)
			return 0;
		else if(value == 10)
			return 1;
		else return ((value/50)+1);
	}

	int prog3(int value)
	{
		if(value < 50)
			return 0;
		else if(value < 250)
			return 1;
		else if(value < 500)
			return 2;
		else
			return ((value/500)+2);
	}

	int prog4(int value)
	{
		if(value < 5)
			return 0;
		else if(value < 10)
			return 1;
		else if(value < 25)
			return 2;
		else
			return value/25;

	}

};
#endif