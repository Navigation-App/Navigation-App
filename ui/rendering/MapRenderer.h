#pragma once

#include <QGraphicsScene>

namespace application
{
class RoutePresentationData;
}


class MapRenderer
{
public:

    explicit MapRenderer(
        QGraphicsScene* scene
    );


    void renderRoute(
        const application::RoutePresentationData& route
    );


    void clearRoute();


private:

    QGraphicsScene* scene;
};
