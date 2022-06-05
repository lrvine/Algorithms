#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "quickSort.h"

using namespace std;

int main(int argc, char** argv) {
    string infilename;
    string outfilename;

    if (argc == 3) {
        infilename = argv[1];
        outfilename = argv[2];
    } else {
        infilename = "quickSort.txt";
        outfilename = "sorted.txt";
    }

    cout << "start quick sort on file " << infilename << " and output to file "
         << outfilename << endl;

    ifstream input;

    input.open(infilename);
    if (input.fail()) {
        cout << "input error!" << endl;
        return -1;
    }

    vector<int> arrayToSort;
    for (string line; getline(input, line);) {
        arrayToSort.push_back(stoi(line));
    }

    input.close();

    auto start = chrono::steady_clock::now();

    quickSort(arrayToSort);

    // Recording end time.
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;

    ofstream output;
    output.open(outfilename);
    if (output.fail()) {
        cout << "output error!" << endl;
        return -1;
    }

    for (auto& i : arrayToSort) {
        output << i << endl;
    }
    output.close();

    cout << "Finished storing result to file. " << endl;

    return 0;
}