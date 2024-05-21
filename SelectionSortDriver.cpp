#include <iostream>
#include "MainHeader/cpa.h"

using namespace std;
using namespace cpa;

int main() 
{
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Testing Selection Sort (Ruim)" << endl;
    testAlgorithms<int>(selectionSortRuim<int>, iLength, iNumTests, "SelectionSortRuim.txt");

    cout << "Testing Optimized Selection Sort" << endl;
    testAlgorithms<int>(optimizedSelectionSort<int>, iLength, iNumTests, "OptimizedSelectionSort.txt");

    return 0;
}
