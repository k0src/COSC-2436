#include <iostream>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr) {}

    void push_front(int item) {
        Node* node = new Node(item);

        if (!head) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void push_back(int item) {
        Node* node = new Node(item);

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void insert(int item, int index) {
        if (index == 0) {
            push_front(item);
            return;
        }

        Node* node = new Node(item);
        Node* current = head;

        for (int i = 0; i < index - 1 && current; i++) {
            current = current->next;
        }

        if (!current) {
            delete node;
            return;
        }

        node->next = current->next;
        current->next = node;

        if (!node->next) {
            tail = node;
        }
    }

    void pop_front() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        
        if (!head) {
            tail = nullptr;
        }

        delete temp;
    }

    void pop_back() {
        if (!head) return;

        Node* current = head;
        Node* prev = nullptr;

        while (current->next) {
            prev = current;
            current = current->next;
        }

        delete current;

        if (prev) {
            prev->next = nullptr;
            tail = prev;
        } else {
            head = tail = nullptr;
        }
    }

    void remove_at(int index) {
        if (!head) return;

        if (index == 0) {
            pop_front();
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        for (int i = 0; i < index && current; i++) {
            prev = current;
            current = current->next;
        }

        if (!current) return;

        prev->next = current->next;
        delete current;

        if (!prev->next) {
            tail = prev;
        }
    }

    void remove(int item) {
        if (!head) return;

        if (head->data == item) {
            pop_front();
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current && current->data != item) {
            prev = current;
            current = current->next;
        }

        if (current) {
            prev->next = current->next;
            delete current;

            if (!prev->next) {
                tail = prev;
            } 
        }
    }
};