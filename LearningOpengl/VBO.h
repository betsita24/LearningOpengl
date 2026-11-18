#pragma once
#include<GL/glew.h>

class VBO {
private:
	GLuint ID;
public:
	VBO(const GLfloat vertices[], GLsizeiptr size, GLenum usage);
	


	void Bind();
	void Unbind();
	void Delete();
};