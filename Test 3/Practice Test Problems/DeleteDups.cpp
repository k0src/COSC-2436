#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;

    ListNode* current = head;

    while (current) {
        if (current->next && current->val == current->next->val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(7);

    ListNode* res = deleteDuplicates(head);

    ListNode* current = res;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }

    return 0;
}