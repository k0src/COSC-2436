#include <iostream>
#include <stack>

int maximumNestingDepth(const std::string& s) {
    std::stack<char> st;
    int depth = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
        	if (!st.empty()) {
        	    st.pop();	
        	}
        }

        depth = std::max(depth, (int) st.size());
    }

    return depth;
}
int main()
{
	std::string s1 = "(1 + (2 * 3) + ((8) - 10 + 7)";
	std::string s2 = "(1 * (2 + (3 - (4) + 8) - 7 + ((((8))))))";
	std::cout << maximumNestingDepth(s1) << std::endl; // 3
	std::cout << maximumNestingDepth(s2) << std::endl; // 6

	return 0;
}