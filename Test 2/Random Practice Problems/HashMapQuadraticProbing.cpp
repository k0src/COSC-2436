#include <iostream>

using namespace std;

class HashMap {
private:
    int hash(int key) {
        return key % size;
    }

    struct KVPair {
        int key;
        int value;
        KVPair() : key(0), value(0) {} // default
        KVPair(int key, int value) : key(key), value(value) {}
    };

    static const int size = 23;
    KVPair table[size];
    bool bool_table[size];
public:
    HashMap() {
        for (int i = 0; i < size; i++) {
            bool_table[i] = false;
        }
    }

    void insert(int key, int value) {
        int index = hash(key);

        int start = index;
        int i = 1;
        while (bool_table[index]) {
            if (table[index].key == key) {  // Update existing key
                table[index].value = value;
                return;
            }

            index = (int) (index + i * i) % size;
            i++;
            if (index == start) return; // full
        }

        table[index] = KVPair(key, value);
        bool_table[index] = true;
    }

    void remove(int key) {
        int index = hash(key);

        int start = index;
        int i = 1;
        while (bool_table[index] && key != table[index].key) {
            index = (int) (index + i * i) % size;
            i++;
            if (index == start) return; // not found
        }

        if (bool_table[index] && table[index].key == key) {
            bool_table[index] = false;
        }
    }

    int get(int key) {
        int index = hash(key);

        int start = index;
        int i = 1;
        while (bool_table[index]) {
            if (table[index].key == key) return table[index].value;
            index = (index + i * i) % size;
            i++;
            if (index == start) break;  // Not found
        }
        return -1;  // Key not present
    }
};