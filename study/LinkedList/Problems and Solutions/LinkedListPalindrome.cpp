#include <iostream>
#include "LinkedList.h"

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

int main() 
{
    LinkedList l;
    l.pushBack(1);
    l.pushBack(2);
    l.pushBack(3);
    l.pushBack(2);
    l.pushBack(1);

    std::cout << isPalindrome(l.head);

    return 0;
}