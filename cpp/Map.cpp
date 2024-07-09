#include "Map.hpp"
#include "SpaceCraft.hpp"
#include "Phenomenon.hpp"
#include <iostream>
#include <vector>

using namespace std;
void Map::setPhenomenon()
{
    //find Space Current and Destination.
    Cardinal temp;
    vector<Cardinal> pos1, pos2;
    int count = 0;
    for (size_t i = 0; i < size.heightMap; i++)
    {
        for (size_t j = 0; j < size.weightMap; j++)
        {
            if (grid[i][j] == '5') { destination.x = i; destination.y = j; continue; } //Set destination

            if (grid[i][j] == '1' && count % 2 == 1)
            {
                temp.x = i; temp.y = j;
                pos2.push_back(temp);
                count++;
            }
            if (grid[i][j] == '1' && count % 2 == 0)
            {
                temp.x = i; temp.y = j; 
                pos1.push_back(temp);
                count++;
            }
            
        } 
    }
    for (size_t i = 0; i < count/2; i++)
    {
        spaceCurrent.push_back(SpaceCurrent(pos1[i], pos2[i])); 
    }

    //find Space Object.
    Cardinal pos;
    bool flag = false;
    for (size_t i = 0; i < size.heightMap; i++){
        for (size_t j = 0; j < size.weightMap; j++)
           if (grid[i][j] == '3') { pos.x = i, pos.y = j; flag = true; break; } 

        if (flag) break;
    }
        
        
    spaceObject = SpaceObject(pos);    

    //find Wormhole.
    Cardinal pos11, pos22;
    count = 0;
    for (size_t i = 0; i < size.heightMap; i++)
    {
        for (size_t j = 0; j < size.weightMap; j++)
        {
            if (grid[i][j] == '4' && count == 1)
            {
                pos22.x = i; pos22.y = j;
                count++;
            }
            if (grid[i][j] == '4' && count == 0)
            {
                pos11.x = i; pos11.y = j;
                count++;
            }
            
        } 
        if (count == 2) break;
    }
    wormhole = Wormhole(pos11, pos22); 
}

bool Map::isValidMove(int &x, int &y)
{
    return x >= 0 && x < size.heightMap && y >= 0 && y < size.weightMap && grid[x][y] != '2';
}

char Map::getCellType(int& x, int& y) {
    return grid[x][y]; 
}
