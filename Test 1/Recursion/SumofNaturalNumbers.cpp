#include <iostream> 

// Sums all natural numbers including n
int sumOfNaturalNumbers(int n) {
	if (n == 1) return 1;

	return n + sumOfNaturalNumbers(n - 1);
}

int main() 
{
	std::cout << sumOfNaturalNumbers(10);
	return 0;
}