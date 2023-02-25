#pragma once
#include "Mesh.h"

class Body {

public:

	Body(float x, float y, float z, Mesh objectMesh);
	virtual ~Body() = default;


private:

	float xPos; float yPos; float zPos;
	Mesh mesh;
};