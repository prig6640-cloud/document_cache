#include "DoublyLinkedList.h"

// This is an empty list
// No nodes yet
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Deletes each node to prevent memory leak
DoublyLinkedList::~DoublyLinkedList(){
    Node* current = head;
    while (current != nullptr){
        Node* next = current->next_node;
        delete current;
        current = next;
    }
}

// Inserts new node at the front of the list
Node* DoublyLinkedList::insert_to_front(const string& doc_name) {
    Node* node = new Node(doc_name);
    add_to_front(node);
    return node;
}

// Moves this node to the front as the most recent
void DoublyLinkedList::add_to_front(Node* node){
    if (node == nullptr){
        return;
    }

    node->prev_node = nullptr;
    node->next_node = head;

    if (head != nullptr) {
        head->prev_node = node;
    }
    head = node;


    if (tail == nullptr) {
        tail = node;
    }

    size++;
}


// Puts node already in the list to the front
void DoublyLinkedList::move_to_front(Node* node) {
    if (node == nullptr || node == head) {
        return;
    }

    if (node->prev_node != nullptr) {
        // links previous node to the next one and skips current node
        node->prev_node->next_node = node->next_node; 
    }
    if (node->next_node != nullptr) {
        node->next_node->prev_node = node->prev_node;
    }

    if (node == tail) {
        tail = node->prev_node;
    }

    node->prev_node = nullptr;
    node->next_node = head;

    if (head != nullptr) {
        head->prev_node = node;
    }

    head = node;

    if (tail == nullptr) {
        tail = head;
    }

}
// Removes last node in list and returns it 
Node* DoublyLinkedList::remove_tail() {
    if (tail == nullptr) {
        return nullptr;
    }

    Node* node = tail;

    if (tail->prev_node != nullptr){
        tail = tail->prev_node;
        tail->next_node = nullptr;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }

    node->prev_node = nullptr;
    node->next_node = nullptr;

    size--;
    return node;
}

void DoublyLinkedList::print_list() const {
    Node* current = head;
    while (current != nullptr){
        cout << current->doc_name;
        if (current->next_node != nullptr) {
            cout << " --> ";
        }
        current = current->next_node;
    }
    cout << endl;
}
// Returns number of nodes in list
int DoublyLinkedList::getsize() const {
    return size;
}

bool DoublyLinkedList::empty() const{
    return size == 0;
}
// Returns recent node
Node* DoublyLinkedList::get_head_node() const{
    return head;
}
// Returns last node
Node* DoublyLinkedList::get_tail_node() const {
    return tail;
}