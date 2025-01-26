#include <cstdio>
#include <iostream>
#include <unordered_set>

int main() 
{
    int n;
    scanf("%d", &n);

    std::unordered_set<int> nums;
    nums.reserve(n + n / 2);

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        nums.insert(num);
    }

    printf("%lu\n", nums.size());
    return 0;
}
