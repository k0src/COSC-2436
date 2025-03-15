#ifndef LIST_H
#define LIST_H

#include <iostream>

// list for problems

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
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    Node* head;
};

#endif