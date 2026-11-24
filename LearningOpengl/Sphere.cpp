#include "Sphere.h"

std::vector<GLfloat> Sphere::getVertices() {
    std::vector<GLfloat> vertices;

    for (int i = 0; i <= rings; i++) {
        float v = static_cast<float>(i) / rings;
        float phi = glm::pi<float>() * v;

        for (int j = 0; j <= segments; j++) {
            float u = static_cast<float>(j) / segments;
            float theta = 2.0f * glm::pi<float>() * u;

            float x = radius * sin(phi) * cos(theta);
            float y = radius * cos(phi);
            float z = radius * sin(phi) * sin(theta);

            // Position
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(z);

            // UV
            vertices.push_back(u);
            vertices.push_back(v);
        }
    }

    return vertices;
}

std::vector<GLuint> Sphere::getIndices() {
    std::vector<GLuint> indices;

    for (int i = 0; i < rings; i++) {
        for (int j = 0; j < segments; j++) {
            GLuint topLeft = i * (segments + 1) + j;
            GLuint topRight = topLeft + 1;

            GLuint bottomLeft = (i + 1) * (segments + 1) + j;
            GLuint bottomRight = bottomLeft + 1;

            // First triangle
            indices.push_back(topLeft);
            indices.push_back(topRight);
            indices.push_back(bottomLeft);

            // Second triangle
            indices.push_back(topRight);
            indices.push_back(bottomRight);
            indices.push_back(bottomLeft);
        }
    }

    return indices;
}

Sphere::Sphere(float radius, int segments, int rings)
    : radius(radius),
    segments(segments),
    rings(rings),
    mesh(
        getVertices(),
        getIndices(),
        { V_Attrib::POS, V_Attrib::UV }
    )
{
}

void Sphere::Draw() {
    mesh.Draw();
}