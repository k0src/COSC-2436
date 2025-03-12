#include <iostream>
#include <vector>
#include <stdexcept>

class PriorityQueue {
public:
    void enqueue(int value) {
        array.push_back(value);
        int i = array.size() - 1;

        while (i != 0 && array[i] > array[(i - 1) / 2]) {
            std::swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int dequeue() {
        if (isEmpty()) throw std::runtime_error("Queue is empty.");

        if (array.size() == 1) {
            int root = array[0];
            array.pop_back();
            return root;
        }

        int root = array[0];
        array[0] = array.back();
        array.pop_back();
        heapify(0);
        return root;
    }

    int peek() const {
        return array[0];
    }

    bool isEmpty() const {
        return array.empty();
    }

private:
    void heapify(int i) {
        int n = array.size();
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < n && array[left] > array[largest]) {
            largest = left;
        }

        if (right < n && array[right] > array[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(array[i], array[largest]);
            heapify(largest);
        }
    }

    std::vector<int> array;
};

int main()
{
    PriorityQueue pq;
    pq.enqueue(10);
    pq.enqueue(14);
    pq.enqueue(2);
    pq.enqueue(5);
    pq.enqueue(9);
    pq.enqueue(13);

    while (!pq.isEmpty()) {
        std::cout << pq.dequeue() << std::endl;
    }
    
    return 0;
}