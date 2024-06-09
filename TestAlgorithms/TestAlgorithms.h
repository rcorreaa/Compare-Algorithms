#pragma once

#include <string>
#include <chrono>
#include "../DLL/DoubleLinkedList.h"

namespace cpa {

template<typename T>
void testAlgorithms(void (*algorithms)(cpa::Node<T>**), int iLength, int iNumTests, const std::string& filename);

template<typename T>
void measureGenerationTime(cpa::Node<T>* (*generate)(int), int size, int numTests, const std::string& filename);

template<typename T>
void measureSearchTime(void (*search)(cpa::Node<T>*), cpa::Node<T>* (*generate)(int), int size, int numTests, const std::string& filename);

}
