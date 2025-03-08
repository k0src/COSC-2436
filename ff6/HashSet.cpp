#include <iostream>
#include <list>
#include <vector>

class MyHashSet {
public:
    MyHashSet() {
        table.resize(256);
    }

    void add (int key) {
        int index = hash(key);

        if (table[index].empty()) {
            table[index].push_back(key);
        } else {
            for (auto it = table[index].begin(); it != table[index].end(); it++) {
                if (*it == key) {
                    return;
                }
            }
            table[index].push_back(key);
        }
    }

    void remove(int key) {
        int index = hash(key);

        if (table[index].empty()) {
            return;
        } else {
            for (auto it = table[index].begin(); it != table[index].end(); it++) {
                if (*it == key) {
                    table[index].erase(it);
                    return;
                }
            }
        }
    }

    bool contains(int key) {
        int index = hash(key);

        if (table[index].empty()) {
            return false;
        } else {
            for (auto it = table[index].begin(); it != table[index].end(); it++) {
                if (*it == key) {
                    return true;
                }
            }
        }

        return false;
    }
private:
    // underlying array of lists
    std::vector<std::list<int>> table;

    // hashing function
    int hash(int key) {
        double A = 0.6180339887;
        return (int) (table.size() * (key * A - (int)(key * A)));
    }
};

int main()
{
    // test
    MyHashSet hashSet;

    hashSet.add(1);
    hashSet.add(2);
    std::cout << hashSet.contains(1) << std::endl; // true
    std::cout << hashSet.contains(3) << std::endl; // false
    hashSet.remove(1);
    std::cout << hashSet.contains(1) << std::endl; // false

    return 0;
}