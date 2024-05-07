#include  <iostream>
#include <chrono>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::pow;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;



typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void deleteNode(Node**, Node*);
void displayList(Node*);
void bubbleSortRuim(Node**);
void optmizedbubbleSort(Node**);
void selectionSortRuim(Node**);
void optimizedselectionSort(Node**);


int main()
{
    
    cout << "===================================" << endl;
    cout << "-- Bubble Sort Ruim --" << endl;
    for(int i = 1; i<7; i++)
    {
        Node* head = nullptr;
        for(int j = 0; j<pow(10,i); j++)
        {
            insertFront(&head, j);
        }
        auto timeStart = high_resolution_clock::now();
        bubbleSortRuim(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << "Para " << pow(10,i) << " elementos:" << endl;
        cout << "Tempo necessario: " << timeDuration.count()*pow(10,-9) << " segundos" << endl;
    }
    
    cout << "===================================" << endl;
    cout << "-- Optmized Bubble Sort --" << endl;
    for(int i = 1; i<7; i++)
    {
        Node* head = nullptr;
        for(int j = 0; j<pow(10,i); j++)
        {
            insertFront(&head, j);
        }
        auto timeStart = high_resolution_clock::now();
        optmizedbubbleSort(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << "Para " << pow(10,i) << " elementos:" << endl;
        cout << "Tempo necessario: " << timeDuration.count()*pow(10,-9) << " segundos" << endl;
    }

    cout << "===================================" << endl;

    cout << "--Selection Sort Ruim--" << endl;
    for(int i = 1; i<7; i++)
    {
        Node* head = nullptr;
        for(int j = 0; j<pow(10,i); j++)
        {
            insertFront(&head, j);
        }
        auto timeStart = high_resolution_clock::now();
        selectionSortRuim(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << "Para " << pow(10,i) << " elementos:" << endl;
        cout << "Tempo necessario: " << timeDuration.count()*pow(10,-9) << " segundos" << endl;
    }

    cout << "===================================" << endl;

    cout << "--Optmized Selection Sort--" << endl;
    for(int i = 1; i<7; i++)
    {
        Node* head = nullptr;
        for(int j = 0; j<pow(10,i); j++)
        {
            insertFront(&head, j);
        }
        auto timeStart = high_resolution_clock::now();
        optimizedselectionSort(&head);
        auto timeStop = high_resolution_clock::now();
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        cout << "Para " << pow(10,i) << " elementos:" << endl;
        cout << "Tempo necessario: " << timeDuration.count()*pow(10,-9) << " segundos" << endl;
    }

    return 0;
}

Node* createNode(int iPayload)
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrPrev = nullptr;
    temp->ptrNext = nullptr;
    return temp;
}

// ta dando erro :(
void displayList(Node* node)
{
    if(node == nullptr)
    {
        cout << "displayList: Node nulo, lista vazia" << endl;
        return;
    }
    
    if(node->ptrPrev != nullptr)
    {
        cout << "displayList: Node prev nao nulo, nao podemos printar" << endl;
        return;
    }

    Node* current = node;
    
    cout << "Payload: ";
    
    while(current)
    {
        cout  << current->iPayload << " ";
        current = current->ptrNext;
    }
    
    cout << endl;
    
}


void insertFront(Node** head, int iPayload)
{
    Node* newNode = createNode(iPayload);
    
    if(*head != nullptr) 
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    
    (*head) = newNode;
}


void bubbleSortRuim(Node** head) {
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


void selectionSortRuim(Node** head)
{
    Node* current = *head;
    while (current != nullptr) 
    {
        Node* temp = current->ptrNext;
        while (temp != nullptr) 
        {
            if (current->iPayload > temp->iPayload)
            {
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
    while (current != nullptr) 
    {
        minNode = current;
        
        Node* temp = current->ptrNext;
        while (temp != nullptr) 
        {
            if (temp->iPayload < minNode->iPayload) 
            {
                minNode = temp;
            }
            temp = temp->ptrNext;
        }

        if (minNode != current) 
        {
            int iTemp = minNode->iPayload;
            minNode->iPayload = current->iPayload;
            current->iPayload = iTemp;
        }

        current = current->ptrNext;
    }
}
