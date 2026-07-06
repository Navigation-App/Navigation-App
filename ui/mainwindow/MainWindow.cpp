#include "MainWindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>

#include "../controllers/SceneController.h"
#include "../rendering/MapRenderer.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setupUi();
    setupScene();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUi()
{
    view = new QGraphicsView(this);
    setCentralWidget(view);
}

void MainWindow::setupScene()
{
    scene = new QGraphicsScene(this);
    view->setScene(scene);

    // Empty canvas ONLY
    scene->setSceneRect(-500, -500, 1000, 1000);

    sceneController = new SceneController(scene);
    renderer = new MapRenderer(scene);
}
