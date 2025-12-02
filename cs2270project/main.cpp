#include <iostream>
#include <string>
#include "DocumentCache.h"

using namespace std;

int main() {

    cout << "==============================" << endl;
    cout << "    Document Cache (LRU)" << endl;
    cout << "==============================" << endl;
    cout << endl;

    int capacity;

    cout << "Enter cache size (example: 3): ";
    cin >> capacity;

    while (capacity <= 0){
        cout << "Capacity cannot be 0. Please enter a valid number: " << endl;
        cin >> capacity;
    }

    cin.ignore();

    DocumentCache cache(capacity);

    cout << "Menu:" << endl;
    cout << "  Enter a document name to open it." << endl;
    cout << "  Press 'p' to print the cache." << endl;
    cout << "  Press 'q' to quit" << endl;
    cout << endl;

    while (true) {
        cout << "> ";
        string input;
        getline(cin, input);

        if (input == "q") {
            cout << "Exiting program." << endl;
            break;
        }
        else if (input == "p") {
            cache.printCache();
        }
        else if (input == "") {
            continue;
        }
        else {
            cache.open_document(input);
        }
    }
    return 0;
}
