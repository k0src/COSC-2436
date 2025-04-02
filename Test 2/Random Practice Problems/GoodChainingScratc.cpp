#include "help.h"

using namespace std;

class HashMap {
private:
    int hash(int key) {
        return (key % size + size) % size;
    }

    struct kv_node {
        int key;
        int value;
        kv_node* next;
        kv_node(int key, int value) : key(key), value(value), next(nullptr) {}
    };

    const static int size = 13;
    std::array<kv_node*, size> table{};
public:
    ~HashMap() {
        for (auto kv : table) {
            while (kv) {
                kv_node* temp = kv;
                kv = kv->next;
                delete temp;
            }
        }
    }

    bool insert(int key, int value) {
        int index = hash(key);
        
        kv_node* current = table[index];
        kv_node* prev = nullptr;
    
        while (current) {  
            if (current->key == key) {  // Update if key already exists
                current->value = value;
                return false;
            }
            prev = current;
            current = current->next;
        }
    
        // Insert new node at the end
        if (prev) {
            prev->next = new kv_node(key, value);
        } else {
            table[index] = new kv_node(key, value); // Insert at head if bucket was empty
        }
        
        return true;
    }

    bool remove(int key) {
        int index = hash(key);
        kv_node* current = table[index];
        kv_node* prev = nullptr;
    
        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    table[index] = current->next; // Update head if deleting first node
                }
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }    

    int get(int key) {
        int index = hash(key);

        kv_node* current = table[index];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }

        return -1;
    }
};

int main()
{

    return 0;
}