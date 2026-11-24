#include"Camera.h"

Camera::Camera(glm::vec3 cameraPos,
    glm::vec3 cameraTarget,
    glm::vec3 cameraUp)
    :cameraPos(cameraPos), cameraTarget(cameraTarget), cameraUp(cameraUp)
{
    cameraFront = glm::normalize(cameraTarget- cameraPos);
}
glm::mat4 Camera::getViewMatrix(){
    return glm::lookAt(cameraPos, cameraPos+cameraFront, cameraUp);
}
void Camera::processKeyboard(GLFWwindow* window){
    const float cameraSpeed = 0.00005f;
    const float wSpeed = 0.00003f;
    const float rotationSpeed = 0.00001f;// adjust accordingly
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    // Rotate around X-axis
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        glm::mat4 rotation = glm::rotate(
            glm::mat4(1.0f), rotationSpeed, glm::vec3(0, 1, 0)
        );
        cameraFront = glm::normalize(glm::vec3(rotation * glm::vec4(cameraFront, 0.0f)));
    }

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        glm::mat4 rotation = glm::rotate(
            glm::mat4(1.0f), -rotationSpeed, glm::vec3(0, 1, 0)
        );
        cameraFront = glm::normalize(glm::vec3(rotation * glm::vec4(cameraFront, 0.0f)));
    }
}