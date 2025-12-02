#ifndef DOCUMENT_CACHE
#define DOCUMENT_CACHE

#include <string>
#include <unordered_map>
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

// DocumentCache uses an LRU
// which keeps track of 
// documents opened in order

class DocumentCache {
private:
    int capacity; // max number of docs the cache can hold
    DoublyLinkedList list; // organizes docs from new to old
    unordered_map<string, Node*> table; // allows quick search 
                                        // matches node by name

public:
    DocumentCache(int cap); // Builds cache given max capacity

    // Opens documents
    // If it exists, then move it to the front
    // If its new, add it to the front
    // if the cache is full, remove least recent one

    void open_document(const string& docName);


    void printCache() const;
};

#endif


