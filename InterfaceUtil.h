#pragma once
#include "GLBuffer.h"
#include "Texture.h"

#include <GLFW/glfw3.h>
#include <iostream>


class InterfaceElement {

public:

	InterfaceElement(bool isClickable);
	virtual ~InterfaceElement() = default;

	void* clickFunction;

	void setLabelText(std::string text = "", int size = 0);

	void setClickFunction(void* func);
	void onClick();

	void setTexture(std::string filePath);


private:

	float width;
	float height;

	Texture* texture;
	float texCoords[];

};

void engineUIBootUp(GLBuffer buffer);
void attachUIElement(GLBuffer buffer);