#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <time.h>
#include "IwRandom.h"

static class AudioPlayer
{
	//int iVolume;
	//bool isMute;
	//game
	//menu
public:
/*	enum PlayerState
	{
		STATE_PLAYING,
		STATE_PAUSED,
		STATE_STOPPED
	};*/

	AudioPlayer();
	void Terminate();
	void setVolume();
	void playGameplay(bool id);
	void playMenu(bool id);
	void playCredits(bool id);
	void stopMusic();

	int AudioStopCallback(void* systemData, void* userData);

}audioPlayer;

#endif