#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixToInfix(const string& postfix) {
    stack<string> st;

    for (char ch : postfix) {
        if (isalnum(ch)) {  // Operand
            st.push(string(1, ch));
        } else {  // Oerator
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            string expression = "(" + operand1 + ch + operand2 + ")";
            st.push(expression);
        }
    }

    return st.top();
}

int main() {
    string postfix = "ABC+-/";
    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}
