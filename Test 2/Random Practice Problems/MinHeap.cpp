#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MinHeap {
private:
    void minHeapify(int i) {
        int smallest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < arr.size() && arr[left] < arr[smallest])
            smallest = left;
        if (right < arr.size() && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    vector<int> arr;
public:
    void insert(int value) {
        arr.push_back(value);
        int i = arr.size() - 1;

        while(i != 0 && arr[i] < arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int getMin() const {
        if (arr.empty()) throw runtime_error("Heap is empty");
        
        return arr[0];
    }

    int extractMin() {
        if (arr.empty()) throw runtime_error("Heap is empty");

        int min = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        if (!arr.empty())
            minHeapify(0);

        return min;
    }
};