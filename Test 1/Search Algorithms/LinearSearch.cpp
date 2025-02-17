#include <iostream>

int linearSearch(int arr[], int n, int target) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == target) return i;
	}

	return -1;
}

int main()
{
	int arr[10] = {19, 4, 5, 1, 3, 12, 8, 9, 11, 16};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 8;

	std::cout << linearSearch(arr, n, target);

	return 0;
}