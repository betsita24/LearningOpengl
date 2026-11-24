#pragma once
#include"Mesh.h"
#include<vector>
#include <glm/gtc/constants.hpp>
#include<glm/glm.hpp>


class Cylinder {
private:
	float radius;
	float height;
	int segments;

	std::vector<GLfloat> getVertices();
	std::vector<GLuint> getIndices();

	Mesh mesh;

public:
	Cylinder(float radius = 0.5, float height=1.0,int segments=32);

	void Draw();
};