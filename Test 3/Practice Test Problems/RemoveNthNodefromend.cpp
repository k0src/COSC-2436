#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* removeNthFromEnd(Node* head, int n) {
    if (!head) return nullptr;

    Node* fast = head;
    Node* slow = head;
    Node* prev = nullptr;

    for (int i = 0; i < n && fast; i++) {
        fast = fast->next;
    }

    while (fast) {
       fast = fast->next;
       prev = slow; 
       slow = slow->next;
    }

    if (!slow) return head;

    if (prev) {
        prev->next = slow->next;
    } else {
        head = head->next;
    }

    delete slow;
    return head;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* res = removeNthFromEnd(head, 2);

    Node* current = res;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}