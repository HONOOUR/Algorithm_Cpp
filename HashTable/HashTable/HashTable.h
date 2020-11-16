//
//  HashTable.h
//  Algorithm_Cpp
//
//  Created by jieunChoi on 2020/11/07.
//  Copyright © 2020 jieunChoi. All rights reserved.
//  Chaining Hash Table

#ifndef HashTable_h
#define HashTable_h

#include "HashNode.h"

#include <iostream>
#include <list>
#include <string>
#include <memory>

#define MAX_TABLE 10

// HashTable 902(key) Apple(value)
//template<typename K, typename V>

class HashTable
{
public:
    HashTable();
//    void initialize();
    int hashFunction(int key);
    void insertNode(int key, std::string value);
    void deleteNode(int key);
    std::string SearchNode(int key);
    void printTable();
    
private:
    HashNode* table[MAX_TABLE];
//    std::shared_ptr<HashNod> table;
};

#endif /* HashTable_h */
