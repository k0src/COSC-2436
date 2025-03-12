#include <iostream>
#include <vector>
#include <queue>

// Using max heap
int minProductMaxHeap(std::vector<int>& arr, int k) {
    std::priority_queue<int> pq;

    for (int i : arr) {
        pq.push(i);

        if (pq.size() > k) {
            pq.pop();
        }
    }

    int res = 1;

    while (!pq.empty()) {
        res *= pq.top();
        pq.pop();
    }

    return res;
}

// Using min heap
int minProductMinHeap(std::vector<int>& arr, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

    for (int i : arr) {
        pq.push(i);
    }

    int res = 1, count = 0;

    while (!pq.empty() && count != k) {
        res *= pq.top();
        pq.pop();
        count++;
    }

    return res;
}

int main()
{
    std::vector<int> arr = {11, 8, 5, 7, 5, 100};
    int k = 4;
    std::cout << minProductMinHeap(arr, k);

    return 0;
}