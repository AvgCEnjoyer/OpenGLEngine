#pragma once
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>



class Camera3D {

public:
	Camera3D(glm::vec3 position, glm::vec3 target);
	virtual ~Camera3D() = default;

	glm::vec3 camPosition;
	glm::vec3 camDirection;
	glm::vec3 camTarget;

	glm::vec3 up;
	glm::vec3 camRight;
	glm::vec3 camUp;

	glm::mat4 view;

	void run(GLFWwindow& window);
	glm::mat4x4 getViewMatrix();

	//TODO
	//void updatePosition(float offsetX, float offSetY);
	//void setPosition(float positionX, float positionY);


private:


};


#define FUNCTIONS_H_INCLUDED
void mouseCallback(GLFWwindow* window, double xPos, double yPos); 
