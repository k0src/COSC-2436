#include "help.h"

using namespace std;

void sortStack(stack<int>& s) {
    stack<int> s2;

    while (!s.empty()) {
        int top = s.top();
        s.pop();

        while (!s2.empty() && top > s2.top()) {
            s.push(s2.top());
            s2.pop();
        }

        s2.push(top);
    }

    s = s2;
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(5);
    s.push(9);
    s.push(10);
    s.push(4);

    printStack(s);
    sortStack(s);
    printStack(s);

    return 0;
}