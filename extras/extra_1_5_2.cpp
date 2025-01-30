#include <iostream>

class Node {
public:
    Node(int value) : value(value), next(nullptr) {}
    int value;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void pushBack(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Node* getHead() {
        return head;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
    }

    void printRec(Node* current) {
        if (current == nullptr) {
            return;
        }
        std::cout << current->value << " ";
        printRec(current->next);
    }

    int count() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    int countRec(Node* current) {
        if (current == nullptr) {
            return 0;
        }
        return 1 + countRec(current->next);
    }

    bool searchRec(Node* current, int value) {
        if (current == nullptr) {
            return false;
        }
        return current->value == value || searchRec(current->next, value);
    }

    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

private:
    Node* head;
};

int main() 
{
    LinkedList list;    
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);

    list.print();
    std::cout << std::endl;
    list.printRec(list.getHead());
    std::cout << std::endl;
    std::cout << list.count() << std::endl;
    std::cout << list.countRec(list.getHead()) << std::endl;
    std::cout << list.search(3) << std::endl;
    std::cout << list.searchRec(list.getHead(), 3) << std::endl;
    return 0;
}