#pragma once

#include <memory>

#include "../Interfaces/IPathFinder.hpp"
#include "../Types/AlgorithmType.hpp"

class PathFinderFactory
{
public:
    [[nodiscard]]
    static std::unique_ptr<IPathFinder>
    create(AlgorithmType algorithm);
};
