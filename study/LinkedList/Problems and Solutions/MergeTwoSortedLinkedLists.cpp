#include <iostream>
#include "LinkedList.h"

Node* mergeLists(Node*& head1, Node*& head2) {
	if (!head1) return head2;

	if (!head2) return head1;

	if (head1->value <= head2->value) {
		head1->next = mergeLists(head1->next, head2);
		return head1;
	} else {
		head2->next = mergeLists(head1, head2->next);
		return head2;
	}
}

int main()
{
	LinkedList l1;
	l1.pushBack(1);
	l1.pushBack(3);
	l1.pushBack(5);
	l1.pushBack(7);

	LinkedList l2;
	l2.pushBack(2);
	l2.pushBack(4);
	l2.pushBack(6);
	l2.pushBack(8);

	LinkedList l3;

	l3.head = mergeLists(l1.head, l2.head);

	l3.print();

	return 0;
}