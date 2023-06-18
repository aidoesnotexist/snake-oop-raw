#include "Snake.h"

Snake::Snake()
	: length{ 1 }, cannibalism{ false }
{
	snakeHead = new BodyNode{ 12, 50 };
}

Snake::~Snake()
{
	BodyNode* _temp = snakeHead;
	while (_temp)
	{
		_temp = snakeHead->getNextNode();
		delete snakeHead;
		snakeHead = _temp;
	}
}

unsigned int Snake::size() const
{
	return length;
}

void Snake::AddNode()
{
	BodyNode* _temp = snakeHead;
	while (_temp->getNextNode() != nullptr)
		_temp = _temp->getNextNode();

	_temp->setNextNode(new BodyNode{});
	++length;
}

void Snake::DeleteNode()
{
	if (snakeHead == nullptr) {}

	else if (snakeHead->getNextNode() == nullptr)
	{
		delete snakeHead;
		snakeHead = nullptr;
	}
	else
	{
		BodyNode* temp = snakeHead;
		while (temp->getNextNode()->getNextNode() != nullptr)
			temp = temp->getNextNode();
		delete temp->getNextNode();
		temp->setNextNode(nullptr);
	}
	--length;
}

void Snake::LoadToMap()
{
	BodyNode* _temp = snakeHead;
	do {
		_temp->LoadToMap();
		_temp = _temp->getNextNode();
	} while (_temp != nullptr);
}

void Snake::Move(const DIRECTION& direction)
{
	std::pair<int, int> newPos;
	switch (direction)
	{
	case UPWARD:
		newPos = std::make_pair<int, int>(snakeHead->getPosition().first - 1,
			snakeHead->getPosition().second);
		break;
	case DOWNWARD:
		newPos = std::make_pair<int, int>(snakeHead->getPosition().first + 1,
			snakeHead->getPosition().second);
		break;
	case LEFT:
		newPos = std::make_pair<int, int>(snakeHead->getPosition().first,
			snakeHead->getPosition().second - 1);
		break;
	case RIGHT:
		newPos = std::make_pair<int, int>(snakeHead->getPosition().first,
			snakeHead->getPosition().second + 1);
		break;
	}
	targetPos = snakeHead->getPosition();
	snakeHead->setPosition(newPos);
}

void Snake::Slither()
{
	BodyNode* _temp = snakeHead;
	while (_temp->getNextNode() != nullptr)
	{
		std::pair<int, int> _tmpPos{ targetPos };
		targetPos = _temp->getNextNode()->getPosition();
		_temp->getNextNode()->setPosition(_tmpPos);

		if (Contains(_tmpPos))
		{
			cannibalism = true;
			break;
		}

		_temp = _temp->getNextNode();
	}
}

bool Snake::Contains(const std::pair<int, int>& position)
{
	return snakeHead->getPosition() == position;
}

BodyNode* Snake::getSnake() const
{
	return snakeHead;
}
