#include <iostream>
#include <stdexcept>

class Stack {
public:
    Stack(int size) : size(size), top(-1) {
        if (size <= 0) {
            throw std::invalid_argument("Stack size must be greater than 0.");
        }
        array = new int[size];
    }

    ~Stack() {
        delete[] array;
    }

    void push(int item) {
        if (top == size - 1) {
            throw std::overflow_error("Stack overflow: Cannot push onto a full stack.");
        }
        array[++top] = item;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow: Cannot pop from an empty stack.");
        }
        top--;
    }

    int peek() {
        if (isEmpty()) {
            throw std::runtime_error("Stack is empty: Cannot peek.");
        }
        return array[top];
    }

    bool isEmpty() const {
        return (top == -1);
    }

private:
    int size;
    int* array;
    int top;
};

int main() 
{
	Stack s(5);

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