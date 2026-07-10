#include "MapRenderer.h"

#include <application/RoutePresentationData.hpp>


MapRenderer::MapRenderer(
    QGraphicsScene* scene
)
    :
    scene(scene)
{
}


void MapRenderer::renderRoute(
    const application::RoutePresentationData& route
)
{
    Q_UNUSED(route);

    if(!scene)
        return;

    scene->update();
}


void MapRenderer::clearRoute()
{
    if(!scene)
        return;

    scene->clear();
}
