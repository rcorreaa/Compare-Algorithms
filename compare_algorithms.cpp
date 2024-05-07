#include  <iostream>
#include <chrono>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;
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
void generateRandomList(Node** head, int size);

int main()
{
    Node* head = nullptr;
    cout << "===================================" << endl;
    cout << "-- Bubble Sort Ruim --" << endl;
    int arriNumbers[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    
    void generateRandomList(&head, 100);
    cout << "Arrayy original: ";
    displayList(head);
    
    auto timeStart = high_resolution_clock::now();
    bubbleSortRuim(&head);
    auto timeStop = high_resolution_clock::now();
    
    cout << "Arrayy ordenado: ";
    displayList(head);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;
    
    cout << "===================================" << endl;
    Node* head2 = nullptr;
    cout << "--Optimized Bubble Sort--" << endl;
    int arriNumbers_2[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize_2 = sizeof(arriNumbers_2)/sizeof(arriNumbers_2[0]);
    for(int i = 0; i<iArraySize_2; i++)
    {
        insertFront(&head2, arriNumbers_2[i]);
    }
    cout << "Array 2 original: ";
    displayList(head2);
    
    timeStart = high_resolution_clock::now();
    optmizedbubbleSort(&head2);
    timeStop = high_resolution_clock::now();
    
    cout << "Array 2 ordenado: ";
    displayList(head2);
    
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;

    cout << "===================================" << endl;
    Node* head3 = nullptr;
    cout << "--Selection Sort Ruim--" << endl;
    int arriNumbers_3[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize_3 = sizeof(arriNumbers_3)/sizeof(arriNumbers_3[0]);
    for(int i = 0; i<iArraySize_3; i++)
    {
        insertFront(&head3, arriNumbers_3[i]);
    }
    cout << "Array 3 original: ";
    displayList(head3);
    
    timeStart = high_resolution_clock::now();
    selectionSortRuim(&head3);
    timeStop = high_resolution_clock::now();
    
    cout << "Array 3 ordenado: ";
    displayList(head3);
    
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;

    cout << "===================================" << endl;
    Node* head4 = nullptr;
    cout << "--Optmized Selection Sort--" << endl;
    int arriNumbers_4[] = {42, 7, 0, 3, 666, 1, 111, 10, 13};
    int iArraySize_4 = sizeof(arriNumbers_4)/sizeof(arriNumbers_4[0]);
    for(int i = 0; i<iArraySize_4; i++)
    {
        insertFront(&head4, arriNumbers_4[i]);
    }
    cout << "Array 4 original: ";
    displayList(head4);
    
    timeStart = high_resolution_clock::now();
    optimizedselectionSort(&head4);
    timeStop = high_resolution_clock::now();
    
    cout << "Array 4 ordenado: ";
    displayList(head4);
    
    timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << endl;
    cout << timeDuration.count() << " nanosegundos" << endl;

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

void optimizedselectionSort(Node** head)
{
    int minValue = 0;
    Node* changed = nullptr;
    Node* current = *head;
    while (current != nullptr)
    {
        minValue = current->iPayload;
        Node* temp = current->ptrNext;
        while(temp != nullptr)
        {
            if(minValue > temp->iPayload)
            {
                minValue = temp->iPayload;
                changed = temp;
            }
            temp = temp->ptrNext;
        }
        
        // fazer o swap somente se tiver algum valor que seja menor que current->iPayload
        if(changed != nullptr)
        {
            int iTemp = current->iPayload;
            current->iPayload = minValue; 
            changed->iPayload = iTemp;
        }
    
        current = current->ptrNext;
    }

}

void generateRandomList(Node** head, int size)
{
        srand(time(nullptr));
    for (int i = 0; i < size; ++i)
    {
        int randomNum = rand() % 100;
        insertFront(head, randomNum);
    }
}