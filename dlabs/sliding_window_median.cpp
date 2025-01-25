#include <iostream>
#include <unordered_set>
#include <algorithm>

int main(int argc, char* argv[])
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    std::vector<int> temp;

    for (int i = 0; i <= n - k; i++) {
        for (int j = i; j < i + k; j++) {
            temp.push_back(nums[j]);
        }
        std::sort(temp.begin(), temp.end());
        std::cout << temp[temp.size() / 2] << " ";
        temp.clear();
    }

    return 0;
}