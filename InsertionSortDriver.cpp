#include <iostream>
#include "MainHeader/cpa.h"

using namespace std;
using namespace cpa;

int main() 
{
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Testing Insertion Sort" << endl;
    testAlgorithms<int>(insertionSort<int>, iLength, iNumTests, "InsertionSort.txt");

    return 0;
}
