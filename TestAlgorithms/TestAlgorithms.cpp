#include "TestAlgorithms.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace TestAlgorithms {

template<typename T>
void testAlgorithms(void (*algorithms)(DLL::Node<T>**), int iLength, int iNumTests, const std::string& filename) 
{
    std::string directory = "DadosDesempenho";
    std::string fullPath = directory + "/" + filename;

    ofstream outFile(fullPath);
    if (!outFile.is_open()) 
    {
        cerr << "Unable to open file: " << fullPath << endl;
        return;
    }

    // Calculate times
    for(int i = 0; i < iNumTests; i++) 
    {
        DLL::Node<T>* head = nullptr;
        DLL::generateRandomList<T>(&head, iLength);
        auto timeStart = high_resolution_clock::now();
        algorithms(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        outFile << timeDuration.count() * 1e-9 << endl;

        // Delete the list
        while (head != nullptr) 
        {
            DLL::Node<T>* temp = head;
            head = head->ptrNext;
            delete temp;
        }
    }

    outFile.close();
}

// Explicit instantiation of the template functions you plan to use
template void testAlgorithms<int>(void (*algorithms)(DLL::Node<int>**), int iLength, int iNumTests, const std::string& filename);

}
