#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

bool linearSearch(const std::vector<int>& array, int target) {
	for (int i = 0; i < array.size(); i++) {
		if (array[i] == target) return true;
	}

	return false;
}

void linearSearchTest() {
    std::cout << "Randomly generating an array with 100,000 values." << std::endl;

    std::vector<int> array;
    std::srand(std::time(nullptr));

    for (int i = 0; i < 100000; i++) {
        array.push_back(1 + std::rand() % 100000);
    }

    int target = 1 + std::rand() % 100000;

    std::cout << "Done. Searching the array (linearly) for the number: " << target << " 100,000 times." << std::endl;

    clock_t start = std::clock();

    for (int i = 0; i < 100000; i++) {
        linearSearch(array, target);
    }

    clock_t end = std::clock();

    double total_time = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "It took " << total_time << " seconds to search an array of 100,000 elements 100,000 times, linearly." << std::endl;
}

bool binarySearch(const std::vector<int>& array, int target) {
	int start = 0;
	int end = array.size() - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (array[mid] == target) {
			return true;
		} else if (array[mid] > target) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return false;
}

void binarySearchTest() {
    std::cout << "Randomly generating an array with 100,000 values." << std::endl;

    std::vector<int> array;
    std::srand(std::time(nullptr));

    for (int i = 0; i < 100000; i++) {
        array.push_back(1 + std::rand() % 100000);
    }

    int target = 1 + std::rand() % 100000;

    std::cout << "Done. Searching the array (binary search) for the number: " << target << " 100,000 times." << std::endl;

    clock_t start = std::clock();

    for (int i = 0; i < 100000; i++) {
        linearSearch(array, target);
    }

    clock_t end = std::clock();

    double total_time = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "It took " << total_time << " seconds to search an array of 100,000 elements 100,000 times, with a binary search." << std::endl;
}

int main() 
{
	int selection;
	std::cout << "Search Algorithm Time Comparison\nSelect an Algorithm:\n1. Linear Search\n2. Binary Search\n3. Exit" << std::endl;

	std::cin >> selection;

	switch (selection) 
	{
		case 1:
			linearSearchTest();
			break;
		case 2:
			binarySearchTest();
			break;
		case 3:
			break;
	}

	return 0;
}