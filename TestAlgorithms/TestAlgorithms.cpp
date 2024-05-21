#include "TestAlgorithms.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace cpa {

template<typename T>
void testAlgorithms(void (*algorithms)(cpa::Node<T>**), int iLength, int iNumTests, const std::string& filename) 
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
        cpa::Node<T>* head = nullptr;
        cpa::generateRandomList<T>(&head, iLength);
        auto timeStart = high_resolution_clock::now();
        algorithms(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        outFile << timeDuration.count() * 1e-9 << endl;

        // Delete the list
        while (head != nullptr) 
        {
            cpa::Node<T>* temp = head;
            head = head->ptrNext;
            delete temp;
        }
    }

    outFile.close();
}

// Explicit instantiation of the template functions you plan to use
template void testAlgorithms<int>(void (*algorithms)(cpa::Node<int>**), int iLength, int iNumTests, const std::string& filename);

}
