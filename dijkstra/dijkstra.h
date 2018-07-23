#ifndef dijkstra_h
#define dijkstra_h

using namespace std;
struct compare {
  bool operator()(const pair<int, int> l, const pair<int, int> r) {
    return l.second > r.second;
  }
};

void dijkstra(int vertices, int startPoint, int* distance,
              vector<vector<pair<int, int> > > adjlist);
#endif
