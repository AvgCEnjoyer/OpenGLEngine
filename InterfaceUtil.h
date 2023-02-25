#pragma once
#include "GLBuffer.h"
#include "Texture.h"
#include "Mesh.h"

#include <GLFW/glfw3.h>
#include <iostream>


class InterfaceElement {

public:

	InterfaceElement(std::string text = "", Mesh objectMesh = Mesh(), bool isClickable = false);
	

	virtual ~InterfaceElement() = default;

	std::vector<glm::vec3> getVertices();

	void setLabelText(std::string text = "", int size = 0);
	void setClickFunction(void* func);
	void setTexture(std::string filePath);

	void update();


private:

	Mesh mesh;

	bool clickable;
	void* clickFunction;
	
	std::string labelText;
	int fontSize;

	Texture* texture;
	float texCoords[];

};
