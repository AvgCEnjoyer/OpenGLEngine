#pragma once
#include "FileUtil.h"


File::File() {}

std::string loadFile(std::string path) {

	std::string content;
	std::ifstream fileStream(path, std::ios::in);

	std::string line = "";

	if (!fileStream.is_open()) {
		std::cerr << "Could not read file " << path << ". File does not exist." << std::endl;
		return "";
	}

	while (!fileStream.eof()) {
		std::getline(fileStream, line);
		content.append(line + "\n");
	}
	fileStream.close();

	return content;

}

void saveFile(std::string path) { //TODO

	return;

}