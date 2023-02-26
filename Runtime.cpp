#pragma once
#include "Runtime.h"
#include "Camera.h"
#include <GLFW/glfw3.h>


Runtime::Runtime(GLFWwindow* glWindow, Renderer* glRenderer, Camera3D* cam3D) {

	renderer = glRenderer;
	camera = cam3D;
	window = glWindow;
}


void Runtime::run() {

	while (!glfwWindowShouldClose(renderer->window->window)) {

		renderer->render();
		camera->run(*window);
	}

	terminate();
}
