#include <iostream>
#include <vector>
#include <queue>

int kthSmallest(std::vector<int>& arr, int k) {
    std::priority_queue<int> pq;

    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
        
        if (pq.size() > k) {
            pq.pop();
        }
    }

    return pq.top();
}

int main()
{
    std::vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    std::cout << kthSmallest(arr, k);
    return 0;
}