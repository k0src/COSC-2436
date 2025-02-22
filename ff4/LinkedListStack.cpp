#include <iostream>

class StackNode {
public:
    StackNode(char data) : data(data), next(nullptr) {}
    char data;
    StackNode* next;

    friend class Stack;
};

class Stack {
public:
    Stack() : _top(nullptr) {}

    void push(char data) {
        StackNode* node = new StackNode(data);
        node->next = _top;
        _top = node;
    }

    void pop() {
        if (!_top) return;

        StackNode* node = _top;
        _top = _top->next;
        delete node;
    }

    char top() {
        if (!_top) return '\0';
        return _top->data;
    }

    bool empty() {
        return _top == nullptr;
    }
    
private:
    StackNode* _top;
};

int main()
{
    Stack stack;

    stack.push('A');
    stack.push('B');
    stack.push('C');

    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}