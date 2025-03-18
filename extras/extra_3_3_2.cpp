#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

const int TABLE_SIZE = 100;

struct htn {
  int key;
  int value;
  bool occupied = false;
};

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(htn hashtable[], int key, int value) {
    int index = hash(key);

    while (hashtable[index].occupied) {
        if (hashtable[index].key == key) {
            hashtable[index].value = value;
            return;
        }

        index = (index + 1) % TABLE_SIZE;
    }

    hashtable[index].key = key;
    hashtable[index].value = value;
    hashtable[index].occupied = true;
}

bool find(htn hashtable[], int key) {
    int index = hash(key);
    int start = index;

    while (hashtable[index].occupied) {
        if (hashtable[index].key == key) {
            return true;
        }

        index = (index + 1) % TABLE_SIZE;

        if (index == start) return false;
    }

    return false;
}

void remove(htn hashtable[], int key) {
    int index = hash(key);

    while (hashtable[index].occupied) {
        if (hashtable[index].key == key) {
            hashtable[index].occupied = false;
            return;
        }

        index = (index + 1) % TABLE_SIZE;
    }

    throw std::out_of_range("Key does not exist.");
}

int main() 
{
    std::srand(std::time(0));

    htn hashtable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashtable[i].occupied = false;
    }

    // Time to insert 100 numbers
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < TABLE_SIZE; i++) {
        int key = rand() % 1000;
        int value = rand() % 1000;
        insert(hashtable, key, value);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_taken = end - start;
    std::cout << "Time taken for 100 insertions: " << time_taken.count() << " milliseconds" << std::endl;
    std::cout << "Table:" << std::endl;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashtable[i].occupied) {
            std::cout << "Index: " << i << " Key: " << hashtable[i].key << " Value: " << hashtable[i].value << std::endl;
        }
    }

    std::cout << std::endl;

    // Search time (100 searches)
    auto start2 = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < TABLE_SIZE; i++) {
        int search = rand() % 1000;
        std::cout << "Searching for: " << search;
        if (find(hashtable, search)) {
            std::cout << ". Found " << search << "." << std::endl;
        } else {
            std::cout << ". Didn't find " << search << "." << std::endl;
        }
    }

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time_taken2 = end2 - start2;
    std::cout << "Time taken for 100 searches: " << time_taken2.count() << " milliseconds" << std::endl;

    std::cout << std::endl;

    return 0;
}