#include "help.h"

using namespace std;

int computeQueueSum(queue<int> q) {
    if (q.empty()) {
        return 0;
    }

    int front = q.front();
    q.pop();
    return front + computeQueueSum(q);
}

int computeQueueSumIter(queue<int> q) {
    if (q.empty()) {
        return 0;
    }

    int sum = 0;

    while (!q.empty()) {
        sum += q.front();
        q.pop();
    }

    return sum;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << computeQueueSum(q) << endl;
    cout << computeQueueSumIter(q) << endl;
    return 0;
}