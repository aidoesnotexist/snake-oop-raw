#pragma once

#include "eCharacteristics.h"
#include <iostream>
#include <vector>

#define WIDTH 25
#define HEIGHT 100

/*
	* Class that represents the map of the game
*/
class Map
{
	// Map is represented as the static 2d vector
	static std::vector<std::vector<OBJECT_TYPE>> map;

public:
	//Cunstructors/Destructors
	Map();
	~Map() {};

	// Placing the object onto the map
	static void loadObjectToMap(const std::pair<int, int>&, const OBJECT_TYPE&);
	// Clears the map by turning all the elements back to OBJECT_TYPE::BLANK
	static void clear();

	// Draws the map: $ - snake, @ - fruit, # - obstacle or outline bounds
	void Draw();
};

