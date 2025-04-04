#include <iostream>
#include <queue>
#include <stack>

class Stack {
private:
    std::queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        while (size > 1) {
            q.push(q.front());
            q.pop();
            size--;
        }
    }

    void pop() {
        if (!q.empty())
            q.pop();
    }

    int top() {
        if (!q.empty())
            return q.front();
        return -1;
    }

    bool isEmpty() {
        return q.empty();
    }
};

class Queue {
private:
    std::stack<int> s1, s2;

    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s2.empty()) {
            if (s1.empty()) return;
            transfer();
        }
        s2.pop();
    }

    int front() {
        if (s2.empty()) {
            if (s1.empty()) return -1;
            transfer();
        }
        return s2.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    std::cout << st.top() << "\n";
    st.pop();
    std::cout << st.top() << "\n";

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    std::cout << q.front() << "\n";
    q.dequeue();
    std::cout << q.front() << "\n";

    return 0;
}
