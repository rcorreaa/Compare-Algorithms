#pragma once

#include <string>
#include <chrono>
#include "../DLL/DoubleLinkedList.h"

namespace cpa {

template<typename T>
void testAlgorithms(void (*algorithms)(cpa::Node<T>**), int iLength, int iNumTests, const std::string& filename);

}
