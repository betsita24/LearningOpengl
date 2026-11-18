#include"EBO.h"

EBO::EBO(const GLuint data[], GLsizeiptr size, GLenum usage) {
	glGenBuffers(1, &ID);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, usage);
}

void EBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}
void EBO::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void EBO::Delete() {
	glDeleteBuffers(1, &ID);
}