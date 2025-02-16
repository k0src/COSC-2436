#include <iostream>
#include <vector>

// 'Merge sort' merge
void mergeArrays(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
	int i = 0, j = 0, k = 0;
	int n1 = arr1.size();
	int n2 = arr2.size();

	while (i < n1 && j < n2) {
		if (arr1[i] < arr2[j]) {
			arr3[k++] = arr1[i++];
		} else {
			arr3[k++] = arr2[j++];
		}
	}

	while (i < n1) {
		arr3[k++] = arr1[i++];
	}

	while (j < n2) {
		arr3[k++] = arr2[j++];
	}
}

int main() 
{
	std::vector<int> arr1 = {1, 3, 5, 8, 7, 9};
	std::vector<int> arr2 = {2, 4, 6, 8, 10, 11, 12};
	std::vector<int> arr3(arr1.size() + arr2.size());

	mergeArrays(arr1, arr2, arr3);

	for (auto i : arr3) {
		std::cout << i << std::endl;
	}

	return 0;
}