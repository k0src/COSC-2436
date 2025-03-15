#include <iostream>

class CircularList {
public:
    CircularList() : head(nullptr) {}

    void addFront(int value) {
        Node* node = new Node(value);

        if (!head) {
            head = node;
            head->next = node;
        } else {
            node->next = head;

            Node* current = head;
            
            do {
                current = current->next;
            } while (current->next != head);

            current->next = node;
            head = node;
        }
    }

    void addBack(int value) {
        Node* node = new Node(value);
    
        if (!head) {
            head = node;
            head->next = node;
        } else {
            Node* current = head;
            
            do {
                current = current->next;
            } while (current->next != head);
    
            current->next = node;
            node->next = head;
        }
    }

    void removeFront() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;

        while (current->next != head) {
            current = current->next;
        }

        current->next = head->next;
        delete head;
        head = current->next;

    }

    void removeBack() {
        if (!head) return;

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current= head;

        while (current->next->next != head) {
            current = current->next;
        }

        delete current->next;
        current->next = head;
    }

    void print() const {
        if (!head) return;

        Node* current = head;

        do {
            std::cout << current->value << " ";
            current = current->next;
        } while (current != head);

        std::cout << std::endl;
    }

private:
    struct Node {
        Node(int value) : value(value), next(nullptr) {}
        int value;
        Node* next;
    };

    Node* head;
};

int main()
{
    CircularList cl;

    cl.addBack(1);
    cl.addFront(2);
    cl.addFront(3);
    cl.addBack(4);
    cl.print(); // 3 2 1 4
    cl.removeFront();
    cl.removeBack();
    cl.print(); // 2 1

    return 0;
}