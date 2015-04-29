#ifndef TRANSTION2D_H
#define TRANSTION2D_H
#include "iostream.h"
#include "Iw2D.h"

class Transitions2D
{
private:
	enum DIR
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		FLIP
	};

	static bool isUsingPrivateTextures;

	static void Slide(DIR d, uint8 transitionSpeed, bool skipFirstAndLastFrame);

public:
	static CIwTexture* mStartTexture;
	static CIwTexture* mEndTexture;
	static CIwTexture* CaptureScreen();
	static CIwTexture* CaptureScreenWOUpload();
	static CIw2DImage* CaptureScreenBuffer();
	static void CaptureStartScreen();
	static void CaptureEndScreen();
	static void Release();
	static void Fade(uint8 transitionSpeed = 20, bool skipFirstAndLastFrame = false);
	static void Fade(CIwTexture* start, CIwTexture* end, uint8 transitionSpeed = 20, bool skipFirstAndLastFrame = false);
	static void SlideLeft(uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void SlideLeft(CIwTexture* start, CIwTexture* end, uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void SlideRight(uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void SlideRight(CIwTexture* start, CIwTexture* end, uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void SlideUp(uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void SlideUp(CIwTexture* start, CIwTexture* end, uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void SlideDown(uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void FlipUp(uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
	static void SlideDown(CIwTexture* start, CIwTexture* end, uint8 transitionSpeed = 30, bool skipFirstAndLastFrame = false);
};

#endif