#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include "dijkstra.h"

using namespace std;

void dijkstra( int vertices, int startPoint, int*distance, vector< vector< pair<int,int> > > adjlist ){

	bool *visit = new bool[vertices];
	priority_queue< pair<int,int> ,vector< pair<int,int> >, compare > pq;
	pair<int,int> current;

	fill_n(visit, vertices, 0 );
	current.first=startPoint;
	current.second=0;

	pq.push(current);

	while( !pq.empty() ){
 		current = pq.top();
 		pq.pop();
        	if( visit[current.first-1] ){
 	   		continue;
        	}else{
 			visit[current.first-1]=1;
 			distance[current.first-1]=current.second;
        	}

		for( unsigned int i=0; i< adjlist[current.first-1].size() ; i++){
 			if( visit[adjlist[current.first-1][i].first-1] ==0){
				pair<int,int> neighbor;
				neighbor.first = adjlist[current.first-1][i].first;
				neighbor.second = current.second+adjlist[current.first-1][i].second;
				pq.push(neighbor);
			}
		}
	}

}
