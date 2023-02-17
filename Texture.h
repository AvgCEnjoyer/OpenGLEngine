#pragma once
#include <iostream>


class Texture {

public:

	Texture();
	virtual ~Texture() = default;

	void setTexture(std::string filePath);

private:

	float width;
	float height;


	std::string texturePath;

};