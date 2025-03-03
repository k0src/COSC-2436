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

void reverse(std::stack<int>& s) {
	if (s.empty()) {
		return;
	}
	
	int top = s.top();
	s.pop();
	reverse(s);

	insertAtBottom(s, top);
}

int main()
{
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	reverse(s);

	while (!s.empty()) {
		std::cout << s.top() <<std::endl;
		s.pop();
	}

	return 0;
}