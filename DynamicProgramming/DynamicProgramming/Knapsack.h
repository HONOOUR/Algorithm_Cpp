//
//  Knapsack.hpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/03/06.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#ifndef Knapsack_h
#define Knapsack_h

#include <stdio.h>
#include <vector>

class Knapsack
{
public:
    int getMaxValueInKnapsack(std::vector<int> value, std::vector<int> weight, int maxWeight);
};
#endif /* Knapsack_hpp */
