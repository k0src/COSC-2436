#include <iostream>
#include <queue>

void printQueue(std::queue<int> q) {
    if (q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();
    std::cout << front << " ";
    printQueue(q);
}

void reverseQueue(std::queue<int>& q) {
    if (q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();

    reverseQueue(q);

    q.push(front);
}

int main()
{
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Print queue
    printQueue(q);
    std::cout << std::endl;
    
    // Reverse then print
    reverseQueue(q);
    printQueue(q);
    std::cout << std::endl;

    return 0;
}