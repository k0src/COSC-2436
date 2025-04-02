#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int value) : value(value), next(nullptr) {}
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->value > b->value;
    }
};

Node* mergeKSortedLists(vector<Node*> heads) {
    priority_queue<Node*, vector<Node*>, compare> min_heap;

    for (Node* head : heads) {
        min_heap.push(head);
    }

    Node* temp = new Node(-1);
    Node* tail = temp;

    while (!min_heap.empty()) {
        Node* top = min_heap.top();
        min_heap.pop();

        tail->next = top;
        tail = top;

        if (top->next) {
            min_heap.push(top->next);
        }
    }

    return temp->next;
}

int main() 
{
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(10);
    head2->next->next->next->next->next = new Node(12);

    Node* head3 = new Node(9);
    head3->next = new Node(11);
    head3->next->next = new Node(13);
    head3->next->next->next = new Node(15);
    head3->next->next->next->next = new Node(17);
    head3->next->next->next->next->next = new Node(19);
    head3->next->next->next->next->next->next = new Node(21);
    head3->next->next->next->next->next->next->next = new Node(23);

    vector<Node*> heads = {head1, head2, head3};

    mergeKSortedLists(heads);

    return 0;
}