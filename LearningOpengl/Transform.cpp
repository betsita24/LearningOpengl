#include "Transform.h"

glm::mat4 Transform::getMatrix() const {
    glm::mat4 model(1.0f);

    // Translation
    model = glm::translate(model, position);

    // Rotation
    model = glm::rotate(model, glm::radians(rotation.x),
        glm::vec3(1, 0, 0));

    model = glm::rotate(model, glm::radians(rotation.y),
        glm::vec3(0, 1, 0));

    model = glm::rotate(model, glm::radians(rotation.z),
        glm::vec3(0, 0, 1));

    // Scale
    model = glm::scale(model, scale);

    return model;
}