#ifndef SPACECRAFT_HPP
#define SPACECRAFT_HPP

#include <vector>
#include <string>
#include <tuple>

using namespace std;

struct Location {
    int x;
    int y;
};

tuple<vector<int>, Location, int, vector<vector<int>>> read_file(const string& file_path);

#endif