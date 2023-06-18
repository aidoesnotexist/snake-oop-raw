#include "Obstacle.h"

Obstacle::Obstacle()
{
	type = OBJECT_TYPE::OBSTACLE;
}

void Obstacle::Spawn()
{
	xPos = rand() % 22 + 2;
	yPos = rand() % 97 + 2;

	obstacles.push_back(std::make_pair<const int&,
		const int&>(xPos, yPos));
}

bool Obstacle::CheckIfCollide(const std::pair<int, int>& snakeHead) const
{
	for (const auto& item : obstacles)
		if (item == snakeHead)
			return true;
	return false;
}

void Obstacle::LoadToMap() const
{
	for (const auto& item : obstacles)
		Map::loadObjectToMap(item, type);
}

