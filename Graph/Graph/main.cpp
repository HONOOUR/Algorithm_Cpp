//
//  main.cpp
//  Graph
//
//  Created by jieunChoi on 2020/11/16.
//  Copyright © 2020 jieunChoi. All rights reserved.
//
#include "GraphImpl.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    
    auto graph = new GraphImpl(6);

    // A -> B -> D -> E
    graph->addEdge(1, 2);
    graph->addEdge(1, 4);
    graph->addEdge(1, 5);
    graph->addEdge(2, 3);
    graph->addEdge(3, 4);
    graph->addEdge(4, 5);
    
    graph->showGraph(1);
    graph->showGraph(2);
    graph->showGraph(3);
    graph->showGraph(4);
    graph->showGraph(5);
    
    graph->bFSearch(1);
    
    return 0;
}
