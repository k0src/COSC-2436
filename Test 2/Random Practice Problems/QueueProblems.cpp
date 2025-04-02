#include "help.h"

using namespace std;

void printRec(queue<int> q) {
    if (q.empty()) {
        return;
    }

    cout << q.front() << " ";
    q.pop();
    printRec(q);
}

void reverseQueueRec(queue<int>& q) {
    if (q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(front);
}

// with a stack
void reverseQueueIter(queue<int>& q) {
    stack<int> s;
    
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int minInQueueHelper(queue<int>& q, int min) {
    if (q.empty()) {
        return min;
    }

    min = (q.front() < min) ? q.front() : min;
    q.pop();

    return minInQueueHelper(q, min);
}

int minInQueue(queue<int> q) {
    return minInQueueHelper(q, INT_MAX);
}

int minInQueueIter(queue<int> q) {
    if (q.empty()) return INT_MAX;
    
    int min = q.front();
    q.pop();
    while (!q.empty()) {
        if (q.front() < min) min = q.front();
        q.pop();
    }
    return min;
}

int main()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    printQueue(q);

    // printRec(q);
    // cout << endl;

    // reverseQueueRec(q);
    // reverseQueueIter(q);

    cout << minInQueue(q);

    return 0;
}