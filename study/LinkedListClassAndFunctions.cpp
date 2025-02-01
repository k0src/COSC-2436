#include <iostream>
#include <stdexcept>

class Node {
public:
	Node(int value) : value(value), next(nullptr) {}

private:
	int value;
	Node* next;

	friend class LinkedList;
};

class LinkedList {
public:
	LinkedList() : head(nullptr), tail(nullptr) {}

	void addFirst(int value) {
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

	void addLast(int value) {
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

	void insertAt(int value, int index) {
		if (index < 0 || index > _size) {
			return;
		}

		if (index == _size) {
			addLast(value);
			return;
		}

		if (index == 0) {
			addFirst(value);
			return;
		}

		Node* current = head;
		Node* node = new Node(value);

 		for (int i = 0; i < index - 1; i++) {
 			current = current->next;
 		}

 		node->next = current->next;
 		current->next = node;

		_size++;
	}

	void deleteFirst() {
	    if (!head) {
	        return; 
	    }

	    Node* current = head;
	    head = head->next;

	    if (!head) {
	        tail = nullptr;
	    }

	    delete current;
	    _size--;
	}


	void deleteLast() {
		if (!head) {
			return;
		}

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
			current->next = nullptr;	
		}

		_size--;
	}

	void deleteAt(int index) {
	    if (index < 0 || index >= _size) {
	        return;
	    }

	    if (index == 0) {
	        deleteFirst();
	        return;
	    }

	    if (index == _size - 1) {
	        deleteLast();
	        return;
	    }

	    Node* current = head;

	    for (int i = 0; i < index - 1; i++) {
	        current = current->next;
	    }

	    Node* toDelete = current->next;
	    current->next = toDelete->next;
	    delete toDelete;

	    _size--;
	}

	void deleteAll(int value) {
	    if (!head) {
	        return;
	    }

	    while (head && head->value == value) {
	        deleteFirst();
	    }

	    Node* current = head;
	    while (current && current->next) {
	        if (current->next->value == value) {
	            Node* toDelete = current->next;
	            current->next = toDelete->next;

	            if (toDelete == tail) {
	                tail = current;
	            }

	            delete toDelete;
	            _size--;
	        } else {
	            current = current->next;
	        }
	    }
	}


	int at(int index) {
		if (index < 0 || index >= _size) {
	        throw std::out_of_range("Index out of range");
	    }

		Node* current = head;

		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		return current->value;
	}

	bool contains(int value) {
		Node* current = head;

		while (current) {
			if (current->value == value) {
				return true;
			}

			current = current->next;
		}

		return false;
	}

	int indexOf(int value) {
		int index = 0;
		Node* current = head;

		while (current) {
			if (current->value == value) {
				return index;
			}

			current = current->next;
			index++;
		}

		return -1;
	}

	void sort() {
	    if (!head || !head->next) {
	        return;
	    }

	    bool swapped;
	    do {
	        swapped = false;
	        Node* current = head;

	        while (current->next) {
	            if (current->value > current->next->value) {
	                int temp = current->value;
	                current->value = current->next->value;
	                current->next->value = temp;
	                swapped = true;
	            }

	            current = current->next;
	        }
	    } while (swapped);
	}

	int size() {
		return _size;
	}

	bool isEmpty() {
		return head == nullptr;
	}

	void print() {
		if (!head) {
			return;
		}

		Node* current = head;

		while (current) {
			std::cout << current->value << " ";
			current = current->next;
		}
	}
 
private:
	Node* head;
	Node* tail;
	int _size = 0;
};

int main()
{
	LinkedList l;
	l.addFirst(10);
	l.addFirst(23);
	l.addLast(4);
	l.addFirst(5);
	l.addLast(16);
	l.addFirst(5);

	l.sort();

	l.print();
	return 0;
}