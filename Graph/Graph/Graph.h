//
//  Graph.h
//  Graph
//
//  Created by jieunChoi on 2020/11/16.
//  Copyright © 2020 jieunChoi. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include "AdjacencyList.h"
#include "Constants.h"

#include <vector>

class Graph
{
public:
    Graph();
    void initializeGraph(int vertexNumber);
    void destroyGraph();
    void addEdge(vertexConstants vertexNameFrom, vertexConstants vertexNameTo);
    void ShowGraph();
private:
    int converVertexNameToNum(vertexConstants name);
    std::vector<adjacencyList> adjacencyListGraph;
};
// initialize graph

// destroy graph

// add edge

// print edge

#endif /* Graph_h */
