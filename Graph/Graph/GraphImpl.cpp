//
//  GraphImpl.cpp
//  Graph
//
//  Created by jieunChoi on 2020/11/24.
//  Copyright © 2020 jieunChoi. All rights reserved.
//

#include "GraphImpl.hpp"

#include <iostream>
#include <queue>

GraphImpl::GraphImpl(int elememtNum)
{
    adjacencyListGraph.resize(elememtNum);
}
void GraphImpl::addEdge(int vertexTo, int vertexFrom)
{
    adjacencyListGraph[vertexTo].push_back(vertexFrom);
}

void GraphImpl::showGraph(int vertex)
{
    std::cout << "vertex " << vertex;

    for (int v : adjacencyListGraph[vertex])
        std::cout << " -> " << v;
    std::cout << std::endl;
}

void GraphImpl::bFSearch(int vertextStart)
{
    // the start vertex to the visited array
    // enqueue start vertex and iterate the linked list
    // // the vertexs to the visited array when iterating
    // // enqueue the vertexs from the linked list

    std::vector<int> arrayVisited;
    std::queue<int> bfsQueue;
    
    arrayVisited.push_back(vertextStart); // 1
    bfsQueue.push(vertextStart); // 1
    
    while (!bfsQueue.empty())
    {
        for(auto v : adjacencyListGraph[bfsQueue.front()]) // 2 -> 4 -> 5
        {
            for (auto i: arrayVisited)
            {
                if (i == v)
                {
                    continue;
                }
            }
            arrayVisited.push_back(v); // 1, 2, 4, 5
            std::cout << "add to arrayVisited vertex: " << v << std::endl;
            bfsQueue.push(v); // 2, 4, 5
            std::cout << "enqueue to bfsQueue vertex: " << v << std::endl;
        }
        std::cout << "pop to bfsQueue vertex: " << bfsQueue.front() << std::endl;
        bfsQueue.pop(); // 1
    }
}
