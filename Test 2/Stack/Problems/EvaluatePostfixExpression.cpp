#include <iostream>
#include <stack>
#include <vector>

int evaluatePostfix(const std::vector<std::string>& expr) {
	std::stack<int> st;

	for (std::string token : expr) {
		// If digit, push onto stack
		if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
			st.push(stoi(token));
		}

		// Otherwise, it must be an operator.
		else {
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();

			if (token == "+") {
                st.push(val2 + val1);
            } else if (token == "-") {
                st.push(val2 - val1);
            } else if (token == "*") {
                st.push(val2 * val1);
            } else if (token == "/") {
                st.push(val2 / val1);
            }
		}
	}
	return st.top();
}

int main()
{
	std::vector<std::string> expr = {"1","2","3","+","4","5","6","*","-","7","*","+","-","8","9","*","+"};
	std::cout << evaluatePostfix(expr) << std::endl;
	return 0;
}