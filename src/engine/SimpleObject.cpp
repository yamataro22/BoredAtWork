#include "SimpleObject.h"

SimpleObject::SimpleObject() : position(0), rotation(0), scale(1)
{}

glm::mat4 SimpleObject::GetModelMatrix()
{
	return PrepareModelMatrix(position, rotation, scale);
}

void SimpleObject::SetPosition(glm::vec2 newPos)
{
	position = newPos;
}

void SimpleObject::SetPosition(float x, float y)
{
	position = glm::vec2(x, y);
}

void SimpleObject::SetRotation(float rot)
{
	rotation = rot;
}

void SimpleObject::SetScale(glm::vec2 newScale)
{
	scale = newScale;
}

void SimpleObject::SetScale(float newScale)
{
	scale = glm::vec2(newScale);
}

void SimpleObject::SetScale(float xScale, float yScale)
{
	scale = glm::vec2(xScale, yScale);
}

glm::vec2 SimpleObject::GetPosition() const
{
	return position;
}

float SimpleObject::GetRotation() const
{
	return rotation;
}

glm::vec2 SimpleObject::GetScale() const
{
	return scale;
}
