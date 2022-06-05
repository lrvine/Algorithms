#include "mergeSort.h"

#include <algorithm>

inline void mergeArray(vector<int>& array, int firstStartPoint,
                       int seocndStartPoint, int endOfSubArray,
                       vector<int>& mergedArray, int mergedIndex) {
    int firstIndex = firstStartPoint;
    int secondIndex = seocndStartPoint;

    while (firstIndex < seocndStartPoint || secondIndex < endOfSubArray) {
        if (secondIndex >= endOfSubArray ||
            (firstIndex < seocndStartPoint &&
             array[firstIndex] <= array[secondIndex])) {
            mergedArray[mergedIndex] = array[firstIndex];
            ++firstIndex;
        } else {
            mergedArray[mergedIndex] = array[secondIndex];
            ++secondIndex;
        }
        ++mergedIndex;
    }
}

void mergeSortIterative(vector<int>& array) {
    int numElements = array.size();
    vector<int> workArray(numElements);

    if (numElements == 0 || numElements == 1) return;

    for (int spacing = 1; spacing < numElements; spacing = spacing * 2) {
        for (int subMergeStart = 0; subMergeStart < numElements;
             subMergeStart = (subMergeStart + (spacing * 2))) {
            mergeArray(array, subMergeStart,
                       min((subMergeStart + spacing), numElements - 1),
                       min((subMergeStart + 2 * spacing), numElements),
                       workArray, subMergeStart);
        }
        array.swap(workArray);
    }
}

void mergeSortRecursiveWithRangeIndex(vector<int>& array, int front, int back) {
    if (front >= back) return;

    int mid = (front + back) / 2;

    mergeSortRecursiveWithRangeIndex(array, front, mid);
    mergeSortRecursiveWithRangeIndex(array, mid + 1, back);

    int indexFirst = front;
    int indexSecond = mid + 1;

    vector<int> mergedArray(back - front + 1);
    mergeArray(array, indexFirst, indexSecond, back + 1, mergedArray, 0);
    swap_ranges(array.begin() + front, array.begin() + back + 1,
                mergedArray.begin());
}

void mergeSortRecursive(vector<int>& array) {
    mergeSortRecursiveWithRangeIndex(array, 0, array.size() - 1);
}