#pragma once
#include <string>
namespace bt{

template<typename T>
struct Node 
{
    T iPayload;
    Node* ptrLeft;
    Node* ptrRight;
};

template <typename T>
Node<T>* newNode(T);

template <typename T>
Node<T>* insertNode(Node<T>*, T);

template <typename T>
Node<T>* searchNodeDFS(Node<T>*, T);

Node<int>* generateRandomTree(int);

template <typename T>
void traversePreOrder(Node<T>*);

template <typename T>
Node<T>* bfsTraversal(Node<T>*, T);

template <typename T>
void deleteTree(Node<T>* node);

void measureBinaryTreeCreation(Node<int>* (*generateTree)(int), int numNodes, int numTests, const std::string& filename);

void benchmarkSearchMethod(Node<int>* (*searchMethod)(Node<int>*, int), int numNodes, int iterations, const std::string& filename);
}
