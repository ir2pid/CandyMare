#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H

#include "IwSound.h"
#include "s3eThread.h"
#include "storage.h"


static class SoundPlayer
{
	CIwResGroup* SoundGroup;
public:


	void construct()
	{
		mount();
		// Init IwSound
		IwSoundInit();
		#ifdef IW_BUILD_RESOURCES
		// Tell resource system how to convert WAV files
		IwGetResManager()->AddHandler(new CIwResHandlerWAV);
		#endif
		IwGetResManager()->LoadGroup("./sound.group");
		SoundGroup = IwGetResManager()->GetGroupNamed("sound");
		unmount();
	}

	void destruct()
	{
		IwGetResManager()->DestroyGroup("sound"); 
		IwSoundTerminate();
	}

	void update()
	{
		IwGetSoundManager()->Update();
	}

	void playPress()
	{
		if(!storage.userData.snd)
			return;
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed("button", IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();
		//unmount();
	}
	void playSwipe()
	{
		if(!storage.userData.snd)
			return;
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed("swipe", IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();
		//unmount();
	}
	void playScroll()
	{
		if(!storage.userData.snd)
			return;
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed("scroll", IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();
		//unmount();
	}
	void playEnd()
	{
		if(!storage.userData.snd)
			return;
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed("end", IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();
		//unmount();
	}
	void playStar()
	{
		if(!storage.userData.snd)
			return;
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed("star", IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();
		//unmount();
	}
	void playToxicated()
	{
		if(!storage.userData.snd)
			return;
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed("toxicated", IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();
		//unmount();
	}
	void playTeleport()
	{
		if(!storage.userData.snd)
			return;
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed("teleport", IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();
		//unmount();
	}
	
	void playEndTalk()//uint16 *talkID)
	{
		if(!storage.userData.snd)
		{
			//talkID = 0;
			return;
		}
		//cout<<"\n\ngo talk at end";
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		IwRandSeed((int32)s3eTimerGetMs());
		int id = IwRandMinMax(1,13);

		char tmp[6];
		sprintf(tmp,"end%d",id);

		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed(tmp, IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play();//Play(NULL,talkID);
		//unmount();
	}

	void playTalk(uint16 *talkID)
	{
		if(!storage.userData.snd)
		{
			talkID = 0;
			return;
		}
		//cout<<"\n\ngo talk a li'l";
		//mount();
		IwGetResManager()->SetCurrentGroup(SoundGroup);
		IwRandSeed((int32)s3eTimerGetMs());
		int id = IwRandMinMax(1,67);

		char tmp[3];
		sprintf(tmp,"%d",id);

		CIwSoundSpec* SoundSpec = (CIwSoundSpec*)SoundGroup->GetResNamed(tmp, IW_SOUND_RESTYPE_SPEC);
		CIwSoundInst* SoundInstance = SoundSpec->Play(NULL,talkID);
		//unmount();
	}

	void mount()
	{
		dzArchiveAttach("./dataSound.ninja");
	}
	void unmount()
	{
		dzArchiveDetach();
	}

}soundPlayer;

#endif