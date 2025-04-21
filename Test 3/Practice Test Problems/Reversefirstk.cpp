#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* reverseFirstK(Node* head, int k) {
    if (!head) return nullptr;

    Node* current = head;
    Node* prev = nullptr;

    for (int i = 0; i < k && current; i++) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    if (current) {
        head->next = current;
    }
    return prev;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* rev = reverseFirstK(head, 3);

    Node* current = rev;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}