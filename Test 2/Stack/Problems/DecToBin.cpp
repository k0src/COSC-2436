#include <iostream>
#include <stack>

int decToBin(int dec) {
	if (dec == 0) return 0;

	std::stack<int> bits;

	while (dec > 0) {
		int bit = dec % 2;
		bits.push(bit);
		dec /= 2;
	}

	int res = 0;

	while (!bits.empty()) {
		res = res * 10 + bits.top();
		bits.pop();
	}

	return res;
}

int main()
{
	std::cout << decToBin(52) << std::endl; // 110100
	std::cout << decToBin(5) << std::endl; // 101
	std::cout << decToBin(68) << std::endl; // 1000100

	return 0;
}