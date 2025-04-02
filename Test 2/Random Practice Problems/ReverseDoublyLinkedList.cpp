#include <iostream>

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
};

void reverseDoublyLinkedList(Node*& head) {
    if (!head || !head->next) return;

    Node* prev = nullptr;
    Node* current = head;

    while (current) {
        Node* next = current->next;
        current->next = prev;
        current->prev = next;

        prev = current;
        current = next;
    }

    head = prev;
}