#include <iostream>

struct Node {
	Node(int val) : val(val), next(nullptr) {}
	int val;
	Node* next;
};

struct List {
	List() : head(nullptr), tail(nullptr) {}

	void pushBack(int val) {
		Node* node = new Node(val);

		if (!head) {
			head = node;
			tail = node;
			head->next = head;
		} else {
			tail->next = node;
			tail = node;
			tail->next = head;
		}
	}

	void print() {
		if (!head) return;

		Node* current = head;
		std::cout << "[";
		
		do {
			std::cout << current->val;
			current = current->next;
			if (current != head) std::cout << ", ";
		} while (current != head);

		std::cout << "]" << std::endl;
	}

	Node* head;
	Node* tail;
};

void insertAtEndofCircularList(Node* head, int value) {
	if (!head) return;

	Node* node = new Node(value);
	Node* current = head;
	
	while (current->next != head) {
		current = current->next;
	}

	current->next = node;
	node->next = head;
}

void insertKNodesRecursively(Node* head, int k, int val) {
	if (k == 0) return;

	insertAtEndofCircularList(head, val);
	insertKNodesRecursively(head, k - 1, val);
}

int main() 
{
	List l;
	l.pushBack(1);
	l.pushBack(2);
	l.pushBack(3);
	l.pushBack(4);

	l.print();

	insertAtEndofCircularList(l.head, 5);

	l.print();

	insertKNodesRecursively(l.head, 5, 10);

	l.print();

	return 0;
}