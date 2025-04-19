#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next (nullptr) {}
};

Node* middle(Node* head) {
    if (!head) return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* mid = middle(head);
    std::cout << mid->data;

    return 0;
}