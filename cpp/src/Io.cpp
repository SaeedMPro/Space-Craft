#include "../Io.hpp"
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

tuple<vector<int>, Cardinal, int, vector<vector<char>>> readInputFile(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        throw runtime_error("Couldn't find that file");
    }

    string line;
    vector<int> size;
    Cardinal location;
    int energy;
    vector<vector<char>> spaceMap;

    if (getline(file, line)) {
        istringstream iss(line);
        int temp;
        while (iss >> temp) {
            size.push_back(temp);
        }
    }

    if (getline(file, line)) {
        istringstream iss(line);
        iss >> location.x >> location.y >> energy;
    }

    while (getline(file, line)) {
        vector<char> row;
        for (char ch : line) {
            if (ch != ' ') { 
                row.push_back(ch);
            }
        }
        spaceMap.push_back(row);
    }
    return make_tuple(size, location, energy, spaceMap);
}

void writeOutput(vector<string> path)
{
    bool writeInConsol = false; 

    if (writeInConsol) { // write in terminal.

        for (string str : path)
        {
            cout << str << endl;
        }
    } else { // write in the "Log.txt" file.

        fstream logFile("../Test/Log.txt", ios::out);

        if (!logFile.is_open()) {
            throw runtime_error("Couldn't Open the Log file!");
        }
        for (string str : path)
        {
            logFile << str << endl;
        }

        logFile.close();
        cout << "It was successfully written into the file..\n\n";
    }
}
