#include "BubbleSort.h"
#include <iostream>

using namespace std;

namespace BubbleSort {

template<typename T>
void bubbleSortRuim(DLL::Node<T>** head) 
{
    DLL::Node<T>* current = *head;
    while (current->ptrNext != nullptr) 
    {
        DLL::Node<T>* temp = *head;
        while (temp->ptrNext != nullptr) 
        {
            if (temp->iPayload > temp->ptrNext->iPayload)
            {
                T iTemp = temp->iPayload;
                temp->iPayload = temp->ptrNext->iPayload;
                temp->ptrNext->iPayload = iTemp;
            }
            temp = temp->ptrNext;
        }
        current = current->ptrNext;
    }
}

template<typename T>
void optimizedBubbleSort(DLL::Node<T>** head)
{
    DLL::Node<T>* last = *head;
    while(last->ptrNext != nullptr)
    {
        last = last->ptrNext;
    }
    
    DLL::Node<T>* current = *head;
    bool bUnordered = false;
    while (current->ptrNext != nullptr) 
    {
        DLL::Node<T>* temp = *head;
        bUnordered = false;
        while ((temp->ptrNext != nullptr) && (temp != last)) 
        {
            if (temp->iPayload > temp->ptrNext->iPayload)
            {
                T iTemp = temp->iPayload;
                temp->iPayload = temp->ptrNext->iPayload;
                temp->ptrNext->iPayload = iTemp;
                bUnordered = true;
            }
            temp = temp->ptrNext;
        }
        if(!bUnordered) break;
        current = current->ptrNext;
        last = last->ptrPrev;
    }
}

// Explicit instantiation of the template functions you plan to use
template void bubbleSortRuim<int>(DLL::Node<int>**);
template void optimizedBubbleSort<int>(DLL::Node<int>**);

} 
