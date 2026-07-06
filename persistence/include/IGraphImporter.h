#pragma once 

class IGraphImporter
{
public:
    virtual ~IGraphImporter() = default;

    [[nodiscard]]
    Graph import(const std::filesystem::path& file) = 0;
};
