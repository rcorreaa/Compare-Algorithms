#include  <iostream>
#include <chrono>
#include "../DLL/DoubleLinkedList.h"
#include "TestAlgorithms.h"

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::nanoseconds;

chrono::duration<double>* testAlgorithms(void (*algorithms)(Node**), int iLength, int iNumTests) {
    auto TestsTime = new std::chrono::duration<double>[iNumTests];
    for(int i = 0; i < iNumTests; i++) 
    {
        Node* head = nullptr;
        generateRandomList(&head, iLength);
        auto timeStart = high_resolution_clock::now();
        algorithms(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        TestsTime[i] = std::chrono::seconds(timeDuration.count());
    }
    return TestsTime;
}