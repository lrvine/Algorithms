#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// accept adjacency matrix format
int prims(int** matrix, int numNode) {
  vector<int> visited;
  vector<int> unvisited;
  long long cost = 0;

  for (int i = 0; i < numNode; i++) {
    unvisited.push_back(i);
  }

  visited.push_back(unvisited.back());
  unvisited.pop_back();

  int mnode;
  int medge;
  vector<int>::iterator p;

  while (!unvisited.empty()) {
    medge = INT_MAX;
    for (int i = 0; i < visited.size(); i++) {
      for (int j = 0; j < unvisited.size(); j++) {
        if (matrix[visited[i]][unvisited[j]] < medge) {
          medge = matrix[visited[i]][unvisited[j]];
          mnode = unvisited[j];
        }
      }
    }
    visited.push_back(mnode);
    p = find(unvisited.begin(), unvisited.end(), mnode);
    if (p != unvisited.end()) {
      unvisited.erase(p);
    } else {
      cout << "Something wrong!" << endl;
    }
    cost += medge;
    //  	cout<<" add node "<<(mnode+1)<<" cost is "<<cost<<endl;
  }
  return cost;
}
