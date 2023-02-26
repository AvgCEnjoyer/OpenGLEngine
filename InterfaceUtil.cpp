#include "InterfaceUtil.h"
#include "Texture.h"



InterfaceElement::InterfaceElement(std::string text, Mesh objectMesh, bool isClickable) {

	clickable = isClickable;
	mesh = objectMesh;
	fontSize = 12;

}


std::vector<glm::vec3> InterfaceElement::getVertices() {

	return mesh.meshData;

}


void InterfaceElement::setLabelText(std::string text, int size) {

	labelText = text;
	fontSize = size;

}


void InterfaceElement::setClickFunction(void* func) {

	clickFunction = func;

}


void InterfaceElement::setTexture(std::string filePath) {

	Texture tex = Texture(filePath);

}


void InterfaceElement::update() {

	//TODO : Mouse Collision Detection

}
