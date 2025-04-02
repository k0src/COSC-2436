#include "help.h"

using namespace std;

void priorityInsert(queue<int>& q, int x) {
    queue<int> q2;

    while (!q.empty() && q.front() < x) {
        q2.push(q.front());
        q.pop();
    }

    q2.push(x);

    while (!q.empty()) {
        q2.push(q.front());
        q.pop();
    }

    q = q2;
}

void priority(std::queue<int> &q, int x) { // using one queue
    int size = q.size();
    bool inserted = false;

    for (int i = 0; i < size; i++) {
        int val = q.front();
        q.pop();

        if (!inserted && val > x) {
            q.push(x);
            inserted = true;
        }

        q.push(val);
    }

    if (!inserted) {
        q.push(x);
    }
}

int main()
{
    queue<int> q;

    q.push(2);
    q.push(4);
    q.push(5);

    printQueue(q);
    priorityInsert(q, 3);
    printQueue(q);

    return 0;
}