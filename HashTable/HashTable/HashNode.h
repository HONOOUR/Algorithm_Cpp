//
//  HashNode.h
//  Algorithm_Cpp
//
//  Created by jieunChoi on 2020/11/07.
//  Copyright © 2020 jieunChoi. All rights reserved.
//

#ifndef HashNode_h
#define HashNode_h

#include <string>

#define MAX_TABLE 10
#define MAX_DATA 12

struct HashNode {
    int key;
    std::string value;
    HashNode* before;
    HashNode* next;
    HashNode* tail;
};
#endif /* HashNode_h */
