#include "application/ApplicationBootstrap.hpp"

#include "application/NavigationService.hpp"
#include "application/RuntimeGeometryProvider.hpp"

#include <core/graph/Graph.hpp>

#include <Factory/PathFinderFactory.hpp>
#include <Types/AlgorithmType.hpp>


namespace application
{

ApplicationBootstrap::ApplicationBootstrap()
{
    graph =
        std::make_unique<core::graph::Graph>();


    pathFinder =
        PathFinderFactory::create(
            AlgorithmType::Dijkstra
        );


    geometryProvider =
        std::make_unique<RuntimeGeometryProvider>();


    service =
        std::make_unique<NavigationService>(
            *graph,
            std::move(pathFinder),
            *geometryProvider
        );
}


ApplicationBootstrap::~ApplicationBootstrap() = default;


NavigationService&
ApplicationBootstrap::navigationService()
{
    return *service;
}

}
