#pragma once

#include <chrono>

// Class that represents ingame timer
class Timer
{
	// Variables
	bool started;
	std::chrono::steady_clock::time_point delta;

public:
	// Constructors/Destructors
	Timer();
	~Timer() {};

	// Stars the countdown
	void start();
	// Resets the starting point
	void reset();

	// Returns the elapsed time since start ot reset
	std::chrono::seconds GetElapsedTime();
};

