#include <iostream>

void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}	
}

void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[j + 1]) {
				minIndex = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

int binarySearch(int arr[], int n, int target) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return -1;
}

int main() 
{
	int arr[10] = {2, 3, 5, 1, 7, 4, 10, 12, 6, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << std::endl;
	}

	int target = 10;

	std::cout << binarySearch(arr, n, target) << std::endl;

	return 0;
}