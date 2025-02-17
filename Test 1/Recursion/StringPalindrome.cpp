#include <iostream>
#include <string>

bool isPalindrome(const std::string s) {
	if (s.length() == 0 || s.length() == 1) return true;

	return (s[0] == s[s.length() - 1]) && isPalindrome(s.substr(1, s.length() - 2));
}

int main()
{
	std::string s = "racecar";

	std::cout << isPalindrome(s);

	return 0;
}