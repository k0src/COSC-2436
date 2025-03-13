#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <stdexcept>

class HashMap {
public:
    HashMap() : capacity(256) {
        table.resize(capacity);
    }

    void add(int key, int value) {
        int index = hash(key);

        table[index].push_back(Entry(key, value));
    }

    void remove(int key) {
        int index = hash(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->key == key) {
                table[index].erase(it);
                return;
            }
        }

        throw std::out_of_range("Key does not exist.");
    }

    int get(int key) {
        int index = hash(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->key == key) {
                return it->value;
            }
        }

        throw std::out_of_range("Key does not exist.");
    }

    bool find(int key) {
        int index = hash(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->key == key) {
                return true;
            }
        }

        return false;
    }

private:
    struct Entry {
        Entry(int key, int value) : key(key), value(value) {}
        int key, value;
    };

    int hash(int key) {
        const double A = 0.6180339887;
        return static_cast<int>(table.size() * fmod(key * A, 1));
    }
    
    std::vector<std::list<Entry>> table;

    int capacity = 256;
};

int main()
{
    HashMap map;
    map.add(1, 2);
    map.add(6, 5);
    map.add(7, 19);

    std::cout << map.get(6);
    return 0;
}