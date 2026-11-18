#pragma once
#include<GL/glew.h>
#include<vector>

class VBO {
private:
	GLuint ID;
public:
	VBO(const std::vector<GLfloat>& vertices, GLenum usage);
	


	void Bind() const;
	void Unbind() const;
	void Delete() const;
};