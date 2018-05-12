#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "tsp.cc"

using namespace std;

int main( int argc, char ** argv ){

  ifstream input;

  if( argc == 2 ){
  	input.open(argv[1]);
  }else{
	cout<<"Please provide cities profile as input."<<endl;
  }

  if(input.fail()){
    cout<<"Cannot open input file!"<<endl;
    return -1;
  }

  vector< pair<double,double> > vets;
  int size;
  input >> size;

  pair<double, double> tmp; 
  for( int i=0 ; i < size ; i++){
    input >> tmp.first;
    input >> tmp.second;
    vets.push_back(tmp);
  }
  input.close();
 
  clock_t startTime = clock();
  tsp(vets);
  cout <<"Total run time is "<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

  return 0;
}
