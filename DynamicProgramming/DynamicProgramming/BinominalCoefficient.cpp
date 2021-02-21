//
//  BinominalCoefficient.cpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/02/20.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "BinominalCoefficient.h"
#include <iostream>

BinominalCoefficient::BinominalCoefficient(int n, int k)
{
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            memoArray[i][j] = -1;
        }
    }
    std::cout << binomial_Memoization(n, k) << std::endl;
    std::cout << binomial_Dynamic(n, k) << std::endl;
}

// memorize nxk array
int BinominalCoefficient::binomial_Memoization(int n, int k)
{
    if (n==k || k==0)
    {
        memoArray[n][k] = 1;
        return memoArray[n][k];
    }
    else if (memoArray[n][k] != -1)
    {
        return memoArray[n][k];
    }
    else
    {
        memoArray[n][k] = binomial_Memoization(n-1, k) + binomial_Memoization(n-1, k-1);
        return memoArray[n][k];
    }
}

// no reculsion, calculate all the array
int BinominalCoefficient::binomial_Dynamic(int n, int k)
{
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=i && j<=k; j++)
        {
            if (i==j || j==0)
            {
                memoArray[i][j] = 1;
            }
            else
            {
                memoArray[i][j] = memoArray[i-1][j] + memoArray[i-1][j-1];
            }
        }
    }
    return memoArray[n][k];
}

