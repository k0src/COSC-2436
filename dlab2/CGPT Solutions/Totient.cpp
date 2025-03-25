#include <iostream>
#include <vector>

const int N = 1000000;
std::vector<int> phi(N + 1);

void computeTotient() {
    for (int i = 0; i <= N; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= N; j += i) {
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
    }
}

int main() {
    computeTotient();
    int t, n;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::cout << phi[n] << "\n";
    }

    return 0;
}