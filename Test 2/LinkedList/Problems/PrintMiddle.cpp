#include <iostream>
#include "List.h"

void printMiddle(Node* head) {
    if (!head) return;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    std::cout << slow->value << std::endl;
}

int main()
{
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);

    printMiddle(list.head); // 3

    return 0;
}