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

int main() 
{
	int arr[10] = {2, 3, 5, 1, 7, 4, 10, 12, 6, 11};
	int n = sizeof(arr) / sizeof(arr[0]);

	bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << std::endl;
	}

	return 0;
}