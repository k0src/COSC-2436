#include <iostream>
#include <stdexcept>

class CircularQueue {
private:
    int size;
    int* arr;
    int front;
    int back;
public:
    CircularQueue(int size) : size(size), front(-1), back(-1) {
        arr = new int[size];
    }

    bool enqueue(int item) {
        if (isEmpty()) {
            front = back = 0;
            arr[back] = item;
        } else {
            if (isFull()) return false;
            back = (back + 1) % size;
            arr[back] = item;
        }

        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        if (front == back) front = back = -1;
        else front = (front + 1) % size;

        return true;
    }

    int getFront() const {
        return arr[front];
    }

    int getBack() const {
        return arr[back];
    }

    bool isEmpty() const {
        return front == -1;
    }

    bool isFull() const {
        return (back + 1) % size == front;
    }
};