#pragma once


namespace DLL {

template<typename T>
struct Node {
    T iPayload;
    Node* ptrPrev;
    Node* ptrNext;
};

template<typename T>
Node<T>* createNode(T iPayload);

template<typename T>
void insertFront(Node<T>** head, T iPayload);

template<typename T>
void displayList(Node<T>* node);

template<typename T>
void generateRandomList(Node<T> **head, int size);

template<typename T>
int countElements(Node<T>** head);

}
