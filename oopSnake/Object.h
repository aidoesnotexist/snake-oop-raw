#pragma once

#include "Map.h"
#include "eCharacteristics.h"
#include <algorithm>

/*
	* Abstrat class
	* Prototype of everything that can be loaded onto the map
*/
class Object
{
protected:
	// Object position: X_axis, Y_axis
	int xPos;
	int yPos;

	OBJECT_TYPE type;
public:
	// Constructors/Destructors
	Object(const int& xPos = 0, const int& yPos = 0);
	virtual ~Object() {};

	// Pure virtual function for spawning an object in a random spot
	virtual void Spawn() = 0;

	// Functions to get/set object position
	virtual std::pair<int, int> getPosition() const;
	virtual void setPosition(const std::pair<int, int>& position);

	// Get the object type
	OBJECT_TYPE getType() const;

	// Function to load an object onto the map
	virtual void LoadToMap() const;
};