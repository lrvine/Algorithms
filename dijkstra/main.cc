#include <stdlib.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#include "dijkstra.h"

using namespace std;

int main(int argc, char** argv) {
    ifstream input;

    input.open(argv[1]);

    if (input.fail()) {
        cout << " input error " << endl;
        return -1;
    }

    vector<int> distance;
    vector<vector<pair<int, int>>> adjlist;

    // read adjacency list
    string s;
    string buf;
    while (getline(input, s)) {
        distance.push_back(-1);

        istringstream iss(s);
        iss >> buf;

        vector<pair<int, int>> vertex;

        while (iss >> buf) {
            istringstream split(buf);
            pair<int, int> edge;
            getline(split, buf, ',');
            edge.first = stoi(buf);
            getline(split, buf, ',');
            edge.second = stoi(buf);
            vertex.push_back(edge);
        }

        adjlist.push_back(vertex);
    }
    input.close();

    dijkstra(1, distance, adjlist);

    // print out the shortest path to each point
    cout << " The shortest path from vertex 1 to each vertex are " << endl;
    for (int i = 0; i < distance.size(); i++) {
        cout << distance[i] << " ";
    }
    cout << endl;

    return 0;
}
