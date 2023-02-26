#include "Camera.h"

float yaw = -90.0f;
float pitch = 0.0f;
float lastX = 0;
float lastY = 0;

bool firstMouse = false;

glm::vec3 ncamTarget = glm::vec3(0.0f, 0.0f, -1.0f);


Camera3D::Camera3D(glm::vec3 position, glm::vec3 target) {

	camPosition = position;
	camTarget = target;
	camDirection = glm::normalize(camPosition - camTarget); //Richtung : [Origo -> Camera]

	up = glm::vec3(0.0f, 1.0f, 0.0f);
	camRight = glm::normalize(glm::cross(up, camDirection)); //Kreuzprodukt VektorNachOben x KameraRichtung gibt die Richtung der positiven x-Achse als Ergebnis 
	camUp = glm::cross(camDirection, camRight);

	view = glm::lookAt(camPosition, camTarget, camUp);
}


void Camera3D::run(GLFWwindow& window) {

	float sensitivity = 0.05f;

	if (glfwGetKey(&window, GLFW_KEY_A) == GLFW_PRESS) {
		camPosition -= glm::normalize(glm::cross(camTarget, camUp)) * sensitivity;
	}
	if (glfwGetKey(&window, GLFW_KEY_D) == GLFW_PRESS) {
		camPosition += glm::normalize(glm::cross(camTarget, camUp)) * sensitivity;
	}
	if (glfwGetKey(&window, GLFW_KEY_W) == GLFW_PRESS) {
		camPosition += sensitivity * camTarget;
	}
	if (glfwGetKey(&window, GLFW_KEY_S) == GLFW_PRESS) {
		camPosition -= sensitivity * camTarget;
	}

	camTarget = glm::normalize(ncamTarget);
	camUp = glm::cross(camDirection, camRight);
	view = glm::lookAt(camPosition, camPosition + camTarget, camUp);
}


glm::mat4x4 Camera3D::getViewMatrix() {

	glm::mat4x4 view = glm::lookAt(camPosition, camPosition + camTarget, camUp);
	glm::mat4x4 Projection = glm::perspective(glm::radians(90.0f), (float)1920 / (float)1080, 0.1f, 100.0f);

	return Projection * view;
}


void mouseCallback(GLFWwindow* window, double xpos, double ypos) {

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	ncamTarget = glm::normalize(direction);
}