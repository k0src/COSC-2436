#include "help.h"

using namespace std;

// (hash1(key) + (i * hash2(key)) ) % size

class HashMap {
private:
    enum SlotState { EMPTY, FILLED, DELETED };

    int hash1(int key) {
        return (key % size + size) % size;
    }

    int hash2(int key) {
        return (5 - (key % 5)); // must be coprime with size
    }

    struct kv_pair {
        int key;
        int value;
        kv_pair(int key, int value) : key(key), value(value) {}
        kv_pair() : key(0), value(0) {}
    };

    const static int size = 13;
    array<kv_pair, size> arr;
    array<SlotState, size> slot_state;
public:
    HashMap() {
        slot_state.fill(EMPTY);
    }

    bool insert(int key, int value) {
        int i = 0;
        int index = hash1(key);
        int start_index = index;

        while (slot_state[index] == FILLED) {
            if (arr[index].key == key) {
                arr[index].value = value;
                return false;
            }

            i++;
            index = (hash1(key) + (i * hash2(key))) % size;
            if (index == start_index) return false;
        }

        return true;
    }

    bool remove(int key) {
        int i = 0;
        int index = hash1(key);
        int start_index = index;

        while (slot_state[index] != EMPTY) {
            if (slot_state[index] == FILLED && arr[index].key == key) {
                slot_state[index] = DELETED;
                return true;
            }

            i++;
            index = (hash1(key) + (i * hash2(key))) % size;
            if (index == start_index) return false;
        }

        return false;
    }

    bool contains(int key) {
        int i = 0;
        int index = hash1(key);
        int start_index = index;

        while (slot_state[index] != EMPTY) {
            if (slot_state[index] == FILLED && arr[index].key == key) {
                return true;
            }

            i++;
            index = (hash1(key) + (i * hash2(key))) % size;
            if (index == start_index) return false;
        }

        return false;
    }
};

int main()
{

    return 0;
}