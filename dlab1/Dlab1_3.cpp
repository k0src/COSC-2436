#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

int median(std::multiset<int>& v, int k) {
    auto it = v.begin();
    std::advance(it, k / 2);

    if (k % 2 == 1) {
        return *it;
    } else {
        std::advance(it, -1);
        return *it;
    }
}

int main(int argc, char* argv[])
{
    int size, k;

    scanf("%d", &size);
    scanf("%d", &k);

    std::vector<int> nums(size);
    std::vector<int> medians(size - k + 1);

    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i <= size - k; i++) {
        std::multiset<int> temp(nums.begin() + i, nums.begin() + i + k);
        medians[i] = median(temp, k);
    }

    for (int i = 0; i < medians.size(); i++) {
        printf("%d ", medians[i]);
    }

    return 0;
}