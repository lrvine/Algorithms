#include "quickSort.h"

void pickMedianOfThree(vector<int>& array, int startIndex, int backIndex) {
    int midIndex = (backIndex + startIndex) / 2;
    // make the last element as the max of three
    if (array[midIndex] > array[backIndex])
        swap(array[midIndex], array[backIndex]);
    if (array[startIndex] > array[backIndex])
        swap(array[startIndex], array[backIndex]);
    // put the median to the position of the startIndex
    if (array[midIndex] > array[startIndex])
        swap(array[startIndex], array[midIndex]);
}

void quickSortWithRangeIndex(vector<int>& array, int startIndex, int endIndex) {
    int numElements = endIndex - startIndex;

    if ((numElements == 0) || (numElements == 1)) return;

    // position startIndex would be the midian of three
    pickMedianOfThree(array, startIndex, endIndex - 1);
    int pivot = array[startIndex];

    int partitionLine = startIndex + 1;
    for (int i = startIndex + 1; i < endIndex; ++i) {
        if (array[i] <= pivot) {
            if (array[i] != array[partitionLine])
                swap(array[i], array[partitionLine]);
            partitionLine++;
        }
    }
    swap(array[startIndex], array[partitionLine - 1]);

    quickSortWithRangeIndex(array, startIndex, partitionLine - 1);
    quickSortWithRangeIndex(array, partitionLine, endIndex);
}

void quickSort(vector<int>& array) {
    quickSortWithRangeIndex(array, 0, array.size());
}