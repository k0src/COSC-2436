#include <iostream>

using namespace std;

class MidStack {
    private:
        struct Node {
            int value;
            Node* next;
            Node* prev;
            Node(int value) : value(value), next(nullptr), prev(nullptr) {}
        };
    
        Node* head;
        Node* mid;
        int size;
    public:
        MidStack() : size(0), head(nullptr), mid(nullptr) {}
    
        void push(int value) {
            Node* node = new Node(value);
            if (!head) {
                head = mid = node;
            } else {
                head->next = node;
                node->prev = head;
                head = node;
                if (size % 2 == 0) {
                    mid = mid->next;
                }
            }
            size++;
        }
    
        void pop() {
            if (!head) return;

            Node* temp = head;
            if (head == mid) {
                head = mid = nullptr;
            } else {
                head = head->prev;
                head->next = nullptr;
                if (size % 2 == 1) {
                    mid = mid->prev;
                }
            }
            delete temp;
            size--;
        }
    
        void popMiddle() {
            if (!head) return;
            
            Node* temp = mid;
            if (head == mid) {
                head = mid = nullptr;
            } else {
                mid->prev->next = mid->next;
                mid->next->prev = mid->prev;
                if (size % 2 == 1) {
                    mid = mid->prev;
                } else {
                    mid = mid->next;
                }
            }
            delete temp;
            size--;
        }
    
        int top() const {
            return head->value;
        }
    
        int middle() const {
            return mid->value;
        }
    };