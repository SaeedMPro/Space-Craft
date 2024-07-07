#include "Io.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

tuple<vector<int>, Location, int, vector<vector<int>>> readInputFile(const string& file_path) {
    ifstream file(file_path);
    if (!file.is_open()) {
        throw runtime_error("Couldn't find that file");
    }

    string line;
    vector<int> size;
    Location location;
    int energy;
    vector<vector<int>> space_map;

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
        istringstream iss(line);
        vector<int> row;
        int temp;
        while (iss >> temp) {
            row.push_back(temp);
        }
        space_map.push_back(row);
    }

    return make_tuple(size, location, energy, space_map);
}

bool WriteLogFile(const string &file_path)
{
    return true;
}
