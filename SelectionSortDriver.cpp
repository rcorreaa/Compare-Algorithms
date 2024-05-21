#include <iostream>
#include "DLL/DoubleLinkedList.h"
#include "SelectionSort/SelectionSort.h"
#include "TestAlgorithms/TestAlgorithms.h"

using namespace std;
using namespace SelectionSort;
using namespace TestAlgorithms;

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
