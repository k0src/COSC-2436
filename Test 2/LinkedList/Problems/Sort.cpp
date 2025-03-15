#include <iostream>
#include "List.h"

void sort(Node* head) {
    if (!head || !head->next) return;

    bool isSorted = false;
    Node* current = head;

    while (!isSorted) {
        isSorted = true;
        current = head;

        while (current->next) {
            if (current->value > current->next->value) {
                std::swap(current->value, current->next->value);
                isSorted = false;
            }
            current = current->next;
        }
    }
}

int main() 
{
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    sort(head);

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }

    return 0;
}