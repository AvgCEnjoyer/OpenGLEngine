#pragma once
#include "GL/glew.h"
#include <glm/glm.hpp>
#include "GLFW/glfw3.h"

class GLBuffer {

public:
	GLBuffer();
	GLBuffer(int n);
	virtual ~GLBuffer() = default;


	unsigned int getBuffer();
	unsigned int getNextSpace();

	void push();
	void pop();
	float pushData(glm::vec3 data);



private:

	unsigned int freeSpace;
	unsigned int bufferID;


};
