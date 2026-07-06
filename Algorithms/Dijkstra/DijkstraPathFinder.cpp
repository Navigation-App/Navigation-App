#include "DijkstraPathFinder.hpp"

#include <queue>
#include <unordered_map>
#include <vector>
#include <limits>

#include <core/model/Route.hpp>
#include <core/graph/Graph.hpp>
#include <core/model/Edge.hpp>

using Cost = double;

struct NodeState
{
    core::NodeId node;
    Cost cost;

    bool operator>(const NodeState& other) const
    {
        return cost > other.cost;
    }
};

core::model::Route DijkstraPathFinder::findPath(
    const core::graph::Graph& graph,
    core::NodeId source,
    core::NodeId destination) const
{
    core::model::Route result;

    // Edge case: same node
    if (source == destination)
    {
        result.nodes = {source};
        result.totalDistance = 0.0;
        return result;
    }

    constexpr Cost INF = std::numeric_limits<Cost>::infinity();

    std::priority_queue<
        NodeState,
        std::vector<NodeState>,
        std::greater<NodeState>
    > pq;

    std::unordered_map<core::NodeId, Cost> dist;
    std::unordered_map<core::NodeId, core::NodeId> parent;

    // Initialization
    dist[source] = 0.0;
    pq.push({source, 0.0});

    while (!pq.empty())
    {
        auto [current, currentCost] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (currentCost > dist[current])
            continue;

        // Early exit
        if (current == destination)
            break;

        // Read-only adjacency access
        const auto& neighbors = graph.getNeighbors(current);

        for (const auto& edge : neighbors)
        {
            core::NodeId next = edge.to;
            Cost weight = edge.weight;

            Cost newCost = currentCost + weight;

            if (!dist.count(next) || newCost < dist[next])
            {
                dist[next] = newCost;
                parent[next] = current;
                pq.push({next, newCost});
            }
        }
    }

    // No path found
    if (!dist.count(destination))
    {
        result.nodes.clear();
        result.totalDistance = INF;
        return result;
    }

    // Reconstruct path
    std::vector<core::NodeId> path;
    core::NodeId current = destination;

    while (true)
    {
        path.push_back(current);

        if (current == source)
            break;

        current = parent[current];
    }

    std::reverse(path.begin(), path.end());

    result.nodes = std::move(path);
    result.totalDistance = dist[destination];

    return result;
}
