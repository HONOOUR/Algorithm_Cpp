//
//  ArrayPath.hpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/02/21.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#ifndef ArrayPath_h
#define ArrayPath_h

#include <stdio.h>
#define MAX 10

class ArrayPath
{
public:
    ArrayPath(int n, int k);
    int getPathValue_Memo(int n, int k);
    int getPathValue_Dynamic(int n, int k);
    void printPath(int n, int k);
    int path[MAX][MAX];
};
#endif /* ArrayPath_h */

