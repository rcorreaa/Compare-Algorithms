#include <iostream>
#include "DLL/DoubleLinkedList.h"
#include "InsertionSort/InsertionSort.h"
#include "TestAlgorithms/TestAlgorithms.h"

using namespace std;

int main() 
{
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Testing insertion Sort" << endl;
    testAlgorithms(insertionSort, iLength, iNumTests, "InsertionSort.txt");

    return 0;
}