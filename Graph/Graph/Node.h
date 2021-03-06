//
//  Node.h
//  Graph
//
//  Created by jieunChoi on 2020/11/16.
//  Copyright © 2020 jieunChoi. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include "Constants.h"

#include <string>

struct HashNode {
    vertexConstants vertexName;
    HashNode* before;
    HashNode* next;
    HashNode* tail;
};

#endif /* Node_h */
