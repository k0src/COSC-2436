#include <iostream>
#include <queue>

using namespace std;

class QueueStack {
private:
    queue<int> q1, q2;
public:
    void push(int item) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(item);

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (q1.empty()) return;
        q1.pop();
    }

    int top() const {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() const {
        return q1.empty();
    }
};