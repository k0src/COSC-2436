#include <iostream>
#include <array>
#include <list>

using namespace std;

class HashMap {
private:
    int hash(int key) {
        return key % size;
    }
    
    static const int size = 11;
    array<list<int>, size> table;
public:
    void insert(int key) {
        int index = hash(key);

        if (find(table[index].begin(), table[index].end(), key) != table[index].end()) 
            return; // Return if there is a duplicate
        
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hash(key);

        if (find(table[index].begin(), table[index].end(), key) == table[index].end()) 
            return;

        table[index].remove(key);
    }

    bool contains(int key) {
        int index = hash(key);

        return find(table[index].begin(), table[index].end(), key) != table[index].end();
    }
};