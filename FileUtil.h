#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

class File {

public:
	File();

};


std::string loadFile(std::string path);
void saveFile(std::string path);

