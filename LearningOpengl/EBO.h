#pragma once
#include<GL/glew.h>

class EBO {
private:
	GLuint ID;
public:
	EBO(const GLuint data[], GLsizeiptr size, GLenum usage);

	void Bind();
	void Unbind();
	void Delete();
};