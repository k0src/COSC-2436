#include <iostream>
#include <vector>

void heapify(std::vector<int>& arr, int n, int i) {
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
        heapify(arr, n, largest);
    }
}

void buildHeap(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapsort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    std::vector<int> arr = {4, 6, 1, 12, 22, 3, 29, 13, 5, 15};
    buildHeap(arr);
    heapsort(arr);

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}