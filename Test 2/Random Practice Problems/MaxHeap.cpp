#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    void heapify(int i) {
        int largest = i;
        int left = i * 2 + 1;
        int right = i * 2 + 2;

        if (left < arr.size() && arr[left] > arr[largest])
            largest = left;
        if (right < arr.size() && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    vector<int> arr;
public:
    void insert(int item) {
        arr.push_back(item);
        int i = arr.size() - 1;

        while (i != 0 && arr[i] > arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i -  1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int max() const {
        if (arr.size() == 0) return -1; // heap is empty
        return arr[0];
    }

    int extractMax() {
        if (arr.size() == 0) return -1; // heap is empty

        if (arr.size() == 1) {
            int root = arr[0];
            arr.pop_back();
            return root;
        }

        int root = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        heapify(0);
        
        return root;
    }
};