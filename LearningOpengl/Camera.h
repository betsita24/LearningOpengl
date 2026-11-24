#pragma once
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
	glm::vec3 cameraPos;
	glm::vec3 cameraTarget;
	glm::vec3 cameraUp;
	glm::vec3 cameraFront;
public:
	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3 cameraTarget = glm::vec3(0.0, 0.0, 0.0),
		glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 getViewMatrix();
	void processKeyboard(GLFWwindow *wiindow);

};