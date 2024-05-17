#include <iostream>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "DLL/DoubleLinkedList.h"
#include "SelectionSort/SelectionSort.h"
#include "InsertionSort/InsertionSort.h"
#include "BubbleSort/BubbleSort.h"
#include "TestAlgorithms/TestAlgorithms.h"


using namespace std;

int main() {
    int iLength = pow(10, 4);
    int iNumTests = 1;
    cout << "===================================" << endl;
    cout << "-- Bubble Sort Ruim --" << endl;
    auto TimeBubbleSortRuim = testAlgorithms(bubbleSortRuim, iLength, iNumTests);
    cout << TimeBubbleSortRuim[0].count() * pow(10, -9) << " segundos" << endl;

    cout << "===================================" << endl;
    cout << "-- Optmized Bubble Sort --" << endl;
    auto TimeOptimizedBubbleSort = testAlgorithms(optmizedbubbleSort, iLength, iNumTests);
    cout << TimeOptimizedBubbleSort[0].count() * pow(10, -9) << " segundos" << endl;

    cout << "===================================" << endl;
    cout << "-- Selection Sort Ruim --" << endl;
    auto TimeSelectionSortRuim = testAlgorithms(selectionSortRuim, iLength, iNumTests);
    cout << TimeSelectionSortRuim[0].count() * pow(10, -9) << " segundos" << endl;

    cout << "===================================" << endl;
    cout << "-- Optmized Selection Sort --" << endl;
    auto TimeOptimizedSelectionSort = testAlgorithms(optimizedselectionSort, iLength, iNumTests);
    cout << TimeOptimizedSelectionSort[0].count() * pow(10, -9) << " segundos" << endl;

    cout << "===================================" << endl;
    cout << "-- Insertion Sort --" << endl;
    auto TimeInsertionSort = testAlgorithms(insertionSort, iLength, iNumTests);
    cout << TimeInsertionSort[0].count() * pow(10, -9) << " segundos" << endl;

    return 0;
}
