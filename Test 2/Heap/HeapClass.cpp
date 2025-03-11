#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
public:
    void insert(int value) {
        array.push_back(value);
        int i = array.size() - 1;

        while (i != 0 && array[i] > array[(i - 1) / 2]) {
            std::swap(array[i], array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int extractMax() {
        if (array.size() == 0) throw std::runtime_error("heap is empty.");

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

    int getMax() const {
        if (array.size() == 0) throw std::runtime_error("heap is empty.");

        return array[0];
    }

private:
    std::vector<int> array;

    void heapify(int i) {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int size = array.size();

        if (left < size && array[left] > array[largest]) {
            largest = left;
        }

        if (right < size && array[right] > array[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(array[i], array[largest]);
            heapify(largest);
        }
    }
};

int main()
{
    MaxHeap mh;
    mh.insert(3);
    mh.insert(5);
    mh.insert(2);
    mh.insert(1);
    mh.insert(7);

    std::cout << mh.extractMax() << std::endl;
    std::cout << mh.getMax() << std::endl;
    
    return 0;
}