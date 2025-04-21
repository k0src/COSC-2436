#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* middle(Node* head) {
    if (!head) return nullptr;

    Node* fast = head;
    Node* slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    Node* mid = middle(head);
    std::cout << mid->data;

    return 0;
}