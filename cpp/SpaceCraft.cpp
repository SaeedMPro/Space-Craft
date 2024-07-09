#include "SpaceCraft.hpp"
#include <iostream>
#include <fstream>
#include <vector>
    
using namespace std;

void SpaceCraft::logDecision(const std::string& decision) {
    bool consol = true;
    if (consol){
        cout << "Decision: " << decision << endl;
    }
    else {
    fstream logFile("log.txt", ios::out | ios::app); 

    if (!logFile.is_open()) {
        throw runtime_error("Couldn't find that file");
    }

    logFile << decision << endl;

    logFile.close();
    }
}

void SpaceCraft::moveCraft(Map* currentMap) {
    
    Cardinal destination = currentMap->destination;
    // destination.x = currentMap->destination.x;
    // destination.y = currentMap->destination.y;

    vector<vector<bool>> visited(currentMap->size.heightMap, vector<bool>(currentMap->size.weightMap, false));
    if (backtrack(position, visited, currentMap, position)) {
        logDecision("Arrived at destination (" + to_string(destination.x) + ", " + to_string(destination.y) + ")");
    } else {
        logDecision("Failed to reach destination");
    }
}

bool SpaceCraft::backtrack(Cardinal current, vector<vector<bool>>& visited, Map* currentMap, Cardinal pervious) {
    
    // cout << "Current: " << current.x << " " << current.y << endl;---------------------------------------
    if (currentMap->getCellType(current.x, current.y) == '5') {
        position = current; 
        return true;
    }

   
    visited[current.x][current.y] = true;
    position = current; 

    char typeCurrent = currentMap->getCellType(current.x, current.y);
    switch (typeCurrent)
    {
        case '4':
            logDecision("Teleporting from (" + to_string(current.x) + ", " + to_string(current.y) + ")");
            current = teleport(currentMap->wormhole, current); 
            logDecision("Teleporting to (" + to_string(current.x) + ", " + to_string(current.y) + ")");
            position = current;
            break;
        case '3':
            logDecision("Orbiting from (" + to_string(current.x) + ", " + to_string(current.y) + ")");
            current = orbit(currentMap->spaceObject, pervious, current);
            logDecision("Orbiting to (" + to_string(current.x) + ", " + to_string(current.y) + ")");
            break;
        case '1':
            logDecision("Riding from (" + to_string(current.x) + ", " + to_string(current.y) + ")");
            current = ride(currentMap->spaceCurrent, current);
            logDecision("Riding to (" + to_string(current.x) + ", " + to_string(current.y) + ")");
            position = current;
            break;  
        default :
            break;
    }

    // vector<pair<int, int>> fieldViewCraft = {{-1, 0}, {0, 1}, {1, 0}, {0, -1},
    //                                         {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    const vector<pair<int, int>> directions = {{1, 0}, {0, -1},{-1, 0}, {0, 1}};
    for (const auto& direction : directions) {
        int newX = current.x + direction.first;
        int newY = current.y + direction.second;
            if(isValidPosition(newX,newY,currentMap) && !visited[newX][newY]){    
                logDecision("Moving to (" + to_string(newX) + ", " + to_string(newY) + ")");
                if(backtrack({newX,newY},visited,currentMap,current)){return true;}
                logDecision("Backtracking from (" + to_string(newX) + ", " + to_string(newY) + ")");
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

        // for (const auto& view : fieldViewCraft) {
        //     int newX2 = current.x + direction.first;
        //     int newY2 = current.y + direction.second;
        //     if (isValidPosition(newX, newY, currentMap)) {
        //         char typeView = currentMap->getCellType(newX, newY);
                
        //         if(typeView == '5') {
        //             newX = newX2; newY = newY2;
        //             break;   
        //         }
        //     } 
        // }
        

        // if (isValidPosition(newX, newY, currentMap) && !visited[newX][newY]) {
        //     char cellType = currentMap->getCellType(newX, newY);

        //     if (isValidPosition(newX, newY, currentMap) && !visited[newY][newX]) {
        //         char cellType = currentMap->getCellType(newX, newY);
        //         if (cellType == '0' || cellType == '1' || cellType == '2' 
        //             || cellType == '3' || cellType == '4' || cellType == '5') { // Check for valid cell types
        //             // Move to the new position
        //             logDecision("Moving to (" + to_string(newX) + ", " + to_string(newY) + ")");
        //             if (backtrack({newX, newY}, visited, currentMap, current)) {
        //                 return true;
        //             }
        //             // If moving to the new position didn't lead to a solution, backtrack
        //             logDecision("Backtracking from (" + to_string(newX) + ", " + to_string(newY) + ")");
        //    }

        //     visited[current.x][current.y] = false;
        //     return false;
        // }

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
