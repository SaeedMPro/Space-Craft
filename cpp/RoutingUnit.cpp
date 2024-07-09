#include "RoutingUnit.hpp"
#include "Cardinal.hpp"
#include "Io.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void RoutingUnit::startRU() {
    cout << "Routing Unit started" << endl;
    
    vector<int> size;
    Cardinal location;
    int energy;
    vector<vector<char>> spaceMap;

    //Reading input from "testcase.txt":
    try {
        auto result = readInputFile("testcase.txt");
        size = get<0>(result);
        location = get<1>(result);
        energy = get<2>(result);
        spaceMap = get<3>(result);
        // cout << "Size: ";
        // for (const auto& s : size) {
        //     cout << s << " ";
        // }
        // cout << endl;
        // cout << "Location: (" << location.x << ", " << location.y << ")" << endl;
        // cout << "Initial Energy: " << energy << endl;
        // cout << "Space map:" << endl;
        // for (const auto& row : spaceMap) {
        //     for (const auto& val : row) {
        //         cout << val << " ";
        //     }
        //     cout << endl;
        // }

        
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    //input from console:
    // cin >> size[0] >> size[1];
    // cin >> location.x >> location.y;
    // cin >> energy;
    // for (int i = 0; i < size[0]; i++) 
    // {   
    //     string line;
    //     vector<char> row;
    //     cin >> line;

    //     for (char ch : line) {
    //         if (ch != ' ') { 
    //             row.push_back(ch);
    //         }
    //     }
    //     spaceMap.push_back(row);
    // }


    // Initialize SpaceCraft and Map according to input.
    craft = new SpaceCraft(energy, location);
    currentMap = new Map(spaceMap, size, craft);
    
    currentMap->setPhenomenon();
    craft->moveCraft(currentMap);

    delete(craft); delete(currentMap);
}

void RoutingUnit::navigate(Cardinal destination) {
    // Implementation here
}
