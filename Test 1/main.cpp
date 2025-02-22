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
	int arr[10] = {3, 5, 1, 8, 9, 10, 13, 16, 2, 21};
	int n = 10;

	selectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}