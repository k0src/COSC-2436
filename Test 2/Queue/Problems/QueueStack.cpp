#include <iostream>
#include <queue>

struct Stack {
	void push(int item) {
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}

		q1.push(item);

		while (!q2.empty()) {
			q1.push(q2.front());
			q2.pop();
		}
	}

	void pop() {
		q1.pop();
	}

	int top() const {
		return q1.front();
	}

	bool isEmpty() const {
		return q1.empty();
	}

	std::queue<int> q1;
	std::queue<int> q2;
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	while (!s.isEmpty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}