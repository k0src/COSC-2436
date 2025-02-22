#include <stack>
#include <iostream>

void moveStack(std::stack<char>& s1, std::stack<char>& s2) {
    if (s1.empty()) {
        return;
    }

    s2.push(s1.top());
    s1.pop();

    moveStack(s1, s2);
}

void reverseStack(std::stack<char>& s) {
    std::stack<char> temp;

    moveStack(s, temp);

    s = temp;
}

int main()
{
    std::stack<char> s;

    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    reverseStack(s);

    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

    return 0;
}