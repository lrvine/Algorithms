#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

struct route {
  vector<int> path;
  vector<int> novisit;
  long double cost;
  long double bound;
};  // branch and bound's path route structure

struct comparer {
  bool operator()(const route l, const route r) { return l.bound > r.bound; }
};

long double calbound(route t, double** distance) {
  long double min1;  // shortest distance among all paths for one city
  long double min2;  // second shortest distance among all paths for one city
  long double minToGoal = numeric_limits<long double>::max();
  long double current;
  int novisits = t.novisit.size();
  long double bound = 0;

  for (int i = 0; i < novisits; i++) {
    current = distance[t.novisit[i]][0];
    if (current < minToGoal) minToGoal = current;
    min1 = distance[t.novisit[i]][t.path.back()];
    min2 = numeric_limits<long double>::max();
    for (int j = 0; j < novisits; j++) {
      if (i != j) {
        current = distance[t.novisit[j]][t.novisit[i]];
        if (current < min2) {
          if (current < min1) {
            min2 = min1;
            min1 = current;
          } else {
            min2 = current;
          }
        }
      }
    }
    bound += (min1 + min2);  // shortest possible path for one city
  }
  return ((bound / 2) + minToGoal + t.cost);
  // bound need to divided by 2 because each path was counted twice
}

void tsp(vector<pair<double, double> >& vets) {
  double** distance;

  int size = vets.size();

  distance = new double*[size];
  for (int i = 0; i < size; i++) {
    distance[i] = new double[size];
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      distance[i][j] = sqrt(pow((vets[i].first - vets[j].first), 2) +
                            pow((vets[i].second - vets[j].second), 2));
      // cout<<distance[i][j]<<" ";
    }
    // cout<<endl;
  }

  priority_queue<route, vector<route>, comparer> rpq;
  for (int i = 1; i < size; i++) {
    route current;
    current.path.push_back(i);
    for (int j = 1; j < size; j++) {
      if (j != i) current.novisit.push_back(j);
    }
    current.cost = distance[i][0];
    current.bound = calbound(current, distance);
    rpq.push(current);
  }

  route current;
  route next;

  // calcaulate one path as current best to reduce initial run qeueu size
  long double best = 0;
  for (int i = 0; i < size; i++) {
    best += distance[i][(i + 1) % size];
  }

  // branch and bound for shortest route
  int novisitsize;
  while (!rpq.empty()) {
    current = rpq.top();
    rpq.pop();
    novisitsize = current.novisit.size();
    cout << "current priority queue size " << rpq.size()
         << " unvisited cities in current path " << novisitsize << endl;
    for (int i = 0; i < novisitsize; i++) {
      next = current;
      next.path.push_back(current.novisit[i]);
      next.novisit.erase(next.novisit.begin() + i);
      next.cost =
          current.cost + distance[current.novisit[i]][current.path.back()];
      if (novisitsize == 2) {
        next.cost += distance[next.novisit.back()][next.path.back()];
        next.cost += distance[next.novisit.back()][0];
        if (next.cost < best) {
          best = next.cost;
          cout << " new best " << best << endl;
        }
        continue;
      }
      next.bound = calbound(next, distance);
      if (next.bound < best) rpq.push(next);
    }
  }
  cout << "The final best distance is " << best << endl;

  for (int i = 0; i < size; i++) {
    delete distance[i];
  }
  delete distance;
}
