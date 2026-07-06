#pragma once

#include <memory>

#include <core/graph/Graph.hpp>
#include <core/model/Route.hpp>
#include <core/types/Types.hpp>

class IPathFinder
{
public:
    virtual ~IPathFinder() = default;

    [[nodiscard]]
    virtual core::Route findPath(
        const core::Graph& graph,
        core::NodeId source,
        core::NodeId destination) const = 0;
};
