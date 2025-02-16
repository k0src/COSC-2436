#include <iostream>
#include <vector>

int maxSubarraySum(std::vector<int>& v) {
	int res = v[0];
	int max_ending = v[0];

	for (int i = 1; i < v.size(); i++) {
		max_ending = std::max(max_ending + v[i], v[i]);
		res = std::max(res, max_ending);
	}

	return res;
}

int main()
{
	std::vector<int> v = {2, 3, -8, 7, -1, 2, 3};
	std::cout << maxSubarraySum(v);
	return 0;
}