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
	List l;
	l.pushBack('a');
	l.pushBack('b');
	l.pushBack('c');
	l.pushBack('d');
	l.pushBack('e');

	reverseList(l.head);

	l.print();

	return 0;
}