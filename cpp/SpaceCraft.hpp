#ifndef SPACE_CRAFT_HPP
#define SPACE_CRAFT_HPP

#include "Cardinal.hpp"
#include "Map.hpp"
#include <vector>
#include <string>

using namespace std;

class SpaceCurrent;
class SpaceObject;
class Wormhole;  
class Map;
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
        std::vector<std::string> logCraft;
    public:
        void logDecision(const std::string& decision);
        void moveCraft(Map* currentMap);
        bool backtrack(Cardinal current, vector<vector<bool>>& visited, Map * currentMap, Cardinal pervious);
        bool isValidPosition(int x, int y, Map * currentMap);

        Cardinal move(Cardinal nextMove);
        Cardinal orbit(SpaceObject so, Cardinal start,Cardinal pos);
        Cardinal teleport(Wormhole wh, Cardinal start);
        Cardinal ride(vector<SpaceCurrent> sc, Cardinal start);
};

#endif
