#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x) {
    if (s.empty()) {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();

    insertAtBottom(s, x);

    s.push(top);
}

void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int top = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, top);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(6);

    reverseStack(s);
    while (!s.empty()) {
        std::cout << s.top();
        s.pop();
    }

    return 0;
}