#ifndef PHENOMENON_HPP
#define PHENOMENON_HPP

#include "RoutingUnit.hpp"

class Wormhole {
    public:
        Wormhole() {}
        ~Wormhole() {}

    public:
        Cardinal start;
        Cardinal end;
};

class SpaceObject {
    public:
        SpaceObject() {}
        ~SpaceObject() {}

    public:
        Cardinal pos1;
        Cardinal pos2;
        Cardinal pos3;
        Cardinal pos4;
};

class SpaceCurrent {
    public:
        SpaceCurrent() {}
        ~SpaceCurrent() {}
    public:
        Cardinal start;
        Cardinal end;
};

#endif
