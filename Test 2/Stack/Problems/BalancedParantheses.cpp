#include <iostream>
#include <stack>

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalancedParentheses(const std::string& s) {
    std::stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty() || !isMatchingPair(st.top(), c)) {
                return false;
            }
            st.pop(); 
        }
    }

    return st.empty();
}

int main() {
    std::string test1 = "()";
    std::string test2 = "({[]})";
    std::string test3 = "(]";
    std::string test4 = "([)]";
    std::string test5 = "{[()]}}";

    std::cout << std::boolalpha;
    std::cout << isBalancedParentheses(test1) << "\n"; // true
    std::cout << isBalancedParentheses(test2) << "\n"; // true
    std::cout << isBalancedParentheses(test3) << "\n"; // false
    std::cout << isBalancedParentheses(test4) << "\n"; // false
    std::cout << isBalancedParentheses(test5) << "\n"; // false

    return 0;
}
