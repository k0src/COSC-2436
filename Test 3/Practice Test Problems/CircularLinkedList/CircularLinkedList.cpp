#include <iostream>

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
public:
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(int data) {
        Node* node = new Node(data);

        if (!head) {
            head = node;
            tail = node;
            head->next = head;
        } else {
            node->next = head;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(int data) {
        Node* node = new Node(data);

        if (!head) {
            head = node;
            tail = node;
            head->next = head;
        } else {
            node->next = head;
            tail->next = node;
            head = node;
        }
    }

    void pop_back() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = head;
    }

    void pop_front() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void print() const {
        if (!head) return;

        Node* current = head;
        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
        std::cout << std::endl;
    }
};

int main()
{
    CircularLinkedList cll;
    cll.push_back(10);
    cll.push_front(20);
    cll.push_back(30);
    cll.push_back(40);
    cll.print();
    return 0;
}