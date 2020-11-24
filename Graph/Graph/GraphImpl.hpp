//
//  GraphImpl.hpp
//  Graph
//
//  Created by jieunChoi on 2020/11/24.
//  Copyright © 2020 jieunChoi. All rights reserved.
//

#ifndef GraphImpl_hpp
#define GraphImpl_hpp

#include <stdio.h>
#include <vector>

class GraphImpl
{
public:
    GraphImpl(int elementNum);
    void addEdge(int vertexTo, int vertexFrom);
    void showGraph(int vertex);
    void bFSearch(int vertextStart);
private:
    std::vector<std::vector<int>> adjacencyListGraph;
};

#endif /* GraphImpl_hpp */
