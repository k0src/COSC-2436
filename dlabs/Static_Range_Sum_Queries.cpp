#include <iostream>
#include <vector>

int main()
{
	int n = 8, q = 4;
	std::vector<int> values = {3, 2, 4, 5, 1, 1, 5, 3};

	int a = 5, b = 6;

	int sum = 0;

	for (int i = a - 1; i < b; ++i) {
		sum += values[i];
	}

	std::cout << sum;

	return 0;
}