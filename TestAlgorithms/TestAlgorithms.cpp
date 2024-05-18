#include <iostream>
#include <chrono>
#include <fstream>
#include "../DLL/DoubleLinkedList.h"
#include "TestAlgorithms.h"

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration_cast;
using chrono::nanoseconds;

void testAlgorithms(void (*algorithms)(Node**), int iLength, int iNumTests, const std::string& filename) 
{
    ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    // calcula os tempos
    for(int i = 0; i < iNumTests; i++) 
    {
        Node* head = nullptr;
        generateRandomList(&head, iLength);
        auto timeStart = high_resolution_clock::now();
        algorithms(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        outFile << timeDuration.count() * 1e-9 << " seconds" << endl;

        // Deleta a lista
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head->ptrNext;
            delete temp;
        }
    }

    outFile.close();
}
