#include "application/RuntimeGeometryProvider.hpp"


namespace application
{


std::optional<Coordinate>
RuntimeGeometryProvider::getCoordinate(
    core::types::NodeId nodeId
) const
{
    return Coordinate{
        static_cast<double>(nodeId),
        static_cast<double>(nodeId)
    };
}


}
