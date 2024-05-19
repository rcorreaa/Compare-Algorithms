#include <iostream>
#include "DLL/DoubleLinkedList.h"
#include "BubbleSort/BubbleSort.h"
#include "TestAlgorithms/TestAlgorithms.h"

using namespace std;

int main() 
{
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Testing Bubble Sort (Ruim)" << endl;
    testAlgorithms(bubbleSortRuim, iLength, iNumTests, "BubbleSortRuim.txt");

    cout << "Testing Optimized Bubble Sort" << endl;
    testAlgorithms(optmizedbubbleSort, iLength, iNumTests, "OptimizedBubbleSort.txt");

    return 0;
}
