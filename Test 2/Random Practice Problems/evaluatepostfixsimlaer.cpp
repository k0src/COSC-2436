#include "help.h"

using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;

    for (char token : exp) {
        // MAKE SURE IF YOU USE THIS USE CHARACTERS!
        if (token >= '0' && token <= '9') { // can also use isdigit - since no letters will be operands.
            // CHAR TO INT:
            st.push(token - '0');
        } else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (token == '+') {
                st.push(val2 + val1);
            } else if (token == '-') {
                st.push(val2 - val1);
            } else if (token == '*') {
                st.push(val2 * val1);
            } else {
                st.push(val2 / val1);
            }
        }
    }

    return st.top();
}

int main()
{
    return 0;
}