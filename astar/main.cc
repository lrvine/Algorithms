#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
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
  char** map = new char*[width];
  for (int i = 0; i < width; i++) {
    map[i] = new char[height];
  }

  pair<int, int> start;
  pair<int, int> destination;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      input >> map[j][i];
      if (int(map[j][i]) == 83) {
        start.first = j;
        start.second = i;
      }
      if (int(map[j][i]) == 68) {
        destination.first = j;
        destination.second = i;
      }
    }
  }

  Astar findpath;

  int shortestPath;

  shortestPath = findpath.search(width, height, map, start, destination);

  if (shortestPath != -1)
    cout << "Shortest distance from start (" << start.first << ","
         << start.second << ") to destination (" << destination.first << ","
         << destination.second << ") is " << shortestPath << endl;
  else
    cout << "Cannot find valid path from start to destination !" << endl;

  return 0;
}
