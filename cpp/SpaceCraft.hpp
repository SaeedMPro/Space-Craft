#ifndef SPACE_CRAFT_HPP
#define SPACE_CRAFT_HPP

#include "Cardinal.hpp"
#include "Map.hpp"

#include <vector>
#include <string>
#include <cmath>

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
        time = 0;
    }
    ~SpaceCraft() {}

        int currentDirection;
        Cardinal position;
        vector<string> logCraft;
        int spaceCurrentLengthFactor;
        vector<string> tempLog;
        vector<string> possiblePath; 
        static const vector<vector<pair<int,int>>> allDirections;
    
    public:
        void logDecision(const std::string& decision, bool flagTempLog = false);
        void moveCraft(Map* currentMap);
        bool backtrack(Cardinal current, vector<vector<bool>>& visited, Map * currentMap, Cardinal pervious);
        bool isValidPosition(int x, int y, Map* currentMap);
        bool enoughEnergy(int amount) const;
        void setTime(int time);

        Cardinal decision(Map *currentMap, Cardinal current, Cardinal nextMove);
        Cardinal orbit(SpaceObject so, Cardinal start, Map* map);
        Cardinal teleport(Wormhole wh, Cardinal start);
        Cardinal ride(vector<SpaceCurrent> sc, Cardinal start);
   
    private : 
        int time;
        int energy;
        void consumeEnergy(int amount);
};


#endif
