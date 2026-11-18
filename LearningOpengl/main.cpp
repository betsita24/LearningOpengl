#include"GL/glew.h"
#include"GLFW/glfw3.h"
#include"glm/glm.hpp"
#include<iostream>
#include<vector>


#include"Shader.h"
#include"Floor.h"


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




	Shader shader("vertex.vs", "fragment.fs");
	Rectangle rectangle(1.0f, 0.5f);

	glfwSetFramebufferSizeCallback(window, resize_callback);

	glClearColor(1.0, 0.9, 0.2, 1.0);
	glEnable(GL_DEPTH_TEST);
	//Render loop
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(window);

		float time=glfwGetTime();
		float greenColor = glm::sin(time) / 2.0f + 0.5f;

		shader.use();
		shader.setFloat("color", greenColor);
		rectangle.Draw();
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//clearing up


	glfwTerminate();
	return 0;
}