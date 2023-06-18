#include "Map.h"

std::vector<std::vector<OBJECT_TYPE>> Map::map;

Map::Map()
{
	map = std::vector<std::vector<OBJECT_TYPE>>{ WIDTH,
		std::vector<OBJECT_TYPE>(HEIGHT, OBJECT_TYPE::BLANK) };
}

void Map::loadObjectToMap(const std::pair<int, int>& position, const OBJECT_TYPE& type)
{
	map.at(position.first).at(position.second) = type;
}
void Map::clear()
{
	for (auto& item : map)
		for (auto& object : item)
			if (object != OBJECT_TYPE::BLANK && object != OBJECT_TYPE::OBSTACLE)
				object = OBJECT_TYPE::BLANK;
}

void Map::Draw()
{
	for (const auto& item : map)
	{
		for (const auto& object : item)
		{
			if (&item - &map[0] == 0 ||
				&item - &map[0] == WIDTH - 1)
				std::cout << '#';

			else if (&object - &item[0] == 0 ||
				&object - &item[0] == HEIGHT - 1)
				std::cout << '#';

			else
			{
				switch (object)
				{
				case OBJECT_TYPE::BLANK:
					std::cout << ' ';
					break;
				case OBJECT_TYPE::SNAKE_BODY:
					std::cout << '$';
					break;
				case OBJECT_TYPE::FRUIT:
					std::cout << '@';
					break;
				case OBJECT_TYPE::OBSTACLE:
					std::cout << '#';
					break;
				}
			}
		}
		std::cout << std::endl;
	}
}
