#pragma once 
#include "Intersection.hpp"
#include "RoadSegment.hpp"
#include <unordered_map>
#include <vector>

namespace NavApp::Core {

class Graph {
private:
    std::unordered_map<uint64_t, Intersection> m_vertices;
    std::unordered_map<uint64_t, std::vector<RoadSegment>> m_adjacencyList;
    
    const std::vector<RoadSegment> m_emptyEdges{};

public:
    Graph() = default;

    void addIntersection(const Intersection& intersection);
    void addRoadSegment(const RoadSegment& roadSegment);

    void clear();

    const Intersection* getIntersection(uint64_t id) const;
    const std::vector<RoadSegment>& getOutgoingEdges(uint64_t vertexId) const;
  
    const std::unordered_map<uint64_t, Intersection> getVertices() const;
};

}
