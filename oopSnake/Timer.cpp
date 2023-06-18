#include "Timer.h"

Timer::Timer() : started{ false },
delta{ std::chrono::seconds(0) } {}

void Timer::start()
{
	if (!started)
	{
		delta = std::chrono::steady_clock::now();
		started = true;
	}
}

void Timer::reset()
{
	delta = std::chrono::steady_clock::now();
}

std::chrono::seconds Timer::GetElapsedTime()
{
	return std::chrono::duration_cast<std::chrono::seconds>
		(std::chrono::steady_clock::now() - delta);
}
