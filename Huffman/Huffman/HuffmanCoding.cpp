//
//  HuffmanCoding.cpp
//  Huffman
//
//  Created by jieunChoi on 2021/01/31.
//  Copyright © 2021 jieunChoi. All rights reserved.
//

#include "HuffmanCoding.h"
#include <algorithm>
#include <queue>
#include <vector>
#include <fstream>
#include <iostream>

void huffmanCoding::compressFile(std::string file)
{
    std::ofstream ofs ("text.txt", std::ofstream::binary);
    std::ifstream ifs ("text.txt", std::ifstream::binary);
    // run to vector<run>
    collectRuns(file);
    // run information to header
    outPutFrequencies(ifs, ofs);
    // for shorter codeword and its length to high frequency word
    createHuffmanTree();
    assignCodewords(*root, 0, 0);
    storeRunsIntoHashMap(*root);
    //시작위치로
    encode(ifs, ofs);
}

void huffmanCoding::collectRuns(std::string file)
{
    // read a character
    // save it to run (symbol, frequency, runLength..)
    std::vector<run> Runs;
    int i = 0;
    while (file[i] != '\0')
    {
        auto symbol = file[i];
        bool exist = false;
        
        // find the symbol in a run array
        for (auto &r: Runs)
        {
            if (r.symbol == symbol)
            {
                r.frequency += 1;
                exist = true;
            }
        }
        
        // if not, add it to the run array
        if (!exist)
        {
            run r;
            r.frequency = 1;
            r.symbol = symbol;
            r.runLength = 1;
            r.next = new run();
            Runs.push_back(r);
        }
        ++i;
    }
    
    totalRuns = Runs;
}

// header info
void huffmanCoding::outPutFrequencies(std::ifstream &ifs, std::ofstream &ofs)
{

//    ofs.open("text.txt");
    ofs << totalRuns.size() << std::endl;
    for (auto &run: totalRuns)
    {
        ofs << run.symbol << std::endl;
        ofs << run.frequency <<std::endl;
    }
}

class cmp{
public:
    bool operator()(run &x, run &y) const{
        return (x.frequency) > (y.frequency);
    }
};

void huffmanCoding::createHuffmanTree()
{
//    1. store all runs into the heap.
//    2. while the heap size > 1 do
//    (1) perform extractMin two times
//    (2) make a combined tree
//    (3) insert the combined tree into the heap.
//    3. Let theRoot be the root of the tree.

    std::vector<run> heap = totalRuns;
    std::priority_queue<run, std::vector<run>, cmp> pq;
    for (auto &r: heap)
    {
        pq.push(r);
    }

    run *tree = new run();
    while (pq.size() > 1)
    {
        tree = new run();
        tree->left = new run();
        tree->right = new run();
        *tree->left = pq.top();
        tree->frequency += pq.top().frequency;
        pq.pop();
        *tree->right = pq.top();
        tree->frequency += pq.top().frequency;
        pq.pop();
        pq.push(*tree);
    }
    root = tree;
}

void huffmanCoding::assignCodewords(run &theRoot, int codeword, int length)
{
    if (theRoot.left==nullptr && theRoot.right==nullptr)
    {
        theRoot.codeword = codeword;
        theRoot.codewordLength = length;
    }
    else
    {
        int word = codeword << 1;
        assignCodewords(*(theRoot.left), word|0, length+1);
        assignCodewords(*(theRoot.right), word|1, length+1);
    }

}
void huffmanCoding::storeRunsIntoHashMap(run &theRoot)
{
    if (theRoot.left==nullptr && theRoot.right==nullptr)
    {
        int hash = theRoot.getHashCode();
        auto *node = hashTable[hash];
        if (node == nullptr)
        {
            hashTable[hash] = &theRoot;
        }
        else
        {
            while (node->next != nullptr)
            {
                node = node->next;
            }
            node = &theRoot;
        }
    }
    else
    {
        storeRunsIntoHashMap(*(theRoot.left));
        storeRunsIntoHashMap(*(theRoot.right));
    }
}
void huffmanCoding::encode(std::ifstream &ifs, std::ofstream &ofs)
{
    for (int i=0; i<MAX; i++)
    {
        char buffer =0;
        int length;
        
        if (hashTable[i]!=nullptr)
        {
            auto codeword = hashTable[i]->codeword;
            length += hashTable[i]->codewordLength;
            // or operation 0x0 | codeword
            // shift it to left with the size of codeword length
            // repeat util the size of buffer and length

            if (length<8)
            {
                buffer << hashTable[i]->codewordLength;
                buffer = buffer | codeword;
            }
            else
            {
                buffer << sizeof(char)-length;
                int unused = (hashTable[i]->codewordLength)-(sizeof(char)-length);
                auto temp = codeword >> unused;
                buffer = buffer | codeword;
                // write to file
                // the last of them to buffer
                buffer = 0;
            }
        }
    }
}
