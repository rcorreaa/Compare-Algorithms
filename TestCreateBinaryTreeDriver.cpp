#include <iostream>
#include "MainHeader/cpa.h"
#include "BinaryTree/BinaryTree.h"

using namespace std;
using namespace cpa;
using namespace bt;

// tem que chamar as funções que cronometra os tempos de criação de arvores
int main()
{
    //Node<int>* root = nullptr;
    int iLength = 10000; // 10,000 elementos
    int iNumTests = 100; // 100 listas

    cout << "Measuring generating time for trees: " << endl;
    measureGenerationTime<int>(generateRandomTree, iLength, iNumTests, "TreeGeneratingTimes.txt");

    cout << "Measuring search time for DFS: " << endl;
    measureSearchTime<int>(searchNodeDFS, generateRandomTree, iLength, iNumTests, "dfs_tree_search_times.txt");

    cout << "Measuring search time for BFS: " << endl;
    measureSearchTime<int>(bfsTraversal, generateRandomTree, iLength, iNumTests, "bfs_tree_search_times.txt");


    return 0;
}