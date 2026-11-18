#pragma once

#include "Mesh.h"

class Rectangle {
private:
    float width;
    float height;
    Mesh mesh;

public:
    Rectangle(float width, float height);

    void Draw() const;
};