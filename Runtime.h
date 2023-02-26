#pragma once
#include "Core.h"
#include "Renderer.h"
#include "Camera.h"
#include <GLFW/glfw3.h>


class Runtime {

public:

	Runtime(GLFWwindow* window, Renderer* glRenderer, Camera3D* cam3D);
	virtual ~Runtime() = default;

	Renderer* renderer;
	Camera3D* camera;
	GLFWwindow* window;
	void run();
};