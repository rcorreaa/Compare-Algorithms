#pragma once

#include "../DLL/DoubleLinkedList.h"
#include <chrono>
#include <string>

void testAlgorithms(void (*algorithms)(Node**), int iLength, int iNumTests, const std::string& filename);
