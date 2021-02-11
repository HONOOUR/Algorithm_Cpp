//
//  Run.cpp
//  Huffman
//
//  Created by jieunChoi on 2021/01/31.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "Run.h"

run::run()
{
    
}

bool run::equal(int len, int freq)
{
    return (runLength == len) && (frequency == freq);
}

int run::getHashCode()
{
    return (int)symbol + runLength;
    
}
