#include <iostream>
#include <array>

using namespace std;

class HashMap {
private:
    int hash(int key) {
        return key % size;
    }

    static const int size = 11;
    array<int, size> table;
    array<bool, size> bool_table = {false};
public:
    void insert(int key) {
        int index = hash(key);

        int start = index;
        while (bool_table[index] == true) {
            index = (index + 1) % size;
            
            if (index = start) throw runtime_error("Table is full");
        }

        table[index] = key;
        bool_table[index] = true;

    }

    void remove(int key) {
        int index = hash(key);

        int start = index;
        while (table[index] != key) {
            index = (index + 1) % size;

            if (index == start) throw runtime_error("Key not found");
        }

        bool_table[index] = false;
    }

    bool contains(int key) {
        int index = hash(key);

        int start = index;
        while (bool_table[index]) {
            if (table[index] == key) return true;
            index = (index + 1) % size;
            
            if (index == start) break;
        }

        return false;
    }
};