#include "TestAlgorithms.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <windows.h>

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

template<typename T>
void measureGenerationTime(Node<T>* (*generate)(int), int size, int numTests, const std::string& filename) {
    std::string directory = "DadosDesempenho";
    CreateDirectory(directory.c_str(), NULL); // Create directory if it doesn't exist
    std::string fullPath = directory + "/" + filename;

    ofstream outFile(fullPath);
    if (!outFile.is_open()) {
        cerr << "Unable to open file: " << fullPath << endl;
        return;
    }

    for (int i = 0; i < numTests; i++) {
        auto timeStart = high_resolution_clock::now();
        Node<T>* root = generate(size);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        outFile << timeDuration.count() * 1e-9 << endl;

        // Delete the tree
        deleteTree(root);
    }

    outFile.close();
}

template<typename T>
void measureSearchTime(void (*search)(Node<T>*), Node<T>* (*generate)(int), int size, int numTests, const std::string& filename) {
    std::string directory = "DadosDesempenho";
    CreateDirectory(directory.c_str(), NULL); // Create directory if it doesn't exist
    std::string fullPath = directory + "/" + filename;

    ofstream outFile(fullPath);
    if (!outFile.is_open()) {
        cerr << "Unable to open file: " << fullPath << endl;
        return;
    }

    for (int i = 0; i < numTests; i++) {
        Node<T>* root = generate(size);
        auto timeStart = high_resolution_clock::now();
        search(root);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        outFile << timeDuration.count() * 1e-9 << endl;

        // Delete the tree
        deleteTree(root);
    }

    outFile.close();
}

template<typename T>
void deleteTree(Node<T>* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

template void testAlgorithms<int>(void (*algorithms)(cpa::Node<int>**), int iLength, int iNumTests, const std::string& filename);
template void measureGenerationTime<int>(Node<int>* (*generate)(int), int size, int numTests, const std::string& filename);
template void measureSearchTime<int>(void (*search)(Node<int>*), Node<int>* (*generate)(int), int size, int numTests, const std::string& filename);

}
