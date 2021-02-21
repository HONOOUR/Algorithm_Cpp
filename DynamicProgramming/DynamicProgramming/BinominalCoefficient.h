//
//  BinominalCoefficient.hpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/02/20.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#ifndef BinominalCoefficient_h
#define BinominalCoefficient_h

#include <stdio.h>

#define MAX 100

class BinominalCoefficient
{
public:
    BinominalCoefficient(int n, int k);
    int binomial_Memoization(int n, int k);
    int binomial_Dynamic(int n, int k);
private:
    int memoArray[MAX][MAX];
};
#endif /* BinominalCoefficient_hpp */
