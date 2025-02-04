#include <iostream>
#include <string>
#include <unordered_set>

int main() 
{
	std::string input = "ABACBCAACCBB";

	std::unordered_set<char> letters;
	int min = 0;

	for (char c : input) {
		letters.insert(c);
		if (letters.size() == 3) {
			min++;
			letters.clear();
		}
	}

	std::cout << min;
	
	return 0;
}