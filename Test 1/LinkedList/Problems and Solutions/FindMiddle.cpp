#include <iostream>
#include "LinkedList.h"

int middle(Node*& head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}

int main()
{
	LinkedList l;
	l.pushBack(1);
	l.pushBack(2);
	l.pushBack(3);
	l.pushBack(4);
	l.pushBack(5);

	std::cout << middle(l.head);

	return 0;
}