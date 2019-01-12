#pragma once
#include "Window.h"

class Timer
{
public:
	Timer();
	void Start();
	void Stop();
	void Resume();
	void Clear();
	int GetTimerTicks();
	bool IsRunning() { return running; };

private:
	int pTicks, sTicks;
	bool running;
};
