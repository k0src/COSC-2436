#include <iostream>

int binarySearch(int arr[], int n, int target) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return -1;
}

int main()
{
	int arr[10] = {1, 4, 5, 6, 9, 12, 13, 16, 19, 21};
	int n = sizeof(arr) / sizeof(arr[0]);
	int target = 9;

	std::cout << binarySearch(arr, n, target);

	return 0;
}