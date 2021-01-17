//
//  Kruskal.cpp
//  Graph_MST
//
//  Created by jieunChoi on 2021/01/14.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include <iostream>
#include <vector>

class Kruskal
{
public:
    int shortestPathLenth(std::vector<std::vector<int>>& graph)
    {
        int size = graph.size();
        sets.resize(size);
        parent.resize(size);
        auto sets = makeSet(graph);
        int path = 0;
        for (int i=0; i < size; i++)
        {
            for (auto v: graph[i])
            {
                if (findSet(i) != findSet(v))
                {
                    unionTrees(i, v);
                    path++;
                }
            }
        }
        
        return path;
    }
    std::vector<std::vector<int>> makeSet(std::vector<std::vector<int>>& graph)
    {
        // each vertex to each set
        for (int i(0); i < graph.size(); i++)
        {
            sets[i].push_back(i);
            parent[i] = i;
        }
        return sets;
    }
    //check parent node
    int findSet(int vertex)
    {
        int parentVertex = parent[vertex];
        if (vertex != parentVertex)
        {
            parentVertex = findSet(parentVertex);
        }
        return parentVertex;
    }
    
    void unionTrees(int u, int v)
    {
        int rootU = findSet(u);
        int rootV = findSet(v);
        if (sets[rootU].size() >= sets[rootV].size())
        {
            parent[rootV] = u;
            sets[rootU].push_back(v);
        }
        else
        {
            parent[rootU] = v;
            sets[rootV].push_back(u);
        }
    }
private:
    std::vector<std::vector<int>> sets;
    std::vector<int> parent;
};
