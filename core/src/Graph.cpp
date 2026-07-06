#include "core/graph/Graph.hpp"

namespace core::graph {

bool Graph::addNode(const model::Node&) {
    return true;
}

bool Graph::addEdge(const model::Edge&) {
    return true;
}

bool Graph::removeNode(types::NodeId) {
    return true;
}

bool Graph::removeEdge(types::EdgeId) {
    return true;
}

} // namespace core::graph
