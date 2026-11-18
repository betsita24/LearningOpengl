#include "Mesh.h"

Mesh::Mesh(const std::vector<GLfloat>& vertices,
    const std::vector<GLuint>& indices)
    : vbo(vertices, GL_STATIC_DRAW), 
    ebo(indices, GL_STATIC_DRAW),
    vao(vbo, ebo, 0, 3 * sizeof(GLfloat), (void*)0),
    indexCount(static_cast<GLsizei>(indices.size()))
{
 
}

Mesh::~Mesh() {
    vao.Delete();
    vbo.Delete();
    ebo.Delete();
}

void Mesh::Draw() const {
    vao.Bind();
    glDrawElements(GL_TRIANGLES, indexCount,
        GL_UNSIGNED_INT, nullptr);
    vao.Unbind();
}