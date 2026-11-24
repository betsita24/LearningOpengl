#pragma once

#include "Transform.h"
#include <functional>
#include <memory>
#include <vector>

class SceneNode {
private:
    std::vector<std::unique_ptr<SceneNode>> children;
    std::function<void()> drawFunction;

public:
    Transform transform;

    void setDrawFunction(std::function<void()> function);

    SceneNode* addChild(std::unique_ptr<SceneNode> child);

    void Draw(const glm::mat4& parentMatrix,
        const std::function<void(const glm::mat4&)>& setModel);
};