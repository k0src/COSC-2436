#include <iostream>
#include <stack>
#include <vector>

bool isMatchingPair(char c1, char c2) {
    return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
}

bool isBalanced(const std::string& s) {
    std::stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (!st.empty() && isMatchingPair(st.top(), c))
                st.pop();
            else return false;
        }
    }

    return st.empty();
}

int main()
{
    std::vector<std::string> tests = {"{([])}", "()", "()[]{}", "{)){})", "([])", "{{)}}"};
    for (auto& s : tests) {
        if (isBalanced(s)) std::cout << s << " is balanced.\n";
        else std::cout << s << " is not balanced\n";
    }
    return 0;
}