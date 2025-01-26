#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

class LinkedList {
public:
	LinkedList() : head(nullptr), tail(nullptr) {}

	void printToyAtStart() const {
		if (head == nullptr) {
			std::cout << "Belt is empty." << std::endl;
		} else {
			std::cout << "Toy at beginning: " << head->name << " Price: " << head->price << std::endl;
		} 
	}

	void printBelt() const {
		if (head == nullptr) {
			std::cout << "Belt is empty." << std::endl;
		} else {
			Node* current = head;
			while (current != nullptr) {
				std::cout << "Toy: " << current->name << " Price: " << current->price << std::endl;
				current = current->next;
			}
		}
	}

	void addToyToEnd(std::string name, int price) {
		Node* toy = new Node(name, price);

		if (tail == nullptr) {
			head = toy;
			tail = toy;
		} else {
			tail->next = toy;
			tail = toy;
		}
	}

	void replaceBelt(int a, int b, LinkedList& replacementBelt) {
		if (head == nullptr) {
			std::cout << "Belt is empty." << std::endl;
			return;
		}

		if (a > b || a < 0) {
			std::cout << "Invalid indices." << std::endl;
			return;
		}

		Node* start = head;
		Node* end = head;

		for (int i = 0; i < a - 1; ++i) {
			if (start == nullptr) {
				std::cout << "Index out of bounds!" << std::endl;
				return;
			}
			start = start->next;
		}

		for (int i = 0; i <= b; ++i) {
			end = end->next;
		}

		if (end == nullptr) {
			std::cout << "Index out of bounds!" << std::endl;
			return;
		}

		if (a == 0) {
        	head = replacementBelt.head;
	    } else {
	        start->next = replacementBelt.head;
	    }

	    if (replacementBelt.tail) {
	        replacementBelt.tail->next = end;
	    }
	}

private:
	Node* head;
	Node* tail;
};

#endif