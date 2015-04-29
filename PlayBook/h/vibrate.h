#ifndef VIBRATE_H
#define VIBRATE_H
#include "s3eVibra.h" 
#include "Storage.h" 

static class Vibrate
{
	uint8 vibForce[4];//low to high
	uint16 vibTime[4]; 
public:

	//bool isValid;

	Vibrate()
	{
		/*if(s3eVibraGetInt(S3E_VIBRA_ENABLED)==1 && s3eVibraGetInt(S3E_VIBRA_AVAILABLE)==1)
			isValid = true;
		else
			isValid = false;*/

		int floor = s3eVibraGetInt(S3E_VIBRA_THRESHOLD);
		int gap = (255-floor)/4;

		vibForce[0] = floor+10;
		vibForce[1] = floor+(gap);
		vibForce[2] = floor+(gap*2);
		vibForce[3] = floor+(gap*3);
		
		vibTime[0] = 30;
		vibTime[1] = 100;
		vibTime[2] = 200;
		vibTime[3] = 300;
	}
	
	//low
	void vibrate00()
	{
		if(storage.userData.vib)// && isValid)
			s3eVibraVibrate(vibForce[0],vibTime[0]);
	}
	void vibrate01()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[0],vibTime[1]);
	}
	void vibrate02()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[0],vibTime[2]);
	}
	void vibrate03()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[0],vibTime[3]);
	}

	
	//mid
	void vibrate10()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[1],vibTime[0]);
	}
	void vibrate11()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[1],vibTime[1]);
	}
	void vibrate12()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[1],vibTime[2]);
	}
	void vibrate13()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[1],vibTime[3]);
	}

	
	//high
	void vibrate20()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[0],vibTime[0]);
	}
	void vibrate21()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[0],vibTime[1]);
	}
	void vibrate22()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[0],vibTime[2]);
	}
	void vibrate23()
	{
		if(storage.userData.vib)// && isValid)
		s3eVibraVibrate(vibForce[0],vibTime[3]);
	}


	
	//v-high
	void vibrate30()
	{
		if(storage.userData.vib)
			s3eVibraVibrate(vibForce[0],vibTime[0]);
	}
	void vibrate31()
	{
		if(storage.userData.vib)
			s3eVibraVibrate(vibForce[0],vibTime[1]);
	}
	void vibrate32()
	{
		if(storage.userData.vib)
			s3eVibraVibrate(vibForce[0],vibTime[2]);
	}
	void vibrate33()
	{
		if(storage.userData.vib)
			s3eVibraVibrate(vibForce[0],vibTime[3]);
	}
}vibrate;

#endif