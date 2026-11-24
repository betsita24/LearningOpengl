#pragma once
#include"GL/glew.h"
#include"VBO.h"
#include"EBO.h"
#include"Enum.h"
//#include"GLFW/glfw3.h"


class VAO {
private:
	GLuint ID;
public:
	VAO(VBO& vbo, EBO& ebo, std::vector< V_Attrib> v_attributes);

	void Bind() const;
	void Unbind() const;
	void Delete() const;
};