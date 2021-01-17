//
//  Prim.cpp
//  Graph_MST
//
//  Created by jieunChoi on 2021/01/17.
//  Copyright © 2021 jieunChoi. All rights reserved.
//
#include <vector>
#include <stdio.h>

#define INF 10000

class Prim
{
    public:
    std::vector<int> shortestPath(std::vector<std::vector<std::pair<int,int>>>& graph) // graph[0] = {{key, vertex}...}
    {
        // initialize each node (key=INF, n=key with minimum edge)
        int graphSize = graph.size();
        std::vector<int> parent(graphSize);
        std::vector<int> key(graphSize);
        std::vector<bool> mstSet(graphSize);
        std::vector<int> path;
        
        // initialize Va set
        for (int i = 0; i<graph.size(); i++)
        {
            key[i] = INF;
            mstSet[i] = false;
        }
        
        // select a start node and push it to Va
        key[0] = 0;
        parent[0] = -1;
        // while the number in Va set equals to n
        for (int count=0; count<graphSize; count++)
        {
            int u = findMinimumkey(key, mstSet);
            mstSet[u] = true;
            path.push_back(u);
            for (auto v: graph[u])
            {
                if (!mstSet[v.second])
                {
                    parent[v.second] = u;
                    key[v.second] = v.first;
                }
            }
        }

        return path;
    }
    
    int findMinimumkey(std::vector<int>key, std::vector<bool>mstSet)
    {
        int index = -1;
        int keyValue = INF;
        
        // not in mstSet
        // the smallest in key
        for (int i=0; i<key.size(); i++)
        {
            if (!mstSet[i] && key[i]<keyValue)
            {
                keyValue = key[i];
                index = i;
            }
        }
        return index;
    }
};
