#include <iostream>
#include "../DLL/DoubleLinkedList.h"
#include "InsertionSort.h"

using namespace std;

void insertionSort(Node** head) 
{
    Node* current = (*head)->ptrNext;
    while (current != nullptr) 
    {
        int InsertValue = current->iPayload;
        Node* temp = current->ptrPrev;
        while (temp != nullptr && temp->iPayload > InsertValue) 
        { 
            temp->ptrNext->iPayload = temp->iPayload;
            temp = temp->ptrPrev;
        }
        if (temp == nullptr) 
        { 
            (*head)->iPayload = InsertValue;
        } 
        else 
        {
            temp->ptrNext->iPayload = InsertValue;
        }
        current = current->ptrNext;
    }
}