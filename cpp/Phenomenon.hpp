#ifndef PHENOMENON_HPP
#define PHENOMENON_HPP

#include "Cardinal.hpp"
#include <iostream>

class Wormhole {
    public:
        Wormhole() {}
        Wormhole(Cardinal pos1, Cardinal pos2) {
            this->pos1 = pos1;
            this->pos2 = pos2;
        }
        ~Wormhole() {}

    public:
        Cardinal pos1;
        Cardinal pos2;
};

class SpaceObject {
    public:
        SpaceObject() {}
        SpaceObject(Cardinal pos) {
            pos1.x = pos.x; pos1.y = pos.y;
            pos2.x = pos.x; pos2.y = pos.y + 1;
            pos3.x = pos.x + 1; pos3.y = pos.y;
            pos4.x = pos.x + 1; pos4.y = pos.y + 1;
        }
        ~SpaceObject() {}

    public:
        bool visited;
        Cardinal pos1; // up left
        Cardinal pos2; // up right 
        Cardinal pos3; // down left
        Cardinal pos4; // down right
};

class SpaceCurrent {
    public:
        SpaceCurrent(Cardinal pos1_, Cardinal pos2_) {
            pos1 = pos1_;
            pos2 = pos2_;

            std::cout << pos1.x << " "  << pos1.y << "\n" ;
            std::cout << pos2.x << " "  << pos2.y << "\n" ;
        }
        ~SpaceCurrent() {}
    public:
        Cardinal pos1;
        Cardinal pos2;
};

#endif
