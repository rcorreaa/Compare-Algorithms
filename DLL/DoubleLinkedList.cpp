#include "DoubleLinkedList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Node* createNode(int iPayload) 
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrPrev = nullptr;
    temp->ptrNext = nullptr;
    return temp;
}

void insertFront(Node** head, int iPayload) 
{
    Node* newNode = createNode(iPayload);
    if (*head != nullptr) 
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    (*head) = newNode;
}

void displayList(Node* node) 
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

    Node* current = node;
    cout << "Payload: ";
    while (current) 
    {
        cout << current->iPayload << " ";
        current = current->ptrNext;
    }
    cout << endl;
}


void generateRandomList(Node **head, int size)
{
    srand(time(nullptr));
    for (int i = 0; i < size; ++i)
    {
        int randomNum = rand() % 100;
        insertFront(head, randomNum);
    }
}