#ifndef SPACE_CRAFT_HPP
#define SPACE_CRAFT_HPP

#include "RoutingUnit.hpp"
#include "Procedures.hpp"

#include <vector>

class SpaceCraft {
    
   public:
    SpaceCraft() {}
    ~SpaceCraft() {}

        int energy;
        Cardinal position;
        Procedures algorithm;
        vector<string> logCraft;
    public:
        void logDecision() {}
        void moveCraft(Cardinal destination) {}

};

#endif