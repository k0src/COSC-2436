#include <iostream>

struct Node {
    Node(char value) : value(value), next(nullptr) {}

    char value;
    Node* next;
};

Node* reverseListRecursive(Node* head) {
	if (!head || !head->next) {
		return head;
	}

	Node* new_head = reverseListRecursive(head->next);

	head->next->next = head;
	head->next = nullptr;

	return new_head;
}

int main() {
    Node* n1 = new Node('a');
    Node* n2 = new Node('b');
    Node* n3 = new Node('c');

    n1->next = n2;
    n2->next = n3;

    Node* result = reverseListRecursive(n1);

    std::cout << result->value << result->next->value << result->next->next->value;

    return 0;
}
