#pragma once
#include<GL/glew.h>
#include<vector>

class EBO {
private:
	GLuint ID;
public:
	EBO(const std::vector<GLuint> data, GLenum usage);

	void Bind() const;
	void Unbind() const;
	void Delete() const;
};