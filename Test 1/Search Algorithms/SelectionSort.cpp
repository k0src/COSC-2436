#include <iostream>

void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

int main() 
{
	int arr[10] = {2, 3, 5, 1, 7, 4, 10, 12, 6, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}