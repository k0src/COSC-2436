#include <iostream>

void printBStrings(std::string s, int n) {
	if (n == 0) {
		std::cout << s << std::endl;
		return;
	}

	printBStrings(s + "0", n - 1);
	printBStrings(s + "1", n - 1);
}

int main()
{
	printBStrings("", 10);
	return 0;
}