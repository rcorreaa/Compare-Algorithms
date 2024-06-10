#include <iostream>
#include "DLL/DoubleLinkedList.h"

using namespace std;
using namespace cpa;

// deve ter a função que cronometra o tempo pra criação de listas
int main()
{
    measureDLLCreation<int>(generateRandomList,10000,100,"CreateDLL");

    return 0;
}
