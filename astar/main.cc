#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "astar.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream input;

    input.open(argv[1]);

    if (input.fail()) {
        cout << " input error " << endl;
        return -1;
    }

    int width;
    int height;

    input >> width >> height;

    vector<vector<char>> map(width, vector<char>(height));
    pair<int, int> start;
    pair<int, int> destination;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            input >> map[j][i];
            if (map[j][i] == 'S') {
                start.first = j;
                start.second = i;
            } else if (map[j][i] == 'D') {
                destination.first = j;
                destination.second = i;
            }
        }
    }

    Astar findpath;

    int shortestPath = findpath.search(map, start, destination);

    if (shortestPath != -1)
        cout << "Shortest distance from start (" << start.first << ","
             << start.second << ") to destination (" << destination.first << ","
             << destination.second << ") is " << shortestPath << endl;
    else
        cout << "Cannot find valid path from (" << start.first << ","
             << start.second << ") to destination (" << destination.first << ","
             << destination.second << ")!" << endl;

    return 0;
}
