#pragma once

class Graph;

class IGraphSerializer
{
public:
    virtual ~IGraphSerializer() = default;

    virtual void serialize(const Graph& graph) = 0;
    virtual void deserialize(Graph& graph) = 0;
};
