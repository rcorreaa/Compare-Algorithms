#include <iostream>
#include "BinaryTree/BinaryTree.h"

using namespace std;
using namespace bt;

// tem que chamar as funções que cronometra os tempos das buscas
int main() {
    int numNodes = 100000; // 100.000 nodes para melhor analise
    int numTrees = 100;
    std::string filename = "bfs_benchmark_results.txt";

    // Cronometrar o método BFS
    benchmarkSearchMethod(bfsTraversal<int>, numNodes, numTrees, filename);

    // Cronometrar o método DFS
    filename = "dfs_benchmark_results.txt";
    benchmarkSearchMethod(searchNodeDFS<int>, numNodes, numTrees, filename);

    return 0;
}
