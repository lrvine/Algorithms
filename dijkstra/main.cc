#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include "dijkstra.h"
using namespace std;


int main( int argc, char** argv ){

int vertices=atoi(argv[2]);

int *distance = new int[vertices];


ifstream input;

input.open(argv[1]);


if(input.fail()){
  cout<<" input error "<<endl;
  return -1;
}

vector< vector< pair<int,int> > > adjlist;

//read adjacency list
string s;
string buf;
for(int i=0; i<vertices ; i++){
  distance[i]=-1;
  getline(input,s);

  istringstream iss(s);
  iss>>buf;
  
  vector< pair<int,int> > vex;

  while(iss>>buf){
    istringstream split(buf);
   
    pair<int,int> edge;
    getline(split,buf,',');
    stringstream ss(buf);
    ss>>edge.first;   
    getline(split,buf,',');
    stringstream ss2(buf);
    ss2>>edge.second;
//    cout<<i<<" edge "<<edge.first<<" "<<edge.second<<endl;
    vex.push_back(edge);
  }  
 
  adjlist.push_back(vex);
}


dijkstra(vertices,1,distance,adjlist);

//print out the shortest path to each point
cout<<" The shortest path from vertex 1 to each vertex are "<<endl;
for(int i=0; i<vertices ; i++){
  cout<<distance[i]<<" ";
} 
cout<<endl;

delete [] distance;

return 0;

}
