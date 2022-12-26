#include "FileUtil.h"
#include "GLWindow.h"
#include "GLBuffer.h"


void running() {

	return;
}

int main() {

	File file = File();
	GLBuffer buf = GLBuffer();
	GLWindow window = GLWindow(1920,1080, "Test");

	window.bindRunFunction(*running);
	window.update();

	return 0;
}