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

int main() 
{
    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(5);

    sortedInsert(s, 4);
    sortedInsert(s, 7);
    sortedInsert(s, 1);

    printStack(s);

    return 0;
}