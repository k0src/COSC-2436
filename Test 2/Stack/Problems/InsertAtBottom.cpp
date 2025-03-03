#include <iostream>
#include <stack>

void insertAtBottom(std::stack<int>& s, int x) {
	if (s.empty()) {
		s.push(x);
	} else {
		int top = s.top();
		s.pop();
		insertAtBottom(s, x);

		s.push(top);
	}
}

int main()
{
	std::stack<int> s({1, 2, 3, 4, 5});

	insertAtBottom(s, 0);

	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}