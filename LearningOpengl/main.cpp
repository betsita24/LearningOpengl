#include"GL/glew.h"
#include"GLFW/glfw3.h"
#include"glm/glm.hpp"
#include<iostream>


#include"Shader.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

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


	//vertex data for triangle
	GLfloat vertices[]{
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.5f,0.5f,0.0f,
		-0.5f,0.5f,0.0f
	};
	GLuint indices[]{
		0,1,2,
		2,3,0
	};




	VBO vbo(vertices,sizeof(vertices), GL_STATIC_DRAW);
	EBO ebo(indices, sizeof(vertices) ,GL_STATIC_DRAW);
	VAO vao(vbo,ebo,0, 3 * sizeof(GLfloat), (void*)0);
	
	Shader shader("vertex.vs", "fragment.fs");


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
		vao.Bind();
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	//clearing up


	glfwTerminate();
	return 0;
}