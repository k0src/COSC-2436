#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

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

int main()
{
    std::vector<int> arr = {38, 10, 15, 29, 19, 40, 12, 20, 30, 21};
    bucketSort(arr);

    for (int i : arr) {
        std::cout << i << " ";
    }

    return 0;
}