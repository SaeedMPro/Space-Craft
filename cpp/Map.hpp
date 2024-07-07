#ifndef MAP_HPP
#define MAP_HPP

#include "spaceCraft.hpp"

#include <vector>

struct sizeMap {
    int heightMap, weightMap;
};

class Map {

    public:
        Map() {}
        ~Map() {}

        vector<vector<char>> grid;
        SpaceCraft craft;
        sizeMap sizeM;

    public:
        bool isValidMove(int& x, int& y) {}
        char getCellType(int& x, int& y) {}      

};


#endif