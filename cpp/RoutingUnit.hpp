#ifndef ROUTING_UNIT_HPP
#define ROUTING_UNIT_HPP

#include "Map.hpp"
#include "SpaceCraft.hpp"
#include "Cardinal.hpp"


class RoutingUnit {
    public:
        RoutingUnit() {}
        ~RoutingUnit() {}

        int energy;
        Map currentMap;
        SpaceCraft craft;

    public:
        void startRU();
        void navigate(Cardinal destination);
};

#endif
