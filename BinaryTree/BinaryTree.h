#pragma once

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
}