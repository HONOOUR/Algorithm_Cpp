//
//  main.cpp
//  Graph_MST
//
//  Created by jieunChoi on 2021/01/14.
//  Copyright © 2021 jieunChoi. All rights reserved.
//
#include "Kruskal.cpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    auto kruskal = new Kruskal;
    auto graph = std::vector<std::vector<int>> {{1},{0,2,4},{1,3,4},{2},{1,2}};
    std::cout << kruskal->shortestPathLenth(graph) <<std::endl;
    return 0;
}
