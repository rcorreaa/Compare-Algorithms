#pragma once

#include <string>
#include <chrono>
#include "../DLL/DoubleLinkedList.h"
#include "./BinaryTree/BinaryTree.h"

using namespace bt;

namespace cpa {

template<typename T>
void testAlgorithms(void (*algorithms)(cpa::Node<T>**), int iLength, int iNumTests, const std::string& filename);

template<typename T>
void measureGenerationTime(bt::Node<T>* (*generate)(int), int size, int numTests, const std::string& filename);

template<typename T>
void measureSearchTime(bt::Node<T>* (*search)(bt::Node<T>*), bt::Node<T>* (*generate)(int), int size, int numTests, const std::string& filename);

}
