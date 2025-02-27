#include <iostream>

struct Node {
	Node(int value) : value(value), next(nullptr), prev(nullptr) {}

	int value;
	Node* next;
	Node* prev;
};

struct DoublyLinkedList {
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	~DoublyLinkedList() {
		if (!head) return;

		Node* current = head;

		while (current) {
			Node* temp = current;
			current = current->next;
			delete temp;
		}
	}

	void pushBack(int value) {
		Node* node = new Node(value);

		if (!head) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}

	Node* head;
	Node* tail;
};

void printDoublyLinkedList(Node* head, bool first = true) {
	if (!head) {
		std::cout << "]" << std::endl;
		return;
	}
	
	if (first) {
		std::cout << "[";
	}

	std::cout << head->value;

	if (head->next) {
		std::cout << ", ";
	}

	printDoublyLinkedList(head->next, false);
}

void printDoublyLinkedListReversed(Node* head, bool last = true) {
	if (!head) {
		std::cout << "[";
		return;
	}

	printDoublyLinkedListReversed(head->next, false);

	std::cout << head->value;

	if (head->prev) {
		std::cout << ", ";
	}

	if (last) {
		std::cout << "]" << std::endl;
	}
}

int main() 
{
	DoublyLinkedList l;
	l.pushBack(1);
	l.pushBack(2);
	l.pushBack(3);
	l.pushBack(4);
	l.pushBack(5);

	printDoublyLinkedList(l.head);
	printDoublyLinkedListReversed(l.head);

	return 0;
}