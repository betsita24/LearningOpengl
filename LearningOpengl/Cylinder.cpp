#include"Cylinder.h"
std::vector<GLfloat> Cylinder::getVertices() {
    std::vector<GLfloat> vertices;

    // SIDE VERTICES
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * glm::pi<float>() * i / segments;

        float x = radius * cos(angle);
        float z = radius * sin(angle);
        float u = static_cast<float>(i) / segments;

        // Bottom
        vertices.push_back(x);
        vertices.push_back(-height / 2.0f);
        vertices.push_back(z);
        vertices.push_back(u);
        vertices.push_back(0.0f);

        // Top
        vertices.push_back(x);
        vertices.push_back(height / 2.0f);
        vertices.push_back(z);
        vertices.push_back(u);
        vertices.push_back(1.0f);
    }

    // TOP CENTER
    vertices.push_back(0.0f);
    vertices.push_back(height / 2.0f);
    vertices.push_back(0.0f);
    vertices.push_back(0.5f);
    vertices.push_back(0.5f);

    // TOP CIRCLE
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * glm::pi<float>() * i / segments;

        float x = radius * cos(angle);
        float z = radius * sin(angle);

        vertices.push_back(x);
        vertices.push_back(height / 2.0f);
        vertices.push_back(z);
        vertices.push_back(0.5f + 0.5f * cos(angle));
        vertices.push_back(0.5f + 0.5f * sin(angle));
    }

    // BOTTOM CENTER
    vertices.push_back(0.0f);
    vertices.push_back(-height / 2.0f);
    vertices.push_back(0.0f);
    vertices.push_back(0.5f);
    vertices.push_back(0.5f);

    // BOTTOM CIRCLE
    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * glm::pi<float>() * i / segments;

        float x = radius * cos(angle);
        float z = radius * sin(angle);

        vertices.push_back(x);
        vertices.push_back(-height / 2.0f);
        vertices.push_back(z);
        vertices.push_back(0.5f + 0.5f * cos(angle));
        vertices.push_back(0.5f - 0.5f * sin(angle));
    }

    return vertices;
}
std::vector<GLuint> Cylinder::getIndices() {
    std::vector<GLuint> indices;

    GLuint topCenter = 2 * (segments + 1);
    GLuint topStart = topCenter + 1;

    GLuint bottomCenter = topStart + segments;
    GLuint bottomStart = bottomCenter + 1;

    for (int i = 0; i < segments; i++) {
        GLuint bottom = 2 * i;
        GLuint top = bottom + 1;

        GLuint nextBottom = bottom + 2;
        GLuint nextTop = bottom + 3;

        // SIDE
        indices.push_back(bottom);
        indices.push_back(top);
        indices.push_back(nextBottom);

        indices.push_back(top);
        indices.push_back(nextTop);
        indices.push_back(nextBottom);

        // TOP CAP
        indices.push_back(topCenter);
        indices.push_back(topStart + i);
        indices.push_back(topStart + (i + 1) % segments);

        // BOTTOM CAP
        indices.push_back(bottomCenter);
        indices.push_back(bottomStart + (i + 1) % segments);
        indices.push_back(bottomStart + i);
    }

    return indices;
}
Cylinder::Cylinder(float radius,float height,int segments)
	:radius(radius),height(height),segments(segments),mesh(
	getVertices(),getIndices(),{V_Attrib::POS,V_Attrib::UV})
{}
void Cylinder::Draw() {
	mesh.Draw();
}