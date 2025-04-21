#include <iostream>
#include <vector>
#include "help.h"

void bubbleSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < arr.size() - 1; j++) {
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

void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        std::swap(arr[i], arr[min_index]);
    }
}

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

void buildHeap(std::vector<int>& arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    buildHeap(arr, n);
    
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;

            while (j >= gap && arr[j - gap] > arr[i]) {
                std::swap(arr[j], arr[j - gap]);
                j -= gap;
            }
        }
    }
}

void bucketSort(std::vector<int>& arr) {
    int n = arr.size();

    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());
    int range = max - min + 1;

    std::vector<std::vector<int>> buckets(n);

    for (int num : arr) {
        int index = ((num - min) / (double) range) * n;
        buckets[index].push_back(num);
    }

    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    int i = 0;
    for (const auto& bucket : buckets) {
        for (int num : bucket) {
            arr[i++] = num;
        }
    }
}

void bucketSortDec(std::vector<double>& arr) {
    int n = arr.size();
    std::vector<std::vector<double>> buckets(n);
    
    for (double d : arr) {
        int index = (int) d * n;
        buckets[index].push_back(d);
    }

    for (auto& b : buckets) {
        std::sort(b.begin(), b.end());
    }

    int i = 0;
    for (const auto& b : buckets) {
        for (double d : b) {
            arr[i++] = d;
        }
    }
}

void countingSort(std::vector<int>& arr) {
    int n = arr.size();

    std::vector<int> res(n);
    int max = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count_array(max + 1, 0);

    for (int i = 0; i < n; i++) {
        count_array[arr[i]]++;
    }

    for (int i = 1; i < count_array.size(); i++) {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        res[count_array[arr[i]] - 1] = arr[i];
        count_array[arr[i]]--;
    }

    arr = res;
}

void radixCountingSort(std::vector<int>& arr, int place) {
    int n = arr.size();
    std::vector<int> res(n);
    std::vector<int> count_array(10, 0);

    for (int i = 0; i < n; i++) {
        count_array[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        res[count_array[(arr[i] / place) % 10] - 1] = arr[i];
        count_array[(arr[i] / place) % 10]--;
    }

    arr = res;
}

void radixSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());

    for (int place = 1; max / place > 0; place *= 10) {
        radixCountingSort(arr, place);
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> t1(n1), t2(n2);

    for (int i = 0; i < n1; i++)
        t1[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        t2[j] = arr[mid + 1 + j];
    
    int k = left;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (t1[i] <= t2[j]) {
            arr[k] = t1[i];
            i++;
        } else {
            arr[k] = t2[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = t1[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = t2[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(std::vector<int>& arr, int low, int high) {
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
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    std::vector<int> arr = {92, 18, 46, 27, 21, 10, 24, 65, 31, 87};
    quickSort(arr, 0, arr.size() - 1);
    printVector(arr);

    return 0;
}