#include "../SpaceCraft.hpp"

void SpaceCraft::logDecision(const string& decision) { 
    tempLog.push_back(decision);
}

void SpaceCraft::consumeEnergy(int amount) { energy -= amount; }

bool SpaceCraft::enoughEnergy(int amount) const { return energy >= amount; }

void SpaceCraft::setTime(int time_) { time += time_; }

void SpaceCraft::moveCraft(Map* currentMap) {

    int initialEnergy = energy;
    Cardinal destination = currentMap->destination;
    Cardinal initialPosition = position;
    
    for (vector<pair<int, int>> dir : allDirections) {
        vector<vector<bool>> visited(currentMap->size.heightMap, vector<bool>(currentMap->size.weightMap, false));
        
        energy = initialEnergy;
        time = 0;
        if (backtrack(initialPosition, visited, currentMap, initialPosition, dir)) {

            logDecision("Arrived at destination (" + to_string(destination.x) + ", " + to_string(destination.y) + ")"
            + " with Energy :" + to_string(initialEnergy - energy) 
            + " with Time :" + to_string(time) + "\n");

        } else {
            logDecision("Failed to reach destination");
        }

        possiblePath.push_back(tempLog);
        pathsIndex.push_back(time);
        tempLog.clear();

    }
    
}

bool SpaceCraft::backtrack(Cardinal current, vector<vector<bool>>& visited, Map* currentMap, Cardinal pervious, vector<pair<int, int>> dir) {
    if (currentMap->getCellType(current.x, current.y) == '5') {
        return true;
    }

    visited[current.x][current.y] = true;
    position = current; 

    char typeCurrent = currentMap->getCellType(current.x, current.y);
    int  energyCost = 0;
    int  timeCost = 0;

    switch (typeCurrent) {
        case '4':
            timeCost = 0;
            if (enoughEnergy(floor(energy / 2))) {    
                logDecision("Teleporting from (" + to_string(current.x) + ", " + to_string(current.y) + ")"
                 + "\t\t\t" + "; Energy : " + to_string(energy)
                 + "\t\t\t" + "; Time : " + to_string(time));
                
                consumeEnergy(floor(energy / 2));
                setTime(timeCost);
                current = teleport(currentMap->wormhole, current);
                visited[current.x][current.y] = true; 
                logDecision("Teleporting to (" + to_string(current.x) + ", " + to_string(current.y) + ")"
                 + "\t\t\t" + "; Energy : " + to_string(energy)
                 + "\t\t\t" + "; Time : " + to_string(time));
                
                position = current;
            } else {
                logDecision("Not Enough energy to (Warmhole)");
                return false;
            }
            break;

        case '3':
            timeCost = 3*3;
            if (enoughEnergy(3*4)) {
                logDecision("Orbiting from (" + to_string(pervious.x) + ", " + to_string(pervious.y) + ")"
                 + "\t\t\t" + "; Energy : " + to_string(energy)
                 + "\t\t\t" + "; Time : " + to_string(time));

                consumeEnergy(3*4);
                current = orbit(currentMap->spaceObject, pervious, currentMap);
                visited[current.x][current.y] = true;
                setTime(timeCost);
                logDecision("Orbiting to (" + to_string(current.x) + ", " + to_string(current.y) + ")"
                 + "\t\t\t" + "; Energy : " + to_string(energy)
                 + "\t\t\t" + "; Time : " + to_string(time));

                position = current;
            } else {
                logDecision("Not Enough energy to (Orbit)");
                return false;
            }
            break;

        case '1':
            energyCost = (spaceCurrentLengthFactor + 1) * 2;
            timeCost = spaceCurrentLengthFactor + 1;
            if (enoughEnergy(energyCost)) {    
                logDecision("Riding from (" + to_string(current.x) + ", " + to_string(current.y) + ")"
                 + "\t\t\t" + "; Energy : " + to_string(energy)
                 + "\t\t\t" + "; Time : " + to_string(time));

                consumeEnergy(energyCost);
                setTime(timeCost);
                current = ride(currentMap->spaceCurrent, current);
                visited[current.x][current.y] = true;
                logDecision("Riding to (" + to_string(current.x) + ", " + to_string(current.y) + ")"
                 + "\t\t\t" + "; Energy : " + to_string(energy)
                 + "\t\t\t" + "; Time : " + to_string(time));
        
                position = current;
            } else {
                logDecision("Not Enough energy to (Space Current)");
                return false;
            }    
            break; 

        default:
            if (enoughEnergy(1)) {
                logDecision("Moving form (" + to_string(current.x) + ", " + to_string(current.y) + ")"
                 + "\t\t\t" + "; Energy : " + to_string(energy)
                 + "\t\t\t" + "; Time : " + to_string(time));
                consumeEnergy(1);
                setTime(5);
                visited[current.x][current.y] = true;
            } else {
                logDecision("Not Enough energy to (Move)");
                return false;
            }
            break;
    }
    


    for (const auto& direction : dir) {                  
        Cardinal nextMove = {current.x + direction.first, current.y + direction.second};

        nextMove = decision(currentMap, current, nextMove);
            
        if (isValidPosition(nextMove.x, nextMove.y, currentMap) && !visited[nextMove.x][nextMove.y]){    

            logDecision("Moving to (" + to_string(nextMove.x) + ", " + to_string(nextMove.y) + ")"
                + "\t\t\t" + "; Energy : " + to_string(energy) 
                + "\t\t\t" + "; Time : " + to_string(time));

            if (backtrack(nextMove, visited, currentMap, current, dir)) { 
                return true; 
            }
            
                int energyCostTwo = (spaceCurrentLengthFactor + 2) * 2;
                switch (currentMap->getCellType(nextMove.x, nextMove.y)) {
                    case '4':
                        setTime(0);
                        consumeEnergy(floor(energy / 2));
                        break;

                    case '3':
                        setTime(3*3);
                        consumeEnergy(3 * 4);
                        break;

                    case '1':
                        setTime(spaceCurrentLengthFactor + 2);
                        consumeEnergy(energyCostTwo);
                        break;

                    default:
                        setTime(5);
                        consumeEnergy(1); 
                        break;                   
                } 

                position = current;
                logDecision("Backtracking from (" + to_string(nextMove.x) + ", " + to_string(nextMove.y) + ")" 
                    + " to (" + to_string(current.x) + ", " + to_string(current.y) + ")"
                    + "\t\t\t" + "; Energy : " + to_string(energy)
                    + "\t\t\t" + "; Time : " + to_string(time));

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

Cardinal SpaceCraft::decision(Map* currentMap, Cardinal current, Cardinal nextMove) {
    const vector<pair<int, int>> directions = {
        {-1, -1},  {-1, 0}, {-1, 1}, 
        {0, -1 },/*current*/{ 0, 1}, 
        {1, -1 },  { 1, 0}, { 1, 1}
    };

    for (const auto& direction : directions) {
        int x = current.x + direction.first;
        int y = current.y + direction.second;

        if (isValidPosition(x, y, currentMap)) {
            char viewCellType = currentMap->getCellType(x, y);

            if (viewCellType == '5') {
                if (x == current.x || y == current.y) { return {x, y}; }
                else {
                    char xCellType = currentMap->getCellType(current.x, y);
                    char yCellType = currentMap->getCellType(x, current.y);

                    if (!(xCellType == '4' || xCellType == '3' || xCellType == '1')) { return {current.x, y}; }
                    else if (!(yCellType == '4' || yCellType == '3' || yCellType == '1')) { return {x, current.y}; }
                    else 
                    { return nextMove; }
                
                }
            }
        }
    }
    return nextMove;
}

Cardinal SpaceCraft::orbit(SpaceObject so, Cardinal start, Map* map) {
    // create bound of object
    int x1 = so.pos1.x, x2 = so.pos4.x,
        y1 = so.pos1.y, y2 = so.pos4.y; 

    Cardinal result = start;
    // routing
    if (start.x < x1)      { result.x += 3; }
    else if(start.x > x2)  { result.x -= 3; }
    else if(start.y < y1)  { result.y += 3; }
    else if(start.y > y2)  { result.y -= 3; }
    
    return (isValidPosition(result.x, result.y, map)) ? result : start;
}

Cardinal SpaceCraft::teleport(Wormhole wh, Cardinal start) {
    if (start.x == wh.pos1.x && start.y == wh.pos1.y) { return wh.pos2; } 
    else { return wh.pos1; }
}

Cardinal SpaceCraft::ride(vector<SpaceCurrent> sc, Cardinal start) {
    for (const SpaceCurrent &spaceCurrent : sc) {   
        if ((start.x == spaceCurrent.pos1.x && start.y == spaceCurrent.pos1.y) ||
            (start.x == spaceCurrent.pos2.x && start.y == spaceCurrent.pos2.y)) {
            return (start.x == spaceCurrent.pos1.x && start.y == spaceCurrent.pos1.y) ? spaceCurrent.pos2 : spaceCurrent.pos1;
        } 
    }
    return start;   
}

const vector<vector<pair<int, int>>> SpaceCraft::allDirections = {
    {{-1, 0}, {0, 1}, {1, 0}, {0, -1}},
    {{-1, 0}, {0, -1}, {1, 0}, {0, 1}},
    {{-1, 0}, {1, 0}, {0, 1}, {0, -1}},
    {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
    {{-1, 0}, {0, 1}, {0, -1}, {1, 0}},
    {{-1, 0}, {0, -1}, {0, 1}, {1, 0}},
    {{0, 1}, {1, 0}, {0, -1}, {-1, 0}},
    {{0, 1}, {-1, 0}, {0, -1}, {1, 0}},
    {{0, 1}, {0, -1}, {1, 0}, {-1, 0}},
    {{0, 1}, {0, -1}, {-1, 0}, {1, 0}},
    {{0, 1}, {1, 0}, {-1, 0}, {0, -1}},
    {{0, 1}, {-1, 0}, {1, 0}, {0, -1}},
    {{1, 0}, {0, 1}, {-1, 0}, {0, -1}},
    {{1, 0}, {0, -1}, {-1, 0}, {0, 1}},
    {{1, 0}, {0, 1}, {0, -1}, {-1, 0}},
    {{1, 0}, {0, -1}, {0, 1}, {-1, 0}},
    {{1, 0}, {-1, 0}, {0, 1}, {0, -1}},
    {{1, 0}, {-1, 0}, {0, -1}, {0, 1}},
    {{1, 0}, {0, 1}, {0, -1}, {-1, 0}},
    {{1, 0}, {0, -1}, {0, 1}, {-1, 0}},
    {{0, -1}, {1, 0}, {0, 1}, {-1, 0}},
    {{0, -1}, {1, 0}, {-1, 0}, {0, 1}},
    {{0, -1}, {0, 1}, {1, 0}, {-1, 0}},
    {{0, -1}, {0, 1}, {-1, 0}, {1, 0}},
    {{0, -1}, {-1, 0}, {0, 1}, {1, 0}},
    {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}
};