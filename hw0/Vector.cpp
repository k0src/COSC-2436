#include "vector.h"
#include <iostream>
#include <algorithm>

Vector::Vector() : data(new int[2]), size(0), capacity(2) {}

Vector::~Vector() {
    delete[] data;
}

void Vector::resize(int new_capacity) {
    if (new_capacity < 2) {
        new_capacity = 2;
    }
    int* new_data = new int[new_capacity];
    for (int i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

void Vector::Add(int x) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size++] = x;
}

void Vector::Delete(int x) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (data[i] == x) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
        if (size < capacity / 2) {
            resize(capacity / 2);
        }
    }
}

void Vector::Print() const {
    if (size == 0) {
        std::cout << std::endl;
        return;
    }
    for (int i = 0; i < size; ++i) {
        std::cout << data[i];
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

void Vector::Size() const {
    std::cout << size << std::endl;
}

void Vector::Capacity() const {
    std::cout << capacity << std::endl;
}
