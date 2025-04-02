#include <iostream>
#include <queue>

using namespace std;

void reverseQueue(queue<int>& q) {
    if (q.empty()) return;

    int front = q.front();
    q.pop();

    reverseQueue(q);

    q.push(front);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    reverseQueue(q);

    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }

    return 0;
}