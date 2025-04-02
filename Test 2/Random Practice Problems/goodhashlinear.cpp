#include <array>
#include <iostream>

using namespace std;

class HashMap {
private:
    enum SlotState { EMPTY, FILLED, DELETED };
    
    struct kv_pair {
        int key;
        int value;
        kv_pair() : key(0), value(0) {}
        kv_pair(int key, int value) : key(key), value(value) {}
    };

    const static int size = 13;
    array<kv_pair, size> arr;
    array<SlotState, size> slot_state;

    int hash(int key) {
        return (key % size + size) % size;
    }

public:
    HashMap() {
        slot_state.fill(EMPTY);
    }

    bool insert(int key, int value) {
        int index = hash(key);
        int start_index = index;

        // can overwrite empty or deleted
        while (slot_state[index] == FILLED) {
            if (arr[index].key == key) {
                arr[index].value = value;
                return false;
            }

            index = (index + 1) % size;
            if (index == start_index) return false;
        }

        arr[index] = {key, value};
        slot_state[index] = FILLED;
        return true;
    }

    // searches for filled, while slot_state is not EMPTY, meaning we pass over the deleted ones, in case there was a previous collision
    bool remove(int key) {
        int index = hash(key);
        int start_index = index;

        while (slot_state[index] != EMPTY) {
            if (slot_state[index] == FILLED && arr[index].key == key) {
                slot_state[index] = DELETED;
                return true;
            }

            index = (index + 1) % size;
            if (index == start_index) return false;
        }

        return false;
    }

    bool contains(int key) {
        int index = hash(key);
        int start_index = index;

        while (slot_state[index] != EMPTY) { 
            if (slot_state[index] == FILLED && arr[index].key == key) {
                return true;
            }

            index = (index + 1) % size;
            if (index == start_index) return false;
        }

        return false;
    }
};
