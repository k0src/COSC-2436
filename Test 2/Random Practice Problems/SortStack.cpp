#include "help.h"

using namespace std;

void sortedInsert(stack<int>& s, int x) {
    if (s.empty() || x >= s.top()) {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(top);
}

void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int top = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, top);
}

int main()
{
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(9);

    printStack(s);

    sortStack(s);

    printStack(s);

    return 0;
}