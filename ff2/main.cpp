// FF2 - Linked Lists

#include <iostream>
#include <unordered_map>

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

    Node* head;
    Node* tail;
};

bool checkPalindrome(Node** left, Node* right) {
    if (right == nullptr) {
        return true;
    }
    
    bool isPal = checkPalindrome(left, right->next);

    if (!isPal) {
        return false;
    }

    bool isEqual = ((*left)->value == right->value);

    *left = (*left)->next;
    
    return isEqual;
}
bool isPalindrome(Node* head) {
    Node* left = head;
    return checkPalindrome(&left, head);
}

Node* freqeuncy(Node* head) {
    LinkedList res;

    std::unordered_map<int, int> freqs;

    while (head) {
        freqs[head->value] += 1;
        head = head->next;
    }

    for (const auto& p : freqs) {
        res.pushBack(p.second);
    }

    return res.head;
}

int main() 
{
    LinkedList l;
    // l.pushBack(1);
    // l.pushBack(2);
    // l.pushBack(2);
    // l.pushBack(1);

    l.pushBack(1);
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);

    // std::cout << isPalindrome(l.head) << std::endl; // True

    auto freq = freqeuncy(l.head); // 1, 2, 3
    while (freq) {
        std::cout << freq->value;
        freq = freq->next;
    }

    return 0;
}