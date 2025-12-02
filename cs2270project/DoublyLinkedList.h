#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <string>
#include <iostream>
using namespace std;

// Each node refers to one document in list
// Each node stores the name of document
// and pointers to earlier and later nodes

struct Node {
    string doc_name;
    Node* prev_node;
    Node* next_node;

    Node(const string& name) {
        doc_name = name;
        prev_node = nullptr;
        next_node = nullptr;
    }
};

// Doubly linked list that stores documents
// in order from newest to oldest

class DoublyLinkedList {
private:
    Node* head; // most recent doc
    Node* tail; // least recent doc
    int size; // number of nodes in list

public:
    // Starts an empty list
    DoublyLinkedList();
    // Deletes each node to free memory
    ~DoublyLinkedList();

    // Inserts new node at the front
    Node* insert_to_front(const string& doc_name);

    // Moves node to the front when
    // document is accessed again
    void add_to_front(Node* node);

    // Moves a node that is already
    // in the list to the front
    void move_to_front(Node* node);

    // Removes last node in the list
    // and returns it back to cache for
    // deletion
    Node* remove_tail();


    void print_list() const;

    int getsize() const; // Returns number of nodes in list
    bool empty() const; // Checks if list is empty

    Node* get_head_node() const; // Points to first node
    Node* get_tail_node() const; // Points to last node
};

#endif


