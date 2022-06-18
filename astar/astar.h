#ifndef astar_h
#define astar_h

#include <utility>
#include <vector>

using namespace std;

class Astar {
   public:
    int search(vector<vector<char>> &originalMap, pair<int, int> start,
               pair<int, int> destination);
    // A * search for shortest path between two points

   private:
    struct node {
        int x;
        int y;
        int cost;
        int f;
    };  // node for A* search
};

#endif
