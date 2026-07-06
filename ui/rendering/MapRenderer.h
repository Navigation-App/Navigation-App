#pragma once

class QGraphicsScene;

class MapRenderer
{
public:
    explicit MapRenderer(QGraphicsScene* scene);
    ~MapRenderer() = default;

    MapRenderer(const MapRenderer&) = delete;
    MapRenderer& operator=(const MapRenderer&) = delete;

private:
    QGraphicsScene* scene = nullptr;
};
