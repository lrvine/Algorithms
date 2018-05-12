#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "prims.cc"

using namespace std;


int main( int argc, char** argv){

ifstream input;

if ( argc == 2 ) {
  	input.open(argv[1]);
}else{
	cout<<"Please provide cities profile as input."<<endl;
}

if (input.fail()) {
	cout<<"Cannot open input file!"<<endl;
	return -1;
}

vector<int> visit;
vector<int> nv;

int numNode;
int edges;
input >> numNode;
input >> edges;


int **matrix= new int*[numNode];
for(int i = 0; i < numNode; i++){
	matrix[i] = new int[numNode];
  	nv.push_back(i);
}

for(int i = 0; i < numNode; i++){
  	for(int j = 0; j < numNode; j++){
    		matrix[i][j] = INT_MAX;
  	}
}


int nodeA;
int nodeB;
long long cost;

for( int i = 0; i < edges; i++){

input >> nodeA;
input >> nodeB;
input >> cost;

matrix[nodeA-1][nodeB-1] = cost;
matrix[nodeB-1][nodeA-1] = cost;

}

input.close();


cost = prims(matrix,numNode);

cout<<" total cost "<<cost<<endl;

for(int i = 0; i < numNode ; i++){
	delete matrix[i];
}
delete [] matrix;

return 0;
}
