#include"VAO.h"

VAO::VAO(VBO &vbo,EBO &ebo, std::vector< V_Attrib> v_attributes) {
	glGenVertexArrays(1, &ID);
	Bind();
	vbo.Bind();
	ebo.Bind();
	int stride{ 0 }, offset{ 0 };

	for (auto attrib : v_attributes) {
		if (attrib == V_Attrib::POS)
			stride += 3;
		else if (attrib == V_Attrib::COLOR)
		{
			stride += 3;
			offset += 3;
		}
		else {
			stride += 2;
			
		}

	}
	for(auto v : v_attributes){
		if (v == V_Attrib::POS) {
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*)0);
			glEnableVertexAttribArray(0);
		}
		if (v == V_Attrib::COLOR) {
			glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  stride * sizeof(GLfloat), (void*)(offset * sizeof(GLfloat)));
			glEnableVertexAttribArray(1);
		}
		if (v == V_Attrib::UV) {

			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride * sizeof(GLfloat), (void*)((offset +3)* sizeof(GLfloat)));
			glEnableVertexAttribArray(2);
		}
	}
	Unbind();
	
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