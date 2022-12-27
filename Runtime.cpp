#pragma once
#include "Runtime.h"


Runtime::Runtime(Renderer* glRenderer) {

	renderer = glRenderer;

}


void Runtime::run() {

	while (!glfwWindowShouldClose(renderer->window->window)) {

		renderer->render();
	}

	terminate();
}
