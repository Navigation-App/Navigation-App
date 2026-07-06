#pragma once

#include <QMainWindow>

class QGraphicsView;
class QGraphicsScene;
class SceneController;
class MapRenderer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private:
    void setupUi();
    void setupScene();

private:
    QGraphicsView* view = nullptr;
    QGraphicsScene* scene = nullptr;

    SceneController* sceneController = nullptr;
    MapRenderer* renderer = nullptr;
};
