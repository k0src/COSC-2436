#include <iostream>
#include <vector>

/* RECURSION SLOW + STACK OVERFLOW - USE MATRIX MULTIPLICATION */

using ll = long long;

const ll MOD = 1000000007;

std::vector<std::vector<ll>> multiply_matrices(const std::vector<std::vector<ll>>& a, const std::vector<std::vector<ll>>& b) {
    ll rows = a.size();
    ll cols = b[0].size();
    std::vector<std::vector<ll>> res(rows, std::vector<ll>(cols, 0));
    
    for (ll row = 0; row < rows; row++) {
        for (ll col = 0; col < cols; col++) {
            for (ll i = 0; i < b.size(); i++) {
                res[row][col] = (res[row][col] + (a[row][i] * b[i][col]) % MOD) % MOD;
            }
        }
    }
    return res;
}

std::vector<std::vector<ll>> matrix_power(std::vector<std::vector<ll>> matrix, ll power) {
    if (power == 0) {
        return {{1, 0}, {0, 1}};
    }
    
    if (power == 1) return matrix;
    
    if (power % 2 == 0) {
        auto half = matrix_power(matrix, power / 2);
        return multiply_matrices(half, half);
    }
    
    auto half = matrix_power(matrix, power / 2);
    auto full = multiply_matrices(half, half);
    return multiply_matrices(full, matrix);
}

ll fib(ll n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    std::vector<std::vector<ll>> matrix = {
        {1, 1},
        {1, 0}
    };
    
    return matrix_power(matrix, n - 1)[0][0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll n;
    std::cin >> n;
    std::cout << fib(n) << std::endl;
    
    return 0;
}