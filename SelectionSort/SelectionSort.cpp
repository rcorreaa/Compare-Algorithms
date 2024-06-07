#include "SelectionSort.h"
#include <iostream>

using namespace std;

namespace cpa {

template<typename T>
void selectionSortRuim(Node<T>** head) 
{
    Node<T>* current = *head;
    while (current != nullptr) 
    {
        Node<T>* temp = current->ptrNext;
        while (temp != nullptr) 
        {
            if (current->iPayload > temp->iPayload) 
            {
                T iTemp = temp->iPayload;
                temp->iPayload = current->iPayload;
                current->iPayload = iTemp;
            }
            temp = temp->ptrNext;
        }
        current = current->ptrNext;
    }
}

template<typename T>
void optimizedSelectionSort(Node<T>** head) 
{
    Node<T>* minNode = nullptr;
    Node<T>* current = *head;
    while (current != nullptr) 
    {
        minNode = current;
        Node<T>* temp = current->ptrNext;
        while (temp != nullptr) 
        {
            if (temp->iPayload < minNode->iPayload) 
            {
                minNode = temp;
            }
            temp = temp->ptrNext;
        }
        if (minNode != current) {
            T iTemp = minNode->iPayload;
            minNode->iPayload = current->iPayload;
            current->iPayload = iTemp;
        }
        current = current->ptrNext;
    }
}

template void selectionSortRuim<int>(Node<int>**);
template void optimizedSelectionSort<int>(Node<int>**);

}