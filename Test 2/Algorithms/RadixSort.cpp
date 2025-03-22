#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// assumes b = 10

void countingSort(std::vector<int>& arr, int place) {
    int n = arr.size();
    if (n == 0) return;

    std::vector<int> res(n);
    std::vector<int> count_array(10, 0);

    for (int i = 0; i < n; i++) {
        count_array[(arr[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count_array[i] = count_array[i - 1] + count_array[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        res[count_array[(arr[i] / place) % 10] - 1] = arr[i];
        count_array[(arr[i] / place) % 10]--;
    }

    arr = res;
}

void radixSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    int max_val = *std::max_element(arr.begin(), arr.end());

    for (int place = 1; max_val / place > 0; place *= 10) {
        countingSort(arr, place);
    }
}

int main()
{
    std::vector<int> arr = {4, 67, 28, 130, 573, 284, 914, 100, 52, 89, 36, 624};
    radixSort(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}