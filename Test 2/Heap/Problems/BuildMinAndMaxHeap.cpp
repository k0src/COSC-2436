#include <iostream>
#include <vector>

void maxHeapify(std::vector<int>& arr, int i) {
    int n = arr.size();
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, largest);
    }
}

void buildMaxHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i);
    }
}

void minHeapify(std::vector<int>& arr, int i) {
    int n = arr.size();
    int smallest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest);
    }
}

void buildMinHeap(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, i);
    }
}

int main()
{
    std::vector<int> arr = {3, 6, 10, 11, 15, 21, 9, 8, 19};

    buildMaxHeap(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    buildMinHeap(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}