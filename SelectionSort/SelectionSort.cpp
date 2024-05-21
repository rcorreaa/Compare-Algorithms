#include "SelectionSort.h"
#include <iostream>

using namespace std;
using namespace DLL;

namespace SelectionSort {

template<typename T>
void selectionSortRuim(DLL::Node<T>** head) 
{
    DLL::Node<T>* current = *head;
    while (current != nullptr) 
    {
        DLL::Node<T>* temp = current->ptrNext;
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
void optimizedSelectionSort(DLL::Node<T>** head) 
{
    DLL::Node<T>* minNode = nullptr;
    DLL::Node<T>* current = *head;
    while (current != nullptr) 
    {
        minNode = current;
        DLL::Node<T>* temp = current->ptrNext;
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

// Explicit instantiation of the template functions
template void selectionSortRuim<int>(DLL::Node<int>**);
template void optimizedSelectionSort<int>(DLL::Node<int>**);

}