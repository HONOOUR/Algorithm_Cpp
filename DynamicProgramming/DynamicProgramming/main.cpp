//
//  main.cpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/02/20.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "BinominalCoefficient.h"
#include "ArrayPath.h"
#include "MatrixChain.h"
#include "Knapsack.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    
//    BinominalCoefficient instance(5, 3);
//    ArrayPath path(5, 4);
//    MatrixChain matrixChian(5);
    Knapsack knapsck;
    std::vector<int> value = {0, 1, 6, 18, 22, 28};
    std::vector<int> weight = {0, 1, 2, 5, 6, 7};
    knapsck.getMaxValueInKnapsack(value, weight, 20);
    
    return 0;
}
