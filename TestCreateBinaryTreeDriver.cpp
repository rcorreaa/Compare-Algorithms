#include <iostream>
#include "BinaryTree/BinaryTree.h"

using namespace std;
using namespace bt;

// tem que chamar as funções que cronometra os tempos de criação de arvores
int main()
{
    Node<int>* root = nullptr;
    int numNodes = 10000;
    int numTrees = 100;
    
    measureBinaryTreeCreation(generateRandomTree,numNodes, numTrees, "CreateBinaryTree");
    return 0;
}
