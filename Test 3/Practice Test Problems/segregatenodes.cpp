#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

Node* segregateEvenOdd(Node* head) {
    if (!head) return nullptr;
    if (!head->next) return head;

    Node* oddHead = head;
    Node* oddTail = head;
    Node* evenHead = head->next;
    Node* evenTail = head->next;

    while (evenTail && evenTail->next) {
        oddTail->next = evenTail->next;
        oddTail = oddTail->next;
        evenTail->next = oddTail->next;
        evenTail = evenTail->next;
    }

    oddTail->next = evenHead;

    return oddHead;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    Node* res = segregateEvenOdd(head);

    Node* current = res;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}