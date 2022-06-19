#ifndef dijkstra_h
#define dijkstra_h

#include <utility>
#include <vector>

using namespace std;

void dijkstra(int startPoint, vector<int>& distance,
              const vector<vector<pair<int, int>>>& adjlist);
#endif
