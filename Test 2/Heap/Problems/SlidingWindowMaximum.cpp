#include <iostream>
#include <vector>
#include <queue>

std::vector<int> slidingWindowMax(std::vector<int>& arr, int k) {
    std::vector<int> res;
    std::priority_queue<std::pair<int, int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push({arr[i], i});
    }

    res.push_back(pq.top().first);

    for (int i = k; i < arr.size(); i++) {
        pq.push({arr[i], i});

        while (pq.top().second <= i - k) {
            pq.pop();
        }

        res.push_back(pq.top().first);
    }
    return res;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;

    for (int i : slidingWindowMax(arr, k)) {
        std::cout << i << " ";
    }

    return 0;
}