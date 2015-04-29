#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include "notification.h"
#include "util.h"

class NotificationSystem
{
	CIwArray<Notification> pNotify;
	CIwArray<CIw2DImage*> pIcon;
	

	int framePosX;
	int objPosXY;//iconx,y,texty
	int textPosX;
	CIwSVec2 textRegion;

public:

	NotificationSystem()
	{
		
	}	

	~NotificationSystem()
	{
		
	}
	void construct()
	{
		CIw2DImage* icon = util.getTexture("notify/arrow2knee.png");
		//CIw2DImage* pFrame = util.getTexture("notify/frame.png");	
		
		framePosX = (util.widthDisplay-util.pNotificationFrame->GetWidth())/2;	
		objPosXY = (util.pNotificationFrame->GetHeight()-icon->GetHeight())/2;
		textPosX = framePosX+(3*objPosXY)+icon->GetWidth();
		textRegion.x = util.pNotificationFrame->GetWidth()-icon->GetWidth()-(5*objPosXY);
		textRegion.y = util.pNotificationFrame->GetHeight()-(2*objPosXY);

		//delete pFrame;pFrame = NULL;
		delete icon;icon = NULL;
	}

	void destruct()
	{
		while(pNotify.size()>0)
		{
			pNotify[0].destruct();
			pNotify.erase(0);			
		}
		for(int i=0;i<pIcon.size();i++)
		{
			delete pIcon[i];
		}
		pIcon.clear_optimised();
		pNotify.clear_optimised();
		//cout<<"\npNotify size "<<pNotify.size();

		/*if(layout.pNotificationFrame != NULL)
			delete layout.pNotificationFrame;layout.pNotificationFrame = NULL;*/
		
		pIcon.clear_optimised();
	}

	void update()
	{
		////cout<<"\nin notification";
		
		if(pNotify.size() == 0)
		{
			for(int i=0;i<pIcon.size();i++)
			{
				delete pIcon[i];
			}
			pIcon.clear_optimised();
		}
		else
		{	
			if(!pNotify[0].update())
			{
				pNotify[0].destruct();
				pNotify.erase(0);
				delete pIcon[0];
				pIcon.erase(0);
			}
		}
	}

	void render()
	{
		for(int i=0;i<pNotify.size();i++)
		{
			pNotify[0].render(framePosX,objPosXY,textPosX,textRegion,util.pNotificationFrame,pIcon[0]);
		}
	}	

	void pushNotification(int id)
	{//1/"arrow2knee.png",2/"BabyLevel.png",3/"GlobeTrotter.png",4/"LevelCompleted.png",
	 //5/"MedicineMan.png",6/"MushroomJunkie.png",7/"NewLevel.png",8/"NewTheme.png",
	 //9/"NoTeleport.png",10/"shortestpath.png",11/"Quitter.png",12/"StarCollector.png",
	 //13/"StarLost.png",14/"TeleportLandmark.png",15/"ThemeCompleted.png",16/"ToxicFinish.png",
	 //17/AllStars.png,18/"perfect level",19/"noToxication",20/"nomedic",21/"noshroom";
		
		char *icon,*title;

		icon = getIcon(id);

		title = getTitle(id);
		
		pIcon.push_back(util.getTexture(icon));
						
		Notification n;
		n.construct(title,util.pNotificationFrame);
		pNotify.push_back(n);
	}
	void pushFeed(char *feedText)
	{
		char *icon,*title;

		icon = "notify/Talk.png";

		title = feedText;
		
		pIcon.push_back(util.getTexture(icon));
						
		Notification n;
		n.construct(title,util.pNotificationFrame);
		pNotify.push_back(n);
	}
	char* quitTaunts()
	{
		IwRandSeed((int32)s3eTimerGetMs());
		int quoteid = IwRandMinMax(1,42);

		switch(quoteid)
		{
			case 1:{
				return "Those who quit don't get candy.";
				break;
				}
			case 2:{
				return "A pro doesn't settle with one less candy. "; 
				break;
				}
			case 3:{
				return "Our lives revolve around candy.";
				break;
				}
			case 4:{
				return "Candy time is over?";
				break;
				}
			case 5:{
				return "It only tastes sweet if you earned it.";
				break;
				}
			case 6:{
				return "Munching candy is good excersise";
				break;
				}
			case 7:{
				return "Blame urself, I'll blame u too.";
				break;
				}
			case 8:{
				return "Valuabe things r getting left behind!";
				break;
				}
			case 9:{
				return "Friend or candy? Restart n I'll tell u.";
				break;
				}
			case 10:{
				return "Play again n the bad feeling will go bye bye.";
				break;
				}
			case 11:{
				return "I'm not judging you...Quitter !";
				break;
				}
			case 12:{
				return "U need cheatcodes ??";
				break;
				}
			case 13:{
				return "I love it, I crave it, I want it!";
				break;
				}
			case 14:{
				return "I didn't quit, U quit on me !";
				break;
				}
			case 15:{
				return "Quit and it becomes a habit...";
				break;
				}
			case 16:{
				return "Not enough sweet in the world.";
				break;
				}
			case 17:{
				return "Ur kidding right? Inexplicable!";
				break;
				}
			case 18:{
				return "Nobody wins..we r 2 loosers...super";
				break;
				}
			case 19:{
				return "Get back in it candy trooper!";
				break;
				}
			case 20:{
				return "You might have to sweat to get sweet.";
				break;
				}
			case 21:{
				return "It is never too late to get that candy back!";
				break;
				}
			case 22:{
				return "If opportunity doesn't knock, build a door.";
				break;
				}
			case 23:{
				return "Winning isn't everything, as long as u got candy!";
				break;
				}
			case 24:{
				return "Candy is fuel to the furnace of joy!";
				break;
				}
			case 25:{
				return "To reach a port, we must sail.";
				break;
				}
			case 26:{
				return "Go back a little to leap further.";
				break;
				}
			case 27:{
				return "It is hard to fail, but it is worse never to have tried.";
				break;
				}
			case 28:{
				return "Failed on way to success ? So try again.";
				break;
				}
			case 29:{
				return "Every failure brings with it less candy to munch on.";
				break;
				}
			case 30:{
				return "Every artist was first an amateur.";
				break;
				}
			case 31:{
				return "There is only one success, and it revolves around a candy!";
				break;
				}
			case 32:{
				return "Success is sweet, I know all about it :)";
				break;
				}
			case 33:{
				return "Impatience never commanded success and got you a candy";
				break;
				}
			case 34:{
				return "Success is the sum of small efforts, repeated day in and day out.";
				break;
				}
			case 35:{
				return "Remember to wax on and wax off.";
				break;
				}
			case 36:{
				return "No man ever got Candy by chance.";
				break;
				}
					
			case 37:{
				return "Do, or do not. There is no \"try\"";
				break;
				}
			case 38:{
				return "Practice gets candy";
				break;
				}
			case 39:{
				return "A life without candy, is a life without candy.";
				break;
				}
			case 40:{
				return "Every story has a candy at the end..";
				break;
				}
			case 41:{
				return "Where there's Candy, there's a way.";
				break;
				}
					
			default:{
				return "Where there's Candy, there's a way.";
				break;
				}

					
		}
		return 0;
	}
	char* getTitle(int id)
	{
		if(id == 1)
			return quitTaunts();
		else if(id == 2)
			return "Baby Steps!";
		else if(id == 3)
			return "New GlobeTrotter Landmark!";
		else if(id == 4)
			return "Level Completed!";
		else if(id == 5)
			return "New MedicineMan Landmark!";
		else if(id == 6)
			return "New MushroomJunkie Landmark!";
		else if(id == 7)
			return "New Level Unlocked!";
		else if(id == 8)
			return "New Theme Unlocked!";
		else if(id == 9)
			return "No Teleportation Used Achivement!";
		else if(id == 10)
			return "Shortest path taken!";
		else if(id == 11)
			return "Habitual Quitter Landmark";
		else if(id == 12)
			return "Star Collector Landmark";
		else if(id == 13)
			return "Stars Lost Landmark";
		else if(id == 14)
			return "Teleport Landmark";
		else if(id == 15)
			return "Theme Completed!";
		else if(id == 16)
			return "Toxic Finish!";
		else if(id == 17)
			return "All 3 Stars!";
		else if(id == 18)
			return "Perfect Level!";
		else if(id == 19)
			return "Avoided Toxic mushrooms Achivement!";
		else if(id == 20)
			return "Avoided Medic mushrooms Achivement!";
		else if(id == 21)
			return "Avoided All mushrooms Achivement!";
		else if(id == 22)
			return "Theme pack 1 finished!";
		else if(id == 23)
			return "Toxic Finish Landmark";
		else
			return "WTF I DUNNO!";
	}

	char* getIcon(int id)
	{
		if(id == 1)
			return "notify/arrow2knee.png";
		else if(id == 2)
			return "notify/BabyLevel.png";
		else if(id == 3)
			return "notify/GlobeTrotter.png";
		else if(id == 4)
			return "notify/LevelCompleted.png";
		else if(id == 5)
			return "notify/MedicineMan.png";
		else if(id == 6)
			return "notify/MushroomJunkie.png";
		else if(id == 7)
			return "notify/NewLevel.png";
		else if(id == 8)
			return "notify/NewTheme.png";
		else if(id == 9)
			return "notify/NoTeleport.png";
		else if(id == 10)
			return "notify/ShortestPath.png";
		else if(id == 11)
			return "notify/Quitter.png";
		else if(id == 12)
			return "notify/StarCollector.png";
		else if(id == 13)
			return "notify/StarLost.png";
		else if(id == 14)
			return "notify/TeleportLandmark.png";
		else if(id == 15)
			return "notify/ThemeCompleted.png";
		else if(id == 16)
			return "notify/ToxicFinish.png";
		else if(id == 17)
			return "notify/AllStar.png";
		else if(id == 18)
			return "notify/PerfectLevel.png";
		else if(id == 19)
			return "notify/noToxic.png";
		else if(id == 20)
			return "notify/noMedic.png";
		else if(id == 21)
			return "notify/noShroom.png";
		else if(id == 22)
			return "notify/all3theme.png";
		else if(id == 23)
			return "notify/ToxicFinish.png";
		else
			return "notify/empty.png";

	}

}notificationSystem;
#endif