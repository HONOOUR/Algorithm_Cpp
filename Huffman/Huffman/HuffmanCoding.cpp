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

void huffmanCoding::compressFile(std::string file)
{
    collectRuns(file);
    outPutFrequencies(file);
    createHuffmanTree();
    assignCodewords(*root, 0, 0);
    storeRunsIntoHashMap(*root);
    //시작위치로
    encode(file);
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
void huffmanCoding::outPutFrequencies(std::string file)
{
    for (auto &run: totalRuns)
    {
        run.symbol;
        run.frequency;
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
void huffmanCoding::encode(std::string file)
{
    
}
