#include "GLWindow.h"


GLWindow::GLWindow(unsigned int windowWidth, unsigned int windowHeight, const char* windowTitle) {

	width = windowWidth;
	height = windowHeight;
    title = windowTitle;
	window = create();
}

GLWindow::GLWindow() {

    width = 800;
    height = 600;
    title = "My Window";
    window = create();
}

GLFWwindow* GLWindow::create() {

    GLFWwindow* window;

    if (!glfwInit())
        return NULL;

    window = glfwCreateWindow(1920, 1080, title, NULL, NULL);

    if (!window) {
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return NULL;

    return window;
}

void GLWindow::update() { 
    
    double lasttime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       
        if(*run != nullptr) run();


        glfwSwapBuffers(window);
        glfwPollEvents();

        while (glfwGetTime() < lasttime + 1.0 / 144) {}
        lasttime += 1.0 / 144;

    }
    terminate();

}

void GLWindow::bindRunFunction(void (*func)(void)) { 
    
    run = *func; 

}

void GLWindow::terminate() { 
    
    glfwTerminate(); 

}