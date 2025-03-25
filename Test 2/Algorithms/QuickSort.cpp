#include <iostream>
#include <vector>

// Lomuto
int partitionL(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hoare's Algorithm
int partitionH(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];

    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) return j;

        std::swap(arr[i], arr[j]);
    }
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionH(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    std::vector<int> arr;
    for (int i = 0; i < 100; i++) {
        arr.push_back(rand() % 1000);
    }

    quickSort(arr, 0, arr.size() - 1);

    for (int i : arr) {
        std::cout << i << " ";
    }
    
    return 0;
}