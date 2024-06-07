#pragma once


namespace cpa {

template<typename T>
struct Node {
    T iPayload;
    Node* ptrPrev;
    Node* ptrNext;
};

template<typename T>
Node<T>* createNode(T);

template<typename T>
void insertFront(Node<T>**, T);

template<typename T>
void insertEnd(Node<T>**, T);

template<typename T>
void displayList(Node<T>*);

template<typename T>
void generateRandomList(Node<T> **, int);

template<typename T>
int countElements(Node<T>**);

template<typename T>
Node<T>* getNode(Node<T>*,int);

}
