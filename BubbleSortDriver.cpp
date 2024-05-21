#include <iostream>
#include "MainHeader/cpa.h"

using namespace std;
using namespace cpa;

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
