#include <iostream>

class Queue {
private:
    int size;
    int count;
    int* arr;
public:
    Queue(int size) : size(size), count(0) {
        arr = new int[size];
    }

    void enqueue(int item) {
        if (count == size) return;
        arr[count++] = item;
    }

    void dequeue() {
        if (count == 0) return;
        
        for (int i = 1; i < count; i++) {
            arr[i - 1] = arr[i];
        }
        count--;
    }

    int front() const {
        if (count == 0) return -1;
        return arr[0];
    }

    bool empty() const {
        return count == 0;
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.dequeue();
    }

    return 0;
}