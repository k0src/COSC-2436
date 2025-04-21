#include <iostream>

class CircularList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head;
    Node* tail;
public:
    CircularList() : head(nullptr), tail(nullptr) {}

    void push_front(int item) {
        Node* node = new Node(item);

        if (!head) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
        tail->next = head;
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
        tail->next = head;
    }

    void pop_front() {
        if (!head) return;

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            tail->next = head;
        }

        if (!head) {
            tail = nullptr;
        }
        delete temp;
    }
    
    void pop_back() {
        if (!head) return;

        Node* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = head;
            tail = current;
        }
        delete temp;
    }

    void print() {
        if (!head) return;

        Node* current = head;

        do {
            std::cout << current->data << " ";
            current = current->next;
        } while (current != head);
    }
};

int main()
{
    CircularList cl;
    cl.push_back(10);
    cl.push_front(5);
    cl.push_back(20);
    cl.pop_back();
    cl.print();
    return 0;
}