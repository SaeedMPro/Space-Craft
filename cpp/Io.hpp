#ifndef IO_HPP
#define IO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

struct Location {
    int x;
    int y;
};

tuple<vector<int>, Location, int, vector<vector<int>>> readInputFile(const string& file_path);
bool WriteLogFile(const string& file_path);

#endif