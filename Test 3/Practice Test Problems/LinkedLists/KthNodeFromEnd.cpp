#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next (nullptr) {}
};

Node* kthNodeFromEnd(Node* head, int k) {
    if (!head) return nullptr;

    Node* fast = head;
    Node* slow = head;

    for (int i = 0; i < k; i++) {
        if (fast == nullptr) return nullptr;
        fast = fast->next;
    }

    while (fast) {
        fast = fast->next;
        slow = slow->next;
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

    int k = 3;
    Node* result = kthNodeFromEnd(head, k);
    std::cout << result->data;

    return 0;
}