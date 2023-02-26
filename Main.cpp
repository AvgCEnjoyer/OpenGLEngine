#include "Core.h"
#include "Renderer.h"
#include "Runtime.h"
#include "Camera.h"

int main() {

	//Window
	GLWindow window = GLWindow(1920,1080, "Test");
	Renderer renderer = Renderer(&window);
    GLBuffer buffer = GLBuffer(1000);
	

	//Load World
    Mesh mesh = Mesh("TriiWorld.obj");

    for (int i = 0; i < mesh.meshData.size(); i++) {
        buffer.pushData(mesh.meshData.at(i));
    }

	//Textures
    std::string vShader = getFileShader("VertexShader.vert");
    std::string fShader = getFileShader("FragmentShader.frag");

    unsigned int shader = createShader(vShader, fShader);
    glUseProgram(shader);

    renderer.setBuffer(&buffer);


	//Camera
	Camera3D cam3d = Camera3D(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, -1.0f));
	glm::mat4x4 viewMatrix = cam3d.getViewMatrix();
	glfwSetInputMode(window.window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window.window, mouseCallback);


	glUniformMatrix4fv(0, 1, GL_FALSE, &viewMatrix[0][0]);

	glGetUniformLocation(shader, "MVP");
	glUniformMatrix4fv(shader, 1, GL_FALSE, &viewMatrix[0][0]);


	//Loop
	// TODO : Implement proper Runtime feature
	//Runtime game = Runtime(window.window, &renderer, &cam3d);
	//game.run();

	while (!glfwWindowShouldClose(window.window)) {

		cam3d.run(*window.window);
		glm::mat4x4 viewMatrix = cam3d.getViewMatrix();
		glUniformMatrix4fv(0, 1, GL_FALSE, &viewMatrix[0][0]);
		renderer.render();
		
	}

	terminate();

	return 0;
}

