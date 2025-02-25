#include <iostream>
#include <stdexcept>

class StackNode {
public:
	StackNode(int item) : item(item), next(nullptr) {}

private:
	int item;
	StackNode* next;

	friend class Stack;
};

class Stack {
public:
	Stack() : top(nullptr) {}

	~Stack() {
	    while (!isEmpty()) {
	        pop();
	    }
	}

	void push(int item) {
		StackNode* stackNode = new StackNode(item);

		if (!top) {
			top = stackNode;
		} else {
			stackNode->next = top;
			top = stackNode;
		}
	}

	void pop() {
		if (isEmpty()) {
            throw std::underflow_error("Stack underflow: Cannot pop from an empty stack.");
        }
        StackNode* current = top;
        top = top->next;
        delete current;
	}

	int peek() {
		if (isEmpty()) {
			throw std::runtime_error("Stack is empty: Cannot peek.");
		}
		return top->item;
	}

	bool isEmpty() const {
		return (top == nullptr);
	}

private:
	StackNode* top;
};

int main() 
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	while (!s.isEmpty()) {
		std::cout << s.peek() << std::endl;
		s.pop();
	}

	return 0;
}