#include <iostream>

struct Node {
    Node(int value) : value(value), next(nullptr) {}
    int value;
    Node* next;
};

struct LinkedList {
    LinkedList() : head(nullptr) {}

    void pushBack(int value) {
        auto node = new Node(value);

        if (!head) {
            head = node;
            tail = node;
        } else {    
            tail->next = node;
            tail = node;
        }
    }

    void print() {
        auto current = head;
        while (current) {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }

    Node* head; 
    Node* tail;
};

Node* mergeSortedLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->value < l2->value) {
        l1->next = mergeSortedLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSortedLists(l1, l2->next);
        return l2;
    }
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    
    Node* slow = head;
    Node* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* mid = slow->next;
    slow->next = nullptr;
    
    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    
    return mergeSortedLists(left, right);
}

void mergeLists(Node* l1, Node* l2, Node*& l3) {
    l3 = mergeSortedLists(l1, l2);
}

int main() {
    LinkedList l1, l2, l3;

    for (int i = 0; i < 10; i++) {
        l1.pushBack(rand() % 100);
        l2.pushBack(rand() % 100);
    }

    l1.head = mergeSort(l1.head);
    l2.head = mergeSort(l2.head);
    mergeLists(l1.head, l2.head, l3.head);
    
    l3.print();
    
    return 0;
}
