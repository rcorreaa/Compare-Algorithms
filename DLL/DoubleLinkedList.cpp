#include "../BinaryTree/BinaryTree.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace cpa {

template<typename T>
Node<T>* createNode(T iPayload) 
{
    Node<T>* temp = new Node<T>;
    temp->iPayload = iPayload;
    temp->ptrPrev = nullptr;
    temp->ptrNext = nullptr;
    return temp;
}

template<typename T>
void insertFront(Node<T>** head, T iPayload) 
{
    Node<T>* newNode = createNode(iPayload);
    if (*head != nullptr) 
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    (*head) = newNode;
}

template<typename T>
void insertEnd(Node<T>** head, T iPayload)
{
    Node<T>* newNode = createNode(iPayload);
    if (*head == nullptr)  (*head) = newNode;
    else
    {
        Node<T>* current = *head;
        while(current->ptrNext != nullptr)
        {
            current = current->ptrNext;
        }
        current->ptrNext = newNode;
        newNode->ptrPrev = current;
    }
}


template<typename T>
void displayList(Node<T>* node) 
{
    if (node == nullptr) 
    {
        cout << "displayList: Node nulo, lista vazia" << endl;
        return;
    }

    if (node->ptrPrev != nullptr) 
    {
        cout << "displayList: Node prev nao nulo, nao podemos printar" << endl;
        return;
    }

    Node<T>* current = node;
    cout << "Payload: ";
    while (current) 
    {
        cout << current->iPayload << " ";
        current = current->ptrNext;
    }
    cout << endl;
}

template<typename T>
void generateRandomList(Node<T> **head, int size)
{
    srand(time(nullptr));
    for (int i = 0; i < size; ++i)
    {
        T randomNum = static_cast<T>(rand() % 100);
        insertFront(head, randomNum);
    }
}

template<typename T>
int countElements(Node<T>** head)
{
    Node<T>* current = *head;
    int iCount = 0;
    while(current)
    {
        iCount++;
        current = current->ptrNext;
    }
    return iCount;
}


template<typename T>
Node<T>* getNode(Node<T>* head, int index) 
{
    Node<T>* current = head;
    for (int i = 0; i < index && current != nullptr; i++) 
    {
        current = current->ptrNext;
    }
    return current;
}

template Node<int>* createNode<int>(int);
template void insertFront<int>(Node<int>**, int);
template void insertEnd<int>(Node<int>**, int);
template void insertEnd<bt::Node<int>*>(Node<bt::Node<int>*>**, bt::Node<int>*);
template void displayList<int>(Node<int>*);
template void generateRandomList<int>(Node<int>**, int);
template int countElements<int>(Node<int>**);
template Node<int>* getNode(Node<int>*, int);

}
