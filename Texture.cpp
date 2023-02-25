#include "Texture.h"



Texture::Texture(std::string filePath) {

	if (filePath != "")
		texturePath = filePath;
	
}

void Texture::setTexture(std::string filePath) {

	texturePath = filePath;

}