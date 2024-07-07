#include <iostream>
#include "Io.hpp"

using namespace std;

int main() {
    try {
        auto [size, location, energy, space_map] = readInputFile("testcase.txt");

        cout << "Size: ";
        for (const auto& s : size) {
            cout << s << " ";
        }
        cout << endl;

        cout << "Location: (" << location.x << ", " << location.y << ")" << endl;
        cout << "Initial Energy: " << energy << endl;
        cout << "Space map:" << endl;
        for (const auto& row : space_map) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}