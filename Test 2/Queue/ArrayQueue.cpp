#include <iostream>
#include <stdexcept>

class Queue {
public:
    Queue(int size) : size(size), count(0) {
        if (size < 1) {
            throw std::invalid_argument("Invalid size.");
        }
        array = new int[size];
    }

    ~Queue() {
        delete[] array;
    }

    void enqueue(int item) {
        if (count == size) {
            throw std::runtime_error("Queue is full.");
        }
        array[count++] = item;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty.");
        }

        for (int i = 1; i < count; i++) {
            array[i - 1] = array[i];
        }
        count--;
    }

    int front() const {
        if (isEmpty()) {
            throw std::runtime_error("Queue is empty.");
        }
        return array[0];
    }

    bool isEmpty() const {
        return count == 0;
    }

private:
    int* array;
    int size;
    int count;
};

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    while (!q.isEmpty()) {
        std::cout << q.front() << std::endl;
        q.dequeue();
    }

    return 0;
}
