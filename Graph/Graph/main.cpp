//
//  main.cpp
//  Graph
//
//  Created by jieunChoi on 2020/11/16.
//  Copyright © 2020 jieunChoi. All rights reserved.
//
#include "Graph.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    auto graph = new Graph();
    graph->initializeGraph(5);
    // A -> B -> D -> E
    graph->addEdge(A, B);
    graph->addEdge(A, D);
    graph->addEdge(A, E);
    graph->addEdge(B, C);
    graph->addEdge(C, D);
    graph->addEdge(D, E);

    // E -> A -> D
    return 0;
}
