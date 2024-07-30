#include "../RoutingUnit.hpp"
#include "../Cardinal.hpp"
#include "../Io.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void RoutingUnit::startRU() {
    cout << "Routing Unit started" << endl;
    
    vector<int> size(2);
    Cardinal location;
    int energy;
    vector<vector<char>> spaceMap;

    bool ReadFile = true;

    //Reading input from "testcase.txt":
    if (ReadFile) {
        try {
            auto result = readInputFile("../Test/testcase.txt");
            size     = get<0>(result);
            location = get<1>(result);
            energy   = get<2>(result);
            spaceMap = get<3>(result);
        } 
            catch(const runtime_error& e) {
            cerr << "File not exists !" << endl;
            cerr << e.what() << endl;
            return;
        }
    } else {
        try {
            cin >> size[0] >> size[1];
            cin >> location.x >> location.y;
            cin >> energy;

            spaceMap.resize(size[0]);
            for(int i = 0; i < size[0]; i++) {
                string line;
                cin >> ws;
                getline(cin,line);
                for(char ch : line) {
                    if(ch != ' ') {
                        spaceMap[i].push_back(ch);
                }
            }
        } 
    } catch(const runtime_error& e) {
        cerr << "Wrong inputes !" << endl;
        cerr << e.what() << endl;
        return;
        }
    }
    // Initialize SpaceCraft and Map according to input
    craft = new SpaceCraft(energy, location);
    currentMap = new Map(spaceMap, size, craft);
    
    currentMap->setPhenomenon();
    craft->moveCraft(currentMap);

    delete(craft); delete(currentMap);
}