#include <iostream>

int binarySearch(int arr[], int left, int right, int target) {
	if (right >= left) {
		int mid = (left + right) / 2;

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] > target) {
			return binarySearch(arr, left, mid - 1, target);
		} else {
			return binarySearch(arr, mid + 1, right, target);
		}
	}
	return -1;
}

int main()
{
	int arr[10] = {2, 3, 6, 8, 9, 11, 14, 16, 17, 21};
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0])) - 1;
	int target = 9;

	std::cout << binarySearch(arr, left, right, target);
	return 0;
}