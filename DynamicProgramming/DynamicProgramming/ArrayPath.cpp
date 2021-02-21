//
//  ArrayPath.cpp
//  DynamicProgramming
//
//  Created by jieunChoi on 2021/02/21.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "ArrayPath.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

ArrayPath::ArrayPath(int n, int k)
{
    // initialize array with nxn
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            int randomNumber = (rand() % 9) + 1;
            path[i][j] = randomNumber;
        }
    }
//    getPathValue_Memo(n, k);
    
    getPathValue_Dynamic(n, k);
}

int ArrayPath::getPathValue_Memo(int n, int k)
{
    if (n==1 && k==1)
    {
        return path[n][k];
    }
    else if (n==1)
    {
        path[n][k] = getPathValue_Memo(n, k-1) + path[n][k];
        return path[n][k];
    }
    else if (k==1)
    {
        path[n][k] = getPathValue_Memo(n-1, k) + path[n][k];
        return path[n][k];
    }
    else
    {
        path[n][k] = std::min(getPathValue_Memo(n, k-1), getPathValue_Memo(n-1, k)) + path[n][k];
        return path[n][k];
    }
    return path[n][k];
}

int ArrayPath::getPathValue_Dynamic(int n, int k)
{
    
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (i==1 && j==1)
            {
                
            }
            else if (i==1)
            {
                path[i][j] = path[i][j-1] + path[i][j];
            }
            else if (j==1)
            {
                path[i][j] = path[i-1][j] + path[i][j];
            }
            else
            {
                path[i][j] = std::min(path[i][j-1], path[i-1][j]) + path[i][j];
            }
        }
    }
    printPath(n, k);
    return path[n][k];
}

void ArrayPath::printPath(int n, int k)
{
    std::vector<std::string> paths;
    std::vector<std::pair<int, int>> dynamicPath;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (i==1 && j==1)
            {
                paths.push_back("-");
                std::cout << "- ";
            }
            else if (i==1)
            {
                paths.push_back("←");
                std::cout << "← ";
            }
            else if (j==1)
            {
                paths.push_back("↑");
                std::cout <<"↑ ";
            }
            else if (path[n-1][k] > path[n][k-1])
            {
                paths.push_back("←");
                std::cout <<"← ";
            }
            else
            {
                paths.push_back("↑");
                std::cout <<"↑ ";
               
            }
        }
    }
//    dynamicPath.push_back({i, j});
}
