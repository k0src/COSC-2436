#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

int numRotations(Node* head) {
    if (!head || !head->next) {
        return 0;
    }

    int count = 0;
    Node* current = head;

    while (current->next) {
        if (current->data > current->next->data) {
            return count + 1;
        }
        count++;
        current = current->next;
    }

    return 0;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    std::cout << numRotations(head);

    return 0;
}