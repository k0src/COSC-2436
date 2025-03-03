#include <iostream>
#include <stack>

void removeLessThanK(std::stack<int>& s, int k) {
	if (s.empty()) {
		return;
	}

	int top = s.top();
	s.pop();

	removeLessThanK(s, k);

	if (top >= k) {
		s.push(top);
	}
}

int main()
{
	std::stack<int> s;
	s.push(6);
	s.push(8);
	s.push(3);
	s.push(2);
	s.push(4);
	s.push(7);

	int k = 6;

	removeLessThanK(s, k);

	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return 0;
}