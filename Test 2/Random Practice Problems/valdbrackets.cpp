#include "help.h"

using namespace std;

bool validBrackets(string exp) {
    stack<char> s;

    for (char c : exp) {
        if (c=='(') s.push(c);
        else {
            if (s.empty()) return false;
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string exp = "(()))";
    cout << validBrackets(exp);
    return 0;
}