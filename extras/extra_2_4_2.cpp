#include <iostream>
#include <sstream>

struct Node {
	Node(char val) : val(val), next(nullptr), prev(nullptr) {}

	char val;
	Node* next;
	Node* prev;
};

struct List {
	List() : head(nullptr), tail(nullptr) {}

	void pushBack(char val) {
		Node* node = new Node(val);

		if (!head) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}

	void print() const {
		if (!head) return;

		Node* current = head;

		std::cout << "[";

		while (current) {
			if (current->next) {
				std::cout << current->val << ", ";
			} else {
				std::cout << current->val << "]" << std::endl;
			}
			current = current->next;
		}
	}

	Node* head;
	Node* tail;
};

/* Checks if Doubly Linked List is a Palindrome:*/

bool isPalindrome(Node*& head) {
	if (!head || !head->next) return true; /// empty list or single node

	// two pointers, i at head, j at tail
	Node* i = head;
	Node* j = head;

	while (j->next) {
		j = j->next;
	}

	// move pointers, check equality
	while (i != j && j->next != i) {
		if (i->val != j->val) {
			return false;
		}
		i = i->next;
		j = j->prev;
	}

	return true;
}

int main() 
{
	List l;
	l.pushBack('r');
	l.pushBack('a');
	l.pushBack('c');
	l.pushBack('e');
	l.pushBack('c');
	l.pushBack('a');
	l.pushBack('r');

	l.print();

	List l2;
	l2.pushBack('r');
	l2.pushBack('a');
	l2.pushBack('k');
	l2.pushBack('e');
	l2.pushBack('c');
	l2.pushBack('a');
	l2.pushBack('r');

	l2.print();

	List l3;
	l3.pushBack('a');
	l3.pushBack('b');
	l3.pushBack('b');
	l3.pushBack('a');

	l3.print();

	std::cout << std::boolalpha << isPalindrome(l.head) << std::endl; // true
	std::cout << std::boolalpha << isPalindrome(l2.head) << std::endl; // false
	std::cout << std::boolalpha << isPalindrome(l3.head) << std::endl; // true

	return 0;
}