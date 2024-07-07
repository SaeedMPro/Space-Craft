#ifndef ROUTING_UNIT_HPP
#define ROUTING_UNIT_HPP
#include "spaceCraft.hpp"
#include "Map.hpp"

struct Cardinal {
    int x, y;
};


class RoutingUnit {

    public:
        RoutingUnit() {}
        ~RoutingUnit() {}

        int energy;
        Map currentMap;
        SpaceCraft craft;

    public:
       void navigate(Cardinal destination) {}

};

#endif