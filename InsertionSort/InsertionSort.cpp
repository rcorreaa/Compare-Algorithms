#include "InsertionSort.h"
#include <iostream>

using namespace std;
using namespace DLL;

namespace InsertionSort {

template<typename T>
void insertionSort(DLL::Node<T>** head) 
{
    DLL::Node<T>* current = (*head)->ptrNext;
    while (current != nullptr) 
    {
        T InsertValue = current->iPayload;
        DLL::Node<T>* temp = current->ptrPrev;
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

// Explicit instantiation of the template functions you plan to use
template void insertionSort<int>(DLL::Node<int>**);

} // namespace InsertionSort
