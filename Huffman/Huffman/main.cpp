//
//  main.cpp
//  Huffman
//
//  Created by jieunChoi on 2021/01/28.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "HuffmanCoding.h"
#include <fstream>
#include <iostream>
#include <istream>

int main(int argc, const char * argv[]) {
    
    std::string file = "Apple";
    auto huffman = new huffmanCoding();
    huffman->compressFile(file);
    
    return 0;
}
