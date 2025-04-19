#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* merge(Node* left, Node* right) {
    if (!left) return right;
    if (!right) return left;

    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Node* sort(Node* head) {
    if (!head || !head->next) {
        return head;
    }

    Node* mid = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        mid = mid->next;
        fast = fast->next->next;
    }

    Node* temp = mid->next;
    mid->next = nullptr;
    Node* left = sort(head);
    Node* right = sort(temp);

    return merge(left, right);
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    Node* sorted = sort(head);

    Node* current = sorted;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}