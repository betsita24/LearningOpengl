#pragma once

#include <GL/glew.h>
#include <vector>
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

class Mesh {
private:
    VAO vao;
    VBO vbo;
    EBO ebo;
    GLsizei indexCount = 0;

public:
    Mesh(const std::vector<GLfloat>& vertices,
        const std::vector<GLuint>& indices);

    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void Draw() const;
};