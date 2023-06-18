#include "Fruit.h"

Fruit::Fruit(const int& xPos, const int& yPos)
	: Object{ xPos, yPos }
{
	type = OBJECT_TYPE::FRUIT;
}

void Fruit::Spawn()
{
	xPos = rand() % 22 + 2;
	yPos = rand() % 97 + 2;
}
