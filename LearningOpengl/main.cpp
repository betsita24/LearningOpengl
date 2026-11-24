#include"GL/glew.h"
#include"GLFW/glfw3.h"
#include"glm/glm.hpp"
#include<iostream>
#include<vector>


#include"Shader.h"
#include"Floor.h"
#include"Enum.h"
#include"Box.h"
#include"Cylinder.h"
#include"Camera.h"
#include"Sphere.h"
#include"SceneNode.h"
//used to resize the viewport when a user changes the window size
void resize_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() {
	//Initialize glfw and set important settings (configure)
	if (!glfwInit()) {
		std::cerr << "GLFW is not initialized!!!" << std::endl;
		glfwTerminate();
		return 1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Create window and make it the current context
	GLFWwindow* window = glfwCreateWindow(800, 800, "TossingBot", NULL, NULL);
	if (!window) {
		std::cerr << "Window is not created!!!" << std::endl;
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);


	//Initialize glew
	if (glewInit() != GLEW_OK) {
		std::cerr << "GLEW is not initialized!!!" << std::endl;
		glfwTerminate();
		return 1;
	}
	glViewport(0, 0, 800, 800); //x,y lower left corner of the window




	Shader f_shader("f_vertex.vs", "f_fragment.fs");
	Floor floor{};


	Shader shader("vertex.vs", "fragment.fs");
	Cylinder box{};

	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	Camera camera(cameraPos, cameraTarget,cameraUp);

	Box body;
	Sphere head;

	SceneNode robot;

	auto bodyNode = std::make_unique<SceneNode>();

	bodyNode->transform.scale = glm::vec3(1.0f, 1.5f, 0.5f);
	bodyNode->setDrawFunction([&]() {
		body.Draw();
		});

	auto headNode = std::make_unique<SceneNode>();

	headNode->transform.position = glm::vec3(0.0f, 1.2f, 0.0f);
	headNode->transform.scale = glm::vec3(0.4f);
	headNode->setDrawFunction([&]() {
		head.Draw();
		});

	SceneNode* bodyPtr = robot.addChild(std::move(bodyNode));
	bodyPtr->addChild(std::move(headNode));


	glfwSetFramebufferSizeCallback(window, resize_callback);

	glClearColor(1.0f, 0.9f, 0.2f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	//Render loop

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(window);
		camera.processKeyboard(window);
		float time=static_cast<float>(glfwGetTime());
		float greenColor = glm::sin(time) / 2.0f + 0.5f;

		glm::mat4 view=camera.getViewMatrix();

		glm::mat4 projection = glm::perspective(
			glm::radians(45.0f),
			800.0f / 800.0f,
			0.1f,
			100.0f
		);

		shader.use();

		robot.Draw(glm::mat4(1.0f), [&](const glm::mat4& model) {
			shader.setMat4("model", model);
			});
		/*b_shader.use();
		b_shader.setFloat("color", greenColor);
		b_shader.setMat4("view", view);
		b_shader.setMat4("projection", projection);
		box.Draw();

		f_shader.use();*/
		//floor.Draw();
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//clearing up


	glfwTerminate();
	return 0;
}