#include <iostream>

struct Node {
	Node(int value) : value(value), next(nullptr), prev(nullptr) {}

	int value;
	Node* next;
	Node* prev;
};

struct DoublyLinkedList {
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	void addFront(int value) {
		Node* node = new Node(value);

		if (!head) {
			head = node;
			tail = node;
		} else {
			head->prev = node;
			node->next = head;
			head = node;
		}
	}

	void addBack(int value) {
		Node* node = new Node(value);

		if (!head) {
			head = node;
			tail = node;
		} else {
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}

	void removeFront() {
		if (!head) return;

		if (head == tail) {
			delete head;
			head = tail = nullptr;
		} else {
			Node* current = head;
			head = head->next;
			head->prev = nullptr;
			
			delete current;
		}
	}

	void removeBack() {
		if (!head) return;

		if (head == tail) {
			delete head;
			head = tail = nullptr;
		} else {
			Node* current = tail;
			tail = tail->prev;
			tail->next = nullptr;

			delete current;
		}
	}

	void insertAt(int index, int value) {
		if (index < 0) return;

		Node* node = new Node(value);

		if (index == 0) {
			addFront(value);
			return;
		}

		Node* current = head;

		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}

		node->next = current->next;
		node->prev = current;

		if (current->next) {
			current->next->prev = node;
		} else {
			tail = node;
		}
		current->next = node;
	}

	void removeAt(int index) {
		if (!head || index < 0) return;

		if (index == 0) {
			removeFront();
			return;
		}

		Node* current = head;

		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		if (current->prev) {
        	current->prev->next = current->next;
	    }

	    if (current->next) {
	        current->next->prev = current->prev;
	    } else {
	        tail = current->prev;
	    }

	    delete current;
	}

	void print() const {
		if (!head) return;

		Node* current = head;

		while (current) {
			std::cout << current->value << " ";
			current = current->next;
		}
	}

	Node* head;
	Node* tail;
};

int main()
{
	DoublyLinkedList l;

	l.addBack(1);
	l.addBack(2);
	l.addBack(3);
	l.addBack(4);

	l.insertAt(2, 5);
	l.removeAt(2);

	l.print();

	return 0;
}