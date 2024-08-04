#ifndef IO_HPP
#define IO_HPP

#include "Cardinal.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

tuple<vector<int>, Cardinal, int, vector<vector<char>>> readInputFile(const string& file_path);
void writeOutput(vector<string> path);
#endif
