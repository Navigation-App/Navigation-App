#pragma once
#include <vector>
#include <cstdint>

namespace NavApp::Core {
struct Route {
    std::vector<uint64_t> nodeIds;
    double totalDistance{0.0};
    bool isFound{false};

    void clear() {
        nodeIds.clear();
        totalDistance = 0.0;
        isFound = false
    }
};

}
