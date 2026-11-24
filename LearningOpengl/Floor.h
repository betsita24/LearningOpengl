#pragma once

#include "Mesh.h"

class Floor {
private:
    
    std::vector<GLfloat> static generateVertices();
    std::vector<GLuint> static generateIndices();

    Mesh mesh;

public:
    Floor();

    void Draw() const;
};