#include <stdio.h>
#include <algorithm>

using llu = unsigned long long;

llu countLess(llu x, llu n) {
    llu count = 0;
    
    for (llu i = 1; i <= n; i++) {
        count += std::min(n, (x / i));
    }

    return count;
}

llu midMultTable(llu n) {
    llu left = 1;
    llu right = n * n;
    llu k = ((n * n) + 1) / 2;

    while (left < right) {
        llu mid = (left + right) / 2;

        if (countLess(mid, n) < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    llu n;
    scanf("%llu", &n);

    printf("%llu", midMultTable(n));
    
    return 0;
}