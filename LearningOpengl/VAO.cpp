#include"VAO.h"

VAO::VAO(VBO &vbo,EBO &ebo, GLuint index, 
	GLsizei stride, const void* pointer) {
	glGenVertexArrays(1, &ID);
	Bind();
	vbo.Bind();
	ebo.Bind();
	glVertexAttribPointer(index, 3, GL_FLOAT, GL_FALSE, stride, pointer);
	glEnableVertexAttribArray(index);
}

void VAO::Bind() const{
	glBindVertexArray(ID);
}
void VAO::Unbind() const{
	glBindVertexArray(0);
}
void VAO::Delete() const{
	glDeleteVertexArrays(1, &ID);
}