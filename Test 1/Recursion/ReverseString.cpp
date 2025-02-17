#include <iostream>
#include <string>

std::string reverseString(const std::string& s) {
	if (s.length() == 0) return "";

	return reverseString(s.substr(1)) + s[0];
}

int main()
{
	std::string s = "hello";

	std::cout << reverseString(s);

	return 0;
}