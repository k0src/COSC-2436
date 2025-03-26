#include <iostream>

using namespace std;

class CircularQueue {
public:
    CircularQueue(int size) : _size(size) {
        _arr = new int[_size];
        _front = -1;
        _back = -1;
    }

    void enqueue(int item) {
        if ((_back + 1) % _size == _front) return; // full
        if (_front == -1) {
            _front = 0;
            _back = 0;
        } else {
            _back = (_back + 1) % _size;
        }
        _arr[_back] = item;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (_front == _back) {
            _front = 0;
            _back = 0;
        } else {
            _front = (_front + 1) % _size;
        }
    }

    int front() {
        if (!isEmpty) return _arr[_front];
    }

    int back() {
        if (!isEmpty) return _arr[_back];
    }

    bool isEmpty() {
        return _front == -1;
    }

private:
    int* _arr;
    int _size;
    int _front;
    int _back;
};