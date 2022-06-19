#include "dijkstra.h"

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void dijkstra(int startPoint, vector<int>& distance,
              const vector<vector<pair<int, int>>>& adjlist) {
    auto compare = [](const pair<int, int> a, const pair<int, int> b) {
        return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);

    pair<int, int> current;
    current.first = startPoint;
    current.second = 0;
    pq.push(current);

    vector<bool> visited(adjlist.size(), false);

    while (!pq.empty()) {
        current = pq.top();
        pq.pop();
        if (visited[current.first - 1]) {
            continue;
        } else {
            visited[current.first - 1] = true;
            distance[current.first - 1] = current.second;
        }

        int listSize = adjlist[current.first - 1].size();
        for (int i = 0; i < listSize; ++i) {
            if (!visited[adjlist[current.first - 1][i].first - 1]) {
                pair<int, int> neighbor;
                neighbor.first = adjlist[current.first - 1][i].first;
                neighbor.second =
                    current.second + adjlist[current.first - 1][i].second;
                pq.push(neighbor);
            }
        }
    }
}
