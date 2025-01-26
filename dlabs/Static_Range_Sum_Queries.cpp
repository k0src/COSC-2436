#include <cstdio>
#include <vector>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    std::vector<long long> nums(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        nums[i] = nums[i - 1] + x; 
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        long long sum = nums[b] - nums[a - 1];
        printf("%lld\n", sum);
    }

    return 0;
}