#include "Camera.h"



Camera3D::Camera3D(glm::vec3 position, glm::vec3 target) {

	camPosition = position;
	camTarget = target;
	camDirection = glm::normalize(camPosition - camTarget); //Richtung : [Origo -> Camera]

	up = glm::vec3(0.0f, 1.0f, 0.0f);
	camRight = glm::normalize(glm::cross(up, camDirection)); //Kreuzprodukt VektorNachOben x KameraRichtung gibt die Richtung der positiven x-Achse als Ergebnis 
	camUp = glm::cross(camDirection, camRight);

	view = glm::lookAt(camPosition, camTarget, camUp);
}


glm::mat4x4 Camera3D::getViewMatrix() {

	glm::mat4x4 view = glm::lookAt(camPosition, camTarget, camUp);
	glm::mat4x4 Projection = glm::perspective(glm::radians(90.0f), (float)1920 / (float)1080, 0.1f, 100.0f);

	return Projection * view;
}