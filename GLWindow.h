#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"



class GLWindow {

public:

	GLWindow();
	GLWindow(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle);
	virtual ~GLWindow() = default;

	const char* title;
	GLFWwindow* window;

	void (*run)(void);
	void update();
	void terminate();
	void bindRunFunction(void (*func)(void));
	
private:

	unsigned width;
	unsigned height;

	GLFWwindow* create();

};
