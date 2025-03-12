#include <iostream>
#include <stdexcept>

// Node

class Node {
public:
	Node(int value) : value(value), next(nullptr) {}

private:
	friend class SinglyLinkedList;

	int value;
	Node* next;	
};

// Singly Linked List

class SinglyLinkedList {
public:
	SinglyLinkedList() : head(nullptr), tail(nullptr) {}

	~SinglyLinkedList() {
		clear();
	}

	void addFront(int value) {
		Node* node = new Node(value);

		if (!head) {
			head = node;
			tail = node;
		} else {
			node->next = head;
			head = node;
		}

		_size++;
	}

	void addBack(int value) {
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

	void removeFront() {
		if (!head) return;

		if (head == tail) {
			delete head;
			head = tail = nullptr;
		} else {
			Node* current = head;
			head = head->next;
			delete current;
		}

		_size--;
	}

	void removeBack() {
		if (!head) return;

		if (head == tail) {
			delete head;
			head = tail = nullptr;
		} else {
			Node* current = head;

			while (current->next != tail) {
				current = current->next;
			}

			delete tail;
			tail = current;
			tail->next = nullptr;
		}

		_size--;
	}

	void insertAt(int value, int index) {
		if (index >= _size || index < 0) return;

		if (index == 0) {
			addFront(value);
		} else if (index == _size) {
			addBack(value);
		} else {
			Node* current = head;
			Node* node = new Node(value);

			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}

			node->next = current->next;
			current->next = node;

			_size++;
		}
	}

	void removeAt(int index) {
		if (index >= _size || index < 0) return;

		if (index == 0) {
			removeFront();
		} else if (index == _size) {
			removeBack();
		} else {
			Node* current = head;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}

			Node* to_delete = current->next;
			current->next = to_delete->next;
			delete to_delete;
			
			_size--;
		}
	}

	int at(int index) const {
		if (index >= _size || index < 0) {
			throw std::invalid_argument("Invalid Index");
		}

		Node* current = head;

		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		return current->value;
	}

	bool contains(int value) const {
		if (!head) return false;

		Node* current = head;

		while (current) {
			if (current->value == value) return true;
			current = current->next;
		}

		return false;
	}

	int indexOf(int value) const {
		if (!head) return -1;

		Node* current = head;
		int index = 0;

		while (current) {
			if (current->value == value) return index;
			current = current->next;
			index++;
		}

		return -1;
	}

	int size() const {
		return _size;
	}

	bool empty() const {
		return _size == 0;
	}

	void print() const {
		if (!head) return;

		Node* current = head;

		while (current) {
			std::cout << current->value << std::endl;
			current = current->next;
		}
	}

	void clear() {
		if (!head) return;

		Node* current = head;

		while (current) {
			Node* to_delete = current;
			current = current->next;
			delete to_delete;
		}
		head = nullptr;
		tail = nullptr;

		_size = 0;
	}

private:
	Node* head;
	Node* tail;

	int _size = 0;
};

int main() 
{
	SinglyLinkedList l;
	l.addBack(2);
	l.addBack(9);
	l.addBack(6);
	l.addBack(13);
	l.addBack(12);

	l.print();
	std::cout << l.indexOf(6) << std::endl;
	std::cout << l.contains(2) << std::endl;
	std::cout << l.at(3) << std::endl;

	return 0;
}