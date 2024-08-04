#ifndef ROUTING_UNIT_HPP
#define ROUTING_UNIT_HPP

#include "Map.hpp"
#include "SpaceCraft.hpp"
#include "Cardinal.hpp"

class Map;
class SpaceCraft;

class RoutingUnit {
    public:
        RoutingUnit() {}
        ~RoutingUnit() {}

        Map* currentMap;
        SpaceCraft* craft;

    public:
        void startRU();
        int minimumPath(vector<vector<string>> possiblePath, vector<double> pathsIndex);
};

#endif
