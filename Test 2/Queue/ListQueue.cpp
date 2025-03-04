#include <iostream>
#include <stdexcept>

class Queue {
public:
	Queue() : head(nullptr), tail(nullptr) {}

	~Queue() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	void enqueue(int item) {
		Node* node = new Node(item);

		if (!head) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
		}
	}

	void dequeue() {
		if (isEmpty()) {
			throw std::runtime_error("Queue is empty.");
		}

		Node* temp = head;
		head = head->next;

		if (!head) {
			tail = nullptr;
		}

		delete temp;
	}

	int front() const {
		if (isEmpty()) {
			throw std::runtime_error("Queue is empty.");
		}
		
		return head->value;
	}

	bool isEmpty() const {
		return head == nullptr;
	}

private:
	struct Node {
		Node(int value) : value(value), next(nullptr) {}

		int value;
		Node* next;
	};

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

	while (!q.isEmpty()) {
		std::cout << q.front() << std::endl;
		q.dequeue();
	}

	return 0;
}