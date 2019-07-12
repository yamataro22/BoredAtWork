#pragma once

#include <glm/glm.hpp>

class Object
{
protected:
	static glm::mat4 PrepareModelMatrix(const glm::vec2& position, float rotation, const glm::vec2& scale);
public:
	virtual ~Object() = default;

	virtual glm::mat4 GetModelMatrix() = 0;
};
