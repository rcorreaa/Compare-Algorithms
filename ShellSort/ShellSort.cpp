#include <iostream>
#include "../DLL/DoubleLinkedList.h"
#include "ShellSort.h"

using namespace std;

namespace cpa{

template <typename T>
void shellSort(Node<T>** head) 
{
    int iLength = countElements(head);
    if (*head == nullptr) 
    {
        return;
    }

    for (int iGap = iLength / 2; iGap > 0; iGap /= 2) 
    {
        for (int i = iGap; i < iLength; i++) 
        {
            Node<T>* temp = getNode(*head, i);
            T iTemp = temp->iPayload;

            Node<T>* inner = temp;
            int j = i;
            while (j >= iGap) 
            {
                Node<T>* innerGap = getNode(*head, j - iGap);
                if (innerGap->iPayload <= iTemp) 
                {
                    break;
                }
                inner->iPayload = innerGap->iPayload;
                inner = innerGap;
                j -= iGap;
            }
            inner->iPayload = iTemp;
        }
    }
}

template void shellSort<int>(Node<int>**);
}
