#pragma once

#include <memory>


namespace core::graph
{
class Graph;
}


namespace algorithms
{
class IPathFinder;
}


namespace application
{

class NavigationService;
class RuntimeGeometryProvider;


class ApplicationBootstrap
{
public:

    ApplicationBootstrap();

    ~ApplicationBootstrap();


    NavigationService& navigationService();


private:

    std::unique_ptr<core::graph::Graph> graph;

    std::unique_ptr<algorithms::IPathFinder> pathFinder;

    std::unique_ptr<RuntimeGeometryProvider> geometryProvider;

    std::unique_ptr<NavigationService> service;
};

}
