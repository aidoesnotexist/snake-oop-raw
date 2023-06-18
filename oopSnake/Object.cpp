#include "Object.h"

Object::Object(const int& xPos, const int& yPos)
    : xPos{ xPos }, yPos{ yPos }, type{ OBJECT_TYPE::BLANK } {}

std::pair<int, int> Object::getPosition() const
{
    return std::make_pair<const int&, const int&>(xPos, yPos);
}

void Object::setPosition(const std::pair<int, int>& position)
{
    xPos = position.first;
    yPos = position.second;
}

OBJECT_TYPE Object::getType() const
{
    return type;
}

void Object::LoadToMap() const
{
    Map::loadObjectToMap(std::make_pair<const int&, const int&>(xPos, yPos), type);
}
