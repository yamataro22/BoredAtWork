#pragma once

#include "Object.h"

class SimpleObject :
	public Object
{
protected:
	glm::vec2 position;
	float rotation;
	glm::vec2 scale;

public:
	SimpleObject();

	// Inherited via Object
	glm::mat4 GetModelMatrix() override;

	//setters
	void SetPosition(glm::vec2 newPos);
	void SetPosition(float x, float y);
	void SetRotation(float rot);
	void SetScale(glm::vec2 newScale);
	void SetScale(float newScale);
	void SetScale(float xScale, float yScale);

	//getters
	glm::vec2 GetPosition() const;
	float GetRotation() const;
	glm::vec2 GetScale() const;
};
