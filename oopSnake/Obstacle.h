#pragma once

#include "Object.h"
#include <vector>

/*
	* Class that implements the behavior of the obstacles occuring on the map
	* Child of Object
*/
class Obstacle : public Object
{
private:
	// Vector stores all the obstacles that are being spawned
	std::vector<std::pair<int, int>> obstacles;

public:
	// Constructors/Destructors
	Obstacle();
	~Obstacle() {};

	// Overridden function to spawn an object and add it to obstacles
	void Spawn() override;

	// Check for the collision with the snake head
	bool CheckIfCollide(const std::pair<int, int>&) const;

	// Overridden funciton to load obstacles onto the map
	void LoadToMap() const override;
};

