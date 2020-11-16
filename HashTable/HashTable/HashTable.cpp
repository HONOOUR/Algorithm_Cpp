//
//  HashTable.cpp
//  Algorithm_Cpp
//
//  Created by jieunChoi on 2020/11/08.
//  Copyright © 2020 jieunChoi. All rights reserved.
//

#include "HashTable.h"

#include <stdio.h>
#include <string>
#define MAX_TABLE 10

HashTable::HashTable()
: table{new HashNode()}
{
    try {
        for (int i=0; i<MAX_TABLE; ++i)
        {
            HashNode *current = table[i];
            HashNode *temp = nullptr;
            while (current != nullptr) {
                temp = current;
                current = current->next;
                free(temp);
            }
        table[i] = nullptr;
        }
    } catch (...) {
        std::cout << "an exception is occured." << std::endl;
    }
}


int HashTable::hashFunction(int key)
{
    return key % MAX_TABLE;
}

void HashTable::insertNode(int key, std::string value)
{
    int hashValue = hashFunction(key);
    HashNode * newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->value = value;
    std::cout << "created a new hash node to hash value: " << hashValue << std::endl;
    std::cout << "key: " << newNode->key << std::endl;
    std::cout << "value: " << newNode->value << std::endl;
    
    if (table[hashValue] == NULL) {
        table[hashValue] = newNode;
        table[hashValue]->tail = newNode;
        newNode->next = newNode;
        newNode->before = newNode;
    } else {
        HashNode *current = table[hashValue];
        HashNode *tailNode = nullptr;
        tailNode = current->tail;
        // add a new node next to the tail node
        current->tail->next = newNode;
        // make the new node's before point to tail node
        newNode->before = tailNode;
        // make the new node to the tail node
        current->tail = newNode;
        // make the node to tail node
        newNode->next = table[hashValue];
    }
}

void HashTable::deleteNode(int key)
{
    // find the hash value
    int hashValue = hashFunction(key);
        
    // find the node
    auto *hashNode = table[hashValue];
    while (hashNode->key != key)
    {
        hashNode = hashNode->next;
    }
    std::cout << "found hash value: " << hashValue << std::endl;
    std::cout << "key: " << hashNode->key << std::endl;
    std::cout << "value: " << hashNode->value << std::endl;
        
    // make the node's next to]
        
    auto *beforeNode = hashNode->before;
    auto *nextNode = hashNode->next;
    beforeNode->next = nextNode;
    nextNode->before = beforeNode;
    auto *tailNode = table[hashValue]->tail;
    if (hashNode == tailNode)
    {
        tailNode = hashNode->before;
    }
}

std::string HashTable::SearchNode(int key)
{
    return std::string();
}

void HashTable::printTable()
{
    
}
