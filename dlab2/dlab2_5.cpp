#include <iostream>
#include <vector>

typedef long long ll;
const ll mod = 1000000007;

// SLOWER AND CAUSES STACK OVERFLOW FOR LARGE N BUT COOLER
ll sumDivisors(ll n, ll i) {
    if (n <= 0) return 0;
    
    if (i > n) return sumDivisors(n - 1, 1) % mod;

    if (n % i == 0) {
        return i + sumDivisors(n, i + 1) % mod;
    } else {
        return sumDivisors(n, i + 1) % mod;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll n;
    std::cin >> n;

    std::cout << sumDivisors(n, 1);

    return 0;
}