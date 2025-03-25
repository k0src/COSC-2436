#include <iostream>
#include <vector>

int countNumbersWithKDivisors(int l, int r, int k) {
    std::vector<int> d(r + 1, 0);

    for (int i = 1; i <= r; i++) {
        for (int j = i; j <= r; j += i) {
            d[j]++;
        }
    }

    int count = 0;
    for (int n = l; n <= r; n++) {
        if (d[n] == k) {
            count++;
        }
    }

    return count;
}

int main() {
    int l, r, k;
    std::cin >> l >> r >> k;
    
    std::cout << countNumbersWithKDivisors(l, r, k);
    
    return 0;
}