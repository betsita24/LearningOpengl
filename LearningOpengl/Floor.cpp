#include "Floor.h"


std::vector<GLfloat> Floor::generateVertices() {
    
    std::vector<GLfloat> vertices;

            vertices.push_back(-0.5);
            vertices.push_back(0.5);
            vertices.push_back(0);
            vertices.push_back(0);
            vertices.push_back(1);

            vertices.push_back(0.5);
            vertices.push_back(0.5);
            vertices.push_back(0);
            vertices.push_back(1);
            vertices.push_back(1);

            vertices.push_back(-0.5);
            vertices.push_back(-0.5);
            vertices.push_back(0);
            vertices.push_back(0);
            vertices.push_back(0);

            vertices.push_back(0.5);
            vertices.push_back(-0.5);
            vertices.push_back(0);
            vertices.push_back(1);
            vertices.push_back(0);

    
    return vertices;
}

std::vector<GLuint> Floor::generateIndices() {
    std::vector<GLuint> indices;
    

            indices.push_back(0);
            indices.push_back(2);
            indices.push_back(1);

            indices.push_back(1);
            indices.push_back(2);
            indices.push_back(3);
     
    return indices;
}

Floor::Floor()
    :mesh(
        generateVertices(),
        generateIndices(),
        {V_Attrib::POS,V_Attrib::UV}
    ) 
{
    
}

void Floor::Draw() const {
    mesh.Draw();
}