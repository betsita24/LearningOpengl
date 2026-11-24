#pragma once

#include <GL/glew.h>
#include <vector>
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

class Mesh {
private:
    
    VBO vbo;
    EBO ebo;
    VAO vao;
    GLsizei indexCount = 0;

public:
    Mesh(const std::vector<GLfloat>& vertices,
        const std::vector<GLuint>& indices,
        const std::vector<V_Attrib>& attributes);

    ~Mesh();

    Mesh(const Mesh&) = delete;
    Mesh& operator=(const Mesh&) = delete;

    void Draw() const;
};