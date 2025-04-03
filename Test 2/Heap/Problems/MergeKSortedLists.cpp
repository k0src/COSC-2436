#include <iostream>
#include <queue>
#include <vector>

struct Node {
    Node(int value) : value(value), next(nullptr) {}
    int value;
    Node* next;
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->value > b->value;
    }
};

Node* mergeKLists(std::vector<Node*>& lists) {
    std::priority_queue<Node*, std::vector<Node*>, compare> pq;

    for (Node* head : lists) {
        if (head) pq.push(head);
    }

    Node* temp = new Node(-1);
    Node* tail = temp;

    while (!pq.empty()) {
        Node* top = pq.top();
        pq.pop();

        tail->next = top;
        tail = top;

        if (top->next) {
            pq.push(top->next);
        }
    }

    return temp->next;
}

void printList(Node* node) {
    while (node) {
        std::cout << node->value << " ";
        node = node->next;
    }
}

int main()
{
    int k = 3; 
  
    std::vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    printList(head);

    return 0;
}