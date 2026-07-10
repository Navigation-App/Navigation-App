#pragma once

#include <QMainWindow>

#include <QString>

namespace application
{
class NavigationService;
class RoutePresentationData;
}

class QGraphicsScene;
class QGraphicsView;

class SceneController;
class MapRenderer;
class NavigationController;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(
        application::NavigationService& navigationService,
        QWidget* parent = nullptr
    );

    ~MainWindow() override = default;


private slots:

    void onRouteReady(
        const application::RoutePresentationData& route
    );

    void onNavigationFailed(
        const QString& message
    );


private:

    QGraphicsScene* scene;

    QGraphicsView* graphicsView;

    SceneController* sceneController;

    NavigationController* navigationController;

    MapRenderer* mapRenderer;
};
