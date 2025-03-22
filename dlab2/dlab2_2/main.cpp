#include <iostream>
#include <cmath>

const size_t mod = 1000000007;

size_t power(size_t a, size_t b) {
    if (b == 0) {
        return 1;
    }

    if (b % 2 == 0) {
        return (power(a, b / 2) * power(a, b / 2) % mod); 
    } else {
        return (a * power(a, b - 1) % mod);
    }
}

int main()
{
    size_t n;
    
    std::cin >> n;

    size_t a, b;

    for (size_t i = 0; i < n; i++) {
        std::cin >> a >> b;
        std::cout << power(a, b) << std::endl;
    }

    return 0;
}