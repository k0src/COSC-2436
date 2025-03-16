#include <iostream>
#include <vector>

// FORMULA:
// where f is the function, N is the number, P is the set of primes, i is the index:
// // f(i, P) = f(N, i - 1, P) + N / P[i] - f(N / P[i], P, i - 1)
// // f(0, P) = 0

long long primeMultiples(long long n, std::vector<long long>& primes, long long i) {
    if (i == 0) {
        return 0;
    }

    long long count = n / primes[i - 1];

    count += primeMultiples(n, primes, i - 1);
    count -= primeMultiples(n / primes[i - 1], primes, i - 1);

    return count;
}

int main()
{
    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> primes;

    for (long long i = 0; i < k; i++) {
        long long p;
        std::cin >> p;
        primes.push_back(p);
    }

    std::cout << primeMultiples(n, primes, primes.size()) << std::endl;

    return 0;
}