#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next (nullptr) {}
};

bool hasCycle(Node* head) {
    if (head) {
        Node* fast = head;
        Node* slow = head;
    
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    // head->next->next->next->next = head->next->next->next; 

    std::cout << hasCycle(head);

    return 0;
}