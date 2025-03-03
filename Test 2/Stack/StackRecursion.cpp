#include <iostream>
#include <stack>

void printStack(std::stack<int>& st) {
	// Base case: Stack empty
	if (st.empty()) {
		return;
	}

	int top = st.top();
	std::cout << top << std::endl;
	st.pop();

	// Recursion:
	printStack(st);
	st.push(top);
}

void removeTarget(std::stack<int>& st, int target) {
	// Base case:
	if (st.empty()) {
		return;
	}

	int top = st.top();
	st.pop();

	// Recurse on the remaining stack
	removeTarget(st, target);

	// Before rebuilding the stack, as recursion unwinds, check
	if (top != target) {
		st.push(top);
	}
}

void sortedInsert(std::stack<int>& st, int item) {
	// Base case
	if (st.empty() || st.top() <= item) { // If stack is empty, or item is larger than or equal to top, push it
		st.push(item);
		return;
	}

	int top = st.top();
	st.pop();
	sortedInsert(st, item);

	st.push(top);
}

void sortStack(std::stack<int>& st) {
	// Base case:
	if (st.empty()) {
		return;
	}

	int top = st.top();
	st.pop();

	// Recurse on remaining stack
	sortStack(st);

	// Sorted Insert
	sortedInsert(st, top);
}

int main()
{
	std::stack<int> st({8, 3, 6, 1, 2, 2, 3, 4, 5, 2});

	// Sort, remove 2's, print
	sortStack(st);
	removeTarget(st, 2);
	printStack(st);

	return 0;
}