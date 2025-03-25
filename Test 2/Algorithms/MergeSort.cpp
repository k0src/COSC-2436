#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> t1(n1), t2(n2);

    for (int i = 0; i < n1; i++)
        t1[i] = arr[left + i];
    for (int j = 0; j < n1; j++)
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
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

int main()
{
    std::vector<int> arr;
    for (int i = 0; i < 50; i++) {
        arr.push_back(rand() % 100);
    }

    mergeSort(arr, 0, arr.size() - 1);

    for (int i : arr) {
        std::cout << i << " ";
    }
    
    return 0;
}