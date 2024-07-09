#include "SpaceCraft.hpp"
#include <vector>
#include <iostream>

using namespace std;
void SpaceCraft::logDecision(const std::string& decision) {
    cout << "Decision: " << decision << endl;
}

void SpaceCraft::moveCraft(Map* currentMap) {
    Cardinal destination;
    destination.x = currentMap->destination.x;
    destination.y = currentMap->destination.y;

    vector<vector<bool>> visited(currentMap->size.heightMap, vector<bool>(currentMap->size.weightMap, false));
    if (backtrack(position, visited, currentMap)) {
        logDecision("Arrived at destination (" + to_string(destination.x) + ", " + to_string(destination.y) + ")");
    } else {
        logDecision("Failed to reach destination");
    }
}

bool SpaceCraft::backtrack(Cardinal current, vector<vector<bool>>& visited, Map* currentMap) {
    
    cout << "Current: " << current.x << " " << current.y << endl;
    if (currentMap->getCellType(current.x, current.y) == '5') {
        position = current; 
        return true;
    }

   
    visited[current.x][current.y] = true;
    position = current; 

    const vector<pair<int, int>> directions = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    for (const auto& direction : directions) {
        int newX = current.x + direction.first;
        int newY = current.y + direction.second;

        if (isValidPosition(newX, newY, currentMap) && !visited[newX][newY]) {
            char cellType = currentMap->getCellType(newX, newY);

            Cardinal temp = {newX, newY};
            switch (cellType)
            {
            case '4':
                // logDecision("Moving to (" + to_string(newX) + ", " + to_string(newY) + ")");
                temp = teleport(currentMap->wormhole, {newX, newY}); 
                break;
            case '0':
                // temp = move({newX, newY});    
                break;
            case '3':
                if (!currentMap->spaceObject.visited) { temp = orbit(currentMap->spaceObject, current, {newX, newY});  currentMap->spaceObject.visited = true; }
                else temp = current;
                break;
            case '1':
                // logDecision("Moving to (" + to_string(newX) + ", " + to_string(newY) + ")");
                temp = ride(currentMap->spaceCurrent, {newX, newY});
                // cout << temp.x << " " << temp.y << endl;
                break;  
            // default :
            //     temp = current;
            // break;  
            }

            if (!(temp.x < 0 || temp.y < 0 || 
            temp.x > currentMap->size.heightMap || 
            temp.y > currentMap->size.weightMap)
            )
            {
                if (backtrack(temp, visited, currentMap)) { return true; }
                // logDecision("Backtrack from (" + to_string(newX) + ", " + to_string(newY) + ")");
            }
        }
    }

    visited[current.x][current.y] = false;
    return false;
}

bool SpaceCraft::isValidPosition(int x, int y, Map* currentMap) {
    return x >= 0 && x < currentMap->size.heightMap && y >= 0 
        && y < currentMap->size.weightMap
        && currentMap->getCellType(x, y) != '2';
}

Cardinal SpaceCraft::move(Cardinal nextMove)
{
    return nextMove;
}

Cardinal SpaceCraft::orbit(SpaceObject so, Cardinal start, Cardinal pos)
{
    
    // create bound of object
    int x1 = so.pos1.x, x2 = so.pos4.x,
        y1 = so.pos1.y, y2 = so.pos4.y; 

    // routing
    if (start.x < x1) { start.x += 3; }
    else if (start.x > x2) { start.x -= 3; }
    else if(start.y < y1) { start.y += 3; }
    else if(start.y > y2) { start.y -= 3; }
    
    return start;
}

Cardinal SpaceCraft::teleport(Wormhole wh, Cardinal start)
{
    if(start.x == wh.pos1.x && start.y == wh.pos1.y) { return wh.pos2; } 
    else return wh.pos1;
}

Cardinal SpaceCraft::ride(vector<SpaceCurrent> sc, Cardinal start)
{
    for (const SpaceCurrent &spaceCurrent : sc)
    {   
        if ((start.x == spaceCurrent.pos1.x && start.y == spaceCurrent.pos1.y) ||
            (start.x == spaceCurrent.pos2.x && start.y == spaceCurrent.pos2.y)) {
            return (start.x == spaceCurrent.pos1.x && start.y == spaceCurrent.pos1.y) ? spaceCurrent.pos2 : spaceCurrent.pos1;
        } 
    }
    return start;
    
}
