#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }
}

void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i) {  
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[middle + 1 + j];
    }  
    
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {

        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        vec[i] = rand() % 10000;
    }
    return vec;
}

void recordSortTimes(std::ofstream& file, const std::string& sortType, std::vector<int> arr, int size, bool sorted) {
    std::string sortedLabel = sorted ? "Sorted" : "Unsorted";

    auto start = std::chrono::high_resolution_clock::now();
    if (sortType == "Bubble Sort") {
        bubbleSort(arr);
    } else if (sortType == "Merge Sort") {
        mergeSort(arr, 0, arr.size() - 1);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    file << sortType << "," << sortedLabel << "," << size << "," << duration.count() << " ms\n";
}

int main() {
    std::ofstream file("sort_test.csv");
    if (!file) {
        return 1;
    }

    file << "Sorting Algorithm,Sorted Status,Input Size,Execution Time (ms)\n";

    std::vector<int> sizes = {10, 100, 1000, 10000};

    for (int size : sizes) {
        std::vector<int> vec = generateRandomVector(size);
        
        // Test Bubble Sort
        recordSortTimes(file, "Bubble Sort", vec, size, false);
        recordSortTimes(file, "Bubble Sort", vec, size, true);

        // Test Merge Sort
        recordSortTimes(file, "Merge Sort", vec, size, false);
        recordSortTimes(file, "Merge Sort", vec, size, true);
    }

    file.close();
    return 0;
}