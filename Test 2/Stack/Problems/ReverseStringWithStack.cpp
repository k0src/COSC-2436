#include <iostream>
#include <stack>

std::string reverseString(std::string& s) {
	std::stack<char> st;
	std::string res;

	for (char c : s) {
		st.push(c);
	}

	while (!st.empty()) {
		res = res += st.top();
		st.pop();
	}

	return res;
}

int main() {
    std::string s1 = "hello";
    std::string s2 = "1234";
    std::string s3 = "racecar";
    std::string s4 = "!@#$%^";
    std::string s5 = "A";

    std::cout << reverseString(s1) << std::endl; // olleh
    std::cout << reverseString(s2) << std::endl; // 4321
    std::cout << reverseString(s3) << std::endl; // racecar
    std::cout << reverseString(s4) << std::endl; // ^%$#@!
    std::cout << reverseString(s5) << std::endl; // A

    return 0;
}
