#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    int max_length = 0;

    for (int num : set) {
        // if num is the start of a sequence
        if (!set.count(num - 1)) {
            int current_num = num;
            int len = 1;
            
            while (set.count(current_num + 1)) {
                current_num++;
                len++;
            }

            max_length = std::max(max_length, len);
        }
    }

    return max_length;
}

int main()
{
    std::vector<int> nums = {100,4,200,1,3,2};
    std::cout << longestConsecutive(nums);
    return 0;
}