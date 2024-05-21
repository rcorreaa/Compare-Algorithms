#include "BubbleSort.h"
#include <iostream>

using namespace std;

namespace cpa {

template<typename T>
void bubbleSortRuim(Node<T>** head) 
{
    Node<T>* current = *head;
    while (current->ptrNext != nullptr) 
    {
        Node<T>* temp = *head;
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
void optimizedBubbleSort(Node<T>** head)
{
    Node<T>* last = *head;
    while(last->ptrNext != nullptr)
    {
        last = last->ptrNext;
    }
    
    Node<T>* current = *head;
    bool bUnordered = false;
    while (current->ptrNext != nullptr) 
    {
        Node<T>* temp = *head;
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
template void bubbleSortRuim<int>(Node<int>**);
template void optimizedBubbleSort<int>(Node<int>**);

} 
