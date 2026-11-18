#include "Floor.h"

Rectangle::Rectangle(float width, float height)
    : width(width),
    height(height),
    mesh(
        {
            -width / 2, -height / 2, 0.0f,
             width / 2, -height / 2, 0.0f,
             width / 2,  height / 2, 0.0f,
            -width / 2,  height / 2, 0.0f
        },
          {
              0, 1, 2,
              2, 3, 0
          }
    )
{
}

void Rectangle::Draw() const {
    mesh.Draw();
}