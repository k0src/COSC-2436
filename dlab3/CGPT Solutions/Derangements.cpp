#include <iostream>

const int MOD = 1000000007;

long long derangements(int n) {
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return 0;
    }

    long long prev2 = 1;
    long long prev1 = 0;
    long long curr = 0;

    for (int i = 2; i <= n; ++i) {
        curr = ((i - 1) * (prev1 + prev2)) % MOD;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main() 
{
    int n;
    std::cin >> n;

    std::cout << derangements(n);
    
    return 0;
}