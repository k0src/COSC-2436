#include <iostream>
#include <queue>
#include <cmath>

int heapHeight(std::priority_queue<int>& pq) {
    int n = pq.size();

    return std::floor(std::log2(n));
}

int main()
{
    std::priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(8);
    pq.push(2);
    pq.push(11);
    pq.push(10);
    pq.push(9);
    pq.push(3);

    std::cout << heapHeight(pq);

    return 0;
}