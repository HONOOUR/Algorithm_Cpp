//
//  MatrixChain.hpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/02/23.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#ifndef MatrixChain_h
#define MatrixChain_h

#include <stdio.h>

#define MAX 10

class MatrixChain
{
public:
    MatrixChain(int n);
    int multiplyMatrixChain(int n, int p[]);
private:
    int m[MAX][MAX];
};
#endif /* MatrixChain_h */
