#include <iostream>
#include <queue>

int kthSmallest(int array[], int size, int k) {
	std::priority_queue<int> pq;

	for (int i = 0; i < size; i++) {
		pq.push(array[i]);

		if (pq.size() > k) pq.pop();
	}

	return pq.top();
}

int main() 
{
	int array[10] = {3, 54, 26, 64, 21, 7, 65, 33, 68, 23};
	int size = 10;
	int k = 4;

	std::cout << k << "th smallest element is: " << kthSmallest(array, size, k) << std::endl;

	return 0;
}