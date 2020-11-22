//
//  Graph.cpp
//  Graph
//
//  Created by jieunChoi on 2020/11/17.
//  Copyright © 2020 jieunChoi. All rights reserved.
//
#include "Graph.h"

#include <stdio.h>
#include <vector>


Graph::Graph()
:adjacencyListGraph{5}
{
}

void Graph::initializeGraph(int vertexNumber)
{
    adjacencyListGraph.resize(vertexNumber);
    auto *graph = adjacencyListGraph.data();
    int count = 0;
    while (count < vertexNumber)
    {
        auto* node = new HashNode();
        graph->list = node;
        ++graph;
    }
}

void Graph::destroyGraph()
{
}

void Graph::addEdge(vertexConstants vertexNameFrom, vertexConstants vertexNameTo)
{
    int vertexNum = converVertexNameToNum(vertexNameFrom);
    
    auto beforeNode = new HashNode();
//    auto nextNode = adjacencyListGraph[vertexNum].list;
    auto* p = adjacencyListGraph.data();
    HashNode* nextNode = p[vertexNum].list;
    while (nextNode != nullptr)
    {
        beforeNode = nextNode;
        nextNode = nextNode->next;
    }
    
    auto node = new HashNode();
    node->vertexName = vertexNameTo;
    nextNode = node;
    nextNode->before = beforeNode;
}

void Graph::ShowGraph() {
    
}

int Graph::converVertexNameToNum(vertexConstants name)
{
    int number = 0;
    switch (name) {
        case A:
            number = 0;
            break;
        case B:
            number = 1;
            break;
        case C:
            number = 2;
            break;
        case D:
            number = 3;
            break;
        case E:
            number = 4;
        default:
            break;
    }
    return number;
}

