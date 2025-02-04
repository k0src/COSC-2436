#include <iostream>

struct Node {
	Node(char value) : value(value), next(nullptr) {}
	char value;
	Node* next;
};

struct LinkedListQueue {
	LinkedListQueue() : head(nullptr), tail(nullptr) {}

	void enqueue(char value) {
		Node* node = new Node(value);

		if (!head) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
		}

		_size++;
	}

	void dequeue() {
		if (!head) {
			std::cerr << "Queue is empty\n";
		}

		Node* current = head;
		head = head->next;

		if (!head) {
			tail = nullptr; // If queue becomes empty, update the tail as well
		}

		delete current;
		_size--;
	}

	char front() const {
		if (!head) {
			std::cerr << "Queue is empty\n";
		}

		return head->value;
	}


	int size() const {
		return _size;
	}

	bool empty() const {
        return _size == 0;
    }

	Node* head;
	Node* tail;
	int _size = 0;
};

int main() 
{
	LinkedListQueue q;

	// Enqueue
	q.enqueue('a');
	q.enqueue('b');
	q.enqueue('c');
	q.enqueue('d');
	q.enqueue('e');

	// Dequeue and print elements
	while (!q.empty()) {
        std::cout << q.front() << std::endl;
        q.dequeue();
    }

	return 0;
}