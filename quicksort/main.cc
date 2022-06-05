#include <cstdlib>
#include <fstream>
#include <iostream>
#include "quicksort.cc"

using namespace std;

int main(int argc, char **argv) {
  int *array;
  int length;
  string infilename;
  string outfilename;

  if (argc == 4) {
    length = atoi(argv[1]);
    infilename = argv[2];
    outfilename = argv[3];
  } else {
    length = 10000;
    infilename = "QuickSort.txt";
    outfilename = "Sorted.txt";
  }

  ifstream input;
  input.open(infilename);
  if (input.fail()) {
    cout << "input error!" << endl;
    return 1;
  }

  ofstream output;
  output.open(outfilename);

  cout << "start quicksort on file " << infilename << " with legnth " << length
       << endl;
  array = new int[length];
  for (int i = 0; i < length; i++) {
    input >> array[i];
  }

  input.close();

  quicksort(array, length);

  cout << "end" << endl;
  for (int i = 0; i < length; i++) {
    output << array[i] << endl;
  }
  output.close();
  delete array;
  return 0;
}
