#pragma once
#include <iostream>


class Texture {

public:

	Texture(std::string filePath = "");
	virtual ~Texture() = default;

	void setTexture(std::string filePath);


private:

	std::string texturePath;

};