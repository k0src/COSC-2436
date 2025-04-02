#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int value) : value(value), next(nullptr) {}
};

Node *reverseKGroup(Node *head, int k) {
    if (head == nullptr) {
        return head;
    }

    Node *curr = head;
    Node *newHead = nullptr;
    Node *tail = nullptr;

    while (curr != nullptr) {
        Node *groupHead = curr;
        Node *prev = nullptr;
        Node *nextNode = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

        if (newHead == nullptr) {
            newHead = prev;
        }

        if (tail != nullptr) {
            tail->next = prev;
        }

        tail = groupHead;
    }

    return newHead;
}