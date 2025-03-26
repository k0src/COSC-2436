#include <iostream>
#include <queue>

using namespace std;

int kthLargest(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i : arr) {
        min_heap.push(i);
        if (min_heap.size() > k) min_heap.pop();
    }

    return min_heap.top();
}