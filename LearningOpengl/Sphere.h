#pragma once
#pragma once
#include"Mesh.h"
#include<vector>
#include <glm/gtc/constants.hpp>
#include<glm/glm.hpp>


class Sphere {
private:
	float radius;
	int segments;
	int rings;

	std::vector<GLfloat> getVertices();
	std::vector<GLuint> getIndices();

	Mesh mesh;

public:
	Sphere(float radius = 0.5f, int segments = 32, int rings = 16);
	void Draw();
};