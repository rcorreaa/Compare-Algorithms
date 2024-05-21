#pragma once

#include <string>
#include <chrono>
#include "../DLL/DoubleLinkedList.h"

namespace TestAlgorithms {

template<typename T>
void testAlgorithms(void (*algorithms)(DLL::Node<T>**), int iLength, int iNumTests, const std::string& filename);

}
