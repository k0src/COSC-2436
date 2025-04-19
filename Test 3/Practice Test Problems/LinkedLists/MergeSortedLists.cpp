#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next (nullptr) {}
};

Node* mergeLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    if (head1->data <= head2->data) {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
}

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    head1->next->next->next->next = new Node(9);

    Node* head2 = new Node(6);
    head2->next = new Node(8);
    head2->next->next = new Node(10);
    head2->next->next->next = new Node(12);
    head2->next->next->next->next = new Node(14);

    Node* mergedHead = mergeLists(head1, head2);
    Node* current = mergedHead;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    return 0;
}