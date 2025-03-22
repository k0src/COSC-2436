#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return;

    std::vector<int> res(n);
    int max = *std::max_element(arr.begin(), arr.end());
    std::vector<int> count_array(max + 1, 0);

    for (int i = 0; i < n; i++) {
        count_array[arr[i]]++;
    }

    for (int i = 1; i < count_array.size(); i++) {
        count_array[i] = count_array[i - 1] + count_array[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        res[count_array[arr[i]] - 1] = arr[i];
        count_array[arr[i]]--;
    }

    arr = res;
}

int main()
{
    std::vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};
    countingSort(arr);
    for (int i : arr) {
        std::cout << i << " ";
    }
    return 0;
}