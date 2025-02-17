#include <iostream>

struct Node {
	Node(int value) : value(value), next(nullptr) {}

	int value;
	Node* next;
};

struct LinkedList {
	LinkedList() : head(nullptr) {}

	void pushBack(int value) {
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

		std::cout << "[";

		while (current) {
			if (current->next) {
				std::cout << current->value << ", ";
			} else {
				std::cout << current->value;
			}
			current = current->next;
		}

		std::cout << "]" << std::endl;
	}


	Node* head;
};