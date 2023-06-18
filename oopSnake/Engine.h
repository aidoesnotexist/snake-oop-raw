#pragma once

#include "Map.h"
#include "Snake.h"
#include "Fruit.h"
#include "Obstacle.h"
#include "eCharacteristics.h"
#include "Timer.h"
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <mutex>

/*
	* Class that represents the gameplay logic
*/
class Engine
{
	// Objects
	Map* map;
	Snake* snake;
	Fruit* fruit;
	Obstacle* obstacle;

	DIRECTION direction, nextMove;
	Timer timer;
	int time;

public:
	// Constructors/Destructors
	Engine();
	~Engine();

	// Reads the user's keyboard input while playing
	void updateKeyboardInput();
	// Checks whether the input was correct (e.g. player cannot move right if the snake moves left)
	void CheckCorrectInput();

	/*
		Updating the snake logic:
		* head turns
		* 'slithering' - when the rest of the body follows the head
		* checks if head eats its body
	*/
	void updateSnake();

	// If fasle Game Over
	bool running;

	/*
		Updating all game logic
	*/
	void Update();
	// Displaying the map
	void Render();
};

