#pragma once

#include "../DLL/DoubleLinkedList.h"

using namespace DLL;

namespace SelectionSort {

template<typename T>
void selectionSortRuim(DLL::Node<T>** head);

template<typename T>
void optimizedSelectionSort(DLL::Node<T>** head);

}
