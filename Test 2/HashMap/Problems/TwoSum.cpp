#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> differences;

    for (int i = 0; i < nums.size(); i++) {
        differences[target - nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (differences.find(nums[i]) != differences.end()) {
            if (i != differences[nums[i]]) {
                return std::vector<int>({i, differences[nums[i]]});
            }
        }
    }

    return std::vector<int>({});
}

int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    for (int i : twoSum(nums, target)) {
        std::cout << i << " ";
    }
    return 0;
}