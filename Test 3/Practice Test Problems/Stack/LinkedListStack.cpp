#include <iostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    
    Node* topNode;
public:
    Stack() : topNode(nullptr) {}

    void push(int item) {
        Node* node = new Node(item);

        if (!topNode) {
            topNode = node;
        } else {
            node->next = topNode;
            topNode = node;
        }
    }

    void pop() {
        if (!topNode) {
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (!topNode) {
            return -1;
        }

        return topNode->data;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl; // Should print 30

    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << std::endl; // Should print 20

    stack.pop();
    stack.pop();
    std::cout << "Top element after popping all: " << stack.top() << std::endl; // Should print -1

    return 0;
}