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

void VAO::Bind() {
	glBindVertexArray(ID);
}
void VAO::Unbind() {
	glBindVertexArray(0);
}
void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}