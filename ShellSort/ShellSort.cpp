#include <iostream>
#include "../DLL/DoubleLinkedList.h"
#include "ShellSort.h"

using namespace std;

int countElements(Node** head)
{
    Node* current = *head;
    int iCount = 0;
    while(current)
    {
        iCount++;
        current = current->ptrNext;
    }
    return iCount;
}

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
    while(current != *head)
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


            outerLoop = outerLoop->ptrNext;
        }
        
        
        
        
        
        
        
        current = current->ptrPrev;
    }


}