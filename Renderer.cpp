#include "Renderer.h"

Renderer::Renderer(GLWindow* glWindow) {

	GLBuffer buf;
	buffer = &buf;
	window = glWindow;

}


void Renderer::render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Render stuff
	glDrawArrays(GL_TRIANGLES, 0, buffer->freeSpace);
	//------------
	window->update();
	window->fpsBlock();
}


void Renderer::setBuffer(GLBuffer* glBuffer) {

	buffer = glBuffer;
}