#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next (nullptr) {}
    };

    Node* head;
    Node* tail;
public:
    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int data) {
        Node* node = new Node(data);

        if (!head) {
            head = node;
            tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void push_back(int data) {
        Node* node = new Node(data);

        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    void insert(int data, int index) {
        if (index == 0) {
            push_front(data);
            return;
        }
    
        Node* node = new Node(data);
        Node* current = head;

        for (int i = 0; i < index - 1 && current; ++i) {
            current = current->next;
        }

        if (!current) {
            delete node;
            return; // Index out of bounds
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
        delete temp;

        if (!head) {
            tail = nullptr;
        }
    }

    void pop_back() {
        if (!head) return;

        Node* current = head;
        Node* previous = nullptr;

        while (current->next) {
            previous = current;
            current = current->next;
        }

        delete current;
        if (previous) {
            previous->next = nullptr;
            tail = previous;
        } else {
            head = nullptr;
            tail = nullptr;
        }
    }

    void remove(int data) {
        if (!head) return;

        if (head->data == data) {
            pop_front();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current && current->data != data) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next;
            delete current;

            if (!previous->next) {
                tail = previous;
            }
        }
    }

    void remove_at(int index) {
        if (index == 0) {
            pop_front();
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        for (int i = 0; i < index && current; ++i) {
            previous = current;
            current = current->next;
        }

        if (!current) return; // Index out of bounds

        previous->next = current->next;
        delete current;

        if (!previous->next) {
            tail = previous;
        }
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() 
{
    SinglyLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.print(); // Output: 1 2 3 4
    list.pop_front();
    list.print(); // Output: 2 3 4

    list.pop_back();
    list.print(); // Output: 2 3

    list.insert(5, 1);
    list.print(); // Output: 2 5 3
    list.remove(5);
    list.print(); // Output: 2 3
    list.remove_at(1);
    list.print(); // Output: 2
    list.remove_at(0);
    list.print(); // Output: (empty)
    return 0;
}