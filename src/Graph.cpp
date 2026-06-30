#include "../include/Core/Graph.hpp"

using G = NavApp::Core::Graph;

void G::addIntersection(const Intersection& intersection) {
    if (m_vertices.contains(intersection.id)) return;
    m_vertices[intersection.id] = intersection;
}

void G::addRoadSegment(const RoadSegment& roadSegment) {
    if (m_adjacencyList.contains(roadSegment.sourceId) || m_adjacencyList.contains(destId)) return;
    m_adjacencyList[]
}
