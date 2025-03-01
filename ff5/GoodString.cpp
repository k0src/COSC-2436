#include <iostream>
#include <stack>

bool isBadPair(const char c1, const char c2) {
	return (std::tolower(c1) == std::tolower(c2)) && ((std::islower(c1) && std::isupper(c2)) || (std::isupper(c1) && std::islower(c2)));
}

std::string goodString(const std::string& s) {
	if (s.length() == 0) return "";

	std::stack<char> st;

	st.push(s[0]);

	for (int i = 1; i < s.length(); i++) {
		if (!st.empty() && isBadPair(st.top(), s[i])) {
			st.pop();
		} else {
			st.push(s[i]);
		}
	}

	std::string res = "";

	while (!st.empty()) {
		res.insert(0, 1, st.top());
		st.pop();
	}

	return res;
}

int main()
{
	std::string s1 = "leEeetcode";
	std::string s2 = "abBAcC";
	std::string s3 = "s";

	std::cout << goodString(s1) << std::endl; // "leetcode"
	std::cout << goodString(s2) << std::endl; // ""
	std::cout << goodString(s3) << std::endl; // "s"

	return 0;
}