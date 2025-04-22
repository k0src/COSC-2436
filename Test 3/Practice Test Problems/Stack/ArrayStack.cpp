#include <iostream>

class Stack {
private:
    int* arr;
    int size;
    int count;
public:
    Stack(int size) : size(size), count(-1) {
        arr = new int[size];
    }

    void push(int item) {
        if (count == size - 1) {
            return;
        }

        arr[++count] = item;
    }

    void pop() {
        if (count == -1) {
            return;
        }

        count--;
    }

    int top() {
        if (count == -1) {
            return -1;
        }

        return arr[count];
    }
};

int main()
{
    Stack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << stack.top();
    
    stack.pop();
    stack.pop();
    
    std::cout << stack.top();

    return 0;
}