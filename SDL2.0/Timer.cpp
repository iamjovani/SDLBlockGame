#include"Timer.h"

Timer::Timer()
{
	sTicks = 0;
	pTicks = 0;
	running = false;
}
void Timer::Start()
{
	running = true;
	sTicks = SDL_GetTicks();
	return;
}
void Timer::Stop()
{
	if (running == true)
	{
		running = false;
		pTicks = SDL_GetTicks() - sTicks;
	}
	return;
}
void Timer::Resume()
{
	if (running == false)
	{
		running = true;
		sTicks = SDL_GetTicks() - pTicks;
		pTicks = 0;
	}
	return;
}
void Timer::Clear()
{
	running = false;
	sTicks = 0;
	pTicks = 0;
	return;
}
int Timer::GetTimerTicks()
{
	if (running == true)
	{
		return (SDL_GetTicks() - sTicks);
	}
	return 0;
}
