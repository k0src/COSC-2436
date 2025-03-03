#include <iostream>
#include <stack>

void printPrimeFactors(int n) {
	std::stack<int> primeFactors;

	int factor = 2;

	while (n != 1) {
		while (n % factor == 0) {
			primeFactors.push(factor);
			n /= factor;
		}

		factor++;
	}

	while (!primeFactors.empty()) {
		std::cout << primeFactors.top() << std::endl;
		primeFactors.pop();
	}
}

int main()
{
	int n = 100;
	printPrimeFactors(n);
	return 0;
}