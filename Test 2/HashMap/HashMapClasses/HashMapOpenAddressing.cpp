#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>

class HashMap {
public:
    HashMap() : capacity(256) {
        table.resize(capacity);
    }

    void add(int key, int value) {
        int index = hash(key);

        while (table[index].occupied) {
            if (table[index].key == key) {
                table[index].value = value;
                return;
            }

            index = (index + 1) % capacity;
        }

        table[index].key = key;
        table[index].value = value;
        table[index].occupied = true;
    }

    void remove(int key) {
        int index = hash(key);

        while (table[index].occupied) {
            if (table[index].key == key) {
                table[index].occupied = false;
                return;
            }

            index = (index + 1) % capacity;
        }

        throw std::out_of_range("Key does not exist.");
    }

    int get(int key) {
        int index = hash(key);

        while (table[index].occupied) {
            if (table[index].key == key) {
                return table[index].value;
            }

            index = (index + 1) % capacity;
        }
        
        throw std::out_of_range("Key does not exist.");
    }

    bool find(int key) {
        int index = hash(key);

        while (table[index].occupied) {
            if (table[index].key == key) {
                return true;
            }

            index = (index + 1) % capacity;
        }

        return false;
    }

private:
    struct Entry {
        Entry() : occupied(false) {}

        int key, value;
        bool occupied;
    };

    int hash(int key) {
        const double A = 0.6180339887;
        return static_cast<int>(table.size() * fmod(key * A, 1));
    }

    std::vector<Entry> table;
    int capacity;
};

int main()
{
    HashMap map;
    map.add(1, 100);
    map.add(2, 200);
    map.add(257, 300);  // Collides with key 1

    std::cout << map.get(1) << "\n";  // Should print 100
    std::cout << map.get(2) << "\n";  // Should print 200
    std::cout << map.get(257) << "\n";  // Should print 300

    map.remove(1);
    std::cout << map.find(1) << "\n";  // Should print 0 (false)

    return 0;
}
