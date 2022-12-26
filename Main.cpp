#include "FileUtil.h"
#include "GLWindow.h"
#include "GLBuffer.h"

float angle = 0.0f;

void running() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glRotatef(angle, 0.0f, 1.0f, 1.0f);

	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();

	glPopMatrix();
	angle += 0.5f;
}

int main() {

	File file = File();
	GLBuffer buffer = GLBuffer();
	GLWindow window = GLWindow(1920,1080, "Test");

	window.bindRunFunction(*running);
	window.update();

	return 0;
}