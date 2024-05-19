#include <iostream>
#include "DLL/DoubleLinkedList.h"
#include "SelectionSort/SelectionSort.h"
#include "TestAlgorithms/TestAlgorithms.h"

using namespace std;

int main() 
{
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Testing Selection Sort (Ruim)" << endl;
    testAlgorithms(selectionSortRuim, iLength, iNumTests, "SelectionSortRuim.txt");

    cout << "Testing Optimized Selection Sort" << endl;
    testAlgorithms(optimizedselectionSort, iLength, iNumTests, "OptimizedSelectionSort.txt");

    return 0;
}
