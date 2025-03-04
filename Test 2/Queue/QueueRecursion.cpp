#include <iostream>
#include <queue>

void reverseQueue(std::queue<int>& q) {
	// Base case:
	if (q.empty()) {
		return;
	}

	// Remove front element
	int front = q.front();
	q.pop();

	// Recursively reverse the remaining queue
	reverseQueue(q);

	// Push front element to the back of the queue
	q.push(front);
}

void printQueue(std::queue<int>& q) {
	// Base case
	if (q.empty()) {
		return;
	}

	// Print front, pop
	std::cout << q.front() << std::endl;
	q.pop();

	printQueue(q);
}

int getMin(std::queue<int>& q, int size) {
    if (size == 1) {
        int minVal = q.front();
        q.pop();
        return minVal;
    }

    int front = q.front();
    q.pop();

    int minVal = getMin(q, size - 1);

    if (front > minVal)
        q.push(front);
    else {
        q.push(minVal);
        minVal = front;
    }

    return minVal;
}

void sortQueue(std::queue<int>& q, int size) {
	if (size <= 1) return;

	int minVal = getMin(q, size);
	sortQueue(q, size - 1);
	q.push(minVal);
}

int main()
{
	std::queue<int> q;
	q.push(10);
	q.push(2);
	q.push(4);
	q.push(8);
	q.push(11);

	// reverseQueue(q);
	// printQueue(q);
	sortQueue(q, q.size());

	while (!q.empty()) {
		std::cout << q.front() << std::endl;
		q.pop();
	}

	return 0;
}