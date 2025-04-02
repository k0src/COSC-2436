#include <iostream>

class CircularDoublyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
        Node(int value) : value(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
public:
    CircularDoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addFront(int item) {
        Node* node = new Node(item);

        if (!head) {
            head = tail = node;
            head->next = head->prev = head;
        } else {
            head->prev = node;
            tail->next = node;
            node->next = head;
            node->prev = tail;
            head = node;
        }
    }

    void addBack(int item) {
        Node* node = new Node(item);

        if (!head) {
            head = tail = node;
            head->next = head->prev = head;
        } else {
            tail->next = node;
            head->prev = node;
            node->next = head;
            node->prev = tail;
            tail = node;
        }
    }

    void removeFront() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;

            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
    }

    void removeBack() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = tail;

            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void display() const {
        if (!head) return;
        
        Node* current = head;

        do {
            std::cout << current->value << " ";
            current = current->next;
        } while (current != head);
    }
};

int main()
{
    CircularDoublyLinkedList l;
    l.addFront(1);
    l.addFront(5);
    l.addFront(6);
    l.addBack(3);
    l.addBack(2);
    l.addBack(8);

    l.display();

    return 0;
}