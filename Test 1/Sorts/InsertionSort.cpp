#include <iostream>

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

int main() 
{
	int arr[10] = {2, 3, 5, 1, 7, 4, 10, 12, 6, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}