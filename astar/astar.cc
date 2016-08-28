#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <fstream>
#include <queue>  
#include "astar.h"


int **Astar::allocateCostMap(int width, int height){

	int **costMap = new int*[width];
	for(int i=0 ; i< width ; i++){
		costMap[i]=new int[height];
	}
	for(int i=0 ; i < height ; i++){
	    for(int j=0 ; j < width ; j++){
		   costMap[j][i]=INT_MAX;	
	    }
	}	
	return costMap;
}

void Astar::deleteCostMap(int** costMap, int width){

	for(int i=0 ; i < width ; i++){
		delete [] costMap[i];
	}
	delete [] costMap;
}

int Astar::search( int width, int height, char** originalMap, pair<int,int> start , pair<int,int> destination){
	priority_queue< node,vector<node>, compare > pq;
	node current;
	node next;
	
	int **costMap = allocateCostMap(width,height);

	current.x = start.first;
	current.y = start.second;
	current.cost = 0;
	current.f=abs(current.x-destination.first)+abs(current.y-destination.second);
	costMap[current.x][current.y]=current.f;
	pq.push(current);

	while( !pq.empty() ){
		current = pq.top();
		pq.pop();
		//arrive at destination
		if( (current.x == destination.first) && (current.y == destination.second) ){
			deleteCostMap(costMap,width);
			return current.cost;
		}
		//try east
		if( (current.x+1<width)&&(originalMap[(current.x+1)][current.y]!='#')){
			next.x=current.x+1;
			next.y=current.y;
			next.cost=current.cost +1;
			next.f= next.cost + abs(next.x-destination.first)+abs(next.y-destination.second); 
			if( costMap[next.x][next.y] > next.f){
					pq.push(next);
					costMap[next.x][next.y] = next.f;
			}
		}
		//try west
		if((current.x-1>=0)&&(originalMap[(current.x-1)][current.y]!='#')){ 
			next.x=current.x-1;
			next.y=current.y;
			next.cost=current.cost +1;
			next.f= next.cost + abs(next.x-destination.first)+abs(next.y-destination.second);
			if( costMap[next.x][next.y] > next.f){
					pq.push(next);
					costMap[next.x][next.y] = next.f;
			}
		}
		//try south
		if((current.y-1>=0)&&(originalMap[(current.x)][current.y-1]!='#')){
			next.x=current.x;
			next.y=current.y-1;
			next.cost=current.cost +1;
			next.f= next.cost + abs(next.x-destination.first)+abs(next.y-destination.second);
			if( costMap[next.x][next.y] > next.f){
					pq.push(next);
					costMap[next.x][next.y] = next.f;
			}
		}
		//try north
		if((current.y+1<height)&&(originalMap[(current.x)][current.y+1]!='#')){
			next.x=current.x;
			next.y=current.y+1;
			next.cost=current.cost +1;
			next.f= next.cost + abs(next.x-destination.first)+abs(next.y-destination.second);
			if( costMap[next.x][next.y] > next.f){
					pq.push(next);
					costMap[next.x][next.y] = next.f;
			}
		}
	}	
	deleteCostMap(costMap,width);
	return -1;
}
