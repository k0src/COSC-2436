#include "help.h"

using namespace std;

int evaluatPostFixExpression(vector<string>& expr) {
    stack<int> st;

    for (const string& s : expr) {
        if (isdigit(s[0]) || s.size() > 1 && s[0] == '-') {
            st.push(stoi(s));
        } else {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            if (s == "+") {
                st.push(val2 + val1);
            } else if (s == "-") {
                st.push(val2 - val1);
            } else if (s == "*") {
                st.push(val2 * val1);
            } else if (s == "/") {
                st.push(val2 / val1);
            }
        }
    }

    return st.top();
}

int main()
{
    vector<string> expr = {"5", "3", "8", "*", "+", "4", "2", "/", "-"};
    cout << evaluatPostFixExpression(expr);
    return 0;
}