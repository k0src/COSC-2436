#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* kthNodeFromEnd(Node* head, int k) {
    if (!head) return nullptr;

    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < k && fast; i++) {
        fast = fast->next;
    }

    if (!fast) {
        return nullptr;
    }

    while (fast) {
        fast = fast->next;
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

    std::cout << kthNodeFromEnd(head, 2)->data;

    return 0;
}