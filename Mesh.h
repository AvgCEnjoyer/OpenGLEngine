#pragma once
#include <iostream>
#include <vector>
#include "glm/glm.hpp"
#include "GLFW/glfw3.h"
#include <sstream>
#include <fstream>


struct Entity {

	std::vector<glm::vec3> vertices;
	std::vector<int> faces; //Speichert indirekt alle Dreiecke des Objekts, durch kontinuierliche Speicherung der Faces => Ein Dreieck ist immer die i-te Folge von 3 Faces
							//Für die Dreiecke in vertices => Gehe gehe vertices |faces| mal durch. Speichere jede 3er Folge von Vertices ab.
};

class Mesh {

public:
	Mesh(std::string file);
	Mesh();
	virtual ~Mesh() = default;

	std::vector<glm::vec3> meshData;
	std::vector<Entity> meshEntities;
	std::vector<glm::vec3> getMeshDataBlender(std::string filePath);

};
