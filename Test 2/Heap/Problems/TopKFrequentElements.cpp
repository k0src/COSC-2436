#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    }
};

std::vector<int> topkFrequent(std::vector<int>& arr, int k) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> pq;
    std::unordered_map<int, int> freq_map;
    std::vector<int> res;

    for (int i : arr) freq_map[i]++;

    for (auto& p : freq_map) pq.push(p);

    for (int i = 0; i < k; i++) {
        res.push_back(pq.top().first);
        pq.pop();
    }

    return res;
}

int main()
{
    std::vector<int> arr = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int k = 4;
    
    for (int i : topkFrequent(arr, k)) {
        std::cout << i << " ";
    }

    return 0;
}