#include "BodyNode.h"

BodyNode::BodyNode(const int& xPos, const int& yPos, BodyNode* nextNode) : Object{ xPos, yPos }
{
	type = OBJECT_TYPE::SNAKE_BODY;
}

void BodyNode::setNextNode(BodyNode* nextNode)
{
	this->nextNode = nextNode;
}

BodyNode* BodyNode::getNextNode() const
{
	return nextNode;
}
