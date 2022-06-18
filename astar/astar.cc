#include "astar.h"

#include <algorithm>
#include <queue>

int Astar::search(vector<vector<char>>& originalMap, pair<int, int> start,
                  pair<int, int> destination) {
    if (originalMap.size() == 0) return -1;

    int width = originalMap.size();
    int height = originalMap[0].size();

    vector<vector<int>> costMap(width, vector<int>(height, INT_MAX));

    auto compare = [](const node& a, const node& b) { return a.f > b.f; };
    priority_queue<node, vector<node>, decltype(compare)> pq(compare);
    node current;
    node next;

    current.x = start.first;
    current.y = start.second;
    current.cost = 0;
    current.f = abs(current.x - destination.first) +
                abs(current.y - destination.second);
    costMap[current.x][current.y] = current.f;
    pq.push(current);

    vector<int> direction = {0, 1, 0, -1, 0};

    while (!pq.empty()) {
        current = pq.top();
        pq.pop();
        // arrive at destination
        if ((current.x == destination.first) &&
            (current.y == destination.second)) {
            return current.cost;
        }

        for (int i = 0; i < 4; ++i) {
            if (current.x + direction[i] < width &&
                current.x + direction[i] >= 0 &&
                current.y + direction[i + 1] >= 0 &&
                current.y + direction[i + 1] < height &&
                originalMap[(current.x + direction[i])]
                           [current.y + direction[i + 1]] != '#') {
                next.x = current.x + direction[i];
                next.y = current.y + direction[i + 1];
                next.cost = current.cost + 1;
                next.f = next.cost + abs(next.x - destination.first) +
                         abs(next.y - destination.second);
                if (costMap[next.x][next.y] > next.f) {
                    pq.push(next);
                    costMap[next.x][next.y] = next.f;
                }
            }
        }
    }

    return -1;
}
