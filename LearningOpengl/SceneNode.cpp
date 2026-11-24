#include "SceneNode.h"
#include <utility>

void SceneNode::setDrawFunction(std::function<void()> function) {
    drawFunction = std::move(function);
}

SceneNode* SceneNode::addChild(std::unique_ptr<SceneNode> child) {
    SceneNode* ptr = child.get();

    children.push_back(std::move(child));

    return ptr;
}

void SceneNode::Draw(
    const glm::mat4& parentMatrix,
    const std::function<void(const glm::mat4&)>& setModel)
{
    glm::mat4 worldMatrix = parentMatrix * transform.getMatrix();

    if (drawFunction) {
        setModel(worldMatrix);
        drawFunction();
    }

    for (auto& child : children) {
        child->Draw(worldMatrix, setModel);
    }
}  