cmake_minimum_required(VERSION 3.16)

project(NavigationSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---------------- CORE ----------------
add_library(core
    core/src/Graph.cpp
    core/src/Node.cpp
    core/src/Edge.cpp
    core/src/Route.cpp
)

target_include_directories(core PUBLIC
    ${CMAKE_SOURCE_DIR}/core/include
)

# ---------------- ALGORITHMS ----------------
add_library(algorithms
    Algorithms/Dijkstra/DijkstraPathFinder.cpp
    Algorithms/AStar/AStarPathFinder.cpp
    Algorithms/Factory/PathFinderFactory.cpp
)

target_include_directories(algorithms PUBLIC
    ${CMAKE_SOURCE_DIR}/Algorithms
)

target_link_libraries(algorithms core)

# ---------------- PERSISTENCE ----------------
add_library(persistence
    persistence/src/GeoJSONImporter.cpp
    persistence/src/GeoJSONParser.cpp
    persistence/src/GraphBuilder.cpp
    persistence/src/RoadFeatureExtractor.cpp
    persistence/src/JsonGraphSerializer.cpp
)

target_include_directories(persistence PUBLIC
    ${CMAKE_SOURCE_DIR}/persistence/include
)

target_link_libraries(persistence core)

# ---------------- UI (optional build) ----------------
add_executable(ui_app
    ui/mainwindow/MainWindow.cpp
    ui/controllers/SceneController.cpp
    ui/rendering/MapRenderer.cpp
)

target_link_libraries(ui_app core algorithms persistence)

# ---------------- TEST (optional) ----------------
enable_testing()
