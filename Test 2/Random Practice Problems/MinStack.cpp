#include <iostream>
#include <stack>

using namespace std;

// Implement a Stack with Get Minimum in O(1) Time

class MinStack {
private:
    stack<int> s, min_stack;
public:
    void push(int item) {
        if (s.empty() || item <= min_stack.top()) {
            min_stack.push(item);
        }

        s.push(item);
    }
    
    void pop() {
        if (s.empty()) return;
        if (s.top() == min_stack.top()) {
            min_stack.pop();
        }

        s.pop();
    }
    
    int top() {
        return s.top();
    }

    int minElement() {
        return min_stack.top();
    }
};