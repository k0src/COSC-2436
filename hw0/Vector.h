#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    int* data;
    int size;
    int capacity;

    void resize(int new_capacity);

public:
    Vector();
    ~Vector();

    void Add(int x);
    void Delete(int x);
    void Print() const;
    void Size() const;
    void Capacity() const;

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }

    int operator[](int index) const { return data[index]; }
};

#endif
