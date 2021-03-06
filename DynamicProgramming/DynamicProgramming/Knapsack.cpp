//
//  Knapsack.cpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/03/06.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "Knapsack.h"
#define MAX 50

int Knapsack::getMaxValueInKnapsack(std::vector<int> value, std::vector<int> weight, int maxWeight)
{
    int valueMatix[MAX][MAX];
    int total = value.size();
    
    for (int w=0; w<=maxWeight; w++)
    {
        valueMatix[0][w] = 0; // no item then, maxValue is zero.
    }
    for (int i=1; i<=total; i++)
    {
        valueMatix[i][0] = 0; // zero weight then, maxValue is zero.
    }
    
    for (int i=1; i<=total; i++)
    {
        for (int w=1; w<=maxWeight; w++)
        {
            if (w<weight[i])
            {
                valueMatix[i][w] = valueMatix[i-1][w];
            }
            // check if Max value with i item is bigger than without the one.
            else if (valueMatix[i-1][w]<(value[i] + valueMatix[i-1][w-weight[i]]))
            {
                valueMatix[i][w] = value[i]+valueMatix[i-1][w-weight[i]]; // with
            }
            else
            {
                valueMatix[i][w] = valueMatix[i-1][w]; // without
            }
        }
    }
    return valueMatix[total][maxWeight];
}
