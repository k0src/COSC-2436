#include <iostream>
#include <stack>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

bool checkRedundantParentheses(const std::string& expr) {
    std::stack<char> st;

    for (char c : expr) {
        if (c == ')') {
            bool hasOperator = false; 

            while (!st.empty() && st.top() != '(') {
                if (isOperator(st.top())) {
                    hasOperator = true;
                }
                st.pop();
            }

            if (!st.empty()) {
                st.pop();
            }

            if (!hasOperator) {
                return true;
            }

        } else {
            st.push(c);
        }
    }

    return false;
}

int main() {
    std::string s1 = "((a+b))";
    std::string s2 = "(a+(b*c))";
    std::string s3 = "(a+b)*(c+d)";
    std::string s4 = "(a)";
    std::string s5 = "((a + b - c))";

    std::cout << checkRedundantParentheses(s1) << std::endl; // Expected: 1 (true)
    std::cout << checkRedundantParentheses(s2) << std::endl; // Expected: 0 (false)
    std::cout << checkRedundantParentheses(s3) << std::endl; // Expected: 0 (false)
    std::cout << checkRedundantParentheses(s4) << std::endl; // Expected: 1 (true)
    std::cout << checkRedundantParentheses(s5) << std::endl; // Expected: 1 (true)

    return 0;
}
