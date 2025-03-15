#include <iostream>
#include "List.h"

Node* sortedInsert(Node* head, int value) {
    Node* node = new Node(value);
    if (head == nullptr || head->value >= value) {
        node->next = head;
        return node;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->value < value) {
        current = current->next;
    }

    if (current->next == nullptr || current->next->value != value) {
        node->next = current->next;
        current->next = node;
    } else {
        delete node;
    }

    return head;
}

int main()
{
    Node* head = nullptr;

    head = sortedInsert(head, 3);
    head = sortedInsert(head, 4);
    head = sortedInsert(head, 1);
    head = sortedInsert(head, 2);

    while (head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }

    return 0;
}