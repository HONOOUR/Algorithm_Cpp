//
//  MatrixChain.cpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/02/23.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "MatrixChain.h"
#include <iostream>
#include <algorithm>
 
MatrixChain::MatrixChain(int n)
{
    // set array p0, p1, p2 ... pn
    // the cost of matrices (A1={p0xp1}, A2={p1xp2})  A1xA2  = m[1,2]
    // the cost of matrices (A3={p2xp3}, A4={p3xp4})  A3xA4  = m[3,4]
    int p[n];
    for (int i = 0; i <=n; i++)
    {
        p[i] = (rand() % 9) + 1;
        std::cout << "p[" << i << "] = " << p[i] <<std::endl;
    }
    
    multiplyMatrixChain(n, p);
}

// m[1,n]: the cost of multiplying matrices from A1 to An
int MatrixChain::multiplyMatrixChain(int n, int p[])
{
    // m[i][j] = m[i][k] + m[k+1][j] + p_i-1*p_k*p_j
    // i <= k <j
    
    //m[1,2] = m[1,1] + m[2,2] + p0*p1*p2 = 0+0+(p0*p1*p2)
    for (int i=1; i<n; i++)
    {
        m[i][i] = 0;
        for (int k=1; k<i; k++)
        {
            m[i][k] = -1;
        }
    }
    
    // r: the number of diagonal direction cell
    for (int r=1; r<n; r++) // the number decreasing, the max is n-1
    {
        // r=1,2,3,4,5
        for (int i=1; i<=n-r; i++) // 대각선 길이 = i행
        {
            int j=i+r; // i행 + 대각선 줄어든 크기
            int temp = -1;
            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];
            for (int k=i; k<j; k++) // (i,k,j) = (1,1,2)(2,2,3)(3,3,4).. (1,1,3)(1,2,3)(2,2,3)(2,2,4)(2,3,4)(3,3,5)(3,4,5)
            {
                temp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (m[i][j]>temp && temp != -1)
                {
                    m[i][j] = temp;
                }
            }
        }
    }
    
    return m[1][n];
}
