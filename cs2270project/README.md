# Project: Document Cache using LRU (Least Recently Used)

Project Goal: This project utilizes a caching system that stores most of the users' recently opened documents. This program keeps recent documents at the front and removes the oldest documents when the cache becomes full.

Data Structure: This project implements a doubly linked list with a hash table. 

This project highlights:
- designing an LRU (Least Recently Used) cache system
- using a doubly linked list to store latest items in the front
- using a hash map to store document names and their nodes
- managing pointers and efficient use of memory allocation

# File Structure

```cpp
main.cpp                    # main file that runs to test cache
DoublyLinkedList.h          # Defines the Node struct and linked list
DoublyLinkedList.cpp        # Performs linked list operations
DocumentCache.h             # Declares LRU cache class
DocumentCache.cpp           # Implementation of cache function
README.md                   # Project description and walkthrough

```

# Program Structure:

- Every document is saved as a Node object in a doubly linked list
- The Node struct stores a single document in the cache

CODE SNIPPET 1:

```cpp

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

```

What's in the node?

1. doc_name is stored as a string
2. prev_node is a pointer that refers to the node on the left
3. next_node is a pointer that points to the next node in the list

The benefit of two pointers is that the list can be traversed either way. 
Operations like inserting or deleting can be done efficiently without traversing through the whole list.

KEY FUNCTION:
```cpp
void DocumentCache::open_document(const string& doc_name)
```
 
- This function handles the opening of documents
- It starts by searching the hash table to find out if the document exists 
- If the document exists, then the node is moved to the front
- If the document is not found, there are two things that occur
    1. The first is that if the cache is out of space, then the least recent node is deleted from the list as well as the hash table
    2. Secondly, a new node is created, placed at the front, and saved in the hash

- This highlights how the linked list and hash table are used together in order to keep the cache ordered.


OTHER KEY FUNCTIONS:
```cpp
1. Node* insert_to_front(const string& doc_name)
```

- This function makes a new node and sets it in the first position
- Any new document is declared as most recent
- Returns the pointer to this node and gets saved in the hash

```cpp
2. void DoublyLinkedList::move_to_front(Node* node)
```

- This function updates the document's position in the list
- If a document is already in the cache, then it moves back to the front 
- This avoids any duplicate entries and maintains the order (most recent to least recent)

```cpp
3. Node* DoublyLinkedList::remove_tail()
```

- This function removes the oldest document from the list
- When capacity is full, it removes the last item and returns to the cache
- It is removed from memory

CODE SNIPPET 2:

``` cpp

class DocumentCache {
private:
    int capacity; 
    DoublyLinkedList list; 
    unordered_map<string, Node*> table; 
};

```
The DocumentCache class uses an LRU which keeps track of the documents in the order the user opened them

Key Member Variables

1. int capacity

- this variable decides the maximum number of documents it can hold
- when the cache is full, the oldest document is dropped from list

2. DoublyLinkedList list

- arranges documents from most recent to least recent
- allows the cache to quickly remove any old document at its tail
- makes it easy to quickly move the document to the front of the list

3. unordered_map<string, Node*> table

- this member variable pairs the document name with its corresponding node
- cache checks if document is stored - fast search (O(1))

```cpp
# Time and Space Complexity

Operation                  Average Case        Worst Case          Explanation

1. Insert/Open new Doc       O(1)                O(1)        Makes new node/stores ptr
2. Search Doc                O(1)                O(1)        Hash finds node fast
3. Move Doc to Front         O(1)                O(1)        Only ptr updates
4. Delete Oldest Doc         O(1)                O(1)        Deletes tail
```

# What the Program Does:

Here is a demo of how the program behaves when you open any document:

``` cpp
==============================
    Document Cache (LRU)
==============================

Enter the cache capacity (example: 3): 3
Menu:
  Enter a document name to open it.
  Press 'p' to print the cache.
  Press 'q' to quit

> recipe book
Opened new document: recipe book
> letters
Opened new document: letters
> notes
Opened new document: notes
> p
List of documents in the cache:
notes --> letters --> recipe book
> shopping list
Cache full. Removing: recipe book
Opened new document: shopping list
> p
List of documents in the cache:
shopping list --> notes --> letters
===================================

```

Explanation: 

- When you type a new document, it gets added to the front of the list
- I declared that only three documents belonged in the cache. 
- When I entered a fourth document, the cache reached its capacity.
- Therefore, it removed recipe book and added shopping list to the front of the list.

# Running the Program Demo

Follow the steps below to set up and run the program:
1. Open terminal inside VS Code
2. Compile the program by pasting in this command:

```cpp
clang++ main.cpp DoublyLinkedList.cpp DocumentCache.cpp -std=c++17 -o doc_cache
```

3. Once it is compiled, run the program using this command:

```cpp
./doc_cache
```

4. The program will execute inside of main.cpp. It will display a menu where you can enter:

- document names 
- 'p' to print
- 'q' to quit


# References

1. GeeksforGeeks – LRU Cache Implementation
https://www.geeksforgeeks.org/system-design/lru-cache-implementation/

2. GeeksforGeeks – Doubly Linked List 
https://www.geeksforgeeks.org/dsa/doubly-linked-list/

3. zyBooks - (Doubly Linked Lists) Chapter 5, Section 5.6 - 5.10 

4. zyBooks - (Hash Tables) Chapter 14

5. C++ Reference - std::unordered_map
https://en.cppreference.com/w/cpp/container/unordered_map.html
