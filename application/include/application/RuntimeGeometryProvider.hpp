#pragma once

#include "application/INodeGeometryProvider.hpp"


namespace application
{

class RuntimeGeometryProvider final
    : public INodeGeometryProvider
{

public:

    RuntimeGeometryProvider() = default;


    std::optional<Coordinate> getCoordinate(
        core::types::NodeId nodeId
    ) const override;

};

}
