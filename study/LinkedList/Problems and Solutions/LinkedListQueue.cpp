#include <iostream>

// First in, first out

struct Node {
	Node(int value) : value(value), next(nullptr) {}

	int value;
	Node* next;
};

struct Queue {
	Queue() : head(nullptr), tail(nullptr) {}

	void enqueue(int value) {
		Node* node = new Node(value);

		if (!head) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
		}
	}

	void dequeue() {
		if (!head) return;

		Node* current = head;
		head = head->next;

		if (!head) {
			tail = nullptr;
		}

		delete current;
	}

	int front() const {
		return head->value;
	}

	Node* head;
	Node* tail;
};

int main() 
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);

	for (int i = 0; i < 6; i++) {
		std::cout << q.front() << std::endl;
		q.dequeue();
	}

	return 0;
}