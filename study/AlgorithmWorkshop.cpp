#include <iostream>

struct Node {
	Node(char value) : value(value), next(nullptr) {}
	char value;
	Node* next;
};

struct List {
	List() : head(nullptr) {}

	void pushBack(char value) {
		Node* node = new Node(value);

		if (!head) {
			head = node;
		} else {
			Node* current = head;

			while (current->next) {
				current = current->next;
			}

			current->next = node;
		}
	}

	void print() const {
		if (!head) return;

		Node* current = head;

		while (current) {
			std::cout << current->value << std::endl;
			current = current->next;
		}
	}

	Node* head;
};

// Frequently asked questions:

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

Node* reverseListRecursive(Node* head) {
	if (!head || !head->next) {
		return head;
	}

	Node* new_head = reverseListRecursive(head->next);

	head->next->next = head;
	head->next = nullptr;

	return new_head;
}

Node* mergeTwoLists(Node* head1, Node* head2) {
	if (!head1) return head2;

	if (!head2) return head1;

	if (head1->value <= head2->value) {
		head1->next = mergeTwoLists(head1->next, head2);
		return head1;
	} else {
		head2->next = mergeTwoLists(head1, head2->next);
		return head2;
	}
}


int main()
{
	List list1;
	list1.pushBack('a');
	list1.pushBack('b');
	list1.pushBack('e');

	// List list2;

	// list2.pushBack('c');
	// list2.pushBack('d');
	// list2.pushBack('f');

	// Node* res = mergeTwoLists(list1.head, list2.head);

	// while (res) {
	// 	std::cout << res->value << std::endl;
	// 	res = res->next;
	// }

	Node* reversed = reverseListRecursive(list1.head);

	while (reversed) {
		std::cout << reversed->value << std::endl;
		reversed = reversed->next;
	}

	return 0;
}