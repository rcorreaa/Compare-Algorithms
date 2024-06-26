#include "../MainHeader/cpa.h"
#include "BinaryTree.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
using namespace std::chrono;

namespace bt{

template <typename T>
Node<T>* newNode(T iData)
{
    Node<T>* tmp = new Node<T>();
  
    if (tmp != nullptr)
    {
        tmp->iPayload = iData;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
    }
  
    return tmp;
}

template <typename T>
Node<T>* insertNode(Node<T>* startingNode, T iData)
{
    if(startingNode == nullptr)
    {
        return newNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

template <typename T>
Node<T>* searchNodeDFS(Node<T>* startingNode, T iData)
{
    if(startingNode == nullptr) return nullptr;
    else if(iData == startingNode->iPayload) return startingNode;
    else if(iData < startingNode->iPayload) return searchNodeDFS(startingNode->ptrLeft, iData);
    else return searchNodeDFS(startingNode->ptrRight, iData);
}


Node<int>* generateRandomTree(int numNodes)
{
    Node<int>* root = nullptr;
    srand(time(0));
    
    for(int i = 0; i < numNodes; ++i)
    {
        int randomValue = rand() % 100 + 1;
        root = insertNode(root, randomValue);
    }
    
    return root;
}

template <typename T>
void traversePreOrder(Node<T>* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        traversePreOrder(ptrStartingNode->ptrLeft);
        traversePreOrder(ptrStartingNode->ptrRight);
    }
}

template <typename T>
Node<T>* bfsTraversal(Node<T>* startingNode, T target)
{
    if(startingNode == nullptr) return nullptr;
    
    cpa::Node<Node<T>*>* head = nullptr;
    cpa::insertEnd(&head, startingNode);
    
    while(head != nullptr)
    {
        Node<T>* currentNode = head->iPayload;
        head = head->ptrNext;
        
        if(currentNode->iPayload == target)
        {
            // Limpar a lista usada como fila
            while (head != nullptr)
            {
                cpa::Node<Node<T>*>* temp = head;
                head = head->ptrNext;
                delete temp;
            }
            return currentNode;
        }
        
        if(currentNode->ptrLeft != nullptr)
        {
            cpa::insertEnd(&head, currentNode->ptrLeft);
        }
        if(currentNode->ptrRight != nullptr)
        {
            cpa::insertEnd(&head, currentNode->ptrRight);
        }
    }
    
    return nullptr;
}

template <typename T>
void deleteTree(Node<T>* node)
{
    if (node == nullptr) return;

    deleteTree(node->ptrLeft);
    deleteTree(node->ptrRight);
    
    delete node;
}

void measureBinaryTreeCreation(Node<int>* (*generateTree)(int), int numNodes, int numTests, const std::string& filename) 
{
    std::string directory = "DadosDesempenho";
    std::string fullPath = directory + "/" + filename;

    ofstream outFile(fullPath);
    if (!outFile.is_open()) 
    {
        cerr << "Unable to open file: " << fullPath << endl;
        return;
    }

    for(int i = 0; i < numTests; i++) 
    {
        auto timeStart = high_resolution_clock::now();
        Node<int>* tree = generateTree(numNodes);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        outFile << timeDuration.count() * 1e-9 << endl;
        
        // Limpar a árvore gerada
        deleteTree(tree);
    }

    outFile.close();
}

void benchmarkSearchMethod(Node<int>* (*searchMethod)(Node<int>*, int), int numNodes, int iterations, const std::string& filename) {
    std::ofstream outFile("DadosDesempenho/" + filename);
    if (!outFile.is_open()) {
        std::cerr << "Unable to open file";
        return;
    }

    for (int i = 0; i < iterations; ++i) {
        Node<int>* root = generateRandomTree(numNodes);
        int target = rand() % 100 + 1;  // Alvo aleatório para a busca

        auto timeStart = high_resolution_clock::now();

        searchMethod(root, target);

        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        outFile << timeDuration.count() * 1e-9 << endl;

        // Liberar a memória da árvore
        deleteTree(root);
    }

    outFile.close();
}

template Node<int>* newNode<int>(int);
template Node<int>* insertNode<int>(Node<int>*, int);
template Node<int>* searchNodeDFS(Node<int>*, int);
template void traversePreOrder(Node<int>*);
template Node<int>* bfsTraversal(Node<int>*,int);
template void deleteTree(Node<int>*);

}
