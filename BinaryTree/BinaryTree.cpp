#include "../MainHeader/cpa.h"
#include "BinaryTree.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <chrono>
#include <functional>
#include <windows.h>
#include<string>

using namespace std;
using namespace std::chrono;

namespace bt {

// Função para criar um novo nó
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

// Função para inserir um nó na árvore
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

// Função para buscar um nó usando DFS
template <typename T>
Node<T>* searchNodeDFS(Node<T>* startingNode, T iData)
{
    if(startingNode == nullptr) return nullptr;
    else if(iData == startingNode->iPayload) return startingNode;
    else if(iData < startingNode->iPayload) return searchNodeDFS(startingNode->ptrLeft, iData);
    else return searchNodeDFS(startingNode->ptrRight, iData);
}

// Função para gerar uma árvore binária aleatória
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

// Função para travessia em pré-ordem
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

// Função para busca em largura (BFS)
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

// Função para medir o tempo de execução
template<typename T>
double measureExecutionTime(void (*algorithm)(cpa::Node<T>**), cpa::Node<T>** head) 
{
    auto timeStart = high_resolution_clock::now();
    algorithm(head);
    auto timeStop = high_resolution_clock::now();
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    return timeDuration.count() * 1e-9; // Retorna o tempo em segundos
}

// Função para criar diretório se não existir
void createDirectoryIfNotExists(const std::string& directory)
{
    // Converter std::string para std::wstring
    std::wstring wDirectory(directory.begin(), directory.end());
    if (!CreateDirectoryW(wDirectory.c_str(), NULL) && GetLastError() != ERROR_ALREADY_EXISTS) 
    {
        cerr << "Erro ao criar diretório: " << directory << endl;
        exit(1);
    }
}

// Função para testar algoritmos
template<typename T>
void testAlgorithms(void (*algorithm)(cpa::Node<T>**), int iLength, const std::string& filename) 
{
    std::string directory = "DadosDesempenho";
    std::string fullPath = directory + "/" + filename;

    // Garantir que o diretório existe
    createDirectoryIfNotExists(directory);

    ofstream outFile(fullPath);
    if (!outFile.is_open()) 
    {
        cerr << "Unable to open file: " << fullPath << endl;
        return;
    }

    // Executar o teste 100 vezes
    const int iNumTests = 100;
    for(int i = 0; i < iNumTests; i++) 
    {
        cpa::Node<T>* head = nullptr;
        cpa::generateRandomList<T>(&head, iLength);
        double duration = measureExecutionTime<T>(algorithm, &head);
        outFile << duration << endl;

        // Liberar a lista
        while (head != nullptr) 
        {
            cpa::Node<T>* temp = head;
            head = head->ptrNext;
            delete temp;
        }
    }

    outFile.close();
}

// Instanciações explícitas das templates
template Node<int>* newNode<int>(int);
template Node<int>* insertNode<int>(Node<int>*, int);
template Node<int>* searchNodeDFS<int>(Node<int>*, int);
template void traversePreOrder<int>(Node<int>*);
template Node<int>* bfsTraversal<int>(Node<int>*, int);
template void testAlgorithms<int>(void (*algorithm)(cpa::Node<int>**), int iLength, const std::string& filename);

} // namespace bt
