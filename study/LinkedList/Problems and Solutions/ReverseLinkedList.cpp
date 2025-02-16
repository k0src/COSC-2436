#include <iostream>
#include "LinkedList.h"

// Reverse linked list in place, 3 pointer method
void reverseList(Node*& head) {
	if (!head || !head->next) return;

	Node* prev = nullptr;
	Node* current = head;

	while (current) {
		Node* next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

int main()
{
	LinkedList l;
	l.pushBack(1);
	l.pushBack(2);
	l.pushBack(3);
	l.pushBack(4);
	l.pushBack(5);

	l.print();

	reverseList(l.head);

	l.print();

	return 0;
}