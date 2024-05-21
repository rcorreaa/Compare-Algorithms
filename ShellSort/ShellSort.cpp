#include <iostream>
#include "../DLL/DoubleLinkedList.h"
#include "ShellSort.h"

using namespace std;

void ShellSort(Node** head)
{
    int iLength = countElements(head);
    if(*head == nullptr)
    {
        return;
    }
    int iGap = iLength / 2;
    Node* current = *head;
    int iCount = 0;
    // encontra o gap
    while(iCount != iGap)
    {
        current = current->ptrNext;
        iCount++;
    }
    
    // começa o algoritimo
    while(current != *head && iGap>0)
    {
        Node* outerLoop = current;
        while(outerLoop->ptrNext != nullptr)
        {
            int iTemp = outerLoop->iPayload;
            Node* innerLoop = outerLoop;
            
            // vamos achar o J, (lembrar do codigo python)
            int iFindInnerLoop = 0;
            Node* auxCurrent = *head;
            while(auxCurrent != innerLoop)
            {
                iFindInnerLoop++;
                auxCurrent = auxCurrent->ptrNext;
            }
            // agora temos o j

            // indo para j-gap
            int iJMenosGap = iFindInnerLoop - iGap;
            auxCurrent = *head;
            int iauxCount = 0;
            while(iauxCount <iJMenosGap)
            {
                iauxCount++;
                auxCurrent = auxCurrent->ptrNext;
            }
            // achamos o arr[j-gap] (auxCurrent)

            while(innerLoop != current->ptrPrev && auxCurrent->iPayload > iTemp)
            {
                innerLoop->iPayload = auxCurrent->iPayload;
                for(int i = 0; i++; i<iGap)
                {
                    innerLoop = innerLoop->ptrPrev;
                }
            } 
            innerLoop->iPayload = iTemp;
            outerLoop = outerLoop->ptrNext;
        }
        iGap = iGap/2;
        for(int i=0;i++;i<iGap){
            current = current->ptrPrev;
        }
    }
}

int main(){
    Node* head = nullptr;
    generateRandomList(&head, 10);
    displayList(head);
    ShellSort(&head);
    displayList(head);
}