#include "../DLL/DoubleLinkedList.h"
#include "../TestAlgorithms/TestAlgorithms.h"
#include "../BubbleSort/BubbleSort.h"
#include "../InsertionSort/InsertionSort.h"
#include "../ShellSort/ShellSort.h"

namespace cpa 
{

template<typename T>
Node<T>* createNode(T iPayload);

template<typename T>
void insertFront(Node<T>** head, T iPayload);

template<typename T>
void displayList(Node<T>* node);

template<typename T>
void generateRandomList(Node<T> **head, int size);

template<typename T>
int countElements(Node<T>** head);

template<typename T>
Node<T>* getNode(Node<T>*,int);

template<typename T>
void bubbleSortRuim(Node<T>** head);

template<typename T>
void optimizedBubbleSort(Node<T>** head);

template<typename T>
void testAlgorithms(void (*algorithms)(Node<T>**), int iLength, int iNumTests, const std::string& filename);

template<typename T>
void insertionSort(Node<T>** head);

template<typename T>
void selectionSortRuim(Node<T>** head);

template<typename T>
void optimizedSelectionSort(Node<T>** head);

template<typename T>
void shellSort(Node<T>** head);

}