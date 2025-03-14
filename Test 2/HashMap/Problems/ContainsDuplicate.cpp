#include <iostream>
#include <unordered_map>
#include <vector>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_map<int, int> freq;

    for (int i : nums) {
        if (freq[i] == 1) return true;

        freq[i]++;
    }

    return false;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 5};
    std::cout << containsDuplicate(nums);
    return 0;
}