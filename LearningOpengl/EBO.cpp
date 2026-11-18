#include"EBO.h"

EBO::EBO(const std::vector<GLuint> data, GLenum usage) {
	glGenBuffers(1, &ID);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size()*sizeof(GLuint),  data.data(), usage);
}

void EBO::Bind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}
void EBO::Unbind() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void EBO::Delete() const {
	glDeleteBuffers(1, &ID);
}