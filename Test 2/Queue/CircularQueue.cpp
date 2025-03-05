#include <iostream>
#include <stdexcept>

class CircularQueue {
public:
    CircularQueue(int capacity) : capacity(capacity), count(0), front(0) {
        if (capacity < 1) {
            throw std::invalid_argument("Invalid size.");
        }

        array = new int[capacity];
    }

    ~CircularQueue() {
        delete[] array;
    }

    void enqueue(int item) {
        if (count == capacity) {
            throw std::runtime_error("Queue is full.");
        }

        int rear = (front + count) % capacity;
        array[rear] = item;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            throw std::runtime_error("Queue is empty.");
        }

        front = (front + 1) % capacity;
        count--;
    }

    int peekFront() const {
        if (count == 0) {
            throw std::runtime_error("Queue is empty.");
        }

        return array[front];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

private:
    int* array;
    int capacity;
    int count;
    int front;
};

int main()
{
	CircularQueue cq(4);
	cq.enqueue(1);
	cq.enqueue(2);
	cq.dequeue();
	cq.enqueue(4);
	cq.enqueue(6);

	while (!cq.isEmpty()) {
		std::cout << cq.peekFront() << std::endl;
		cq.dequeue();
	}

	return 0;
}