#include "help.h"

using namespace std;

class HashMap {
private:
    int hash(int key) {
        return (key % size + size) % size;
    }

    struct KVPair {
        int key;
        int value;
        KVPair(int key, int value) : key(key), value(value) {}
    };

    const static int size = 13;
    std::array<list<KVPair>, size> arr;
public:
    bool insert(int key, int value) {
        int index = hash(key);

        for (auto& kv : arr[index]) {
            if (kv.key == key) {
                kv.value = value;
                return false;
            }
        }

        arr[index].push_back({key, value});
        return true;
    }

    bool remove(int key) {
        int index = hash(key);

        for (auto it = arr[index].begin(); it != arr[index].end(); it++) {
            if (it->key == key) {
                arr[index].erase(it);
                return true;
            }
        }

        return false;
    }

    bool contains(int key) {
        int index = hash(key);

        for (auto& kv : arr[index]) {
            if (kv.key == key) return true;
        }

        return false;
    }
};

int main()
{
    HashMap m;
    m.insert(12, 10);
    m.insert(2, 15);
    m.insert(4, 6);
    m.insert(8, 90);

    cout << m.contains(2);
    return 0;
}