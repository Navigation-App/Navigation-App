#pragma once

#include "../Interfaces/IPathFinder.hpp"

class DijkstraPathFinder : public IPathFinder
{
public:
    core::model::Route findPath(
        const core::graph::Graph& graph,
        core::NodeId source,
        core::NodeId destination) const override;
};
