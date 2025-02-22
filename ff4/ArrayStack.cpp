#include <iostream>

class Stack {
public:
    Stack() : _array(nullptr), _size(0), _capacity(0) {}

    void push(int data) {
        if (_size == _capacity) {
            _capacity = _capacity == 0 ? 1 : _capacity * 2;
            int* temp = new int[_capacity];
            for (int i = 0; i < _size; i++) {
             temp[i] = _array[i];
            }
            delete[] _array;
            _array = temp;
        }

        _array[_size++] = data;
    }

    void pop() {
        if (_size == 0) return;
        _array[_size - 1] = 0;

        _size--;
    }

    int top() {
        if (_size == 0) return -1;
        return _array[_size - 1];
    }

    bool empty() {
        return _size == 0;
    }

private:
    int* _array;
    int _size;
    int _capacity;
};

int main()
{
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    while (!stack.empty()) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}