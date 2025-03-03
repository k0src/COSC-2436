#include <iostream>
#include <stack>

struct StackQueue {
	StackQueue() {}

	void push(int item) {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(item);

		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	void pop() {
		s1.pop();
	}

	int top() const {
		return s1.top();
	}

	bool isEmpty() const {
		return s1.empty();
	}

	std::stack<int> s1, s2;
};

int main()
{
	StackQueue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.isEmpty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}

	return 0;
}