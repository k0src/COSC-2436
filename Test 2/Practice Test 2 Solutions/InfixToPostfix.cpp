#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

bool isOperand(char c) {
    return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool hasHigherPrecedence(char c1, char c2) {
    int rank1, rank2;

    if (c1 == '+' || c1 == '-')
        rank1 = 1;
    else if (c1 == '*' || c1 == '/')
        rank1 = 2;
    else if (c1 == '$')
        rank1 = 3;
    else
        rank1 = 0;
    
    if (c2 == '+' || c2 == '-')
        rank2 = 1;
    else if (c2 == '*' || c2 == '/')
        rank2 = 2;
    else if (c2 == '%')
        rank2 = 3;
    else
        rank2 = 0;

    return rank1 >= rank2;
    
} 

string infixToPostfix(string expr) {
    stack<char> st;
    string postfix = "";

    for (char c : expr) {
        if (c == ' ') continue;

        if (isOperator(c)) {
            while (!st.empty() && st.top() != '(' && hasHigherPrecedence(st.top(), c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        } else if (isOperand(c)) {
            postfix += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}