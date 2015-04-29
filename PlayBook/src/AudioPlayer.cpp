#include "AudioPlayer.h"
#include "IwResManager.h"
#include "s3e.h"
AudioPlayer::AudioPlayer()
{
}
void AudioPlayer::Terminate()
{
	s3eAudioStop();
}

void AudioPlayer::setVolume()
{
}

void AudioPlayer::playGameplay(bool id)
{
	if(!id)
		return;
	s3eAudioStop();
	char *cAudio[8];
	cAudio[0] = "./sound/gameplay/gameplay1.mp3";
	cAudio[1] = "./sound/gameplay/gameplay2.mp3";
	cAudio[2] = "./sound/gameplay/gameplay3.mp3";
	cAudio[3] = "./sound/gameplay/gameplay4.mp3";
	cAudio[4] = "./sound/gameplay/gameplay5.mp3";
	cAudio[5] = "./sound/gameplay/gameplay6.mp3";
	cAudio[6] = "./sound/gameplay/gameplay7.mp3";
	cAudio[7] = "./sound/gameplay/gameplay8.mp3";
	
	IwRandSeed((int32)s3eTimerGetMs());
	int no = IwRandMinMax(0,8);
	s3eAudioPlay(cAudio[no], 0);
}

void AudioPlayer::playMenu(bool id)
{
	if(!id)
		return;
	s3eAudioStop();
	char *cAudio[4];
	cAudio[0] = "./sound/menu/menu1.mp3";
	cAudio[1] = "./sound/menu/menu2.mp3";
	cAudio[2] = "./sound/menu/menu3.mp3";
	cAudio[3] = "./sound/credits/credits.mp3";
	
	IwRandSeed((int32)s3eTimerGetMs());
	int no = IwRandMinMax(0,4);
	s3eAudioPlay(cAudio[no], 0);
}

void AudioPlayer::playCredits(bool id)
{
	if(!id)
		return;
	s3eAudioStop();
	char *cAudio;
	cAudio = "./sound/credits/credits.mp3";
	
	//IwRandSeed((int32)s3eTimerGetMs());
	//int no = IwRandMinMax(0,3);
	s3eAudioPlay(cAudio, 0);
}

void AudioPlayer::stopMusic()
{
	s3eAudioStop();
}

int AudioPlayer::AudioStopCallback(void* systemData, void* userData)
{
    //g_Status = STATE_STOPPED;
    return 0;
}