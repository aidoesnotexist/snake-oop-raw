#pragma once

#include "Object.h"

/*
	* Class representing the food that the snake eats
	* Child of Object
*/
class Fruit : public Object
{
public:
	// Constructors/Destructors
	Fruit(const int& xPos = 0, const int& yPos = 0);
	~Fruit() {};

	// Overridden function for spawning the food
	void Spawn() override;
};

