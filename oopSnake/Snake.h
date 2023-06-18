#pragma once

#include "BodyNode.h"

/*
	* Class that inplements the behavior of the snake
	* The class itself stores only the snake's head
*/
class Snake
{
	// Size
	unsigned int length;
	// Head of the snake, it is body part as all the next parts
	BodyNode* snakeHead;

	// Stores the location coordinates where the snake will turn
	std::pair<int, int> targetPos;

public:
	// Constructors/Destructors
	Snake();
	~Snake();

	// Variable that stores the denotation whether the snake eats itself
	bool cannibalism;
	// Get snake length
	unsigned int size() const;

	// Adding a new part of the snake
	void AddNode();
	// Deleting the last part
	void DeleteNode();
	// Loading the snake onto the map
	void LoadToMap();

	// Function to turn the snake head in a certain direction
	void Move(const DIRECTION&);
	// Funtion that makes the snake body follow its head
	void Slither();

	// Checking if the head intersects with the food
	bool Contains(const std::pair<int, int>& position);

	// Get a snake head
	BodyNode* getSnake() const;
};

