#pragma once

#include "application/INodeGeometryProvider.hpp"

namespace application
{

class RuntimeGeometryProvider final
    : public INodeGeometryProvider
{
public:

    std::optional<Coordinate> getCoordinate(
        core::types::NodeId nodeId
    ) const override
    {
        return Coordinate{
            static_cast<double>(nodeId),
            static_cast<double>(nodeId)
        };
    }

};

}
