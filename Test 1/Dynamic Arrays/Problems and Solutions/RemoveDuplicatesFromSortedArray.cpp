#include <iostream>

int removeDuplicates(int array[], int size) {
    if (size == 0) return 0;

    int unique_index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] != array[unique_index]) {
            unique_index++;
            array[unique_index] = array[i];
        }
    }
    return unique_index + 1;
}

int main() 
{
	int array[10] = {1, 1, 1, 2, 3, 4, 4, 5, 6, 7};
	int size = 10;

	std::cout << removeDuplicates(array, size);

	return 0;
}