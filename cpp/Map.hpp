#ifndef MAP_HPP
#define MAP_HPP

#include "SpaceCraft.hpp"
#include "Cardinal.hpp"
#include <vector>

using namespace std;


class SpaceCraft;  

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

        std::vector<std::vector<char>> grid;
        SpaceCraft* craft;  
        sizeMap size;

    public:
        bool isValidMove(int& x, int& y);
        char getCellType(int& x, int& y);
};

#endif
