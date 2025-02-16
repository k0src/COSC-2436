#include <iostream>

int maximum(int array[], int size) {
	int max = INT_MIN;

	for (int i = 0; i < size; i++) {
		if (array[i] > max) {
			max = array[i];
		}
	}

	return max;
}

int minimum(int array[], int size) {
	int min = INT_MAX;

	for (int i = 0; i < size; i++) {
		if (array[i] < min) {
			min = array[i];
		}
	}

	return min;
}

int main() 
{
	int a[10] = {32, 1, 4, 2, 7, 8, 10, 21, 3, 12};
	int size = 10;
	std::cout << "Max: " << maximum(a, size) << " Min: " << minimum(a, size); 
	return 0;
}