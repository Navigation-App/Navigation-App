#pragma once

class QGraphicsScene;

class SceneController
{
public:
    explicit SceneController(QGraphicsScene* scene);
    ~SceneController() = default;

    SceneController(const SceneController&) = delete;
    SceneController& operator=(const SceneController&) = delete;

private:
    QGraphicsScene* scene = nullptr;
};

