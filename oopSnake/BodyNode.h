#pragma once

#include <algorithm>
#include "Object.h"
#include "Map.h"

/*
	* Class that represents the body part of the snake
	* Each body part stores a pointer to the next part.
	  If there's no body part ahead it points to nullptr
	* Child of Object
*/
class BodyNode : public Object
{
	// Next body part
	BodyNode* nextNode;

public:
	// Constructors/Destructors
	BodyNode(const int& xPos = 0, const int& yPos = 0,
		BodyNode* nextNode = nullptr);
	~BodyNode() {};

	// Overridden function with no implementation to keep the class non abstract
	void Spawn() override {};

	// Setting the next body part. It is needed when the next part is empty
	void setNextNode(BodyNode*);
	// Get what the current body part is pointing to (a next node)
	BodyNode* getNextNode() const;
};


