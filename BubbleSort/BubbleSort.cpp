#include <iostream>
#include "../DLL/DoubleLinkedList.h"
#include "BubbleSort.h"

using namespace std;

void bubbleSortRuim(Node** head) 
{
    Node* current = *head;
    while (current->ptrNext != nullptr) 
    {
        Node* temp = *head;
        while (temp->ptrNext != nullptr) 
        {
            if (temp->iPayload > temp->ptrNext->iPayload)
            {
                int iTemp = temp->iPayload;
                temp->iPayload = temp->ptrNext->iPayload;
                temp->ptrNext->iPayload = iTemp;
            }
            temp = temp->ptrNext;
        }
        current = current->ptrNext;
    }
}


void optmizedbubbleSort(Node** head)
{
    Node* last = *head;
    while(last->ptrNext != nullptr)
    {
        last = last->ptrNext;
    }
    
    Node* current = *head;
    bool bUnordered = false;
    while (current->ptrNext != nullptr) 
    {
        Node* temp = *head;
        bUnordered = false;
        while ((temp->ptrNext != nullptr) & (temp != last)) 
        {
            if (temp->iPayload > temp->ptrNext->iPayload)
            {
                int iTemp = temp->iPayload;
                temp->iPayload = temp->ptrNext->iPayload;
                temp->ptrNext->iPayload = iTemp;
                bUnordered = true;
            }
            temp = temp->ptrNext;
        }
        if(bUnordered == false) break;
        current = current->ptrNext;
        last = last->ptrPrev;
    }
}
