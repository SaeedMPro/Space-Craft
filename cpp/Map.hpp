#ifndef MAP_HPP
#define MAP_HPP

#include "SpaceCraft.hpp"
#include "Phenomenon.hpp"
#include "Cardinal.hpp"

#include <vector>

using namespace std;

class SpaceCraft;
class SpaceCurrent;
class SpaceObject;
class Wormhole; 

class Map {
    public:
        Map() {}
        Map(vector<vector<char>> spaceMap_, vector<int> size_, SpaceCraft* craft_) {
            grid = spaceMap_;
            size.heightMap = size_[0];
            size.weightMap = size_[1];
            craft = craft_;
        }
        ~Map() {}

        vector<vector<char>> grid;
        SpaceCraft* craft;  
        Cardinal destination;
        sizeMap size;
        vector<SpaceCurrent> spaceCurrent;
        SpaceObject spaceObject;
        Wormhole wormhole;

    public:
        void setPhenomenon();
        bool isValidMove(int& x, int& y);
        char getCellType(int& x, int& y);        
};

#endif
