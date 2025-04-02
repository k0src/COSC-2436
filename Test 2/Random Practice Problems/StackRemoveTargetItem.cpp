#include "help.h"

using namespace std;

void removeItem(stack<int>& s, int x) {
    if (s.empty()) {
        return;
    }

    int top = s.top();
    s.pop();

    removeItem(s, x);

    if (top != x) s.push(top);
} 

int main()
{
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(6);
    s.push(9);

    printStack(s);

    removeItem(s, 6);

    printStack(s);

    return 0;
}