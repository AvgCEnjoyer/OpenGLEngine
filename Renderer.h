#pragma once
#include "Core.h"
#include <glm/gtc/matrix_transform.hpp>

class Renderer {

public:
	Renderer(GLWindow* glfwWindow);
	virtual ~Renderer() = default;

	void render();
	void setBuffer(GLBuffer* glBuffer);

	GLBuffer* buffer;
	GLWindow* window;

};