#include"EBO.h"
#include<iostream>

void CheckGLErrors(const char* location)
{
    GLenum error;

    while ((error = glGetError()) != GL_NO_ERROR)
    {
        std::cerr << "OpenGL error at "
            << location << ": "
            << error << std::endl;
    }
}
EBO::EBO(const std::vector<GLuint>& data, GLenum usage)
{
    CheckGLErrors("Before EBO Generate");

    glGenBuffers(1, &ID);

    CheckGLErrors("After EBO Generate");

    Bind();
    CheckGLErrors("EBO Bind");

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        data.size() * sizeof(GLuint),
        data.data(),
        usage
    );
    CheckGLErrors("EBO Upload");
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