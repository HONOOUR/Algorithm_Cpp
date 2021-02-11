//
//  FloydWarshall.cpp
//  Graph_MST
//
//  Created by jieunChoi on 2021/01/24.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include <vector>
#include <stdio.h>

#define INF 10000

class FloydWarshall
{
public:
    void shortestPath(std::vector<std::vector<std::pair<int,int>>>& graph)
    {
        int size = graph.size();
        int d[size][size];
//        std::vector<std::vector<int>> d {INF};
        for (int i=0; i<size; i++)
        {
            for (auto v: graph[i]) // v={weight, vertex}
            {
                d[i][v.second] = v.first;
            }
        }
        
        for (int k=0; k<size; k++)
        {
            for (int i=0; i<size; i++)
            {
                for (int j=0; j<size; j++) // v={weight, vertex}
                {
                    if (d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                    }
                }
            }
        }
    }
};
