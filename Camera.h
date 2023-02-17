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

	glm::mat4x4 getViewMatrix();

	//TODO
	//void updatePosition(float offsetX, float offSetY);
	//void setPosition(float positionX, float positionY);


private:


};

/*
float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 0;
float lastY = 0;

bool firstMouse = false;

glm::vec3 ncamTarget = glm::vec3(0.0f, 0.0f, -1.0f);

void mouseCallback(GLFWwindow* window, float xPos, float yPos); */
