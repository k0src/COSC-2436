#include <iostream>
#include <stack>

class MinStack {
public:
    MinStack() : _top(nullptr) {}

    void push(int val) {
        Node* node = new Node(val);

        if (!_top) {
            node->min = val;
            _top = node;
        } else {
            node->min = std::min(val, _top->min);
            node->next = _top;
            _top = node;
        }
    }

    void pop() {
        if (!_top) return;
        
        Node* temp = _top;
        _top = _top->next;
        delete temp;
    }

    int top() const {
        return _top->val;
    }

    int getMin() const {
        return _top->min;
    }
private:
    struct Node {
        Node(int val) : val(val), next(nullptr), min(0) {}

        int val;
        Node* next;
        int min;
    };

    Node* _top;
};

int main() {
    MinStack minStack;
    
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << minStack.getMin() << std::endl; // -3
    minStack.pop();
    std::cout << minStack.top() << std::endl; // 0
    std::cout << minStack.getMin() << std::endl; // -2

    return 0;
}