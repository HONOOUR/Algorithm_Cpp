//
//  Run.hpp
//  Huffman
//
//  Created by jieunChoi on 2021/01/31.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#ifndef Run_hpp
#define Run_hpp

#include <stdio.h>
class run
{
public:
    run();
    bool equal(int len, int freq);
    char symbol;
    int getHashCode();
    int runLength = 0;
    int frequency = 0;
    int codeword = 0;
    int codewordLength = 0;
    run *left = nullptr;
    run *right = nullptr;
    run *next = nullptr;
};
#endif /* Run_hpp */
