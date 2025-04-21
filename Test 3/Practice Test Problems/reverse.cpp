#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* reverse(Node* head) {
    if (!head) return nullptr;

    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    Node* rev = reverse(head);

    Node* current = rev;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}