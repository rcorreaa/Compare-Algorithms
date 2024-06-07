#include "InsertionSort.h"
#include <iostream>

using namespace std;

namespace cpa {

template<typename T>
void insertionSort(Node<T>** head) 
{
    Node<T>* current = (*head)->ptrNext;
    while (current != nullptr) 
    {
        T InsertValue = current->iPayload;
        Node<T>* temp = current->ptrPrev;
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


template void insertionSort<int>(Node<int>**);

} 
