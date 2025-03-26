#include <iostream>
#include <stdexcept>

class CircularQueue {
private:
    int* arr;
    int size;
    int front;
    int back;
public:
    CircularQueue(int size) : size(size), front(-1), back(-1) {
        arr = new int[size];
    }
    void enqueue(int item) {
        if (isEmpty()) {
            front = back = 0;
            arr[back] = item;
        } else {
            if ((back + 1) % size == front) throw std::runtime_error("Queue is full.");
            back = (back + 1) % size;
            arr[back] = item;
        }
    }

    void dequeue() {
        if (isEmpty()) throw std::runtime_error("Queue is empty.");
        if (front == back) {
            front = back = -1; // empty, reset
        } else {
            front = (front + 1) % size;
        }
    }

    int getFront() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty.");
        return arr[front];
    }

    int getBack() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty.");
        return arr[back];
    }

    bool isEmpty() const {
        return front == -1;
    }
};