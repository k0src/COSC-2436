#include <iostream>

bool isSorted(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		if (array[i] > array[i + 1]) return false;
	}

	return true;
}

bool isSortedRecursive(int array[], int size) {
	if (size == 1 || size == 0) return true;

	return array[size - 1] >= array[size - 2] && isSortedRecursive(array, size - 1);
}

int main() 
{
	int array[10] = {1, 3, 5, 21, 32, 77, 109, 201, 277, 329};
	int size = 10;

	std::cout << isSorted(array, size) << std::endl;
	std::cout << isSortedRecursive(array, size) << std::endl;
	return 0;
}