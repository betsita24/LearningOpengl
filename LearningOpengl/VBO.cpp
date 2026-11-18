#include"VBO.h"

VBO::VBO(const std::vector<GLfloat>& vertices, GLenum usage) {
	glGenBuffers(1, &ID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, vertices.size() *sizeof(GLfloat),  
		vertices.data(), usage);
}

void VBO::Bind() const{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}
void VBO::Unbind() const {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void VBO::Delete() const {
	glDeleteBuffers(1, &ID);
}