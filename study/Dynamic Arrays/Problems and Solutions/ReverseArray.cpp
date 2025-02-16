#include <iostream>

void reverse(int array[], int size) {
	if (size < 2) return;

	int i = 0;
	int j = size - 1;

	while (i < j) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		i++;
		j--;
	}
}

int main()
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = 10;

	reverse(array, size);

	for (int i = 0; i < size; i++) {
		std::cout << array[i] << std::endl;
	}

	return 0;
}