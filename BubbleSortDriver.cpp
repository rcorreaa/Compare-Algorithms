#include <iostream>
#include "DLL/DoubleLinkedList.h"
#include "BubbleSort/BubbleSort.h"
#include "TestAlgorithms/TestAlgorithms.h"

using namespace std;
using namespace TestAlgorithms;
using namespace BubbleSort;

int main() 
{
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Testing Bubble Sort (Ruim)" << endl;
    testAlgorithms<int>(bubbleSortRuim<int>, iLength, iNumTests, "BubbleSortRuim.txt");

    cout << "Testing Optimized Bubble Sort" << endl;
    testAlgorithms<int>(optimizedBubbleSort<int>, iLength, iNumTests, "OptimizedBubbleSort.txt");

    return 0;
}
