#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next (nullptr) {}
};

Node* reverse(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* new_head = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* reversed = reverse(head);

    Node* current = reversed;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}