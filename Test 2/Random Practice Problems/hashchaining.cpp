#include <iostream>

// scratch

using namespace std;

class HashMap {
private:
    int hash(int key) {
        return key % size;
    }

    class TableNode {
    private:
        struct KVPair {
            int key;
            int value;
            KVPair(int key, int value) : key(key), value(value) {}
        };

    public:
        TableNode(int key, int value) : p(new KVPair(key, value)), next(nullptr) {}
        ~TableNode() { delete p; }

        KVPair* p;
        TableNode* next;
    };

    static const int size = 11;
    TableNode* table[size];
public:
    HashMap() {
        for (int i = 0; i < size; i++) table[i] = nullptr;
    }

    ~HashMap() {
        for (int i = 0; i < size; i++) {
            TableNode* current = table[i];
            while (current) {
                TableNode* temp = current;
                delete temp;
                current = current->next;
            }
        }
    }
    void insert(int key, int value) {
        int index = hash(key);

        TableNode* current = table[index];

        if (!current) {
            table[index] = new TableNode(key, value);
            return;
        }

        while (current->next) {
            if (key == current->p->key) {
                current->p->value = value;
                return;
            }
            current = current->next;
        }

        if (key == current->p->key) { // one node
            current->p->value = value;
        } else {
            current->next = new TableNode(key, value);
        }
    }

    void remove(int key) {
        int index = hash(key);

        TableNode* current = table[index];
        TableNode* prev = nullptr;

        if (!current) return; // item doesn't exist

        while (current) {
            if (key == current->p->key) {
                if (prev) {
                    prev->next = current->next; // bypass the current node
                } else {
                    table[index] = current->next; // update head if first node
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    int get(int key) {
        int index = hash(key);

        TableNode* current = table[index];

        while (current) {
            if (key == current->p->key) return current->p->value;
            current = current->next;
        }

        return -1; // or throw
    }
};