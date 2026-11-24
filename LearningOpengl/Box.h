#pragma once
#include"Mesh.h"
class Box {
private:
	std::vector<GLfloat> static generateVertices();
	std::vector<GLuint> static generateIndices();

	Mesh mesh;
public:
	Box();
	void Draw();
};