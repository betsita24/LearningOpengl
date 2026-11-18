#pragma once
#include"GL/glew.h"
#include"VBO.h"
#include"EBO.h"
//#include"GLFW/glfw3.h"
class VAO {
private:
	GLuint ID;
public:
	VAO(VBO& vbo, EBO& ebo, GLuint index, 
		GLsizei stride, const void* pointer);

	void Bind() const;
	void Unbind() const;
	void Delete() const;
};