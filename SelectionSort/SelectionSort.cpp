#include <iostream>
#include "../DLL/DoubleLinkedList.h"
#include "SelectionSort.h"

using namespace std;

void selectionSortRuim(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* temp = current->ptrNext;
        while (temp != nullptr) {
            if (current->iPayload > temp->iPayload) {
                int iTemp = temp->iPayload;
                temp->iPayload = current->iPayload;
                current->iPayload = iTemp;
            }
            temp = temp->ptrNext;
        }
        current = current->ptrNext;
    }
}

void optimizedselectionSort(Node** head) {
    Node* minNode = nullptr;
    Node* current = *head;
    while (current != nullptr) {
        minNode = current;
        Node* temp = current->ptrNext;
        while (temp != nullptr) {
            if (temp->iPayload < minNode->iPayload) {
                minNode = temp;
            }
            temp = temp->ptrNext;
        }
        if (minNode != current) {
            int iTemp = minNode->iPayload;
            minNode->iPayload = current->iPayload;
            current->iPayload = iTemp;
        }
        current = current->ptrNext;
    }
}
