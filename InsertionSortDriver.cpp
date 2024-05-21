#include <iostream>
#include "DLL/DoubleLinkedList.h"
#include "InsertionSort/InsertionSort.h"
#include "TestAlgorithms/TestAlgorithms.h"

using namespace std;
using namespace InsertionSort;
using namespace TestAlgorithms;

int main() 
{
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Testing Insertion Sort" << endl;
    testAlgorithms<int>(insertionSort<int>, iLength, iNumTests, "InsertionSort.txt");

    return 0;
}
