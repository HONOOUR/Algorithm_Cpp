//
//  AdjacencyList.h
//  Graph
//
//  Created by jieunChoi on 2020/11/16.
//  Copyright © 2020 jieunChoi. All rights reserved.
//

#ifndef AdjacencyList_h
#define AdjacencyList_h

#include "Node.h"
#include <vector>

struct adjacencyList {
    int vertexNum;
    int edgeNum;
    HashNode *list;
};
#endif /* AdjacencyList_h */
