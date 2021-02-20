//
//  HuffmanCoding.hpp
//  Huffman
//
//  Created by jieunChoi on 2021/01/31.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#ifndef HuffmanCoding_hpp
#define HuffmanCoding_hpp

#include "Run.h"
#include <stdio.h>
#include <string>
#include <queue>
#include <vector>

#define MAX 500

class huffmanCoding
{
public:

    void compressFile(std::string file);
private:
    void collectRuns(std::string file);
    void outPutFrequencies(std::ifstream &ifs, std::ofstream &ofs);
    void createHuffmanTree();
    void assignCodewords(run &theRoot, int codeword, int length);
    void storeRunsIntoHashMap(run &theRoot);
    void encode(std::ifstream &ifs, std::ofstream &ofs);

    std::vector<run> totalRuns;
    std::queue<run> pQueue;
    run* hashTable[MAX];
    run* root;
};
#endif /* HuffmanCoding_hpp */
