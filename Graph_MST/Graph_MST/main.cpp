//
//  main.cpp
//  Graph_MST
//
//  Created by jieunChoi on 2021/01/14.
//  Copyright © 2021 jieunChoi. All rights reserved.
//
#include "Kruskal.cpp"
#include "Prim.cpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    auto kruskal = new Kruskal;
    auto graph = std::vector<std::vector<int>> {{1},{0,2,4},{1,3,4},{2},{1,2}};
    std::cout << kruskal->shortestPathLenth(graph) <<std::endl;
    
    auto prim = new Prim;
    auto weightedGraph = std::vector<std::vector<std::pair<int, int>>> {{{4,1}, {8,7}},{{4,0}, {8,2}, {11,7}},{{8,1}, {7,3}, {2,8}, {4,5}}, {{9,4}, {7,2}, {14,5}}, {{9,3}, {10,5}}, {{14,3}, {4,2}, {2,6}, {10,4}}, {{2,5}, {1,7}, {6, 8}}, {{8,0}, {1,6}, {7,8}, {11,1}}, {{2,2}, {6,6}, {7,7}}};
    for (auto v :prim->shortestPath(weightedGraph))
    {
        std::cout << v << "\t";
    }
    return 0;
}
