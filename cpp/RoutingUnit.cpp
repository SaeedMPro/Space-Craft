#include "RoutingUnit.hpp"
#include "Cardinal.hpp"
#include "Io.hpp"
#include <iostream>
#include <vector>

using namespace std;

void RoutingUnit::startRU() {
    cout << "Routing Unit started" << endl;
    
    vector<int> size;
    Cardinal location;
    int energy;
    vector<vector<char>> spaceMap;
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
    SpaceCraft craft(energy, location);
    Map currentMap(spaceMap, size, &craft);

    
    
}

void RoutingUnit::navigate(Cardinal destination) {
    // Implementation here
}
