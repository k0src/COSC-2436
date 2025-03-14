#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> seen;
    std::vector<int> res;

    for (int i : nums1) {
        seen[i] = 1;
    }

    for (int i : nums2) {
        if (seen[i] == 1) {
            res.push_back(i);
            seen[i] = 0;
        }
    }

    return res;
}

int main()
{
    std::vector<int> nums1 = {1, 2, 2, 1};
    std::vector<int> nums2 = {2, 2};

    for (int i : intersection(nums1, nums2)) {
        std::cout << i << " ";
    }

    return 0;
}