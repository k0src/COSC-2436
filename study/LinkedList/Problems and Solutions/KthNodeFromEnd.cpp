#include <iostream>
#include "LinkedList.h"

// this function *can* include more error handling.
int kthFromEnd(Node*& head, int k) {
	Node* fast = head;
	Node* slow = head;

	for (int i = 0; i < k; i++) {
		fast = fast->next;
	}

	while (fast->next) {
		fast = fast->next;
		slow = slow->next;
	}

	return slow->value;
}

int main()
{
	LinkedList l;
	l.pushBack(1);
	l.pushBack(3);
	l.pushBack(5);
	l.pushBack(7);
	l.pushBack(9);
	l.pushBack(11);

	int k = 2;

	l.print();

	std::cout << kthFromEnd(l.head, k);

	return 0;
}