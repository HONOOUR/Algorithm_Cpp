#include "Graph_DFS.cpp"
#include "BipartiteGraph.cpp"
#include <iostream>

int main()
{
    auto graph_DFS = new Graph_DFS(4);
    graph_DFS->addEdge(0, 1);
    graph_DFS->addEdge(0, 3);
    graph_DFS->addEdge(1, 0);
    graph_DFS->addEdge(1, 2);
    graph_DFS->addEdge(2, 1);
    graph_DFS->addEdge(2, 3);
    graph_DFS->addEdge(3, 0);
    auto graph = graph_DFS->addEdge(3, 2);
    auto bipartite = new Bipartite();
    bool result = bipartite->isBipartite(graph);
    //graph_DFS->addEdge(1, 2);
    //graph_DFS->addEdge(1, 4);
    //graph_DFS->addEdge(1, 5);
    //graph_DFS->addEdge(2, 1);
    //graph_DFS->addEdge(2, 3);
    //graph_DFS->addEdge(3, 2);
    //graph_DFS->addEdge(3, 4);
    //graph_DFS->addEdge(4, 1);
    //graph_DFS->addEdge(4, 3);
    //graph_DFS->addEdge(4, 5);
    //graph_DFS->addEdge(5, 1);
    //graph_DFS->addEdge(5, 4);

    //graph_DFS->showGraph(1);
    //graph_DFS->showGraph(2);
    //graph_DFS->showGraph(3);
    //graph_DFS->showGraph(4);
    //graph_DFS->showGraph(5);

    //graph_DFS->dFSearch(2);
    
    graph_DFS->addEdge(1, 2);
    graph_DFS->addEdge(1, 4);
    graph_DFS->addEdge(1, 5);
    graph_DFS->addEdge(2, 3);
    graph_DFS->addEdge(3, 4);
    graph_DFS->addEdge(4, 5);
    // #1 find a node without incoming edges
    //graph_DFS->topologicalSort_1(1);
    // #2 find a node without outgoing edges
    graph_DFS->topologicalSort_2(4);
}
