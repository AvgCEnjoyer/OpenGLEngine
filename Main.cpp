#include "Core.h"
#include "Renderer.h"
#include "Runtime.h"

int main() {

	GLWindow window = GLWindow(1920,1080, "Test");
	Renderer renderer = Renderer(&window);
	Runtime game = Runtime(&renderer);
    GLBuffer buffer = GLBuffer(1000);

    Mesh mesh = Mesh("TriiWorld.obj");

    for (int i = 0; i < mesh.meshData.size(); i++) {
        buffer.pushData(mesh.meshData.at(i));
    }

    std::string vShader = getFileShader("VertexShader.vert");
    std::string fShader = getFileShader("FragmentShader.frag");

    unsigned int shader = createShader(vShader, fShader);
    glUseProgram(shader);

    renderer.setBuffer(&buffer);

	//Kamera Stuff
	glm::vec3 camTarget = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 camPosition = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 camDirection = glm::normalize(camPosition - camTarget);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 camRight = glm::normalize(glm::cross(up, camDirection));
	glm::vec3 camUp = glm::cross(camDirection, camRight);
	glm::mat4x4 view = glm::lookAt(camPosition, camTarget, camUp);
	glm::mat4x4 Projection = glm::perspective(glm::radians(90.0f), (float)1920 / (float)1080, 0.1f, 100.0f);
	glm::mat4x4 viewMatrix = Projection * view;

	glUniformMatrix4fv(0, 1, GL_FALSE, &viewMatrix[0][0]);

	glGetUniformLocation(shader, "MVP");
	glUniformMatrix4fv(shader, 1, GL_FALSE, &viewMatrix[0][0]);

	game.run();

	return 0;
}

