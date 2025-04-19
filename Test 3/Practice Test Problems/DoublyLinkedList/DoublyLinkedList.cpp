#include <iostream>

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;

        Node(int data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int data) {
        Node* node = new Node(data);

        if (!head) {
            head = node;
            tail = node;
        }
        else {
            node->next = head;
            head->prev = node;
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
            node->prev = tail;
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
            return;
        }

        node->next = current->next;
        node->prev = current;
        current->next = node;

        if (node->next) {
            node->next->prev = node;
        } else {
            tail = node;
        }
    }

    void pop_front() {
        if (!head) return;

        Node* temp = head;
        head = head->next;

        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    void pop_back() {
        if (!head) return;

        Node* temp = tail;
        tail = tail->prev;

        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }

    void remove(int data) {
        if (!head) return;

        if (head->data == data) {
            pop_front();
            return;
        }

        Node* current = head;

        while (current && current->data != data) {
            current = current->next;
        }

        if (current) {
            if (current->prev) {
                current->prev->next = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
        }
    }

    void remove_at(int index) {
        if (index == 0) {
            pop_front();
            return;
        }

        Node* current = head;

        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }

        if (!current) return;

        if (current->prev) {
            current->prev->next = current->next;
        }

        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
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
    DoublyLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.print();
    
    return 0;
}