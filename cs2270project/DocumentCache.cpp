#include "DocumentCache.h"

DocumentCache::DocumentCache(int cap) {
    capacity = cap;
}

void DocumentCache::open_document(const string& doc_name) {
    
    // finds document in the hash table
    auto search_result = table.find(doc_name);

    // if doc is found, then moves to the front if recent
    if (search_result != table.end()) {
        Node* node = search_result->second;
        list.move_to_front(node);
        cout << "Document found: " << doc_name << endl;
    }
    // if document is not found, then adds it to the cache
    else {
        if (list.getsize() == capacity && !list.empty()) {
            Node* lru_node = list.remove_tail();
            if (lru_node != nullptr) {
                cout << "Cache full. Removing: " << lru_node->doc_name << endl;
                table.erase(lru_node->doc_name);
                delete lru_node;
            }
        }

        // adds any new documents to the front of the list
        Node* new_node = list.insert_to_front(doc_name);
        table[doc_name] = new_node;
        cout << "Opened new document: " << doc_name << endl;

    }
}

void DocumentCache::printCache() const {
    if (list.empty()) {
        cout << "Cache is empty." << endl;
    }
    else {
        cout << "List of documents in the cache:" << endl;
        list.print_list();
    }
}