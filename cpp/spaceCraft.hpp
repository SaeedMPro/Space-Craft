#ifndef SPACE_CRAFT_HPP
#define SPACE_CRAFT_HPP

#include "Cardinal.hpp"
#include "Procedures.hpp"
#include <vector>
#include <string>

class SpaceCraft {
   public:
    SpaceCraft() {}
    SpaceCraft(int energy_, Cardinal startLoc) {
        energy = energy_;
        position.x = startLoc.x;    
        position.y = startLoc.y;
    }
    ~SpaceCraft() {}

        int energy;
        Cardinal position;
        Procedures algorithm;
        std::vector<std::string> logCraft;
    public:
        void logDecision();
        void moveCraft(Cardinal destination);
};

#endif
